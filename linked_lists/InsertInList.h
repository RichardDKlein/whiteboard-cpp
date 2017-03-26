#pragma once
#include "LinkedLists.h"

/**
 * @brief insert an item in a linked list.
 *
 * @param after List node after which item is to be inserted.
 * @param data Item to be inserted.
 * @return New list node containing inserted data item.
 */
template<typename T>
Node<T>* insertInList(Node<T>* after, const T& data) {
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = after->next;
    after->next = node;

    return node;
}
