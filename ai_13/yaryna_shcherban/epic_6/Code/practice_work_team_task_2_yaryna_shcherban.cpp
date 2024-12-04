#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    TreeNode* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    void inOrder(TreeNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    TreeNode* mirrorFlip(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        TreeNode* flipped = new TreeNode(node->data);
        flipped->left = mirrorFlip(node->right);
        flipped->right = mirrorFlip(node->left);

        return flipped;
    }

    void sumSubtrees(TreeNode* node) {
        if (node == nullptr) return;

        sumSubtrees(node->left);
        sumSubtrees(node->right);

        if (node->left != nullptr) {
            node->data += node->left->data;
        }
        if (node->right != nullptr) {
            node->data += node->right->data;
        }
    }

    void sumSubtrees() {
        sumSubtrees(root);
    }

    BinaryTree mirror() {
        BinaryTree mirroredTree;
        mirroredTree.root = mirrorFlip(root);
        return mirroredTree;
    }

    void displayTree(TreeNode* node) {
        if (node == nullptr) return;

        cout << node->data << " ";
        displayTree(node->left);
        displayTree(node->right);
    }

    void displayTree() {
        displayTree(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "Original tree (In-order traversal): ";
    tree.inOrder();

    cout << "\nMirrored tree: ";
    BinaryTree mirroredTree = tree.mirror();
    mirroredTree.displayTree();

    cout << "\nTree after adding subtree sums: ";
    tree.sumSubtrees();
    tree.displayTree();

    return 0;
}