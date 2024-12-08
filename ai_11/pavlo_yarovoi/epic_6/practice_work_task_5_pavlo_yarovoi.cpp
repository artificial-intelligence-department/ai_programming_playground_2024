#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int tree_sum(TreeNode* root) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return root->data;
    }

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    root->data = leftSum + rightSum;

    return root->data;
}

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

void freeTree(TreeNode* root) {
    if (!root) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Tree before calculating: ";
    printTree(root);
    cout << endl;

    tree_sum(root);

    cout << "After calculating: ";
    printTree(root);
    cout << endl;

    freeTree(root);

    return 0;
}
