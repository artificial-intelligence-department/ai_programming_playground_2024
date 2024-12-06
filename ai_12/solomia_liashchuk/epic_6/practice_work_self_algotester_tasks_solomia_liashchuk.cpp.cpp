#include <iostream>

struct TreeNode 
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct BinarySearchTree 
{
    TreeNode* root;
    BinarySearchTree() : root(nullptr) {}

    TreeNode* insert(TreeNode* node, int value) 
    {
        if(node == nullptr) 
        {
            return new TreeNode(value); 
        }

        if(value < node->data) 
        {
            node->left = insert(node->left, value); 
        } else if(value > node->data) 
        {
            node->right = insert(node->right, value); 
        }

        return node;
    }

    void add(int value) {
        root = insert(root, value);
    }

    void traverse(TreeNode* node) 
    {
        if(node == nullptr) 
        {
            return;
        }
        std::cout << node->data << " "; 
        traverse(node->left);         
        traverse(node->right);         
    }

    void display() 
    {
        traverse(root);
        std::cout << std::endl;
    }
};

int main() 
{
    BinarySearchTree bst;
    bst.add(10);
    bst.add(5);
    bst.add(15);
    bst.add(3);
    bst.add(7);
    std::cout << "Дерево: ";
    bst.display();

    return 0;
}
