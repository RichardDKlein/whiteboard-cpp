#pragma once
#include "LinkedLists.h"

/**
 * @brief Reverse a linked list.
 *
 * @param head Head of list to be reversed.
 * @return Head of reversed list.
 */
template<typename T>
Node<T>* reverseList(Node<T>* head) {
    Node<T>* rev = nullptr;
    Node<T>* curr = head;
    while (curr) {
        Node<T>* next = curr->next;
        curr->next = rev;
        rev = curr;
        curr = next;
    }
    return rev;
}
