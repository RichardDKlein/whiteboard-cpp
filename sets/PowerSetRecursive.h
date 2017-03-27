#pragma once
#include "Sets.h"

/**
 * @brief Return the power set of a set, i.e. the set of all subsets
 * of that set, using recursion.
 *
 * @param s The set of interest.
 * @return The power set of |s|.
 */
template<typename T>
set<set<T>> powerSetRecursive(const set<T>& s) {
    set<set<T>> powerSet;
    if (s.empty()) {
        powerSet.insert(set<T>());
        return powerSet;
    }
    set<T> rem = s;
    T firstElt = *rem.begin();
    rem.erase(rem.begin());
    set<set<T>> remPowerSet = powerSetRecursive(rem);
    powerSet = remPowerSet;
    for (auto subset : remPowerSet) {
        subset.insert(firstElt);
        powerSet.insert(subset);
    }
    return powerSet;
}
