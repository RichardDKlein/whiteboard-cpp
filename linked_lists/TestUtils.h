#include <iostream>
#include "LinkedLists.h"

using namespace std;

template<typename T>
void printList(Node<T>* head) {
    Node<T>* curr = head;
    bool atHead = true;
    while (curr) {
        if (!atHead) {
            cout << "->";
        } else {
            atHead = false;
        }
        cout << curr->data;
        curr = curr->next;
    }
    cout << endl;
}

template<typename T>
void printList(Node<T>* head, int max) {
    Node<T>* curr = head;
    int count = 0;
    bool atHead = true;
    while (curr && (count < max)) {
        if (!atHead) {
            cout << "->";
        } else {
            atHead = false;
        }
        cout << curr->data;
        curr = curr->next;
        count++;
    }
    cout << endl;
}
