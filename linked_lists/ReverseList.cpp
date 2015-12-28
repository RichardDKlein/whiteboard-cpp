#include <cstdio>
#include "LinkedLists.h"

using namespace std;

/**
 * @brief Reverse a linked list.
 *
 * @param list Head of list to be reversed.
 * @return Head of reversed list.
 */
template<typename T>
Node<T>* reverseList(Node<T>* list) {
    Node<T>* curr = list;
    Node<T>* rev = nullptr;
    while (curr) {
        Node<T>* tmp = curr;
        curr = curr->next;
        tmp->next = rev;
        rev = tmp;
    }
    return rev;
}

void testReverseList() {
    printf("\n");
    printf("Test reverseList():\n");
    printf("===================\n");

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";
    char f[] = "f";
    char g[] = "g";

    Node<char*> list;
    list.data = a;
    list.next = nullptr;
    appendToList(&list, b);
    appendToList(&list, c);
    appendToList(&list, d);
    appendToList(&list, e);
    appendToList(&list, f);
    appendToList(&list, g);
    printList(&list);

    Node<char*>* rev = reverseList(&list);
    printList(rev);

    Node<char*>* orig = reverseList(rev);
    printList(orig);
}
