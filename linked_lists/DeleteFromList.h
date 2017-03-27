#pragma once
#include "LinkedLists.h"

/**
 * @brief Delete a node from a linked list,
 * given only a pointer to the node to be deleted.
 *
 * @param toDelete List node to be deleted.
 * @return |true| if the node was successfully deleted,
 * |false| otherwise. (Will return |false| only if the
 * node is at the end of the list.)
 */
template<typename T>
bool deleteFromList(Node<T>* toDelete) {
    Node<T>* next = toDelete->next;
    if (next == nullptr) {
        return false;
    }
    toDelete->data = next->data;
    toDelete->next = next->next;
    delete next;
    return true;
}
