#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* createMirrorFlip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* left = createMirrorFlip(root->left);
    TreeNode* right = createMirrorFlip(root->right);

    root->left = right;
    root->right = left;

    return root;
}

void inOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Оригінальне дерево: ";
    inOrder(root);
    cout << endl;

    root = createMirrorFlip(root);

    cout << "Віддзеркалене дерево: ";
    inOrder(root);
    cout << endl;

    return 0;
}