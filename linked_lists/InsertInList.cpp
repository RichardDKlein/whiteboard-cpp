#include <cstdio>
#include "ListNode.h"

/**
 * @brief Append a data item to a linked list.
 *
 * @param list Ptr to the head of the list.
 * @param after Ptr to the list node after which the data item
 * is to be inserted.
 * @param data Ptr to the data item to be inserted.
 * @return Ptr to the new list node containing the inserted data item.
 */
ListNode* insertInList(ListNode* list, ListNode* after, void* data) {
    ListNode* curr = list;
    while (curr && (curr != after)) {
        curr = curr->next;
    }
    if (curr == after) {
        ListNode* node = new ListNode;
        node->data = data;
        node->next = curr->next;
        curr->next = node;
        return node;
    } else {
        return nullptr;
    }
}

ListNode* appendToList(ListNode* list, void* data);
void printList(ListNode* list);

void testInsertInList() {
    printf("\n");
    printf("Test insertInList():\n");
    printf("====================\n");

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";
    char f[] = "f";
    char g[] = "g";
    char x[] = "x";

    ListNode list;
    list.data = a;
    list.next = nullptr;
    appendToList(&list, b);
    appendToList(&list, c);
    ListNode* dNode = appendToList(&list, d);
    appendToList(&list, e);
    appendToList(&list, f);
    appendToList(&list, g);
    printList(&list);

    insertInList(&list, dNode, x);
    printList(&list);
}
