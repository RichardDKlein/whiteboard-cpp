#pragma once
#include "Trees.h"

/**
 * @brief Perform a postorder traversal of a BST.
 *
 * @param root Root node of BST.
 * @return Vector containing postordered data.
 */
template<typename T>
vector<T> traverseBstPostOrder(Node<T>* root) {
    vector<T> data;
    if (root == nullptr) {
        return data;
    }
    data = traverseBstPostOrder(root->left);
    vector<T> right = traverseBstPostOrder(root->right);
    data.insert(data.end(), right.begin(), right.end());
    data.push_back(root->data);
    return data;
}
