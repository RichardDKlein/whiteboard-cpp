#include <cstdio>
#include <set>
#include <vector>

#include "ListNode.h"

using namespace std;

/**
 * @brief Remove duplicates from a linked list.
 *
 * @param list Ptr to the head of the list.
 * @return Vector of ptrs to the removed list nodes.
 */
vector<ListNode*> removeDupsFromList(ListNode* list) {
    vector<ListNode*> result;
    set<void*> seen;
    ListNode* curr = list;
    ListNode* prev = NULL;
    while (curr) {
        if (seen.count(curr->data) > 0) {
            // delete curr, don't advance prev
            result.push_back(curr);
            prev->next = curr->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
    return result;
}

ListNode* appendToList(ListNode* list, void* data);
ListNode* insertInList(ListNode* list, ListNode* after, void* data);
void printList(ListNode* list);

void testRemoveDupsFromList() {
    printf("\n");
    printf("Test removeDupsFromList():\n");
    printf("==========================\n");

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
    ListNode* eNode = appendToList(&list, e);
    ListNode* fNode = appendToList(&list, f);
    appendToList(&list, g);
    printList(&list);

    insertInList(&list, cNode, a);
    insertInList(&list, eNode, b);
    insertInList(&list, fNode, d);
    appendToList(&list, c);
    appendToList(&list, e);
    appendToList(&list, g);
    printList(&list);

    vector<ListNode*> dups = removeDupsFromList(&list);
    printf("Removing duplicates: ");
    for (auto& dup : dups) {
        printf("%s ", (char*) dup->data);
    }
    printf("\n");
    printList(&list);
}
