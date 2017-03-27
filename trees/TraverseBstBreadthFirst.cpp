#include "Trees.h"
#include "TraverseBstBreadthFirst.h"
#include "CreateBstFromSortedArray.h"

void testTraverseBstBreadthFirst() {
    cout << endl;
    cout << "Test traverseBstBreadthFirst():" << endl;
    cout << "===============================" << endl;

    cout << "               9                  " << endl;
    cout << "        4            13           " << endl;
    cout << "     2     6     11      15       " << endl;
    cout << "    1 3   5 7  10  12  14  16     " << endl;
    cout << "             8              17    " << endl;
    cout << endl;

    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    vector<int> v;
    for (auto n : data) {
        v.push_back(n);
    }
    Node<int>* root = createBstFromSortedArray(v);
    vector<int> t = traverseBstBreadthFirst(root);
    cout << "traverse BST breadth-first = " << vectorToString(t) << endl;
}
