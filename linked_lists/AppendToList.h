#pragma once
#include "LinkedLists.h"

/**
 * @brief Append a data item to a linked list.
 *
 * @param head Head of list.
 * @param data Data item.
 * @return New list node containing appended data item.
 */
template<typename T>
Node<T>* appendToList(Node<T>* head, const T& data) {
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    while (curr) {
        prev = curr;
        curr = curr->next;
    }
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = nullptr;
    prev->next = node;

    return node;
}
