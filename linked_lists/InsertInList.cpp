#include "LinkedLists.h"

/**
 * @brief Append an item to a linked list.
 *
 * @param list Head of list.
 * @param after List node after which the item is to be inserted.
 * @param data Item to be inserted.
 * @return New list node containing inserted data item.
 */
template<typename T>
Node<T>* insertInList(Node<T>* list, Node<T>* after, T data) {
    Node<T>* curr = list;
    while (curr && (curr != after)) {
        curr = curr->next;
    }
    if (!curr) {
        return nullptr;
    }
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = curr->next;
    curr->next = node;

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

    insertInList(&list, dNode, x);
    printList(&list);
}
