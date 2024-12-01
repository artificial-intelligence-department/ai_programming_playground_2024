#include <iostream>

using namespace std;

struct Node 
{
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree 
{
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int value) 
    {
        root = insertRecursive(root, value);
    }

    bool contains(int value) 
    {
        return search(root, value);
    }

    int size() 
    {
        return sizeRecursive(root);
    }

    void print() 
    {
        printInOrder(root);
        cout << "\n";
    }

private:
    Node* insertRecursive(Node* node, int value) 
    {
        if (node == nullptr) 
        {
            return new Node(value);
        }

        if (value < node->value) 
        {
            node->left = insertRecursive(node->left, value);
        } 
        else if (value > node->value) 
        {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    bool search(Node* node, int value) 
    {
        if (node == nullptr) 
        {
            return false;
        }

        if (value == node->value) 
        {
            return true;
        }

        if (value < node->value) 
        {
            return search(node->left, value);
        } 
        else 
        {
            return search(node->right, value);
        }
    }

    int sizeRecursive(Node* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }

        return 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
    }

    void printInOrder(Node* node) 
    {
        if (node == nullptr) 
        {
            return;
        }

        printInOrder(node->left);
        cout << node->value << " ";
        printInOrder(node->right);
    }
};

int main() {
    int Q;
    cin >> Q;

    BinarySearchTree tree;

    while (Q--) 
    {
        string command;
        cin >> command;

        if (command == "insert") 
        {
            int value;
            cin >> value;
            tree.insert(value);
        } 
        else if (command == "contains") 
        {
            int value;
            cin >> value;
            cout << (tree.contains(value) ? "Yes" : "No") << "\n";
        } 
        else if (command == "size") 
        {
            cout << tree.size() << "\n";
        } 
        else if (command == "print") 
        {
            tree.print();
        }
    }

    return 0;
}
