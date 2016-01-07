#include "LinkedLists.h"

/**
 * @brief Append a data item to a linked list.
 *
 * @param head Head of list.
 * @param data Data item.
 * @return New list node containing appended data item.
 */
template<typename T>
Node<T>* appendToList(Node<T>* head, T data) {
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
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
    cout << endl;
    cout << "Test appendToList():" << endl;
    cout << "====================" << endl;

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";
    char f[] = "f";
    char g[] = "g";

    Node<char*> head;
    head.data = a;
    head.next = nullptr;
    printList(&head);

    appendToList(&head, b);
    printList(&head);

    appendToList(&head, c);
    printList(&head);

    appendToList(&head, d);
    printList(&head);

    appendToList(&head, e);
    printList(&head);

    appendToList(&head, f);
    printList(&head);

    appendToList(&head, g);
    printList(&head);
}
