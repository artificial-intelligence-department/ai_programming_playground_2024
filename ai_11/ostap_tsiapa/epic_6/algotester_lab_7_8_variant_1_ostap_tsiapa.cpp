#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    size_t treeSize;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool contains(TreeNode* node, int value) const {
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

    void inorder(TreeNode* node, ostream& os) const {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, os);
        os << node->value << " ";
        inorder(node->right, os);
    }

public:
    BinaryTree() : root(nullptr), treeSize(0) {}

    void insert(int value) {
        if (!contains(root, value)) {
            root = insert(root, value);
            treeSize++;
        }
    }

    bool contains(int value) const {
        return contains(root, value);
    }

    size_t size() const {
        return treeSize;
    }

    friend ostream& operator<<(ostream& os, const BinaryTree& tree) {
        tree.inorder(tree.root, os);
        return os;
    }
};

int main() {
    BinaryTree tree;
    int Q;
    cin >> Q;

    vector<string> commands(Q);
    vector<int> values(Q, 0);

    for (int i = 0; i < Q; ++i) {
        cin >> commands[i];
        if (commands[i] == "insert" || commands[i] == "contains") {
            cin >> values[i];
        }
    }

    for (int i = 0; i < Q; ++i) {
        if (commands[i] == "insert") {
            tree.insert(values[i]);
        } else if (commands[i] == "contains") {
            cout << (tree.contains(values[i]) ? "Yes" : "No") << endl;
        } else if (commands[i] == "size") {
            cout << tree.size() << endl;
        } else if (commands[i] == "print") {
            cout << tree << endl;
        }
    }

    return 0;
}
