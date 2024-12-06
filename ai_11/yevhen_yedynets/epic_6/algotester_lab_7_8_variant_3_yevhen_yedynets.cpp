#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node* left;
    Node* right;

    Node(T val) : value(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree {
private:
    Node<T>* root;

    void insert(Node<T>*& node, T value) {
        if (node == nullptr) {
            node = new Node<T>(value);
        } else if (value < node->value) {
            insert(node->left, value);
        } else if (value > node->value) {
            insert(node->right, value);
        }
    }

    bool contains(Node<T>* node, T value) {
        if (node == nullptr) {
            return false;
        }
        if (value == node->value) {
            return true;
        } else if (value < node->value) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

    void print(Node<T>* node) {
        if (node != nullptr) {
            print(node->left);
            cout << node->value << " ";
            print(node->right);
        }
    }

    int size(Node<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + size(node->left) + size(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T value) {
        insert(root, value);
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
        } else if (command == "print") {
            bst.print();
        } else if (command == "size") {
            cout << bst.size() << endl;
        }
    }

    return 0;
}
