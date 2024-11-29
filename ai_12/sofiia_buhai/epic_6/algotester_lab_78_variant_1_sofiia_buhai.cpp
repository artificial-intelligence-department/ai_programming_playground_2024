#include <iostream>
#include <string>



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

    void print() {
        print(root);
    }

    bool contains(int value) {
        return contains(root, value);
    }
    int size(){
        return size(root);
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

    bool contains(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

    void print(TreeNode* node) {
        if (node != nullptr) {
            print(node->left); // LEFT
            std::cout << node->data << " "; // CENTER
            print(node->right);  // RIGHT
        }
    }

    int size(TreeNode* node) {
        int s = 0;
        if(node != nullptr){
            s= 1 + size(node->left) + size(node->right);
        } else {
            return s;
        }
        return s;
    }
};

int main() {
    BinarySearchTree myTree;
    int N;
    std::string operation;
    

    std::cin >> N;
    for(int i=0; i<N; i++){
        std::cin >> operation;
        if(operation =="insert"){
            int a;
            std::cin >> a;
            myTree.insert(a);
        }
        if(operation == "print"){
            myTree.print();
            std::cout << std::endl;
        }
        if(operation == "contains" ){
            int a;
            std::cin >> a;
            if (myTree.contains(a)){
                std::cout << "Yes" 
                << std::endl;
            } else {
                std::cout << "No" 
                << std::endl;
            }
            
            
        }
        if(operation == "size"){
            std::cout << myTree.size() << std::endl;
        }
    }
    return 0;
}