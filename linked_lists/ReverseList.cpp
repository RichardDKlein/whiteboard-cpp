#include "LinkedLists.h"
#include "AppendToList.h"

/**
 * @brief Reverse a linked list.
 *
 * @param head Head of list to be reversed.
 * @return Head of reversed list.
 */
template<typename T>
Node<T>* reverseList(Node<T>* head) {
    Node<T>* rev = nullptr;
    Node<T>* curr = head;
    while (curr) {
        Node<T>* next = curr->next;
        curr->next = rev;
        rev = curr;
        curr = next;
    }
    return rev;
}

void testReverseList() {
    cout << endl;
    cout << "Test reverseList():" << endl;
    cout << "===================" << endl;

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
    appendToList(&head, &b[0]);
    appendToList(&head, &c[0]);
    appendToList(&head, &d[0]);
    appendToList(&head, &e[0]);
    appendToList(&head, &f[0]);
    appendToList(&head, &g[0]);
    printList(&head);

    Node<char*>* rev = reverseList(&head);
    printList(rev);

    Node<char*>* orig = reverseList(rev);
    printList(orig);
}
