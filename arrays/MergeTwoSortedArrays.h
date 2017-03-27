#pragma once
#include "Arrays.h"

/**
 * @brief Merge two sorted arrays into a single sorted array.
 *
 * @param v1 One sorted array.
 * @param v2 The other sorted array.
 * @return The merged array.
 */
template<typename T>
vector<T> mergeTwoSortedArrays(vector<T>& v1, vector<T>& v2) {
    vector<T> merged;
    for (;;) {
        if (v1.empty()) {
            merged.insert(merged.end(), v2.begin(), v2.end());
            break;
        }
        if (v2.empty()) {
            merged.insert(merged.end(), v1.begin(), v1.end());
            break;
        }
        if (v1[0] < v2[0]) {
            merged.push_back(v1[0]);
            v1.erase(v1.begin());
        } else {
            merged.push_back(v2[0]);
            v2.erase(v2.begin());
        }
    }
    return merged;
}
