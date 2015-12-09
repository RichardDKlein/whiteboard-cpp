#include <climits>
#include <cstdio>
#include <vector>

#include "BstNode.h"

using namespace std;

vector<int> traverseBstInOrder(BstNode* root);

/**
 * @brief Determine whether a binary tree is a BST.
 *
 * @param root Ptr to the root node of the BST.
 * @return |true| if BST, |false| otherwise.
 */
bool isBst(BstNode* root) {
	vector<int> inorder = traverseBstInOrder(root);
	int count = inorder.size();
	if (count == 0 || count ==1) {
		return true;
	}
	int prev = INT_MIN;
	for (auto& curr : inorder) {
		if (curr <= prev) {
			return false;
		} else {
			prev = curr;
		}
	}
	return true;
}

void testIsBst() {
	printf("\n");
	printf("Test isBst():\n");
	printf("=============\n");

	BstNode node1 = { 1, nullptr, nullptr };
	BstNode node2 = { 2, nullptr, nullptr };
	BstNode node3 = { 3, nullptr, nullptr };
	BstNode node4 = { 4, nullptr, nullptr };
	BstNode node5 = { 5, nullptr, nullptr };
	BstNode node6 = { 6, nullptr, nullptr };
	BstNode node7 = { 7, nullptr, nullptr };

	printf("        4      \n");
	printf("     2     6   \n");
	printf("    1 3   5 7  \n");
	printf("\n");

	node4.left = &node2;
	node4.right = &node6;

	node2.left = &node1;
	node2.right = &node3;

	node6.left = &node5;
	node6.right = &node7;

	printf("Is BST = %s\n", isBst(&node4) ? "true" : "false");

	printf("\n");
	printf("        4      \n");
	printf("     2     6   \n");
	printf("    1 5   3 7  \n");
	printf("\n");

	node2.right = &node5;
	node6.left = &node3;

	printf("Is BST = %s\n", isBst(&node4) ? "true" : "false");
}
