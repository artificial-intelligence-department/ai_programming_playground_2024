#include <iostream>

using namespace std;

template <typename T>
struct TreeNode {
    T value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;
    int tree_size;

    void insert(TreeNode<T>*& node, T value) {
        if (node == nullptr) {
            node = new TreeNode<T>(value);
            ++tree_size;
        } else if (value < node->value) {
            insert(node->left, value);
        } else if (value > node->value) {
            insert(node->right, value);
        }
    }

    bool contains(TreeNode<T>* node, T value) const {
        if (node == nullptr) return false;
        if (value == node->value) return true;
        if (value < node->value) return contains(node->left, value);
        return contains(node->right, value);
    }

    void print(TreeNode<T>* node) const {
        if (node == nullptr) return;
        print(node->left);
        cout << node->value << " ";
        print(node->right);
    }

    void clear(TreeNode<T>* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr), tree_size(0) {}
    ~BinarySearchTree() { clear(root); }

    void insert(T value) { insert(root, value); }
    bool contains(T value) const { return contains(root, value); }
    int size() const { return tree_size; }
    void print() const { print(root); cout << endl; }
};

int main() {
    BinarySearchTree<int> bst;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
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