#include <iostream>
using namespace std;

//Структура TreeNode
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int New_Node) {
        data = New_Node;
        left = NULL;
        right = NULL;
    }
};

//Прямий обхід дерева
void preOrder(TreeNode* root) {
    if (root != NULL) {
        cout << " " << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Відзеркалення дерева
TreeNode* mirror(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* left = mirror(root->left);
    TreeNode* right = mirror(root->right);

    root->left = right;
    root->right = left;

   return root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->left->left = new TreeNode(9);

    cout << "Binary tree in pre-order traversal: ";
    preOrder(root);

    root = mirror(root);
    cout << "\n" << "Mirrored binary tree in pre-order traversal: ";
    preOrder(root);
    
    return 0;
}