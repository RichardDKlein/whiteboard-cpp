#include <cstdio>
#include "LinkedLists.h"

using namespace std;

/**
 * @brief Determines whether a linked list contains a cycle.
 *
 * @param list Head of list.
 * @return |true| if list contains a cycle, |false| otherwise.
 */
template<typename T>
bool listHasCycle(Node<T>* list) {
    Node<T>* slow = list;
    if (!list) return false;
    Node<T>* fast = list->next;
    while (fast) {
        if (!fast->next) return false;
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

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

    Node<char*> list;
    list.data = a;
    list.next = nullptr;
    appendToList(&list, b);
    Node<char*>* cNode = appendToList(&list, c);
    appendToList(&list, d);
    appendToList(&list, e);
    appendToList(&list, f);
    Node<char*>* gNode = appendToList(&list, g);
    printList(&list);
    printf("Has cycle = %s\n", listHasCycle(&list) ?
        "true" : "false");

    gNode->next = cNode;
    printList(&list, 22);
    printf("Has cycle = %s\n", listHasCycle(&list) ?
        "true" : "false");
}
