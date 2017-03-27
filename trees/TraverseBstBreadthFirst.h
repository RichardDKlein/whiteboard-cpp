#pragma once
#include "Trees.h"

/**
 * @brief Perform a breadth-first traversal of a BST.
 *
 * @param root Root node of BST.
 * @return Vector containing data in breadth-first order.
 */
template<typename T>
vector<T> traverseBstBreadthFirst(Node<T>* root) {
    vector<T> data;
    if (root == nullptr) {
        return data;
    }
    queue<Node<T>*> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
        Node<T>* node = nodeQueue.front();
        nodeQueue.pop();
        data.push_back(node->data);
        if (node->left) {
            nodeQueue.push(node->left);
        }
        if (node->right) {
            nodeQueue.push(node->right);
        }
    }
    return data;
}
