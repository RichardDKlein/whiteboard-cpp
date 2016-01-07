#include "LinkedLists.h"

/**
 * @brief Remove duplicates from a linked list.
 *
 * @param head Head of list.
 */
template<typename T>
void removeDupsFromList(Node<T>* head) {
    Node<T>* curr = head;
    Node<T>* prev = nullptr;
    unordered_set<T> seen;
    while (curr) {
        if (seen.count(curr->data) > 0) {
            curr = curr->next;
            delete prev->next;
            prev->next = curr;
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
    appendToList(&head, b);
    Node<char*>* cNode = appendToList(&head, c);
    appendToList(&head, d);
    Node<char*>* eNode = appendToList(&head, e);
    Node<char*>* fNode = appendToList(&head, f);
    appendToList(&head, g);
    printList(&head);

    insertInList(cNode, a);
    insertInList(eNode, b);
    insertInList(fNode, d);
    appendToList(&head, c);
    appendToList(&head, e);
    appendToList(&head, g);
    printList(&head);

    removeDupsFromList(&head);
    cout << "Removing duplicates:" << endl;
    printList(&head);
}
