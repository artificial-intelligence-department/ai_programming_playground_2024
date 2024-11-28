#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

struct BinarySearchTree
{
    Node *root;
    int size;
};

enum Ident
{
    ID_insert,
    ID_contains,
    ID_treeSize,
    ID_print,
    ID_unknown
};

Ident parseToEnum(const string &id)
{
    if (id == "insert")
        return ID_insert;
    if (id == "contains")
        return ID_contains;
    if (id == "size")
        return ID_treeSize;
    if (id == "print")
        return ID_print;
    return ID_unknown;
}

void initializeTree(BinarySearchTree &tree)
{
    tree.root = nullptr;
    tree.size = 0;
}

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insertNode(Node *&node, int value, int &treeSize)
{
    if (node == nullptr)
    {
        node = createNode(value);
        ++treeSize;
    }
    else if (value < node->value)
    {
        insertNode(node->left, value, treeSize);
    }
    else if (value > node->value)
    {
        insertNode(node->right, value, treeSize);
    }
}

bool containsNode(Node *node, int value)
{
    if (node == nullptr)
    {
        return false;
    }
    else if (value == node->value)
    {
        return true;
    }
    else if (value < node->value)
    {
        return containsNode(node->left, value);
    }
    else
    {
        return containsNode(node->right, value);
    }
}

void printTree(Node *node)
{
    if (node == nullptr)
        return;
    printTree(node->left);
    cout << node->value << " ";
    printTree(node->right);
}

void destroyTree(Node *node)
{
    if (node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

int main()
{
    BinarySearchTree bst;
    initializeTree(bst);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        string ident;
        cin >> ident;

        Ident identifier = parseToEnum(ident);
        switch (identifier)
        {
        case ID_insert:
        {
            int value;
            cin >> value;
            insertNode(bst.root, value, bst.size);
            break;
        }
        case ID_contains:
        {
            int value;
            cin >> value;
            if (containsNode(bst.root, value))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            break;
        }
        case ID_treeSize:
            cout << bst.size << endl;
            break;
        case ID_print:
            printTree(bst.root);
            cout << endl;
            break;
        case ID_unknown:
            cout << "Unknown identifier!" << endl;
            break;
        }
    }

    destroyTree(bst.root);
    return 0;
}
