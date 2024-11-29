#include <iostream>

using namespace std;

template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) { }
};

template<typename T>
class BinarySearchTree {
public:
    // Constructor
    BinarySearchTree() : root(nullptr), treeSize(0) {}

    void insert(T value) {
        root = insert(root, value);
    }

    bool contains(T value) {
        return contains(root, value);
    }

    int size() {
        return treeSize;
    }

    void print() {
        if (root == nullptr) {
            cout << endl;  // Якщо дерево порожнє
        } else {
            inorderTraverse(root);
            cout << endl;
        }
    }

private:
    TreeNode<T>* root;
    int treeSize;

    TreeNode<T>* insert(TreeNode<T>* node, T value) {
        if (node == nullptr) {
            treeSize++;
            return new TreeNode<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool contains(TreeNode<T>* node, T value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

    void inorderTraverse(TreeNode<T>* node) {
        if (node != nullptr) {
            inorderTraverse(node->left);
            cout << node->data << " ";
            inorderTraverse(node->right);
        }
    }
};

int main() {
    int Q;
    cin >> Q;

    BinarySearchTree<int> tree;
    string command;
    int value;

    for (int i = 0; i < Q; i++) {
        cin >> command;

        if (command == "insert") {
            cin >> value;
            tree.insert(value);
        } else if (command == "contains") {
            cin >> value;
            if (tree.contains(value)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (command == "size") {
            cout << tree.size() << endl;
        } else if (command == "print") {
            tree.print(); 
        }
    }

    return 0;
}