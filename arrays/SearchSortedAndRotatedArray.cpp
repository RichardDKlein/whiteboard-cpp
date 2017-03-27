#include "Arrays.h"
#include "SearchSortedAndRotatedArray.h"

using namespace std;

void testSearchSortedAndRotatedArray() {
    cout << endl;
    cout << "Test searchSortedAndRotatedArray():" << endl;
    cout << "===================================" << endl;
    int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

    vector<int> v;
    for (auto& i : a) {
        v.push_back(i);
    }

    cout << vectorToString(v) << endl;

    for (auto& target : v) {
        int index = searchSortedAndRotatedArray(v, target);
        cout << "target = " << target << ", index = " << index << endl;
    }

    int target = 999;
    int index = searchSortedAndRotatedArray(v, target);
    cout << "target = " << target << ", index = " << index << endl;
}
