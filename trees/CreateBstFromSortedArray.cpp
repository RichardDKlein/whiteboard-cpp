#include "Trees.h"
#include "CreateBstFromSortedArray.h"
#include "TraverseBstInOrder.h"

void testCreateBstFromSortedArray() {
    cout << endl;
    cout << "Test createBstFromSortedArray():" << endl;
    cout << "================================" << endl;
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    vector<int> v;
    for (auto n : data) {
        v.push_back(n);
    }
    cout << "sorted array = " << vectorToString(v) << endl;
    Node<int>* root = createBstFromSortedArray(v);
    vector<int> t = traverseBstInOrder(root);
    cout << "traverse BST inorder = " << vectorToString(t) << endl;
}
