#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

int calculate_sum(TreeNode* root) {
    if (!root) 
        return 0; 

    if (!root->left && !root->right) //вузол - листок
        return root->data;

    int left_sum = calculate_sum(root->left);
    int right_sum = calculate_sum(root->right);

    root->data += left_sum + right_sum;

    return root->data;
}

void print_tree(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree: ";
    print_tree(root);
    cout << endl;

    calculate_sum(root);

    cout << "Sum tree: ";
    print_tree(root);
    cout << endl;

    return 0;
}
