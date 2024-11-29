#include <iostream>

using namespace std;

//Structure to create a tree vertex 
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    //Constructor
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct BinarySearchTree {
    //Construct a tree
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void mirrorFlip() {
        root = createMirrorFlip(root);
    }

    void treeSum() {
        iterativeTreeSum(root);
    }

    void printTree() {
        printTree(root);
    }

private:
    TreeNode* root;

    //Fuction to insert a tree element
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } 
        else if (value > node->data){
            node->right = insert(node->right, value);
        }

        return node;
    }

    //Function to create new mirrored tree
    TreeNode* createMirrorFlip(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        //Swap each right and left leaves
        TreeNode* newNode = new TreeNode(node->data);
        newNode->left = createMirrorFlip(node->right);
        newNode->right = createMirrorFlip(node->left);

        return newNode;
    }
    //Calculate sum of subnodes
    void iterativeTreeSum(TreeNode* node) {
        if (node == nullptr) return;
        
        TreeNode* current = node;
        TreeNode* stack[100];
        int top = -1;
        while (current != nullptr || top >= 0) {
            while (current != nullptr) {
                stack[++top] = current;
                current = current->left;
            }
            current = stack[top--];
            if (current->left == nullptr && current->right == nullptr) {
                current = nullptr;
            } else {
                int sum = 0;
                if (current->left) sum += current->left->data;
                if (current->right) sum += current->right->data;
                current->data += sum;
                current = nullptr;
            }
        }
    }

    void printTree(TreeNode* node) {
        if (node != nullptr) {
            printTree(node->left);
            cout << node->data << " ";
            printTree(node->right);
        }
    }
};

int main() {
    BinarySearchTree myTree;

    myTree.insert(4);
    myTree.insert(2);
    myTree.insert(5);
    myTree.insert(1);
    myTree.insert(6);
    myTree.insert(3);

    //Fourth task: create mirrored tree
    cout << "Original tree: ";
    myTree.printTree();
    cout << endl;

    myTree.mirrorFlip();
    cout << "Mirrored flip tree: ";
    myTree.printTree();
    cout << endl;

    //Fifth task: calculate sum of subnodes
    myTree.treeSum();
    cout << "Tree with sums: ";
    myTree.printTree();
    cout << endl;

    return 0;
}
