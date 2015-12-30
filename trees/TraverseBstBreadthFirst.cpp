#include "Trees.h"

/**
 * @brief Perform a breadth-first traversal of a BST.
 *
 * @param root Root node of BST.
 * @return Vector containing results of traversal.
 */
template<typename T>
vector<T> traverseBstBreadthFirst(Node<T>* root) {
    vector<T> result;
    if (root == nullptr) {
        return result;
    }
    queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        Node<T>* node = q.front();
        q.pop();
        result.push_back(node->data);
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    return result;
}

void testTraverseBstBreadthFirst() {
    cout << endl;
    cout << "Test traverseBstBreadthFirst():" << endl;
    cout << "===============================" << endl;

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
    vector<int> t = traverseBstBreadthFirst(root);
    cout << "traverse BST breadth-first = " << vectorToString(t) << endl;
}
