#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> RowCol;
typedef vector<vector<int>> Array2d;

/**
 * @brief Search a 2D array of ints in which all rows
 * and columns are sorted in ascending order.
 *
 * @param v Sorted 2D array to be searched.
 * @param target The int to search for.
 * @return The (row, col) of |target|, or (-1, -1) if
 * |v| does not contain |target|.
 */
RowCol searchSorted2dArray(const Array2d& v, int target) {
    int rows = v.size();
    int cols = v[0].size();

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    int row = bottom;
    int col = left;
    while (row >= top && col <= right) {
        int curr = v[row][col];
        if (curr > target) {
            --row;
        } else if (curr < target) {
            ++col;
        } else {
            return RowCol(row, col);
        }
    }
    return RowCol(-1, -1);
}

void testSearchSorted2dArray() {
    printf("\n");
    printf("Test searchSorted2dArray():\n");
    printf("===========================\n");

    #define ROWS 4
    #define COLS 5
    int a[ROWS][COLS] = {
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

    Array2d v(ROWS);
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            v[row].push_back(a[row][col]);
        }
    }

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            int target = v[row][col];
            RowCol loc = searchSorted2dArray(v, target);
            printf("target = %d, row = %d, col = %d\n",
                target, loc.first, loc.second);
        }
    }

    int target = 16;
    RowCol loc = searchSorted2dArray(v, target);
    printf("target = %d, row = %d, col = %d\n",
        target, loc.first, loc.second);
}
