#include <cstdio>
#include "LinkedLists.h"

/**
 * @brief Append a data item to a linked list.
 *
 * @param list Head of list.
 * @param data Data item.
 * @return New list node containing appended data item.
 */
template<typename T>
Node<T>* appendToList(Node<T>* list, T data) {
    Node<T>* curr = list;
    Node<T>* prev = nullptr;
    while (curr) {
        prev = curr;
        curr = curr->next;
    }
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = nullptr;
    prev->next = node;

    return node;
}

void testAppendToList() {
    printf("\n");
    printf("Test appendToList():\n");
    printf("====================\n");

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
    printList(&list);

    appendToList(&list, b);
    printList(&list);

    appendToList(&list, c);
    printList(&list);

    appendToList(&list, d);
    printList(&list);

    appendToList(&list, e);
    printList(&list);

    appendToList(&list, f);
    printList(&list);

    appendToList(&list, g);
    printList(&list);
}
