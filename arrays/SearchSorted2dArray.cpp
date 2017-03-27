#include "Arrays.h"
#include "SearchSorted2dArray.h"

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
