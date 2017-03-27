#pragma once
#include "Arrays.h"

using namespace std;

/**
 * @brief Search a sorted and rotated array.
 *
 * @param v The sorted and rotated array to be searched.
 * @param target The value to search for.
 * @return The index, in |v|, of |target| (or -1 if |v|
 * does not contain |target|).
 */
template<typename T>
int searchSortedAndRotatedArray(const vector<T>& v, const T& target) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == target) {
            return mid;
        }
        if (v[left] < v[mid]) { // if left half is normally ordered
            if (v[left] <= target && target <= v[mid]) {
                right = mid - 1; // search left
            } else {
                left = mid + 1; // search right
            }
        } else { // right half is normally ordered
            if (v[mid] <= target && target <= v[right]) {
                left = mid + 1; // search right
            } else {
                right = mid - 1; // search left
            }
        }
    }
    return -1;
}
