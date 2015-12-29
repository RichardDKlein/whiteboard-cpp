#ifndef TREES_H
#define TREES_H

#include <vector>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
};

#include "../arrays/TestUtils.h"

template<typename T> Node<T>* createBstFromSortedArray(const vector<T>& v);
template<typename T> bool isBst(Node<T>* root);
template<typename T> vector<T> traverseBstBreadthFirst(Node<T>* root);
template<typename T> vector<T> traverseBstInOrder(Node<T>* root);
template<typename T> vector<T> traverseBstPostOrder(Node<T>* root);
template<typename T> vector<T> traverseBstPreOrder(Node<T>* root);

void testCreateBstFromSortedArray();
void testCreateNestedFolders();
void testIsBst();
void testTraverseBstBreadthFirst();
void testTraverseBstInOrder();
void testTraverseBstPostOrder();
void testTraverseBstPreOrder();

#endif // #ifndef TREES_H
