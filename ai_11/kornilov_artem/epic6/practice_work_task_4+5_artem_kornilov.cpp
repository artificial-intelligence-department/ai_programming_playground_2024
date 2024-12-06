#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
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

    bool contains(int value) {
        return contains(root, value);
    }

    TreeNode* createMirrorFlip() {
        return create_mirror_flip(root);
    }

    void updateTreeSum() {
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

    void inorderTraverse(TreeNode* node) {
        if (node != nullptr) {
            inorderTraverse(node->left); // LEFT
            std::cout << node->data << " "; // CENTER
            inorderTraverse(node->right);  // RIGHT
        }
    }

    TreeNode* create_mirror_flip(TreeNode* root) {
        if (!root) {
            return nullptr; 
        }

        
        TreeNode* newNode = new TreeNode(root->data);

        newNode->left = create_mirror_flip(root->right);
        newNode->right = create_mirror_flip(root->left);

        return newNode; 
    }

    void tree_sum(TreeNode* root) {
    if (!root) return; 

    if (!root->left && !root->right) {
        return;
    }

    int leftSum = root->left ? root->left->data : 0;
    int rightSum = root->right ? root->right->data : 0;

    if (root->left) {
        tree_sum(root->left);
        leftSum = root->left->data;
    }
    if (root->right) {
        tree_sum(root->right);
        rightSum = root->right->data;
    }

    root->data = leftSum + rightSum;
}

};

void inorderTraverse(TreeNode* node) {
    if (node != nullptr) {
        inorderTraverse(node->left); // LEFT
        std::cout << node->data << " "; // CENTER
        inorderTraverse(node->right);  // RIGHT
    }
}

int main() {
    BinarySearchTree myTree;

    myTree.insert(4);
    myTree.insert(2);
    myTree.insert(5);
    myTree.insert(1);
    myTree.insert(6);
    myTree.insert(3);

    std::cout << "Original tree (Inorder): ";
    myTree.inorderTraverse();
    std::cout << std::endl;

    TreeNode* mirroredRoot = myTree.createMirrorFlip();

    int searchValue = 5;
    bool searchResult = myTree.contains(searchValue);
    std::cout << "Does the Tree contain '" << searchValue << "' ? "
              << (searchResult ? "Yes" : "No") 
              << std::endl;

    std::cout << "Mirrored tree (Inorder): ";
    inorderTraverse(mirroredRoot);
    std::cout << std::endl;

    myTree.updateTreeSum();

    std::cout << "Tree after applying tree_sum (Inorder): ";
    myTree.inorderTraverse();
    std::cout << std::endl;

    return 0;
}
