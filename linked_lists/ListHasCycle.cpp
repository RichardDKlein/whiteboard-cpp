#include <cstdio>

#include "ListNode.h"

using namespace std;

/**
 * @brief Determines whether a linked list contains a cycle.
 *
 * @param list Ptr to head of list.
 * @return |true| if list contains a cycle, |false| otherwise.
 */
bool listHasCycle(ListNode* list) {
    ListNode* slow = list;
    if (!list) return false;
    ListNode* fast = list->next;
    while (fast && (fast != slow)) {
        if (!fast->next) return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return (fast == slow);
}

ListNode* appendToList(ListNode* list, void* data);
void printList(ListNode* list);
void printList(ListNode* list, int max);

void testListHasCycle() {
    printf("\n");
    printf("Test listHasCycle():\n");
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
    appendToList(&list, b);
    ListNode* cNode = appendToList(&list, c);
    appendToList(&list, d);
    appendToList(&list, e);
    appendToList(&list, f);
    ListNode* gNode = appendToList(&list, g);
    printList(&list);
    printf("Has cycle = %s\n", listHasCycle(&list) ?
        "true" : "false");

    gNode->next = cNode;
    printList(&list, 22);
    printf("Has cycle = %s\n", listHasCycle(&list) ?
        "true" : "false");
}
