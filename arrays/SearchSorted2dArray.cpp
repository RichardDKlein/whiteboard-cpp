#include <cstdio>
#include <utility>

using namespace std;

/**
 * @brief Search a 2D array of ints in which all rows
 * and columns are sorted in ascending order.
 *
 * @param rows Number of rows in the array.
 * @param cols Number of columns in the array.
 * @param p Ptr to sorted 2D array to be searched.
 * @param target The int to search for.
 * @return The (row, col) of |target|, or (-1, -1) if
 * |*p| does not contain |target|.
 */

pair<int, int>
searchSorted2dArray(int rows, int cols, int** p, int target) {
    typedef int array2d[rows][cols];
    array2d& a = *(array2d*) p;

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    int row = bottom;
    int col = left;
    while (row >= top && col <= right) {
        int curr = a[row][col];
        if (curr > target) {
            --row;
        } else if (curr < target) {
            ++col;
        } else {
            return pair<int, int>(row, col);
        }
    }
    return pair<int, int>(-1, -1);
}

void testSearchSorted2dArray() {
    printf("\n");
    printf("Test searchSorted2dArray():\n");
    printf("===========================\n");

    #define ROWS 4
    #define COLS 5
    int a[][COLS] = {
        { 15, 20, 40, 60, 63 },
        { 25, 35, 65, 70, 74 },
        { 30, 55, 75, 80, 82 },
        { 45, 61, 85, 90, 99 }
    };

    for (int row = 0; row < ROWS; ++row) {
        printf("[ ");
        for (int col = 0; col < COLS; ++col) {
            printf("%d ", a[row][col]);
        }
        printf("]\n");
    }

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            int target = a[row][col];
            pair<int, int> loc =
                searchSorted2dArray(ROWS, COLS, (int**)a, target);
            printf("target = %d, row = %d, col = %d\n",
                target, loc.first, loc.second);
        }
    }

    int target = 16;
    pair<int, int> loc =
        searchSorted2dArray(ROWS, COLS, (int**)a, target);
    printf("target = %d, row = %d, col = %d\n",
        target, loc.first, loc.second);
}
