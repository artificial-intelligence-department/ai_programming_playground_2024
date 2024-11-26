#include <iostream>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int treeSum(TreeNode* root){
    if (root == nullptr){
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr){
        return root->data;
    }

    int leftSum = treeSum(root->left);
    int rightSum = treeSum(root->right);

    root->data = leftSum + rightSum;

    return root->data;

}

void printTree(TreeNode* root){
    if (root == nullptr){
        return;
    }

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main (){

    /*
    Original tree
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
    Tree after calculating sum in each root:
       22
     /    \
    9      13
   / \    /  \
  4   5  6    7
    
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    treeSum(root);

    cout << "Tree after calculating sum in each root: ";
    printTree(root);
    cout << endl;

    return 0;
}