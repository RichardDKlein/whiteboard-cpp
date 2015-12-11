#include <cstdio>

#include "ListNode.h"

using namespace std;

/**
 * @brief Find the kth to last item in a linked list.
 *
 * @param list Ptr to head of list.
 * @return Ptr to kth to last node in list, or nullptr
 * if k is too big.
 */
ListNode* findKthToLast(ListNode* list, int k) {
    ListNode* lead = list;
    int count = 0;
    while (lead && (count < k)) {
        lead = lead->next;
        count++;
    }
    if (count < k) {
        return NULL;
    }
    ListNode* lag = list;
    while (lead) {
        lead = lead->next;
        lag = lag->next;
    }
    return lag;
}

ListNode* appendToList(ListNode* list, void* data);
void printList(ListNode* list);

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

    ListNode list;
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
        ListNode* kthToLastNode = findKthToLast(&list, k);
        printf("kth to last element (k = %d) is %s\n",
            k, (kthToLastNode) ?
            (char*) kthToLastNode->data : "NULL");
    }
}
