#pragma once
#include "Trees.h"

/**
 * @brief Perform a preorder traversal of a BST.
 *
 * @param root Root node of BST.
 * @return Vector containing preordered data.
 */
template<typename T>
vector<T> traverseBstPreOrder(Node<T>* root) {
    vector<T> data;
    if (root == nullptr) {
        return data;
    }
    data.push_back(root->data);
    vector<T> left = traverseBstPreOrder(root->left);
    data.insert(data.end(), left.begin(), left.end());
    vector<int> right = traverseBstPreOrder(root->right);
    data.insert(data.end(), right.begin(), right.end());
    return data;
}
