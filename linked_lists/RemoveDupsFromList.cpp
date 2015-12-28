#include <cstdio>
#include <set>
#include <vector>
#include "LinkedLists.h"

using namespace std;

/**
 * @brief Remove duplicates from a linked list.
 *
 * @param list Head of list.
 */
template<typename T>
void removeDupsFromList(Node<T>* list) {
    set<T> seen;
    Node<T>* curr = list;
    Node<T>* prev = nullptr;
    while (curr) {
        if (seen.count(curr->data) > 0) {
            Node<T>* tmp = curr;
            curr = curr->next;
            prev->next = curr;
            delete tmp;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

void testRemoveDupsFromList() {
    printf("\n");
    printf("Test removeDupsFromList():\n");
    printf("==========================\n");

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
    Node<char*>* cNode = appendToList(&list, c);
    appendToList(&list, d);
    Node<char*>* eNode = appendToList(&list, e);
    Node<char*>* fNode = appendToList(&list, f);
    appendToList(&list, g);
    printList(&list);

    insertInList(&list, cNode, a);
    insertInList(&list, eNode, b);
    insertInList(&list, fNode, d);
    appendToList(&list, c);
    appendToList(&list, e);
    appendToList(&list, g);
    printList(&list);

    removeDupsFromList(&list);
    printf("Removing duplicates:\n");
    printList(&list);
}
