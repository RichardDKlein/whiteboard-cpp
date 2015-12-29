#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <set>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
};

#include "TestUtils.h"

template<typename T> Node<T>* appendToList(Node<T>* list, T data);
template<typename T> bool deleteFromList(Node<T>* toDelete);
template<typename T> Node<T>* findKthToLast(Node<T>* list, int k);
template<typename T> Node<T>* insertInList(Node<T>* list,
    Node<T>* after, T data);
template<typename T> bool listHasCycle(Node<T>* list);
template<typename T> void removeDupsFromList(Node<T>* list);
template<typename T> Node<T>* reverseList(Node<T>* list);

void testAppendToList();
void testDeleteFromList();
void testInsertInList();
void testKthToLastInList();
void testLinkedLists();
void testListHasCycle();
void testRemoveDupsFromList();
void testReverseList();

#endif // #ifndef LINKED_LISTS_H
