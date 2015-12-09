#include <cstdio>
#include <string>
#include <vector>

#include "BstNode.h"

using namespace std;

/**
 * @brief Perform a preorder traversal of a BST.
 *
 * @param root Ptr to the root node of the BST.
 * @return Vector containing the data obtained during the traversal.
 */
vector<int> traverseBstPreOrder(BstNode* root) {
	vector<int> result;
    if (root == nullptr) {
        return result;
    }
    result.push_back(root->data);
    vector<int> left = traverseBstPreOrder(root->left);
    result.insert(result.end(), left.begin(), left.end());
    vector<int> right = traverseBstPreOrder(root->right);
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

BstNode* createBstFromSortedArray(int count, int a[]);
string vectorToString(vector<int> v);

void testTraverseBstPreOrder() {
	printf("\n");
	printf("Test traverseBstPreOrder():\n");
	printf("===========================\n");

    printf("               9                  \n");
    printf("        4            13           \n");
    printf("     2     6     11      15       \n");
    printf("    1 3   5 7  10  12  14  16     \n");
    printf("             8              17    \n");
	printf("\n");

	int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    BstNode* root = createBstFromSortedArray(
    	sizeof(data)/sizeof(data[0]), data);
    vector<int> v = traverseBstPreOrder(root);
    string s = vectorToString(v);
    printf("traverse BST preorder = %s\n", s.c_str());
}
