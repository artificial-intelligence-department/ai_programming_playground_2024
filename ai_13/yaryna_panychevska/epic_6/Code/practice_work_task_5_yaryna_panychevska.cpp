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

//Префіксний обхід дерева
void preOrder(TreeNode* root) {
    if (root != NULL) {
        cout << " " << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Сума дочірніх вузлів для кожного батьківського вузла
int treeSum(TreeNode* root) {
    //Порожній вузол
    if (root == NULL) {
        return 0;
    }
    //Вузол - листок
    if (!root->left && !root->right) {
        return root->data;
    }
    int sum_left = treeSum(root->left);
    int sum_right = treeSum(root->right);

    root->data = sum_left + sum_right;
    return root->data;
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

    treeSum(root);

    cout << "\n" << "Binary tree in pre-order after treeSum: ";
    preOrder(root);

    return 0;
}