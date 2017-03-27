#pragma once
#include "Trees.h"
#include "TraverseBstInOrder.h"

/**
 * @brief Determine whether a binary tree is a BST.
 *
 * @param root Ptr to the root node of the BST.
 * @return |true| if BST, |false| otherwise.
 */
template<typename T>
bool isBst(Node<T>* root) {
    vector<T> data = traverseBstInOrder(root);
    if (data.size() < 2) {
        return true;
    }
    for (int i = 1; i < data.size(); ++i) {
        if (data[i] <= data[i - 1]) {
            return false;
        }
    }
    return true;
}
