#include "LinkedLists.h"
#include "InsertInList.h"
#include "AppendToList.h"

void testInsertInList() {
    cout << endl;
    cout << "Test insertInList():" << endl;
    cout << "====================" << endl;

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";
    char f[] = "f";
    char g[] = "g";
    char x[] = "x";

    Node<char*> head;
    head.data = a;
    head.next = nullptr;
    appendToList(&head, &b[0]);
    appendToList(&head, &c[0]);
    Node<char*>* dNode = appendToList(&head, &d[0]);
    appendToList(&head, &e[0]);
    appendToList(&head, &f[0]);
    appendToList(&head, &g[0]);
    printList(&head);

    insertInList(dNode, &x[0]);
    printList(&head);
}
