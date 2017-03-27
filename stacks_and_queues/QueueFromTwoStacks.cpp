#include <iostream>
#include <stack>
#include "QueueFromTwoStacks.h"

using namespace std;

void testQueueFromTwoStacks() {
    cout << endl;
    cout << "Test QueueFromTwoStacks:" << endl;
    cout << "========================" << endl;

    QueueFromTwoStacks<char*> q;

    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";

    cout << "Push a" << endl;
    q.push(a);
    cout << "Push b" << endl;
    q.push(b);
    cout << "Push c" << endl;
    q.push(c);
    cout << "Push d" << endl;
    q.push(d);
    cout << "Push e" << endl;
    q.push(e);

    cout << endl;

    char* d1 = q.pop();
    cout << "Pop: " << d1 << endl;
    char* d2 = q.pop();
    cout << "Pop: " << d2 << endl;
    char* d3 = q.pop();
    cout << "Pop: " << d3 << endl;
    char* d4 = q.pop();
    cout << "Pop: " << d4 << endl;
    char* d5 = q.pop();
    cout << "Pop: " << d5 << endl;

    char* d6 = q.pop();
    cout << "Pop: " << ((d6 == nullptr) ? "<empty>" : d6) << endl;
}
