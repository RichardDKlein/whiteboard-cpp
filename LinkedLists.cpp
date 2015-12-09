#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

struct Node {
    void* data;
    Node* next;
};

Node* push_back(Node* list, void* data) {
    Node* curr = list;
    Node* prev = NULL;
    while (curr) {
        prev = curr;
        curr = curr->next;
    }
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    prev->next = node;
    return node;
}

Node* insert(Node* list, Node* after, void* data) {
    Node* curr = list;
    while (curr && (curr != after)) {
        curr = curr->next;
    }
    if (curr == after) {
        Node* node = new Node;
        node->data = data;
        node->next = curr->next;
        curr->next = node;
        return node;
    } else {
        return NULL;
    }
}

bool erase(Node* list, Node* toErase) {
    Node* curr = list;
    Node* prev = NULL;
    while (curr && (curr != toErase)) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == toErase) {
        prev->next = curr->next;
        return true;
    } else {
        return false;
    }
}

void removeDups(Node* list) {
    using namespace std;
    set<void*> seen;
    Node* curr = list;
    Node* prev = NULL;
    while (curr) {
        if (seen.count(curr->data) > 0) {
            // delete curr, don't advance prev
            prev->next = curr->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
}

Node* reverse(Node* list) {
    Node* curr = list;
    Node* rev = NULL;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        tmp->next = rev;
        rev = tmp;
    }
    return rev;
}

bool hasCycle(Node* list) {
    Node* slow = list;
    if (!list) return false;
    Node* fast = list->next;
    while (fast && (fast != slow)) {
        if (!fast->next) return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return (fast == slow);
}

Node* findKthToLast(Node* list, int k) {
    Node* lead = list;
    int count = 0;
    while (lead && (count < k)) {
        lead = lead->next;
        count++;
    }
    if (count < k) {
        return NULL;
    }
    Node* lag = list;
    while (lead) {
        lead = lead->next;
        lag = lag->next;
    }
    return lag;
}

void print(Node* list) {
    Node* curr = list;
    bool atHead = true;
    while (curr) {
        if (!atHead) {
            printf("->");
        } else {
            atHead = false;
        }
        printf("%s", (char*) curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void print(Node* list, int max) {
    Node* curr = list;
    int count = 0;
    bool atHead = true;
    while (curr && (count < max)) {
        if (!atHead) {
            printf("->");
        } else {
            atHead = false;
        }
        printf("%s", (char*) curr->data);
        curr = curr->next;
        count++;
    }
    printf("\n");
}

void testLinkedLists() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "                 LINKED LISTS                " << endl;
    cout << "=============================================" << endl;
    cout << endl;
    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    char e[] = "e";
    char f[] = "f";
    char g[] = "g";
    char x[] = "x";

    // Test push_back()
    printf("\nTest push_back():\n");
    Node list;
    list.data = a;
    list.next = NULL;
    push_back(&list, b);
    Node* cNode = push_back(&list, c);
    Node* dNode = push_back(&list, d);
    Node* eNode = push_back(&list, e);
    Node* fNode = push_back(&list, f);
    Node* gNode = push_back(&list, g);
    print(&list);

    // Test insert()
    printf("\nTest insert():\n");
    Node* xNode = insert(&list, dNode, x);
    print(&list);

    // Test erase()
    printf("\nTest erase():\n");
    erase(&list, xNode);
    print(&list);

    // Test removeDups()
    printf("\nRemoveDups():\n");
    insert(&list, cNode, a);
    insert(&list, eNode, b);
    insert(&list, fNode, d);
    push_back(&list, c);
    push_back(&list, e);
    push_back(&list, g);
    print(&list);
    removeDups(&list);
    print(&list);

    // Test reverse()
    printf("\nTest reverse():\n");
    Node* rev = reverse(&list);
    print(rev);
    Node* orig = reverse(rev);
    print(orig);

    // Test hasCycle()
    printf("\nTest hasCycle():\n");
    gNode->next = cNode;
    print(&list, 100);
    printf("Has cycle = %s\n", hasCycle(&list) ?
        "true" : "false");
    gNode->next = NULL;
    print(&list);
    printf("Has cycle = %s\n", hasCycle(&list) ?
        "true" : "false");

    // Test FindKthToLast()
    printf("\nTest FindKthToLast():\n");
    print(&list);
    for (int k = 1; k <= 8; ++k) {
        Node* kthToLastNode = findKthToLast(&list, k);
        printf("kth to last element (k = %d) is %s\n",
            k, (kthToLastNode) ?
            (char*) kthToLastNode->data : "NULL");
    }
}
