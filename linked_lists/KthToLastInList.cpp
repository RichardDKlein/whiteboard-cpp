#include "LinkedLists.h"

/**
 * @brief Find the kth to last node in a linked list.
 *
 * @param head Head of list.
 * @return Kth to last node in list, or nullptr if k is too big.
 */
template<typename T>
Node<T>* kthToLastInList(Node<T>* head, int k) {
    Node<T>* lead = head;
    int count = 0;
    while (lead && (count < k)) {
        lead = lead->next;
        ++count;
    }
    if (count < k) {
        return nullptr;
    }
    Node<T>* lag = head;
    while (lead) {
        lead = lead->next;
        lag = lag->next;
    }
    return lag;
}

void testKthToLastInList() {
    cout << endl;
    cout << "Test kthToLastInList():" << endl;
    cout << "=======================" << endl;

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
    appendToList(&head, c);
    appendToList(&head, d);
    appendToList(&head, e);
    appendToList(&head, f);
    appendToList(&head, g);
    printList(&head);

    for (int k = 1; k <= 8; ++k) {
        Node<char*>* kthToLastNode = kthToLastInList(&head, k);
        cout << "kth to last element (k = " << k << ") is "
             << (kthToLastNode ? kthToLastNode->data : "nullptr")
             << endl;
    }
}
