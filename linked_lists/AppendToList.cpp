#include <cstdio>
#include "ListNode.h"

/**
 * @brief Append a data item to a linked list.
 *
 * @param list Ptr to the head of the list.
 * @param data Ptr to the data item.
 * @return Ptr to the new list node containing the appended data item.
 */
ListNode* appendToList(ListNode* list, void* data) {
    ListNode* curr = list;
    ListNode* prev = nullptr;
    while (curr) {
        prev = curr;
        curr = curr->next;
    }
    ListNode* node = new ListNode;
    node->data = data;
    node->next = nullptr;
    prev->next = node;
    return node;
}

void printList(ListNode* list);

void testAppendToList() {
    printf("\n");
    printf("Test appendToList():\n");
    printf("====================\n");

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";
    char f[] = "f";
    char g[] = "g";

    ListNode list;
    list.data = a;
    list.next = nullptr;
    printList(&list);

    appendToList(&list, b);
    printList(&list);

    appendToList(&list, c);
    printList(&list);

    appendToList(&list, d);
    printList(&list);

    appendToList(&list, e);
    printList(&list);

    appendToList(&list, f);
    printList(&list);

    appendToList(&list, g);
    printList(&list);
}
