#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

template<typename T>
struct Node {
    T data;
    Node* next;
};

#include "TestUtils.h"

template<typename T> Node<T>* appendToList(Node<T>* list, T data);
template<typename T> bool deleteFromList(Node<T>* toDelete);
template<typename T> Node<T>* findKthToLast(Node<T>* list, int k);
template<typename T> Node<T>* insertInList(Node<T>*, Node<T>*, T data);
template<typename T> bool listHasCycle(Node<T>* list);
template<typename T> void removeDupsFromList(Node<T>* list);
template<typename T> Node<T>* reverseList(Node<T>* list);

void testAppendToList();
void testDeleteFromList();
void testFindKthToLastInList();
void testInsertInList();
void testLinkedLists();
void testListHasCycle();
void testRemoveDupsFromList();
void testReverseList();

#endif // #ifndef LINKED_LISTS_H
