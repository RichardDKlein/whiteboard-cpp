#include <cstdio>
#include "LinkedLists.h"

using namespace std;

/**
 * @brief Find the kth to last node in a linked list.
 *
 * @param list Head of list.
 * @return Kth to last node in list, or nullptr if k is too big.
 */
template<typename T>
Node<T>* findKthToLast(Node<T>* list, int k) {
    Node<T>* lead = list;
    int count = 0;
    while (lead && (count < k)) {
        lead = lead->next;
        count++;
    }
    if (count < k) {
        return nullptr;
    }
    Node<T>* lag = list;
    while (lead) {
        lead = lead->next;
        lag = lag->next;
    }
    return lag;
}

void testFindKthToLastInList() {
    printf("\n");
    printf("Test findKthToLastInList():\n");
    printf("===========================\n");

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
    appendToList(&list, c);
    appendToList(&list, d);
    appendToList(&list, e);
    appendToList(&list, f);
    appendToList(&list, g);
    printList(&list);

    for (int k = 1; k <= 8; ++k) {
        Node<char*>* kthToLastNode = findKthToLast(&list, k);
        printf("kth to last element (k = %d) is %s\n",
            k, kthToLastNode ? kthToLastNode->data : "nullptr");
    }
}
