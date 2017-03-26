#pragma once
#include "LinkedLists.h"

/**
 * @brief Find the kth to last node in a linked list.
 *
 * @param head Head of list.
 * @return Kth to last node in list, or nullptr if k is too big.
 */
template<typename T>
Node<T>* kthToLastInList(Node<T>* head, int k) {
    Node<T>* lead = head;
    int count = 0;
    while (lead && (count < k)) {
        lead = lead->next;
        ++count;
    }
    if (count < k) {
        return nullptr;
    }
    Node<T>* lag = head;
    while (lead) {
        lead = lead->next;
        lag = lag->next;
    }
    return lag;
}
