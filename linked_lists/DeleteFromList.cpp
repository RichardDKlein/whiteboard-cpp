#include "LinkedLists.h"
#include "AppendToList.h"
#include "InsertInList.h"

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
    cout << endl;
    cout << "Test deleteFromList():" << endl;
    cout << "======================" << endl;

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
    appendToList(&head, &b[0]);
    appendToList(&head, &c[0]);
    Node<char*>* dNode = appendToList(&head, &d[0]);
    appendToList(&head, &e[0]);
    appendToList(&head, &f[0]);
    appendToList(&head, &g[0]);
    printList(&head);

    Node<char*>* xNode = insertInList(dNode, &x[0]);
    printList(&head);

    deleteFromList(xNode);
    printList(&head);
}
