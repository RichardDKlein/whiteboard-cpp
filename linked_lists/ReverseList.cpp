#include <cstdio>

#include "ListNode.h"

using namespace std;

/**
 * @brief Reverse a linked list.
 *
 * @param list Ptr to head of list to be reversed.
 * @return Ptr to head of reversed list.
 */
ListNode* reverseList(ListNode* list) {
    ListNode* curr = list;
    ListNode* rev = nullptr;
    while (curr) {
        ListNode* tmp = curr;
        curr = curr->next;
        tmp->next = rev;
        rev = tmp;
    }
    return rev;
}

ListNode* appendToList(ListNode* list, void* data);
void printList(ListNode* list);

void testReverseList() {
    printf("\n");
    printf("Test reverseList():\n");
    printf("===================\n");

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

    ListNode* rev = reverseList(&list);
    printList(rev);

    ListNode* orig = reverseList(rev);
    printList(orig);
}
