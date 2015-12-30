#include "Trees.h"

/**
 * @brief Perform an inorder traversal of a BST.
 *
 * @param root Root node of BST.
 * @return Vector containing results of traversal.
 */
template<typename T>
vector<T> traverseBstInOrder(Node<T>* root) {
    vector<T> result;
    if (root == nullptr) {
        return result;
    }
    result = traverseBstInOrder(root->left);
    result.push_back(root->data);
    vector<T> right = traverseBstInOrder(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

void testTraverseBstInOrder() {
    cout << endl;
    cout << "Test traverseBstInOrder():" << endl;
    cout << "==========================" << endl;

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
    vector<int> t = traverseBstInOrder(root);
    cout << "traverse BST inorder = " << vectorToString(t) << endl;
}
