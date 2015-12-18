#include <cstdio>
#include "ListNode.h"

/**
 * @brief Delete a data item from a linked list,
 * given only a pointer to the item to be deleted.
 *
 * @param toDelete Ptr to the list node containing the
 * data item to be deleted.
 * @return |true| if the node was successfully deleted,
 * |false| otherwise. (Will return |false| only if the
 * node is at the end of the list.)
 */
bool deleteFromList(ListNode* toErase) {
    ListNode* next = toErase->next;
    if (next == nullptr) {
        return false;
    }
    toErase->data = next->data;
    toErase->next = next->next;
    delete next;
    return true;
}

ListNode* appendToList(ListNode* list, void* data);
ListNode* insertInList(ListNode* list, ListNode* after, void* data);
void printList(ListNode* list);

void testDeleteFromList() {
    printf("\n");
    printf("Test deleteFromList():\n");
    printf("======================\n");

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

    deleteFromList(xNode);
    printList(&list);
}
