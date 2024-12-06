#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Функція для створення дзеркального дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* newRoot = new TreeNode(root->data);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);
    return newRoot;
}

// Функція для обчислення суми піддерев
int treeSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }
    int leftSum = treeSum(root->left);
    int rightSum = treeSum(root->right);
    root->data = leftSum + rightSum;
    return root->data;
}

// Функція для друку дерева
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Початкове дерево
    /*
        Original tree:
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
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

    // Дзеркальне дерево
    TreeNode* mirroredTree = create_mirror_flip(root);
    cout << "Mirrored tree: ";
    printTree(mirroredTree);
    cout << endl;

    // Обчислення суми піддерев
    treeSum(root);
    cout << "Tree after calculating sum in each root: ";
    printTree(root);
    cout << endl;

    return 0;
}
