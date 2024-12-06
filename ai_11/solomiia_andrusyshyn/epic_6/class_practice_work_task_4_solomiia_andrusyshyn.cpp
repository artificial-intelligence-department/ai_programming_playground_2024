#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

struct Node {
    int data;      
    Node* left;    
    Node* right;   

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* makeMirror(Node* root) {
    if (root == nullptr) {
        return nullptr; 
    }

    Node* newRoot = new Node(root->data);

    newRoot->left = makeMirror(root->right);
    newRoot->right = makeMirror(root->left);

    return newRoot;
}

void printTree(Node* root) {
    if (root == nullptr) {
        return; 
    }

    printTree(root->left);    
    cout << root->data << " "; 
    printTree(root->right);   
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Початкове дерево: ";
    printTree(root);
    cout << endl;

    Node* mirroredRoot = makeMirror(root);

    cout << "Дзеркальне дерево: ";
    printTree(mirroredRoot);
    cout << endl;

    return 0;
}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode(root->val);
    
    newNode->left = create_mirror(root->right);
    newNode->right = create_mirror(root->left);
    
    return newNode;
}

void print(TreeNode* root) {
    if (root == nullptr) return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original tree: ";
    print(root);
    cout << endl;

    TreeNode* mirroredRoot = create_mirror(root);
    
    cout << "Mirrored tree: ";
    print(mirroredRoot);
    cout << endl;

    return 0;
}