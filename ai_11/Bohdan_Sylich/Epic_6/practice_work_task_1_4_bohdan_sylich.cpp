#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* mirrored = new TreeNode(root->val);
    mirrored->left = create_mirror_flip(root->right);
    mirrored->right = create_mirror_flip(root->left);
    return mirrored;
}

void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    TreeNode* mirrored = create_mirror_flip(root);

    cout << "Mirrored tree: ";
    printTree(mirrored);
    cout << endl;

    return 0;
}
