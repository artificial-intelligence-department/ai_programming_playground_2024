#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {} // Конструктор
};

// Функція для створення віддзеркаленого дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;  
    }

    TreeNode* newNode = new TreeNode(root->data);

    // обмін
    newNode->left = create_mirror_flip(root->right);
    newNode->right = create_mirror_flip(root->left);

    return newNode;
}

// Функція для виведення дерева 
void preorderPrint(TreeNode* root) {
    if (root != nullptr) {
        cout << root->data << " ";  
        preorderPrint(root->left);  
        preorderPrint(root->right); 
    }
}

// сума підвузлів
int tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return 0;  
    }

    if (root->left == nullptr && root->right == nullptr) { // для листка
        return root->data;  
    }

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    root->data = leftSum + rightSum;

    return root->data;
}

// заповнення дерева
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value); 
    }

    if (value < root->data) {
        root->left = insert(root->left, value);  
    } else {
        root->right = insert(root->right, value);  
    }

    return root;
}

int main() {
    TreeNode* root = nullptr;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    cout << "Original tree (preorder): ";
    preorderPrint(root);
    cout << endl;

    TreeNode* mirroredTree = create_mirror_flip(root);

    cout << "Mirrored tree (preorder): ";
    preorderPrint(mirroredTree);
    cout << endl;

    tree_sum(root);
    cout << "Tree after sum (preorder): ";
    preorderPrint(root);

    return 0;
}
