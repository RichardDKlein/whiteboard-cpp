#pragma once
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
        if (fast == slow) {
            return true;
        }
        slow = slow->next;
        fast = fast->next ? fast->next->next : nullptr;
    }
    return false;
}
