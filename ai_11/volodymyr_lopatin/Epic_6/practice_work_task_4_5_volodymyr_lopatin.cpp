#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) return nullptr;
    
    TreeNode* left = create_mirror_flip(root->left);
    TreeNode* right = create_mirror_flip(root->right);
    
    root->left = right;
    root->right = left;
    
    return root;
}

void tree_sum(TreeNode* root) {
    if (!root) return;
    
    tree_sum(root->left);
    tree_sum(root->right);
    
    if (root->left) root->data += root->left->data;
    if (root->right) root->data += root->right->data;
}

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

TreeNode* createTreeFromArray(int arr[], int size) {
    if (size == 0) return nullptr;
    TreeNode* root = new TreeNode(arr[0]);
    TreeNode* nodes[size];
    nodes[0] = root;
    
    for (int i = 1; i < size; ++i) {
        TreeNode* newNode = new TreeNode(arr[i]);
        if (i % 2 == 1) {
            nodes[(i - 1) / 2]->left = newNode;
        } else {
            nodes[(i - 2) / 2]->right = newNode;
        }
        nodes[i] = newNode;
    }
    
    return root;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = createTreeFromArray(arr, 7);
    
    cout << "Original Tree: ";
    printTree(root);
    cout << endl;
    
    TreeNode* mirroredTree = create_mirror_flip(root);
    cout << "Mirrored Tree: ";
    printTree(mirroredTree);
    cout << endl;
    
    tree_sum(mirroredTree);
    cout << "Tree after sum of subtrees: ";
    printTree(mirroredTree);
    cout << endl;
    
    return 0;
}
