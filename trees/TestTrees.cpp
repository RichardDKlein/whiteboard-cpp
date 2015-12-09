#include <cstdio>
#include <queue>

#include "BstNode.h"

using namespace std;

void testCreateBstFromSortedArray();
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
    testIsBst();
    testTraverseBstBreadthFirst();
    testTraverseBstInOrder();
    testTraverseBstPostOrder();
    testTraverseBstPreOrder();
}
