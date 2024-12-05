#include <iostream>
#include <stack>
using namespace std; 

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value): data(value), left(nullptr), right(nullptr) {};
};

void printTree(TreeNode* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        printTree(root->left);  
        printTree(root->right);
    }
}

TreeNode *create_mirror_flip(TreeNode *root){
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* left = create_mirror_flip(root->left);
    TreeNode* right = create_mirror_flip(root->right);

    root->left = right;
    root->right = left;

    return root;
}

int tree_sum(TreeNode* root) {

    if (root == nullptr) {
        return 0;
    }

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);
    
    if (root->left != nullptr || root->right != nullptr) {
        root->data += leftSum + rightSum;
    }
    
    return root->data;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(8);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(7);

    cout << "Task 4 " << endl;
    printTree(root);

    root = create_mirror_flip(root);
    cout << endl << "Mirrotred tree: " << endl;
    printTree(root);

    cout << endl << "Task 5" << endl;
    tree_sum(root);

    cout << "Tree sum: ";
    printTree(root);
    cout << endl;

    return 0;
}
