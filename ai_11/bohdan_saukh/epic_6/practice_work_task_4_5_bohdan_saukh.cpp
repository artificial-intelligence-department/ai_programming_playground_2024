#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* leftChild;
    Node* rightChild;

    Node(int data) : value(data), leftChild(nullptr), rightChild(nullptr) {}
};

class BinaryTree {
public:
    static void displayTree(Node* root) {
        if (root) {
            cout << root->value << " ";
            displayTree(root->leftChild);
            displayTree(root->rightChild);
        }
    }

    static Node* flipMirror(Node* root) {
        if (!root) return nullptr;

        Node* left = flipMirror(root->leftChild);
        Node* right = flipMirror(root->rightChild);

        root->leftChild = right;
        root->rightChild = left;

        return root;
    }

    static int calculateSum(Node* root) {
        if (!root) return 0;

        int leftTotal = calculateSum(root->leftChild);
        int rightTotal = calculateSum(root->rightChild);

        if (root->leftChild || root->rightChild) {
            root->value += leftTotal + rightTotal;
        }

        return root->value;
    }
};

int main() {
    Node* treeRoot = new Node(1);
    treeRoot->leftChild = new Node(2);
    treeRoot->rightChild = new Node(4);
    treeRoot->leftChild->leftChild = new Node(8);
    treeRoot->rightChild->leftChild = new Node(9);
    treeRoot->rightChild->rightChild = new Node(7);

    cout << "Original Tree (Task 4):" << endl;
    BinaryTree::displayTree(treeRoot);

    treeRoot = BinaryTree::flipMirror(treeRoot);
    cout << endl << "Mirrored Tree:" << endl;
    BinaryTree::displayTree(treeRoot);

    cout << endl << "Tree with Updated Sums (Task 5):" << endl;
    BinaryTree::calculateSum(treeRoot);
    BinaryTree::displayTree(treeRoot);
    cout << endl;

    return 0;
}
