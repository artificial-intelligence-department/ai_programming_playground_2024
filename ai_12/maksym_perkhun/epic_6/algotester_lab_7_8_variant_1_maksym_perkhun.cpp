#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

enum Operation {
    INSERT,
    SIZE,
    PRINT,
    CONTAINS,
    UNKNOWN
};

Operation getOperation(const string& command) {
    if (command == "insert") return INSERT;
    if (command == "size") return SIZE;
    if (command == "print") return PRINT;
    if (command == "contains") return CONTAINS;
    return UNKNOWN;
}

template<typename T = int>
class binaryTree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(T val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int treeSize;

    void destroyTree(Node* root) {
        if (root != nullptr) {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }

    void insertRecursively(Node* node, T value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new Node(value);
                treeSize++;
            } 
            else {
                insertRecursively(node->left, value);
            }
        } 
        else if (value > node->value) {
            if (node->right == nullptr) {
                node->right = new Node(value);
                treeSize++;
            } else {
                insertRecursively(node->right, value);
            }
        }
    }

    bool containsRecursively(Node* node, T value) {
        if (node == nullptr) return false;
        if (value == node->value) return true;
        if (value < node->value) return containsRecursively(node->left, value);
        return containsRecursively(node->right, value);
    }

    void printTree(Node* node, ostream& os) const {
        if (node != nullptr) {
            printTree(node->left, os);
            os << node->value << " ";
            printTree(node->right, os);
        }
    }

public:
    binaryTree() : root(nullptr), treeSize(0) {}

    ~binaryTree() {
        destroyTree(root);
    }

    void insert(T value) {
        if (root == nullptr) {
            root = new Node(value);
            treeSize++;
        } else {
            insertRecursively(root, value);
        }
    }

    bool contains(T value) {
        return containsRecursively(root, value);
    }

    int getSize() const {
        return treeSize;
    }


    friend ostream& operator<<(ostream& os, const binaryTree& tree) {
        tree.printTree(tree.root, os);
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;
    binaryTree<int> tree;

    for (int i = 0; i < Q; i++) {
        string option;
        cin >> option;
        Operation operation = getOperation(option);

        switch (operation) {
            case INSERT: {
                int value;
                cin >> value;
                tree.insert(value);
                break;
            }
            case SIZE: {
                cout << tree.getSize() << endl;
                break;
            }
            case CONTAINS: {
                int value;
                cin >> value;
                cout << (tree.contains(value) ? "Yes" : "No") << endl;
                break;
            }
            case PRINT: {
                cout << tree << endl;
                break;
            }
            default:
                break;
        }
    }
}