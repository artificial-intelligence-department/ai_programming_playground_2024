#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

int tree_sum(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->val;

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);
    root->val = leftSum + rightSum;
    return root->val + leftSum + rightSum;
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

    tree_sum(root);

    cout << "Tree with sums: ";
    printTree(root);
    cout << endl;

    return 0;
}
