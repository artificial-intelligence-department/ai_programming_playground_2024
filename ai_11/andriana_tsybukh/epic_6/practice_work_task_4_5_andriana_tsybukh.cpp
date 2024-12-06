#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// task 4
TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) return nullptr;

    TreeNode* newRoot = new TreeNode(root->data);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

// task 5
int tree_sum(TreeNode* root) {
    if (!root) return 0;

    if (!root->left && !root->right) return root->data;

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    root->data = leftSum + rightSum;
    return root->data;
}

void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original tree (in-order): ";
    printTree(root);
    cout << endl;

    // task 4
    TreeNode* mirrored = create_mirror_flip(root);
    cout << "Mirrored tree (in-order): ";
    printTree(mirrored);
    cout << endl;

    // task 5
    tree_sum(root);
    cout << "Tree with subtree sums (in-order): ";
    printTree(root);
    cout << endl;

    return 0;
}
