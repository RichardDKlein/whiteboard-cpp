#include "Trees.h"
#include "IsBst.h"

void testIsBst() {
    cout << endl;
    cout << "Test isBst():" << endl;
    cout << "=============" << endl;

    Node<int> node1 = { 1, nullptr, nullptr };
    Node<int> node2 = { 2, nullptr, nullptr };
    Node<int> node3 = { 3, nullptr, nullptr };
    Node<int> node4 = { 4, nullptr, nullptr };
    Node<int> node5 = { 5, nullptr, nullptr };
    Node<int> node6 = { 6, nullptr, nullptr };
    Node<int> node7 = { 7, nullptr, nullptr };

    cout << "        4      " << endl;
    cout << "     2     6   " << endl;
    cout << "    1 3   5 7  " << endl;
    cout << endl;

    node4.left = &node2;
    node4.right = &node6;

    node2.left = &node1;
    node2.right = &node3;

    node6.left = &node5;
    node6.right = &node7;

    cout << "Is BST = " << (isBst(&node4) ? "true" : "false") << endl;

    cout << endl;
    cout << "        4      " << endl;
    cout << "     2     6   " << endl;
    cout << "    1 5   3 7  " << endl;
    cout << endl;

    node2.right = &node5;
    node6.left = &node3;

    cout << "Is BST = " << (isBst(&node4) ? "true" : "false") << endl;
}
