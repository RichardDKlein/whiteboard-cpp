#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Folder {
    string name;
    string parentName;
};

struct TreeNode {
    string name;
    TreeNode* parent;
    vector<TreeNode*> children;
};

typedef unordered_map<string, TreeNode*> NodeMap;
typedef unordered_map<string, TreeNode*>::iterator NodeMapIterator;

TreeNode* buildFolderTree(const vector<Folder>& folders);
TreeNode* createOrFindNode(NodeMap& nodeMap, const string& name);
void destroyFolderTree(TreeNode* root);
vector<Folder> traverseFolderTree(TreeNode* root);

/**
 * @brief Create a tree of nested folders.
 *
 * @param folders List of folder specs for the folders to be created.
 * The folder specs are not in any particular order. Each folder spec
 * consists of the folder's name and its parent's name. The root folder
 * has a parent name of "".
 *
 * @return Copy of |folders|, but in creation order, so that parents
 * are created before their children.
 */
vector<Folder> createNestedFolders(const vector<Folder>& folders) {
    vector<Folder> result;
    TreeNode* root = buildFolderTree(folders);
    result = traverseFolderTree(root);
    destroyFolderTree(root);
    return result;
}

TreeNode* buildFolderTree(const vector<Folder>& folders) {
    TreeNode* root = nullptr;
    NodeMap nodeMap;
    NodeMapIterator iter;
    for (const auto& folder : folders) {
        TreeNode* folderNode = createOrFindNode(nodeMap, folder.name);
        if (folder.parentName == "") {
            folderNode->parent = nullptr;
            root = folderNode;
            continue;
        }
        TreeNode* parentNode = createOrFindNode(nodeMap, folder.parentName);
        folderNode->parent = parentNode;
        parentNode->children.push_back(folderNode);
    }
    return root;
}

TreeNode* createOrFindNode(NodeMap& nodeMap, const string& name) {
    TreeNode* node;
    NodeMapIterator iter = nodeMap.find(name);
    if (iter == nodeMap.end()) {
        node = new TreeNode;
        node->name = name;
        nodeMap[name] = node;
    } else {
        node = iter->second;
    }
    return node;
}

vector<Folder> traverseFolderTree(TreeNode* root) {
    vector<Folder> result;
    if (root == nullptr) {
        return result;
    }
    Folder folder;
    folder.name = root->name;
    folder.parentName = (root->parent) ? root->parent->name : "";
    result.push_back(folder);
    for (const auto& child : root->children) {
        vector<Folder> childFolders = traverseFolderTree(child);
        for (const auto& childFolder : childFolders) {
            result.push_back(childFolder);
        }
    }
    return result;
}

void destroyFolderTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    for (const auto& child : root->children) {
        destroyFolderTree(child);
    }
}

void testCreateNestedFolders() {
    printf("\n");
    printf("Test createNestedFolders():\n");
    printf("===========================\n");

    string folderNames[] = {
        "root",
        "I",
        "I.A",
        "I.A.1",
        "I.A.2",
        "I.A.3",
        "I.B",
        "I.B.1",
        "I.B.1.a",
        "I.B.1.b",
        "I.B.2",
        "II",
        "II.A",
        "II.A.1",
        "II.A.2",
        "II.A.2.a",
        "II.A.2.b",
        "II.A.2.c",
        "II.B",
        "II.B.1",
        "II.B.2",
        "II.B.3"
    };

    string parentNames[] = {
        "",
        "root",
        "I",
        "I.A",
        "I.A",
        "I.A",
        "I",
        "I.B",
        "I.B.1",
        "I.B.1",
        "I.B",
        "root",
        "II",
        "II.A",
        "II.A",
        "II.A.2",
        "II.A.2",
        "II.A.2",
        "II",
        "II.B",
        "II.B",
        "II.B"
    };

    int numFolders = sizeof(folderNames) / sizeof(folderNames[0]);
    vector<Folder> folders;
    for (int i = numFolders - 1; i >=0; --i) {
        Folder folder;
        folder.name = folderNames[i];
        folder.parentName = parentNames[i];
        folders.push_back(folder);
    }

    vector<Folder> result = createNestedFolders(folders);

    printf("Creation order:\n");
    for (auto& folder : result) {
        printf("\t%s\n", folder.name.c_str());
    }
}
