#include <iostream>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    TreeNode* root;
public:
    BinaryTree(){
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void DirectTraverse() {
        DirectTraverse(root);
    }

    void tree_sum() {
        tree_sum(root);
        return;
    }
    
    BinaryTree create_mirror_flip() {
        BinaryTree reversedtree;
        reversedtree.root = create_mirror_flip(root);
        return reversedtree;
    }

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


    void DirectTraverse(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            DirectTraverse(node->left);
            DirectTraverse(node->right);
        }
    }

    TreeNode* create_mirror_flip(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(node->data);

        newNode->left = create_mirror_flip(node->right);
        newNode->right = create_mirror_flip(node->left);

        return newNode;
    }

    int tree_sum(TreeNode* node) {

        if (node != nullptr) {
            int sum = 0;
            sum += tree_sum(node->left);
            sum += tree_sum(node->right);

            if(sum > 0) {
                node->data = sum;
                return sum;
            } else {
                return node->data;
            }


        } else {
            return 0;
        }
    }

};

int main() {

    BinaryTree tree;


    tree.insert(9);
    tree.insert(7);
    tree.insert(15);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(12);
    tree.insert(10);
    tree.insert(16);

    cout << "Original tree: ";
    tree.DirectTraverse();

    BinaryTree reversedtree = tree.create_mirror_flip();

    cout << endl << "Reversed tree: ";
    reversedtree.DirectTraverse();
    cout << endl << "Tree after sum operation: ";
    tree.tree_sum();
    tree.DirectTraverse();


    return 0;
}