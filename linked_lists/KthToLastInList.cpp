#include "LinkedLists.h"
#include "AppendToList.h"
#include "KthToLastInList.h"

void testKthToLastInList() {
    cout << endl;
    cout << "Test kthToLastInList():" << endl;
    cout << "=======================" << endl;

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
    appendToList(&head, &b[0]);
    appendToList(&head, &c[0]);
    appendToList(&head, &d[0]);
    appendToList(&head, &e[0]);
    appendToList(&head, &f[0]);
    appendToList(&head, &g[0]);
    printList(&head);

    for (int k = 1; k <= 8; ++k) {
        Node<char*>* kthToLastNode = kthToLastInList(&head, k);
        cout << "kth to last element (k = " << k << ") is "
             << (kthToLastNode ? kthToLastNode->data : "nullptr")
             << endl;
    }
}
