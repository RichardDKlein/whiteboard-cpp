#include <cstdio>
#include <string>

using namespace std;

/**
 * @brief Search a sorted and rotated array of ints.
 *
 * @param count Number of ints in the array.
 * @param a The sorted and rotated array to be searched.
 * @param target The int to search for.
 * @return The index, in |a|, of |target| (or -1 if |a|
 * does not contain |target|).
 */

int searchSortedAndRotatedArray(int count, int a[], int target) {
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == target) {
            return mid;
        } else if (a[left] < a[mid]) {
            // left half is normally ordered
            if (a[left] <= target && target <= a[mid]) {
                // search left
                right = mid - 1;
            } else {
                // search right
                left = mid + 1;
            }
        } else {
            // right half is normally ordered
            if (a[mid] <= target && target <= a[right]) {
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

string arrayToString(int count, int array[]);

void testSearchSortedAndRotatedArray() {
    printf("\n");
    printf("Test searchSortedAndRotatedArray():\n");
    printf("===================================\n");
    int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    size_t len = sizeof(a) / sizeof(int);

    printf("%s\n", arrayToString(len, a).c_str());

    for (size_t i = 0; i < len; ++i) {
        int target = a[i];
        printf("target = %d, index = %d\n",
            target, searchSortedAndRotatedArray(len, a, target));
    }

    int target = 999;
    printf("target = %d, index = %d\n",
        target, searchSortedAndRotatedArray(len, a, target));
}
