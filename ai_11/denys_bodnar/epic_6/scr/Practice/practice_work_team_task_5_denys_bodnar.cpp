#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int treeSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = treeSum(root->left);
    int rightSum = treeSum(root->right);

    if (root->left || root->right) {
        root->data = leftSum + rightSum;
    }

    return root->data + leftSum + rightSum;
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
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);

    treeSum(root);

    cout << "Дерево після оновлення суми: ";
    inOrder(root);
    cout << endl;

    return 0;
}