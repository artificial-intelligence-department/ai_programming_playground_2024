#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int sumSubtree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
   
    int leftSum = sumSubtree(root->left);
    int rightSum = sumSubtree(root->right);
 
    if (root->left != nullptr || root->right != nullptr) {
        root->data = leftSum + rightSum;
    }
    return root->data + leftSum + rightSum; 
}

void tree_sum(TreeNode* root) {
    sumSubtree(root);
}

void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printTree(root->left);
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

    cout << "Original Tree: ";
    printTree(root);
    cout << endl;

    tree_sum(root);

    cout << "Tree with sums: ";
    printTree(root);
    cout << endl;

    return 0;
}
