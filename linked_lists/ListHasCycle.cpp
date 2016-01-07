#include "LinkedLists.h"

/**
 * @brief Determines whether a linked list contains a cycle.
 *
 * @param head Head of list.
 * @return |true| if list contains a cycle, |false| otherwise.
 */
template<typename T>
bool listHasCycle(Node<T>* head) {
    Node<T>* slow = head;
    Node<T>* fast = head ? head->next : nullptr;
    while (fast) {
        slow = slow->next;
        fast = fast->next ? fast->next->next : nullptr;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

void testListHasCycle() {
    cout << endl;
    cout << "Test listHasCycle():" << endl;
    cout << "====================" << endl;

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";
    char f[] = "f";
    char g[] = "g";

    Node<char*> head;
    head.data = a;
    head.next = nullptr;
    appendToList(&head, b);
    Node<char*>* cNode = appendToList(&head, c);
    appendToList(&head, d);
    appendToList(&head, e);
    appendToList(&head, f);
    Node<char*>* gNode = appendToList(&head, g);
    printList(&head);
    cout << "Has cycle = "
         << (listHasCycle(&head) ? "true" : "false") << endl;

    gNode->next = cNode;
    printList(&head, 22);
    cout << "Has cycle = "
         << (listHasCycle(&head) ? "true" : "false") << endl;
}
