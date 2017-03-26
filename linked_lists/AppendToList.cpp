#include "LinkedLists.h"
#include "AppendToList.h"

void testAppendToList() {
    cout << endl;
    cout << "Test appendToList():" << endl;
    cout << "====================" << endl;

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
    printList(&head);

    appendToList(&head, &b[0]);
    printList(&head);

    appendToList(&head, &c[0]);
    printList(&head);

    appendToList(&head, &d[0]);
    printList(&head);

    appendToList(&head, &e[0]);
    printList(&head);

    appendToList(&head, &f[0]);
    printList(&head);

    appendToList(&head, &g[0]);
    printList(&head);
}
