#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

using City = string;
using CityPair = pair<City, City>;
using Territory = list<City>;

class SalesTerritories {
    using CityMap = unordered_map<City, Territory*>;

public:
    SalesTerritories(const vector<CityPair>& cityPairs);
    ~SalesTerritories();
    vector<Territory> getTerritories();

private:
    void addCityPair(const CityPair& cityPair);
    Territory* findTerritory(const City& city);
    void newTerritory(const City& city1, const City& city2);
    void addCityToTerritory(const City& city, Territory* territory);
    void mergeTerritories(Territory* src, Territory* dest);

    vector<CityPair> cityPairs_;
    vector<Territory*> territories_;
    CityMap cityMap_;
};

SalesTerritories::SalesTerritories(const vector<CityPair>& cityPairs)
    : cityPairs_(cityPairs) {

    for (auto& cityPair : cityPairs) {
        addCityPair(cityPair);
    }
}

SalesTerritories::~SalesTerritories() {
    for (auto& territory : territories_) {
        delete territory;
    }
}

vector<Territory> SalesTerritories::getTerritories() {
    vector<Territory> result;
    for (auto& territory : territories_) {
        if (!territory->empty()) {
            result.push_back(*territory);
        }
    }
    return result;
}

void SalesTerritories::addCityPair(const CityPair& cityPair) {
    City city1 = cityPair.first;
    City city2 = cityPair.second;

    Territory* territory1 = findTerritory(city1);
    Territory* territory2 = findTerritory(city2);

    if (territory1 == nullptr) {
        if (territory2 == nullptr) {
            newTerritory(city1, city2);
        } else {
            addCityToTerritory(city1, territory2);
        }
    } else {
        if (territory2 == nullptr) {
            addCityToTerritory(city2, territory1);
        } else {
            if (territory1 != territory2) {
                mergeTerritories(territory2, territory1);
            }
        }
    }
}

Territory* SalesTerritories::findTerritory(const City& city) {
    CityMap::iterator iter = cityMap_.find(city);
    if (iter == cityMap_.end()) {
        return nullptr;
    } else {
        return iter->second;
    }
}

void SalesTerritories::newTerritory(const City& city1, const City& city2) {
    Territory* territory = new Territory;
    territory->push_back(city1);
    territory->push_back(city2);
    territories_.push_back(territory);
    cityMap_[city1] = territory;
    cityMap_[city2] = territory;
}

void SalesTerritories::addCityToTerritory(const City& city, Territory* territory) {
    territory->push_back(city);
    cityMap_[city] = territory;
}

void SalesTerritories::mergeTerritories(Territory* src, Territory* dest) {
    for (auto& city : *src) {
        cityMap_[city] = dest;
    }
    dest->splice(dest->end(), *src);
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

    SalesTerritories salesTerritories(cityPairs);
    vector<Territory> territories = salesTerritories.getTerritories();

    cout << "Territories = " << endl;
    for (auto& territory : territories) {
        cout << "{" << endl;
        for (const auto& city : territory) {
            cout << "\t" << city << endl;
        }
        cout << "}" << endl;
    }
}
