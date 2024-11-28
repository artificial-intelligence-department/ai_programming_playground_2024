#include <iostream>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value): data(value), left(nullptr), right(nullptr) {}
};

struct BinarySearchTree {

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void inorderTraverse() {
        inorderTraverse(root);
    }


    void create_mirror_flip(){
         inorderTraverse(create_mirror_flip(root));
    }

    void tree_sum(){
        tree_sum(root);
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void inorderTraverse(TreeNode* node) {
        if (node != nullptr) {
            inorderTraverse(node->left); 
            std::cout << node->data << " "; 
            inorderTraverse(node->right);  
        }
    }

    TreeNode* create_mirror_flip(TreeNode* node){
        if(node == nullptr){
            return nullptr;
        }
        TreeNode* NewNode = new TreeNode(node->data);
        NewNode->left = create_mirror_flip(node->right);
        NewNode->right = create_mirror_flip(node->left);
        
        return NewNode;
    }

    void tree_sum(TreeNode* &root){
        if(root == nullptr){
            return;
        }
        tree_sum(root->left);
        tree_sum(root->right);
        if(root->left && root->right){
            root->data = root->left->data + root->right->data;
        }
        if(root->left && !root->right){
            root->data = root->left->data;
        }
        if(!root->left && root->right){
            root->data = root->right->data;
        }
    }
};





int main(){


    BinarySearchTree myTree;

    myTree.insert(4);
    myTree.insert(2);
    myTree.insert(5);
    myTree.insert(1);
    myTree.insert(6);
    myTree.insert(3);

    std::cout << "The tree : ";
    myTree.inorderTraverse();
    std::cout << "\n";


    std::cout << "Flipped : ";
    myTree.create_mirror_flip();
    std::cout << "\n";


    std::cout << "The sum of dauthers of node : ";
    myTree.tree_sum();
    myTree.inorderTraverse();
    std::cout << "\n"; 


    return 0;
}