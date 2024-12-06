#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Task 4: Create a mirrored tree
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* tempNode = new TreeNode(root->data);
    
    tempNode->left = create_mirror_flip(root->right);
    tempNode->right = create_mirror_flip(root->left);
    
    return tempNode;
}

void Print(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    Print(root->left);
    cout << root->data << " ";
    Print(root->right);
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

// Task 5: Find the sum of tree
void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    int sum = 0;
    
    if (root->left != nullptr) {
        sum += root->left->data;
    }
    
    if (root->right != nullptr) {
        sum += root->right->data;
    }
    
    if (sum > 0) {
        root->data = sum;
    }

    tree_sum(root->left);
    tree_sum(root->right);
}

int main(){
    // Task 4:
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(15);
    root->right = new TreeNode(27);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(18);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(30);

    cout << "Original tree: ";
    Print(root);
    cout << endl;

    TreeNode* Mirrored = create_mirror_flip(root);
    
    cout << "Mirrored tree: ";
    Print(Mirrored);
    cout << endl;

    deleteTree(root);
    deleteTree(Mirrored);

    // Task 5:
    tree_sum(root);

    cout << "Sum of the tree: ";
    Print(root);

    return 0;
}