#include "Trees.h"

/**
 * @brief Create a BST from a sorted array.
 *
 * @param v The sorted array.
 * @return Root of created BST.
 */
template<typename T>
Node<T>* createBstFromSortedArray(const vector<T>& v) {
    if (v.empty()) {
        return nullptr;
    }
    int mid = (v.size() - 1) / 2;
    vector<T> left;
    for (int i = 0; i < mid; ++i) {
        left.push_back(v[i]);
    }
    vector<T> right;
    for (int i = mid + 1; i < v.size(); ++i) {
        right.push_back(v[i]);
    }
    Node<T>* root = new Node<T>;
    root->data = v[mid];
    root->left = createBstFromSortedArray(left);
    root->right = createBstFromSortedArray(right);
    return root;
}

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
