#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

using City = string;
using CityPair = pair<City, City>;
using Territory = vector<City>;

class SalesTerritories {
public:
    SalesTerritories(const vector<CityPair>& cityPairs)
        : cityPairs_(cityPairs) {}

    vector<Territory> getTerritories() {
        buildCityGraph();
        findConnectedSubgraphs();
        collateTerritories();
        return territories_;
    }

private:
    struct Node {
        City city;
        int territory; // negative => uninitialized
        vector<shared_ptr<Node>> neighbors;
        Node(City aCity) :
            city(aCity),
            territory(-1) {
        }
    };
    using CityMap = unordered_map<City, shared_ptr<Node>>;

    vector<CityPair> cityPairs_;
    vector<Territory> territories_;
    CityMap cityMap_;

    void buildCityGraph() {
        for (auto& cityPair : cityPairs_) {
            City city1 = cityPair.first;
            City city2 = cityPair.second;
            shared_ptr<Node> node1 = findOrCreateNode(city1);
            shared_ptr<Node> node2 = findOrCreateNode(city2);
            node1->neighbors.push_back(node2);
            node2->neighbors.push_back(node1);
        }
    }

    shared_ptr<Node> findOrCreateNode(const City& city) {
        shared_ptr<Node> node = findNode(city);
        if (node == nullptr) {
        	node = createNode(city);
        }
        return node;
    }

    shared_ptr<Node> findNode(const City& city) {
        CityMap::iterator iter = cityMap_.find(city);
        return (iter == cityMap_.end()) ? nullptr : iter->second;
    }

    shared_ptr<Node> createNode(const City& city) {
        shared_ptr<Node> node(new Node(city));
        cityMap_[city] = node;
        return node;
    }

    void findConnectedSubgraphs() {
        int currTerritory = 0;
        for (auto& entry : cityMap_) {
            shared_ptr<Node> node = entry.second;
            if (node->territory < 0) {
                labelConnectedNodes(node, currTerritory);
                ++currTerritory;
            }
        }
        territories_.resize(currTerritory);
    }

    void labelConnectedNodes(const shared_ptr<Node>& root,
    		int territory) {

    	// Breadth-First Search (BFS)
        queue<shared_ptr<Node>> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            shared_ptr<Node> node = nodeQueue.front();
            nodeQueue.pop();
            node->territory = territory;
            for (auto& neighbor : node->neighbors) {
                if (neighbor->territory < 0) {
                    nodeQueue.push(neighbor);
                }
            }
        }
    }

    void collateTerritories() {
        for (auto& entry : cityMap_) {
            City city = entry.first;
            shared_ptr<Node> node = entry.second;
            territories_[node->territory].push_back(city);
        }
    }
};

void testSalesTerritories() {
    cout << endl;
    cout << "Test salesTerritories():" << endl;
    cout << "========================" << endl;

    vector<CityPair> cityPairs;

    cityPairs.push_back(CityPair("San Francisco", "San Jose"));
    cityPairs.push_back(CityPair("Denver", "Colorado Springs"));
    cityPairs.push_back(CityPair("Los Angeles", "San Francisco"));
    cityPairs.push_back(CityPair("New York City", "Buffalo"));
    cityPairs.push_back(CityPair("San Jose", "San Diego"));
    cityPairs.push_back(CityPair("Colorado Springs", "Aspen"));
    cityPairs.push_back(CityPair("Santa Monica", "Pasadena"));
    cityPairs.push_back(CityPair("Buffalo", "Yonkers"));
    cityPairs.push_back(CityPair("Oakland", "Sacramento"));
    cityPairs.push_back(CityPair("Fort Collins", "Aurora"));
    cityPairs.push_back(CityPair("San Diego", "Los Angeles"));
    cityPairs.push_back(CityPair("Syracuse", "Albany"));
    cityPairs.push_back(CityPair("Los Angeles", "San Diego"));
    cityPairs.push_back(CityPair("Boulder", "Aspen"));
    cityPairs.push_back(CityPair("Oakland", "Santa Monica"));
    cityPairs.push_back(CityPair("Rochester", "Yonkers"));
    cityPairs.push_back(CityPair("San Francisco", "Oakland"));
    cityPairs.push_back(CityPair("Denver", "Fort Collins"));
    cityPairs.push_back(CityPair("San Jose", "San Francisco"));
    cityPairs.push_back(CityPair("New York City", "Syracuse"));
    cityPairs.push_back(CityPair("Pasadena", "Sacramento"));

    cout << "City pairs = " << endl;
    for (auto& cityPair : cityPairs) {
        cout << "\t(" << cityPair.first << ", "
             << cityPair.second << ")" << endl;
    }
    cout << endl;

    SalesTerritories salesTerritories(cityPairs);
    vector<Territory> territories = salesTerritories.getTerritories();

    cout << "Territories = " << endl;
    for (auto& territory : territories) {
        cout << "{" << endl;
        for (auto& city : territory) {
            cout << "\t" << city << endl;
        }
        cout << "}" << endl;
    }
}
