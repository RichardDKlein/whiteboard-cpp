#include <cstdio>
#include <vector>

using namespace std;

/**
 * @brief Search a sorted and rotated array of ints.
 *
 * @param v The sorted and rotated array to be searched.
 * @param target The int to search for.
 * @return The index, in v, of target (or -1 if v does not
 * contain target).
 */

int searchSortedAndRotatedArray(vector<int> v, int target) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == target) {
            return mid;
        } else if (v[left] < v[mid]) {
            // left half is normally ordered
            if (v[left] <= target && target <= v[mid]) {
                // search left
                right = mid - 1;
            } else {
                // search right
                left = mid + 1;
            }
        } else {
            // right half is normally ordered
            if (v[mid] <= target && target <= v[right]) {
                // search right
                left = mid + 1;
            } else {
                // search left
                right = mid - 1;
            }
        }
    }
    return -1;
}

void testSearchSortedAndRotatedArray() {
    printf("\n");
    printf("Test searchSortedAndRotatedArray():\n");
    printf("===================================\n");
    int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    size_t len = sizeof(a) / sizeof(int);
    vector<int> v;
    for (size_t i = 0; i < len; ++i) {
        v.push_back(a[i]);
        printf("%d ", a[i]);
    }
    printf("\n");
    for (size_t i = 0; i < v.size(); ++i) {
        int target = v[i];
        printf("target = %d, index = %d\n",
            target, searchSortedAndRotatedArray(v, target));
    }
    int target = 999;
    printf("target = %d, index = %d\n",
        target, searchSortedAndRotatedArray(v, target));
}
