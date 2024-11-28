#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr), right(nullptr) {}
};

void Insert(Node*& root, int value);
void Show(Node* root);
void FreeTree(Node*& root);
Node* MirrorTree(Node*& root);
void TreeSum(Node*& root);


int main()
{
    Node* myTree = nullptr;
    Insert(myTree, 50);
    Insert(myTree, 40);
    Insert(myTree, 60);
    Insert(myTree, 30);
    Insert(myTree, 70);
    Insert(myTree, 80);
    Insert(myTree, 20);
    
    std::cout << "Tree: ";
    Show(myTree);
    std::cout << std::endl;
    std::cout << "Mirrored Tree: ";
    MirrorTree(myTree);
    Show(myTree);
    MirrorTree(myTree);
    std::cout << std::endl << "Tree of sum: ";
    TreeSum(myTree);
    Show(myTree);
    FreeTree(myTree);

    return 0;
}

void Insert(Node*& root, int value)
{
    if (root == nullptr)
    {
        root = new Node(value);
        return;
    }
    if (root->data == value)
        return;

    if (root->data > value)
    {
        if (root->left == nullptr)
        {
            root->left = new Node(value);
            return;
        }
        Insert(root->left, value);
    }
    if(root->data < value)
    {
        if (root->right == nullptr)
        {
            root->right = new Node(value);
            return;
        }
        Insert(root->right, value);
    }
}

void Show(Node* root)
{
    if(root != nullptr)
    {
        Show(root->left);
        std::cout << root->data << " ";
        Show(root->right);
    }
}

void FreeTree(Node*& root)
{
    if(root != nullptr)
    {
        FreeTree(root->left);
        FreeTree(root->right);
        delete root;
    }
}

Node* MirrorTree(Node*& root)
{
    if (root == nullptr)
        return nullptr;
    Node* left = MirrorTree(root->left);
    Node* right = MirrorTree(root->right);

    root->right = left;
    root->left = right;
    return root;
}

void TreeSum(Node*& root)
{
    if (root == nullptr)
        return;

    TreeSum(root->left);
    TreeSum(root->right);

    if (root->left != nullptr)
        root->data += root->left->data;

    if (root->right != nullptr)
        root->data += root->right->data;
}