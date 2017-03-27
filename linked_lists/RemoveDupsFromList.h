#pragma once
#include "LinkedLists.h"

/**
 * @brief Remove duplicates from a linked list.
 *
 * @param head Head of list.
 */
template<typename T>
void removeDupsFromList(Node<T>* head) {
    unordered_set<T> seen;
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    while (curr) {
        if (seen.count(curr->data) > 0) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}
