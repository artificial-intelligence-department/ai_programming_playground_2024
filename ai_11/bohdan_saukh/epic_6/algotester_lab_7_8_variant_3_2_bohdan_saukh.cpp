#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int val) : value(val), leftChild(nullptr), rightChild(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* rootNode;
    long long nodeCount;

    void deleteTree(TreeNode* node) {
        if (node) {
            deleteTree(node->leftChild);
            deleteTree(node->rightChild);
            delete node;
        }
    }

    bool search(TreeNode* node, int target) const {
        if (node == nullptr) return false;
        if (node->value == target) return true;
        return target < node->value ? search(node->leftChild, target) : search(node->rightChild, target);
    }

    void traverse(TreeNode* node) const {
        if (!node) return;
        traverse(node->leftChild);
        cout << node->value << " ";
        traverse(node->rightChild);
    }

public:
    BinaryTree() : rootNode(nullptr), nodeCount(0) {}

    ~BinaryTree() {
        deleteTree(rootNode);
    }

    void add(int val) {
        if (!search(rootNode, val)) {
            if (rootNode == nullptr) {
                rootNode = new TreeNode(val);
            } else {
                TreeNode* current = rootNode;
                while (true) {
                    if (val > current->value) {
                        if (current->rightChild) {
                            current = current->rightChild;
                        } else {
                            current->rightChild = new TreeNode(val);
                            break;
                        }
                    } else {
                        if (current->leftChild) {
                            current = current->leftChild;
                        } else {
                            current->leftChild = new TreeNode(val);
                            break;
                        }
                    }
                }
            }
            nodeCount++;
        }
    }

    void checkPresence(int val) const {
        if (search(rootNode, val)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    void printSize() const {
        cout << nodeCount << endl;
    }

    void printTree() const {
        traverse(rootNode);
        cout << endl;
    }
};

int main() {
    int numCommands;
    cin >> numCommands;

    BinaryTree tree;

    while (numCommands--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int value;
            cin >> value;
            tree.add(value);
        } else if (command == "contains") {
            int value;
            cin >> value;
            tree.checkPresence(value);
        } else if (command == "size") {
            tree.printSize();
        } else if (command == "print") {
            tree.printTree();
        }
    }

    return 0;
}

