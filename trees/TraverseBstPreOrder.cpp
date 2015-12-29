#include <cstdio>
#include <string>
#include <vector>

#include "Trees.h"

using namespace std;

/**
 * @brief Perform a preorder traversal of a BST.
 *
 * @param root Root node of BST.
 * @return Vector containing results of traversal.
 */
template<typename T>
vector<T> traverseBstPreOrder(Node<T>* root) {
    vector<T> result;
    if (root == nullptr) {
        return result;
    }
    result.push_back(root->data);
    vector<T> left = traverseBstPreOrder(root->left);
    result.insert(result.end(), left.begin(), left.end());
    vector<int> right = traverseBstPreOrder(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

void testTraverseBstPreOrder() {
    printf("\n");
    printf("Test traverseBstPreOrder():\n");
    printf("===========================\n");

    printf("               9                  \n");
    printf("        4            13           \n");
    printf("     2     6     11      15       \n");
    printf("    1 3   5 7  10  12  14  16     \n");
    printf("             8              17    \n");
    printf("\n");

    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    vector<int> v;
    for (auto n : data) {
        v.push_back(n);
    }
    Node<int>* root = createBstFromSortedArray(v);
    vector<int> t = traverseBstPreOrder(root);
    printf("traverse BST preorder = %s\n",
        vectorToString(t).c_str());
}
