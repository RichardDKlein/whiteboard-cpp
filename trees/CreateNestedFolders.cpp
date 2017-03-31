#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Folder {
    string folderName;
    string parentName;
};

/**
 * Given a list of folders and subfolders in no particular order,
 * reorder the list so that it is in a valid creation order, i.e.
 * so that parents are created before their children.
 */
class CreateNestedFolders {
    struct Node {
        string folderName;
        Node* parent;
        vector<Node*> children;
    };
    using NodeMap = unordered_map<string, Node*>;

private:
    vector<Folder> folders_;
    NodeMap nodeMap_;
    Node* root_;
    vector<Folder> nested_;

public:
    CreateNestedFolders(const vector<Folder>& folders) : folders_(folders) {}

    vector<Folder> solve() {
        buildFolderTree();
        nested_ = traverseFolderTree(root_);
        destroyFolderTree(root_);
        return nested_;
    }

private:
    void buildFolderTree() {
        for (const auto& folder : folders_) {
            Node* folderNode = findOrCreate(folder.folderName);
            if (folder.parentName == "") {
                root_ = folderNode;
                folderNode->parent = nullptr;
                continue;
            }
            Node* parentNode = findOrCreate(folder.parentName);
            folderNode->parent = parentNode;
            parentNode->children.push_back(folderNode);
        }
    }

    Node* findOrCreate(const string& folderName) {
        Node* folderNode;
        NodeMap::iterator iter = nodeMap_.find(folderName);
        if (iter == nodeMap_.end()) {
            folderNode = new Node;
            folderNode->folderName = folderName;
            nodeMap_[folderName] = folderNode;
        } else {
            folderNode = iter->second;
        }
        return folderNode;
    }

    vector<Folder> traverseFolderTree(Node* root) {
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

    void destroyFolderTree(Node* root) {
        if (root == nullptr) {
            return;
        }
        for (auto& child : root->children) {
            destroyFolderTree(child);
        }
        delete root;
    }
};

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

    CreateNestedFolders createNestedFolders(folders);
    vector<Folder> reorderedFolders = createNestedFolders.solve();

    cout << "Creation order:" << endl;
    for (auto& folder : reorderedFolders) {
        cout << "\t" << folder.folderName << endl;
    }
}
