#include <cstdio>
#include "LinkedLists.h"

/**
 * @brief Delete a node from a linked list,
 * given only a pointer to the node to be deleted.
 *
 * @param toDelete List node to be deleted.
 * @return |true| if the node was successfully deleted,
 * |false| otherwise. (Will return |false| only if the
 * node is at the end of the list.)
 */
template<typename T>
bool deleteFromList(Node<T>* toDelete) {
    Node<T>* next = toDelete->next;
    if (next == nullptr) {
        return false;
    }
    toDelete->data = next->data;
    toDelete->next = next->next;
    delete next;
    return true;
}

void testDeleteFromList() {
    printf("\n");
    printf("Test deleteFromList():\n");
    printf("======================\n");

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";
    char f[] = "f";
    char g[] = "g";
    char x[] = "x";

    Node<char*> list;
    list.data = a;
    list.next = nullptr;
    appendToList(&list, b);
    appendToList(&list, c);
    Node<char*>* dNode = appendToList(&list, d);
    appendToList(&list, e);
    appendToList(&list, f);
    appendToList(&list, g);
    printList(&list);

    Node<char*>* xNode = insertInList(&list, dNode, x);
    printList(&list);

    deleteFromList(xNode);
    printList(&list);
}
