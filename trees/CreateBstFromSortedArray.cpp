#include <cstdio>
#include <string>
#include <vector>

#include "BstNode.h"

using namespace std;

/**
 * @brief Create a BST from a sorted array of ints.
 *
 * @param count The number of ints in the sorted array.
 * @param a The sorted array of ints.
 * @return Ptr to the root of the created BST.
 */
BstNode* createBstFromSortedArray(int count, int a[]) {
    if (count == 0) {
        return nullptr;
    }
    BstNode* root = new BstNode;
    int mid = (count - 1) / 2;
    root->data = a[mid];
    int countLeft = mid;
    int countRight = count - 1 - mid;
    root->left = createBstFromSortedArray(countLeft, &a[0]);
    root->right = createBstFromSortedArray(countRight, &a[mid + 1]);
    return root;
}

vector<int> traverseBstInOrder(BstNode* root);
string vectorToString(vector<int> v);

void testCreateBstFromSortedArray() {
    printf("\n");
    printf("Test createBstFromSortedArray():\n");
    printf("================================\n");
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    printf("sorted array = [ ");
    for (auto& elt : data) {
        printf("%d ", elt);
    }
    printf("]\n");
    BstNode* root = createBstFromSortedArray(
        sizeof(data)/sizeof(data[0]), data);
    vector<int> v = traverseBstInOrder(root);
    string s = vectorToString(v);
    printf("traverse BST inorder = %s\n", s.c_str());
}
