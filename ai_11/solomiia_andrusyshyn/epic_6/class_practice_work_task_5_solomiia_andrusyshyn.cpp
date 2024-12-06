#include <iostream>
using namespace std;

struct Node {
    int value;   
    Node* left;   
    Node* right;  

    Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

int calculateSum(Node* root) {
    if (root == nullptr) {
        return 0; 
    }

    if (root->left == nullptr && root->right == nullptr) {
        return root->value; 
    }

    int leftSum = calculateSum(root->left);
    int rightSum = calculateSum(root->right);

    root->value += leftSum + rightSum;

    return root->value; 
}

void printTree(Node* root) {
    if (root == nullptr) {
        return; 
    }

    cout << root->value << " ";

    printTree(root->left);
    printTree(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Початкове дерево: ";
    printTree(root);
    cout << endl;

    calculateSum(root);

    cout << "Дерево з сумами: ";
    printTree(root);
    cout << endl;

    return 0;
}
