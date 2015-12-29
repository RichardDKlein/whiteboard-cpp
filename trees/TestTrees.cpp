#include <cstdio>
#include <queue>
#include "Trees.h"

using namespace std;

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
