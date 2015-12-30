#include "Trees.h"

/**
 * @brief Perform a postorder traversal of a BST.
 *
 * @param root Root node of BST.
 * @return Vector containing results of traversal.
 */
template<typename T>
vector<T> traverseBstPostOrder(Node<T>* root) {
    vector<T> result;
    if (root == nullptr) {
        return result;
    }
    result = traverseBstPostOrder(root->left);
    vector<T> right = traverseBstPostOrder(root->right);
    result.insert(result.end(), right.begin(), right.end());
    result.push_back(root->data);

    return result;
}

void testTraverseBstPostOrder() {
    cout << endl;
    cout << "Test traverseBstPostOrder():" << endl;
    cout << "============================" << endl;

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
    vector<int> t = traverseBstPostOrder(root);
    cout << "traverse BST postorder = " << vectorToString(t) << endl;
}
