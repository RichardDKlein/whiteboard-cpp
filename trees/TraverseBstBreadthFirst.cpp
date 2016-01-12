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
