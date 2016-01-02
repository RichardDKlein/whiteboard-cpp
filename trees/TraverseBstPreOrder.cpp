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

void testTraverseBstPreOrder() {
    cout << endl;
    cout << "Test traverseBstPreOrder():" << endl;
    cout << "===========================" << endl;

    cout << "               9                  " << endl;
    cout << "        4            13           " << endl;
    cout << "     2     6     11      15       " << endl;
    cout << "    1 3   5 7  10  12  14  16     " << endl;
    cout << "             8              17    " << endl;
    cout << endl;

    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    vector<int> v;
    for (auto n : data) {
        v.push_back(n);
    }
    Node<int>* root = createBstFromSortedArray(v);
    vector<int> t = traverseBstPreOrder(root);
    cout << "traverse BST preorder = " << vectorToString(t) << endl;
}
