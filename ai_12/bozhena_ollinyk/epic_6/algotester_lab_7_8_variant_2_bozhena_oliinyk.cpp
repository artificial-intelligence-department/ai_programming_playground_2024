#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

enum Ident {
    Ident_insert,
    Ident_contains,
    Ident_treeSize,
    Ident_print,
    Ident_unknown
};

Ident parseToEnum(const string& id) {
    if (id == "insert") return Ident_insert;
    if (id == "contains") return Ident_contains;
    if (id == "size") return Ident_treeSize;
    if (id == "print") return Ident_print;
    return Ident_unknown;
}

class BinarySearchTree {
private:
    Node* root;
    int tree_size;

    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            ++tree_size;
        } else if (value < node->value) {
            insert(node->left, value);
        } else if (value > node->value) {
            insert(node->right, value);
        }
    }

    bool contains(Node* node, int value) const {
        if (node == nullptr) {
            return false;
        } else if (value == node->value) {
            return true;
        } else if (value < node->value) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

    void print(Node* node, ostream& os) const {
        if (node == nullptr) return;
        print(node->left, os);
        os << node->value << " ";
        print(node->right, os);
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr), tree_size(0) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int value) {
        insert(root, value);
    }

    bool contains(int value) const {
        return contains(root, value);
    }

    int size() const {
        return tree_size;
    }

    friend ostream& operator<<(ostream& os, const BinarySearchTree& tree) {
        tree.print(tree.root, os);
        return os;
    }
};

int main() {
    BinarySearchTree bst;
    int q;

    cin >> q;
    for (int i = 0; i < q; i++) {
        string ident;
        cin >> ident;

        Ident identifier = parseToEnum(ident);
        switch (identifier) {
        case Ident_insert: {
            int value;
            cin >> value;
            bst.insert(value);
            break;
        }
        case Ident_contains: {
            int value;
            cin >> value;            
            if (bst.contains(value))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            break;
        }
        case Ident_treeSize:
            cout << bst.size() << endl;
            break;
        case Ident_print:
            cout << bst << endl;
            break;
        case Ident_unknown:
            cout << "Unknown identifier!" << endl;
            break;
        }
    }

    return 0;
}
