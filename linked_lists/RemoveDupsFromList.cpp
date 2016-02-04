#include "LinkedLists.h"

/**
 * @brief Remove duplicates from a linked list.
 *
 * @param head Head of list.
 */
template<typename T>
void removeDupsFromList(Node<T>* head) {
    unordered_set<T> seen;
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    while (curr) {
        if (seen.count(curr->data) > 0) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

void testRemoveDupsFromList() {
    cout << endl;
    cout << "Test removeDupsFromList():" << endl;
    cout << "==========================" << endl;

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
    Node<char*>* cNode = appendToList(&head, &c[0]);
    appendToList(&head, &d[0]);
    Node<char*>* eNode = appendToList(&head, &e[0]);
    Node<char*>* fNode = appendToList(&head, &f[0]);
    appendToList(&head, &g[0]);
    printList(&head);

    insertInList(cNode, &a[0]);
    insertInList(eNode, &b[0]);
    insertInList(fNode, &d[0]);
    appendToList(&head, &c[0]);
    appendToList(&head, &e[0]);
    appendToList(&head, &g[0]);
    printList(&head);

    removeDupsFromList(&head);
    cout << "Removing duplicates:" << endl;
    printList(&head);
}
