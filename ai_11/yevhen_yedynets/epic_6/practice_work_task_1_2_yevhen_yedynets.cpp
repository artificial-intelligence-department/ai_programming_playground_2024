#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* left = create_mirror_flip(root->left);
    TreeNode* right = create_mirror_flip(root->right);
    root->left = right;
    root->right = left;
    return root;
}

int tree_sum(TreeNode* root) {
    if (root == nullptr) return 0;
    int left_sum = tree_sum(root->left);
    int right_sum = tree_sum(root->right);
    if (root->left != nullptr || root->right != nullptr) {
        root->data = left_sum + right_sum;
    }
    return root->data + left_sum + right_sum;
}

void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    cout << "=== Робота з бінарними деревами ===\n";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "Дерево до дзеркала: ";
    printTree(root);
    cout << endl;
    create_mirror_flip(root);
    cout << "Дерево після дзеркала: ";
    printTree(root);
    cout << endl;

    tree_sum(root);
    cout << "Дерево після підрахунку сум: ";
    printTree(root);
    cout << endl;

    return 0;
}
