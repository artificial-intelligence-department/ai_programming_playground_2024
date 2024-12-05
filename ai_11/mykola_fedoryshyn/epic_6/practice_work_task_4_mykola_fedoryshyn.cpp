#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value): data(value), left(nullptr), right(nullptr) {};
};

TreeNode* create_mirror_flip(TreeNode* root){
    if (root == nullptr){
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->data);

    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
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
       
    /* Original tree
        1
       /  \ 
      2    3
     / \  / \
     4 5  6  7 
      */
    /*  Mirrored tree
        1
       /  \
      3    2
     / \  / \  
    7  6  5  4

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

    TreeNode* mirroredTree = create_mirror_flip(root);
    
    cout << "Mirrored tree: ";
    printTree(mirroredTree);

    return 0;
}