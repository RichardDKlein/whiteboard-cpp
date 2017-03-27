#pragma once
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
    int first = 0;
    int last = v.size() - 1;
    int mid = (first + last) / 2;
    vector<T> left;
    for (int i = 0; i < mid; ++i) {
        left.push_back(v[i]);
    }
    vector<T> right;
    for (int i = mid + 1; i <= last; ++i) {
        right.push_back(v[i]);
    }
    Node<T>* root = new Node<T>;
    root->data = v[mid];
    root->left = createBstFromSortedArray(left);
    root->right = createBstFromSortedArray(right);

    return root;
}
