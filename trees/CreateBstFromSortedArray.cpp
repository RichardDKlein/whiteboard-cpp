#include <cstdio>
#include <string>
#include <vector>
#include "Trees.h"

using namespace std;

/**
 * @brief Create a BST from a sorted array.
 *
 * @param v The sorted array.
 * @return Root of created BST.
 */
template<typename T>
Node<T>* createBstFromSortedArray(const vector<T>& v) {
    int count = v.size();
    if (count == 0) {
        return nullptr;
    }
    int mid = (count - 1) / 2;
    vector<T> left;
    for (int i = 0; i < mid; ++i) {
        left.push_back(v[i]);
    }
    vector<T> right;
    for (int i = mid + 1; i < count; ++i) {
        right.push_back(v[i]);
    }
    Node<T>* root = new Node<T>;
    root->data = v[mid];
    root->left = createBstFromSortedArray(left);
    root->right = createBstFromSortedArray(right);

    return root;
}

void testCreateBstFromSortedArray() {
    printf("\n");
    printf("Test createBstFromSortedArray():\n");
    printf("================================\n");
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    vector<int> v;
    for (auto n : data) {
        v.push_back(n);
    }
    printf("sorted array = %s\n", vectorToString(v).c_str());
    Node<int>* root = createBstFromSortedArray(v);
    vector<int> t = traverseBstInOrder(root);
    printf("traverse BST inorder = %s\n", vectorToString(t).c_str());
}
