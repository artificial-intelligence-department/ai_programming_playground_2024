#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    int data;  
    Node* left; 
    Node* right;

    Node(int val) 
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


struct BinarySearchTree 
{
    Node* root; 
    int size; 

    BinarySearchTree() 
    {
        root = nullptr;
        size = 0;
    }

    void insert(int value) 
    {
        if (!contains(value))
        { 
            root = insertRec(root, value);
            size++;
        }
    }

    Node* insertRec(Node* node, int value) 
    {
        if (node == nullptr) 
        {
            return new Node(value);
        }

        if (value < node->data) 
        {
            node->left = insertRec(node->left, value);
        }
        else 
        {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    bool contains(int value) 
    {
        return containsRec(root, value);
    }

    bool containsRec(Node* node, int value) 
    {
        if (node == nullptr) 
        {
            return false;
        }
        if (node->data == value) 
        {
            return true;
        }
        if (value < node->data) 
        {
            return containsRec(node->left, value);
        } 
        else 
        {
            return containsRec(node->right, value);
        }
    }

    int getSize() 
    {
        return size;
    }

    void print() 
    {
        printRec(root);
        cout << endl;
    }

    void printRec(Node* node) 
    {
        if (node == nullptr) 
        {
            return;
        }
        printRec(node->left); 
        cout << node->data << " ";
        printRec(node->right); 
    }
};

int main() {
    BinarySearchTree tree;
    int Q;
    cin >> Q;

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
            if (tree.contains(value)) 
            {
                cout << "Yes" << endl;
            } 
            else 
            {
                cout << "No" << endl;
            }
        } 
        else if (command == "size") 
        {
            cout << tree.getSize() << endl;
        } 
        else if (command == "print") 
        {
            tree.print();
        }
    }

    return 0;
}
