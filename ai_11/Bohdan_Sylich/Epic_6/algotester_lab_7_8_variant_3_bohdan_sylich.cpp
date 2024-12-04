#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(T val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, T value) {
        if (!node) return new Node(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        return node;
    }

    bool contains(Node* node, T value) {
        if (!node) return false;
        if (value == node->value) return true;
        if (value < node->value)
            return contains(node->left, value);
        return contains(node->right, value);
    }

    void print(Node* node) {
        if (!node) return;
        print(node->left);
        cout << node->value << " ";
        print(node->right);
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    int size(Node* node) {
        if (!node) return 0;
        return 1 + size(node->left) + size(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        clear(root);
    }

    void insert(T value) {
        root = insert(root, value);
    }

    bool contains(T value) {
        return contains(root, value);
    }

    void print() {
        print(root);
        cout << endl;
    }

    int size() {
        return size(root);
    }

    friend ostream& operator<<(ostream& os, BinarySearchTree& tree) {
        tree.print();
        return os;
    }
};

int main() {
    BinarySearchTree<int> bst;
    int Q;
    cin >> Q;

    while (Q--) {
        string command;
        cin >> command;
        if (command == "insert") {
            int value;
            cin >> value;
            bst.insert(value);
        } else if (command == "contains") {
            int value;
            cin >> value;
            cout << (bst.contains(value) ? "Yes" : "No") << endl;
        } else if (command == "size") {
            cout << bst.size() << endl;
        } else if (command == "print") {
            bst.print();
        }
    }

    return 0;
}
