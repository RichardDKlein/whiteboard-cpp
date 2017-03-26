#pragma once

#include <unordered_set>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
};

#include "TestUtils.h"

void testAppendToList();
void testDeleteFromList();
void testInsertInList();
void testKthToLastInList();
void testLinkedLists();
void testListHasCycle();
void testRemoveDupsFromList();
void testReverseList();
