#include <cstdio>
#include "ListNode.h"

/**
 * @brief Erase a data item from a linked list.
 *
 * @param list Ptr to the head of the list.
 * @param after Ptr to the list node containing the data item
 * to be erased.
 * @return |true| if the data item was successfully erased,
 * |false| otherwise.
 */
bool eraseFromList(ListNode* list, ListNode* toErase) {
    ListNode* curr = list;
    ListNode* prev = NULL;
    while (curr && (curr != toErase)) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == toErase) {
        prev->next = curr->next;
        return true;
    } else {
        return false;
    }
}

ListNode* appendToList(ListNode* list, void* data);
ListNode* insertInList(ListNode* list, ListNode* after, void* data);
void printList(ListNode* list);

void testEraseFromList() {
    printf("\n");
    printf("Test eraseFromList():\n");
    printf("=====================\n");

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

    ListNode* xNode = insertInList(&list, dNode, x);
    printList(&list);

    eraseFromList(&list, xNode);
    printList(&list);
}
