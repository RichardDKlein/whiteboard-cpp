#include "Arrays.h"

typedef pair<int, int> RowCol;
template<typename T> using Array2d = vector<vector<T>>;

/**
 * @brief Search a 2D array in which all rows
 * and columns are sorted in ascending order.
 *
 * @param v Sorted 2D array to be searched.
 * @param target The value to search for.
 * @return The (row, col) of |target|, or (-1, -1) if
 * |v| does not contain |target|.
 */
template<typename T>
RowCol searchSorted2dArray(const Array2d<T>& v, T target) {
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
    cout << endl;
    cout << "Test searchSorted2dArray():" << endl;
    cout << "===========================" << endl;

    #define ROWS 4
    #define COLS 5
    int a[ROWS][COLS] = {
        { 15, 20, 40, 60, 63 },
        { 25, 35, 65, 70, 74 },
        { 30, 55, 75, 80, 82 },
        { 45, 61, 85, 90, 99 }
    };

    for (int row = 0; row < ROWS; ++row) {
        cout << "[ ";
        for (int col = 0; col < COLS; ++col) {
            cout << a[row][col] << " ";
        }
        cout << "]" << endl;
    }

    Array2d<int> v(ROWS);
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            v[row].push_back(a[row][col]);
        }
    }

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            int target = v[row][col];
            RowCol loc = searchSorted2dArray(v, target);
            cout << "target = " << target << ", row = " <<
                loc.first << ", col = " << loc.second << endl;
        }
    }

    int target = 16;
    RowCol loc = searchSorted2dArray(v, target);
    cout << "target = " << target << ", row = " <<
        loc.first << ", col = " << loc.second << endl;
}
