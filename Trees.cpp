#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a Binary Search Tree from a sorted array
Node* createBst(int count, int a[]) {
    if (count == 0) {
        return NULL;
    }
    int mid = (count - 1) / 2;
    Node* root = new Node;
    root->data = a[mid];
    int countLeft = mid;
    int countRight = count - 1 - mid;
    root->left = createBst(countLeft, &a[0]);
    root->right = createBst(countRight, &a[mid + 1]);
    return root;
}

void traverseInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->data << " ";
    traverseInOrder(root->right);
}

void traversePreOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

void traversePostOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    traversePostOrder(root->left);
    traversePostOrder(root->right);
    cout << root->data << " ";
}

void traverseBreadthFirst(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
}

bool isBst(Node* root) {
    if (root == NULL) {
        return true;
    }
    if (!isBst(root->left)) {
        return false;
    }
    if (!isBst(root->right)) {
        return false;
    }
    if (root->left && root->left->data >= root->data) {
        return false;
    }
    if (root->right && root->right->data <= root->data) {
        return false;
    }
    return true;
}

void testTrees() {
	cout << endl;
	cout << "=============================================" << endl;
	cout << "                    TREES                    " << endl;
	cout << "=============================================" << endl;
	cout << endl;

	// Test createBst() and TraverseInOrder()
    cout << endl <<
        "Test createBst() and TraverseInOrder():" << endl;
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    cout << "sorted array = [ ";
    for (auto elt : data) {
        cout << elt << " ";
    }
    cout << "]" << endl;
    Node* root = createBst(sizeof(data)/sizeof(data[0]), data);
    cout << "traverse BST inorder = ";
    traverseInOrder(root);
    cout << endl;

    // Test traversePreOrder()
    cout << endl << "Test traversePreOrder():" << endl;
    traversePreOrder(root);
    cout << endl;

    // Test traversePostOrder()
    cout << endl << "Test traversePostOrder():" << endl;
    traversePostOrder(root);
    cout << endl;

    // Test traverseBreadthFirst()
    cout << endl << "Test traverseBreadthFirst():" << endl;
    traverseBreadthFirst(root);
    cout << endl;

    // Test isBst()
    cout << endl << "Test isBst():" << endl;
    traverseInOrder(root);
    cout << endl << "Is BST = " <<
        (isBst(root) ? "true" : "false") << endl;
    int save = root->data;
    root->data = 999;
    traverseInOrder(root);
    cout << endl << "Is BST = " <<
        (isBst(root) ? "true" : "false") << endl;
    root->data = save;
}
