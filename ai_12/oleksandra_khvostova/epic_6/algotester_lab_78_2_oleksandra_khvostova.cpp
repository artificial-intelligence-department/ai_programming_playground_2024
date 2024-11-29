#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct TreeNode {
    T value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    TreeNode<T>* root;
    size_t treeSize;

    TreeNode<T>* insert(TreeNode<T>* node, T value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        // Якщо value == node->value, нічого не робимо (ігноруємо дублікати)
        return node;
    }

    bool contains(TreeNode<T>* node, T value) const {
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

    void inorder(TreeNode<T>* node, ostream& os) const {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, os);
        os << node->value << " ";
        inorder(node->right, os);
    }

public:
    BinaryTree() : root(nullptr), treeSize(0) {}

    void insert(T value) {
        if (!contains(value)) {
            root = insert(root, value);
            treeSize++;
        }
    }

    bool contains(T value) const {
        return contains(root, value);
    }

    size_t size() const {
        return treeSize;
    }

    friend ostream& operator<<(ostream& os, const BinaryTree<T>& tree) {
        tree.inorder(tree.root, os);
        return os;
    }
};

int main() {
    BinaryTree<int> tree;
    int Q;
    cin >> Q;
    string* commands = new string[Q];
    int* values = new int[Q];

    for (int i = 0; i < Q; i++) {
        cin >> commands[i];
        if (commands[i] == "insert" || commands[i] == "contains") {
            cin >> values[i];
        } else {
            values[i] = 0;
        }
    }

    for (int i = 0; i < Q; i++) {
        if (commands[i] == "insert") {
            tree.insert(values[i]);
        } else if (commands[i] == "contains") {
            if (tree.contains(values[i])) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (commands[i] == "size") {
            cout << tree.size() << endl;
        } else if (commands[i] == "print") {
            cout << tree << endl;
        }
    }

    delete[] commands;
    delete[] values;

    return 0;
}