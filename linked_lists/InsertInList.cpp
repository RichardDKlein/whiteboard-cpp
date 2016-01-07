#include "LinkedLists.h"

/**
 * @brief insert an item in a linked list.
 *
 * @param after List node after which item is to be inserted.
 * @param data Item to be inserted.
 * @return New list node containing inserted data item.
 */
template<typename T>
Node<T>* insertInList(Node<T>* after, T data) {
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = after->next;
    after->next = node;

    return node;
}

void testInsertInList() {
    cout << endl;
    cout << "Test insertInList():" << endl;
    cout << "====================" << endl;

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";
    char f[] = "f";
    char g[] = "g";
    char x[] = "x";

    Node<char*> head;
    head.data = a;
    head.next = nullptr;
    appendToList(&head, b);
    appendToList(&head, c);
    Node<char*>* dNode = appendToList(&head, d);
    appendToList(&head, e);
    appendToList(&head, f);
    appendToList(&head, g);
    printList(&head);

    insertInList(dNode, x);
    printList(&head);
}
