#include <iostream>

using namespace std;

template<typename T>
void printList(Node<T>* list) {
    Node<T>* curr = list;
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
void printList(Node<T>* list, int max) {
    Node<T>* curr = list;
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
