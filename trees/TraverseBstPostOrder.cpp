#include <cstdio>
#include <string>
#include <vector>

#include "BstNode.h"

using namespace std;

/**
 * @brief Perform a postorder traversal of a BST.
 *
 * @param root Ptr to the root node of the BST.
 * @return Vector containing the data obtained during the traversal.
 */
vector<int> traverseBstPostOrder(BstNode* root) {
	vector<int> result;
    if (root == nullptr) {
        return result;
    }
    result = traverseBstPostOrder(root->left);
    vector<int> right = traverseBstPostOrder(root->right);
    result.insert(result.end(), right.begin(), right.end());
    result.push_back(root->data);
    return result;
}

BstNode* createBstFromSortedArray(int count, int a[]);
string vectorToString(vector<int> v);

void testTraverseBstPostOrder() {
	printf("\n");
	printf("Test traverseBstPostOrder():\n");
	printf("============================\n");

    printf("               9                  \n");
    printf("        4            13           \n");
    printf("     2     6     11      15       \n");
    printf("    1 3   5 7  10  12  14  16     \n");
    printf("             8              17    \n");
	printf("\n");

	int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    BstNode* root = createBstFromSortedArray(
    	sizeof(data)/sizeof(data[0]), data);
    vector<int> v = traverseBstPostOrder(root);
    string s = vectorToString(v);
    printf("traverse BST postorder = %s\n", s.c_str());
}
