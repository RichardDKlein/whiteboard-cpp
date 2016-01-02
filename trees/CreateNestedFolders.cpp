#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Folder {
    string name;
    string parentName;
};

struct Node {
    string name;
    Node* parent;
    vector<Node*> children;
};

using NodeMap = unordered_map<string, Node*>;
using NodeMapIterator = NodeMap::iterator;

static Node* buildFolderTree(const vector<Folder>& folders);
static Node* createOrFindNode(NodeMap& nodeMap, const string& name);
static void destroyFolderTree(Node* root);
static vector<Folder> traverseFolderTree(Node* root);

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
    vector<Folder> reorderedFolders;
    Node* root = buildFolderTree(folders);
    reorderedFolders = traverseFolderTree(root);
    destroyFolderTree(root);
    return reorderedFolders;
}

static Node* buildFolderTree(const vector<Folder>& folders) {
    Node* root = nullptr;
    NodeMap nodeMap;
    NodeMapIterator iter;
    for (const auto& folder : folders) {
        Node* folderNode = createOrFindNode(nodeMap, folder.name);
        if (folder.parentName == "") {
            folderNode->parent = nullptr;
            root = folderNode;
            continue;
        }
        Node* parentNode = createOrFindNode(nodeMap, folder.parentName);
        folderNode->parent = parentNode;
        parentNode->children.push_back(folderNode);
    }
    return root;
}

static Node* createOrFindNode(NodeMap& nodeMap, const string& name) {
    Node* node;
    NodeMapIterator iter = nodeMap.find(name);
    if (iter == nodeMap.end()) {
        node = new Node;
        node->name = name;
        nodeMap[name] = node;
    } else {
        node = iter->second;
    }
    return node;
}

static vector<Folder> traverseFolderTree(Node* root) {
    vector<Folder> folders;
    if (root == nullptr) {
        return folders;
    }
    Folder folder;
    folder.name = root->name;
    folder.parentName = (root->parent) ? root->parent->name : "";
    folders.push_back(folder);
    for (const auto& child : root->children) {
        vector<Folder> grandkids = traverseFolderTree(child);
        folders.insert(folders.end(), grandkids.begin(), grandkids.end());
    }
    return folders;
}

static void destroyFolderTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    for (const auto& child : root->children) {
        destroyFolderTree(child);
    }
}

void testCreateNestedFolders() {
    cout << endl;
    cout << "Test createNestedFolders():" << endl;
    cout << "===========================" << endl;

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

    vector<Folder> reorderedFolders = createNestedFolders(folders);

    cout << "Creation order:" << endl;
    for (auto& folder : reorderedFolders) {
        cout << "\t" << folder.name << endl;
    }
}
