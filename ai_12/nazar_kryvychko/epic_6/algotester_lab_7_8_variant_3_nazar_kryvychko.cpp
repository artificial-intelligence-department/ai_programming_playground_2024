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

template<typename T>
class Tree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(T val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;

    void clear(Node* root) {
        if (root != nullptr) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }

    void insertP(Node* node, T value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new Node(value);
                size++;
            }
            else {
                insertP(node->left, value);
            }
        }
        else if (value > node->value) {
            if (node->right == nullptr) {
                node->right = new Node(value);
                size++;
            }
            else {
                insertP(node->right, value);
            }
        }
    }

    bool containsP(Node* node, T value) {
        if (node == nullptr) return false;
        if (value == node->value) return true;
        if (value < node->value) return containsP(node->left, value);
        return containsP(node->right, value);
    }

    void printP(Node* node, ostream& os) const {
        if (node != nullptr) {
            printP(node->left, os);
            os << node->value << " ";
            printP(node->right, os);
        }
    }

public:
    Tree() : root(nullptr), size(0) {}

    ~Tree() {
        clear(root);
    }

    void insert(T value) {
        if (root == nullptr) {
            root = new Node(value);
            size++;
        }
        else {
            insertP(root, value);
        }
    }

    bool contains(T value) {
        return containsP(root, value);
    }

    int getSize() const {
        return size;
    }

    friend ostream& operator<<(ostream& os, const Tree& tree) {
        tree.printP(tree.root, os);
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;
    Tree<int> tree;

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
            cout << tree;
            break;
        }
        default:
            break;
        }
    }
}