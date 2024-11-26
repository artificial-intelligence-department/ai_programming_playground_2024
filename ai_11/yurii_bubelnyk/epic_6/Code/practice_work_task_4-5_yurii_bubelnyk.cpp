#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value): data(value), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* myTree) {
    if (myTree == nullptr) return nullptr;

    TreeNode* root = new TreeNode(myTree->data);
    root->left = create_mirror_flip(myTree->right);
    root->right = create_mirror_flip(myTree->left);

    return root;
}

void printTree(TreeNode* myTree) {
    if (myTree != nullptr) {
        printTree(myTree->left);
        cout << myTree->data << " ";
        printTree(myTree->right);
    }
}

void tree_sum(TreeNode* myTree) {
    if (myTree == nullptr) return;

    int left_sum = 0;
    int right_sum = 0;

    tree_sum(myTree->left);
    tree_sum(myTree->right);

    if (!myTree->left && !myTree->right) return;

    if (myTree->left != nullptr) {
        left_sum += myTree->left->data;
    }
    if (myTree->right != nullptr) {
        right_sum += myTree->right->data;
    }

    myTree->data = left_sum + right_sum;
}

int main() {
    TreeNode* myTree = new TreeNode(1);
    myTree->left = new TreeNode(2);
    myTree->right = new TreeNode(3);
    myTree->left->left = new TreeNode(4);
    myTree->left->right = new TreeNode(5);

    cout << "Original tree: ";
    printTree(myTree);
    cout << endl;

    TreeNode* mirrored = create_mirror_flip(myTree);

    cout << "Mirrored tree: ";
    printTree(mirrored);
    cout << endl;

    tree_sum(myTree);
    cout << "Updated tree: ";
    printTree(myTree);
    cout << endl;

    return 0;
}
