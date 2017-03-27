#pragma once

#include "../bit_manipulation/BitManipulation.h"
#include "Sets.h"

/**
 * @brief Return the power set of a set, i.e. the set of all subsets
 * of that set, using iteration.
 *
 * @param s The set of interest.
 * @return The power set of |s|.
 */
template<typename T>
set<set<T>> powerSetIterative(const set<T>& s) {
    set<set<T>> powerSet;
    unsigned int numSubsets = pow(2, s.size());
    for (unsigned int i = 0; i < numSubsets; ++i) {
        set<T> subset;
        typename set<T>::iterator iter = s.begin();
        for (int bit = 0; bit < s.size(); ++bit, ++iter) {
            if (getBit(i, bit) == 1) {
                subset.insert(*iter);
            }
        }
        powerSet.insert(subset);
    }
    return powerSet;
}
