#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Folder {
    string folderName;
    string parentName;
};

struct Node {
    string folderName;
    Node* parent;
    vector<Node*> children;
};

using NodeMap = unordered_map<string, Node*>;

static Node* buildFolderTree(const vector<Folder>& folders);
static Node* findOrCreate(NodeMap& nodeMap, const string& folderName);
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
    Node* root = buildFolderTree(folders);
    vector<Folder> nested = traverseFolderTree(root);
    destroyFolderTree(root);
    return nested;
}

static Node* buildFolderTree(const vector<Folder>& folders) {
    Node* root;
    NodeMap nodeMap;
    for (const auto& folder : folders) {
        Node* folderNode = findOrCreate(nodeMap, folder.folderName);
        if (folder.parentName == "") {
            root = folderNode;
            folderNode->parent = nullptr;
            continue;
        }
        Node* parentNode = findOrCreate(nodeMap, folder.parentName);
        folderNode->parent = parentNode;
        parentNode->children.push_back(folderNode);
    }
    return root;
}

static Node* findOrCreate(NodeMap& nodeMap, const string& folderName) {
    Node* folderNode;
    NodeMap::iterator iter = nodeMap.find(folderName);
    if (iter == nodeMap.end()) {
        folderNode = new Node;
        folderNode->folderName = folderName;
        nodeMap[folderName] = folderNode;
    } else {
        folderNode = iter->second;
    }
    return folderNode;
}

static vector<Folder> traverseFolderTree(Node* root) {
    vector<Folder> folders;
    if (root == nullptr) {
        return folders;
    }
    Folder rootFolder;
    rootFolder.folderName = root->folderName;
    rootFolder.parentName = root->parent ?
        root->parent->folderName : "";
    folders.push_back(rootFolder);
    for (auto& child : root->children) {
        vector<Folder> childFolders = traverseFolderTree(child);
        folders.insert(folders.end(),
            childFolders.begin(), childFolders.end());
    }
    return folders;
}

static void destroyFolderTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    for (auto& child : root->children) {
        destroyFolderTree(child);
    }
    delete root;
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
        folder.folderName = folderNames[i];
        folder.parentName = parentNames[i];
        folders.push_back(folder);
    }

    vector<Folder> reorderedFolders = createNestedFolders(folders);

    cout << "Creation order:" << endl;
    for (auto& folder : reorderedFolders) {
        cout << "\t" << folder.folderName << endl;
    }
}
