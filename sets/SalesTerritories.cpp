#include "Sets.h"

using City = string;
using CityPair = pair<City, City>;
using Territory = unordered_set<City>;
using CityMap = unordered_map<City, Territory*>;

/**
 * @brief Find the cities in each sales territory.
 *
 * @param cityPairs A vector of pairs of cities.
 * The cities in each pair are in the same territory.
 *
 * @return A vector of territories. Each territory
 * contains the names of all the cities in that territory.
 */
vector<Territory> salesTerritories(const vector<CityPair>& cityPairs) {
    vector<Territory*> territories;
    CityMap cityMap;
    for (auto& cityPair : cityPairs) {
        City city1 = cityPair.first;
        City city2 = cityPair.second;
        CityMap::iterator iter1 = cityMap.find(city1);
        CityMap::iterator iter2 = cityMap.find(city2);
        if (iter1 == cityMap.end()) {
            if (iter2 == cityMap.end()) {
                // haven't seen city1 or city2 yet
                Territory* territory = new Territory;
                territory->insert(city1);
                territory->insert(city2);
                territories.push_back(territory);
                cityMap[city1] = territory;
                cityMap[city2] = territory;
            } else {
                // add city1 to city2's territory
                Territory* city2Territory = iter2->second;
                city2Territory->insert(city1);
                cityMap[city1] = city2Territory;
            }
        } else {
            if (iter2 == cityMap.end()) {
                // add city2 to city1's territory
                Territory* city1Territory = iter1->second;
                city1Territory->insert(city2);
                cityMap[city2] = city1Territory;
            } else {
                Territory* city1Territory = iter1->second;
                Territory* city2Territory = iter2->second;
                if (city1Territory != city2Territory) {
                    // merge city2's territory into city1's
                    for (auto& city : *city2Territory) {
                        cityMap[city] = city1Territory;
                    }
                    city1Territory->insert(city2Territory->begin(),
                        city2Territory->end());
                    city2Territory->clear();
                }
            }
        }
    }
    // remove empty territories from final result
    vector<Territory> result;
    for (auto& territory : territories) {
        if (!territory->empty()) {
            result.push_back(*territory);
        }
        delete territory; // garbage collection
    }
    return result;
}

void testSalesTerritories() {
    cout << endl;
    cout << "Test salesTerritories():" << endl;
    cout << "========================" << endl;

    vector<CityPair> cityPairs;

    cityPairs.push_back(CityPair("San Francisco", "San Jose"));
    cityPairs.push_back(CityPair("Denver", "Colorado Springs"));
    cityPairs.push_back(CityPair("New York City", "Buffalo"));
    cityPairs.push_back(CityPair("San Jose", "San Diego"));
    cityPairs.push_back(CityPair("Colorado Springs", "Aspen"));
    cityPairs.push_back(CityPair("Buffalo", "Yonkers"));
    cityPairs.push_back(CityPair("Oakland", "Sacramento"));
    cityPairs.push_back(CityPair("Fort Collins", "Aurora"));
    cityPairs.push_back(CityPair("Syracuse", "Albany"));
    cityPairs.push_back(CityPair("Los Angeles", "San Diego"));
    cityPairs.push_back(CityPair("Boulder", "Aspen"));
    cityPairs.push_back(CityPair("Rochester", "Yonkers"));
    cityPairs.push_back(CityPair("San Francisco", "Oakland"));
    cityPairs.push_back(CityPair("Denver", "Fort Collins"));
    cityPairs.push_back(CityPair("New York City", "Syracuse"));

    cout << "City pairs = " << endl;
    for (auto& cityPair : cityPairs) {
        cout << "\t(" << cityPair.first << ", "
             << cityPair.second << ")" << endl;
    }
    cout << endl;

    vector<Territory> territories = salesTerritories(cityPairs);
    cout << "Territories = " << endl;
    for (auto& territory : territories) {
        cout << "{" << endl;
        for (const auto& city : territory) {
            cout << "\t" << city << endl;
        }
        cout << "}" << endl;
    }
}
