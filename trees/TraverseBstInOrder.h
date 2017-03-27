#pragma once
#include "Trees.h"

/**
 * @brief Perform an inorder traversal of a BST.
 *
 * @param root Root node of BST.
 * @return Vector containing inordered data.
 */
template<typename T>
vector<T> traverseBstInOrder(Node<T>* root) {
    vector<T> data;
    if (root == nullptr) {
        return data;
    }
    data = traverseBstInOrder(root->left);
    data.push_back(root->data);
    vector<T> right = traverseBstInOrder(root->right);
    data.insert(data.end(), right.begin(), right.end());
    return data;
}
