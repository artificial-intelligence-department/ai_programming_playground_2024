#include <iostream>
using namespace std;

struct TreeNode 
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* create_mirror_flip(TreeNode* root) 
{
    if (root == nullptr) 
    {
        return nullptr; 
    }

    TreeNode* mirroredNode = new TreeNode(root->data);

    mirroredNode->left = create_mirror_flip(root->right);
    mirroredNode->right = create_mirror_flip(root->left);

    return mirroredNode;
}

void printTree(TreeNode* root) 
{
    if (root == nullptr) 
    {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() 
{
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

    TreeNode* mirroredRoot = create_mirror_flip(root);

    cout << "Mirrored tree: ";
    printTree(mirroredRoot);
    cout << endl;

    return 0;
}
