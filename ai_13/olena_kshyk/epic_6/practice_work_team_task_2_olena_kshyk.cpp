#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int value) : data(value), right(nullptr), left(nullptr) {}
};

TreeNode *insert(TreeNode *node, int value)
{
    if (node == nullptr)
        return new TreeNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);

    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

TreeNode *create_mirror_flip(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    TreeNode *newRoot = new TreeNode(root->data);

    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);
    return newRoot;
}

void tree_sum(TreeNode *root)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
        return;

    tree_sum(root->left);
    tree_sum(root->right);

    int leftVal = root->left != nullptr ? root->left->data : 0;
    int rightVal = root->right != nullptr ? root->right->data : 0;
    root->data = leftVal + rightVal;
}

void output(TreeNode *root)
{
    if (root == nullptr)
        cout << "The tree is empty" << endl;
    else
    {
        if (root->left != nullptr)
            output(root->left);

        cout << root->data << " ";

        if (root->right != nullptr)
            output(root->right);
    }
}

int main()
{
    TreeNode *root = nullptr;
    vector<int> v = {7, 3, 5, 1, 2, 9};
    for (auto el : v)
        root = insert(root, el);

    cout << "Original tree: " << endl;
    output(root);
    
    TreeNode *reversed = create_mirror_flip(root);
    cout << "\nReversed tree: " << endl;
    output(reversed);

    cout << "\nTree with sum of elements: " << endl;
    tree_sum(root);
    output(root);
    
    return 0;
}