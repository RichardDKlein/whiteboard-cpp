#pragma once
#include "Arrays.h"

using RowCol = pair<int, int>;
template<typename T> using Array2d = vector<vector<T>>;

/**
 * @brief Search a 2D array in which all rows
 * and columns are sorted in ascending order.
 *
 * @param a Sorted 2D array to be searched.
 * @param target The value to search for.
 * @return The (row, col) of |target|, or (-1, -1) if
 * |a| does not contain |target|.
 */
template<typename T>
RowCol searchSorted2dArray(const Array2d<T>& a, const T& target) {
    int rows = a.size();
    int cols = a[0].size();

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    int row = bottom;
    int col = left;
    while (row >= top && col <= right) {
        if (a[row][col] < target) {
            ++col;
        } else if (a[row][col] > target) {
            --row;
        } else {
            return RowCol(row, col);
        }
    }
    return RowCol(-1, -1);
}
