#include <cstdio>
#include <queue>

#include "BstNode.h"

using namespace std;

void testCreateBstFromSortedArray();
void testCreateNestedFolders();
void testIsBst();
void testTraverseBstBreadthFirst();
void testTraverseBstInOrder();
void testTraverseBstPostOrder();
void testTraverseBstPreOrder();

void testTrees() {
    printf("\n");
    printf("=============================================\n");
    printf("                    TREES                    \n");
    printf("=============================================\n");

    testCreateBstFromSortedArray();
    testCreateNestedFolders();
    testIsBst();
    testTraverseBstBreadthFirst();
    testTraverseBstInOrder();
    testTraverseBstPostOrder();
    testTraverseBstPreOrder();
}
