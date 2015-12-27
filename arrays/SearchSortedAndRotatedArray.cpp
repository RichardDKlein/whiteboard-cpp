#include <cstdio>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Search a sorted and rotated array of ints.
 *
 * @param v The sorted and rotated array to be searched.
 * @param target The int to search for.
 * @return The index, in |v|, of |target| (or -1 if |v|
 * does not contain |target|).
 */

int searchSortedAndRotatedArray(vector<int> v, int target) {
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

string arrayToString(int count, int array[]);

void testSearchSortedAndRotatedArray() {
    printf("\n");
    printf("Test searchSortedAndRotatedArray():\n");
    printf("===================================\n");
    int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    size_t len = sizeof(a) / sizeof(int);

    printf("%s\n", arrayToString(len, a).c_str());

    vector<int> v;
    for (auto& i : a) {
        v.push_back(i);
    }

    for (auto& target : v) {
        printf("target = %d, index = %d\n",
            target, searchSortedAndRotatedArray(v, target));
    }

    int target = 999;
    printf("target = %d, index = %d\n",
        target, searchSortedAndRotatedArray(v, target));
}
