#include <cstdio>
#include "ListNode.h"

void printList(ListNode* list) {
    ListNode* curr = list;
    bool atHead = true;
    while (curr) {
        if (!atHead) {
            printf("->");
        } else {
            atHead = false;
        }
        printf("%s", (char*) curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void printList(ListNode* list, int max) {
    ListNode* curr = list;
    int count = 0;
    bool atHead = true;
    while (curr && (count < max)) {
        if (!atHead) {
            printf("->");
        } else {
            atHead = false;
        }
        printf("%s", (char*) curr->data);
        curr = curr->next;
        count++;
    }
    printf("\n");
}
