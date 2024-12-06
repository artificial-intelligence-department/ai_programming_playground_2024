#include <iostream>
using namespace std;

class BinarySearchTreeNode
{
    public:
    int val;
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
    BinarySearchTreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
    BinarySearchTreeNode* root;
    public:
    BinarySearchTree() { root = nullptr; }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void print_in_order()
    {
        print_in_order(root);
        cout << endl;
    }

    BinarySearchTree create_mirror()
    {
        BinarySearchTree mirrored_tree;
        mirrored_tree.root = create_mirror(root);
        return mirrored_tree;
    }

    void update_to_sum()
    {
        update_to_sum(root);
    }

    private:
    BinarySearchTreeNode* insert(BinarySearchTreeNode* node, int value)
    {
        if (node == nullptr)
        {
            return new BinarySearchTreeNode(value);
        }
        if (value < node->val)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->val)
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void print_in_order(BinarySearchTreeNode* node)
    {
        if (node != nullptr)
        {
            print_in_order(node->left);
            cout << node->val << " ";
            print_in_order(node->right);
        }
    }

    BinarySearchTreeNode* create_mirror(BinarySearchTreeNode* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        BinarySearchTreeNode* mirror_node = new BinarySearchTreeNode(node->val);
        mirror_node->left = create_mirror(node->right);
        mirror_node->right = create_mirror(node->left);
        return mirror_node;
    }

    int update_to_sum(BinarySearchTreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left_sum = update_to_sum(node->left);
        int right_sum = update_to_sum(node->right);
        int old_value = node->val;
        node->val = left_sum + right_sum;
        return node->val + old_value;
    }
};

int main()
{
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(4);
    bst.insert(15);
    bst.insert(2);
    bst.insert(6);
    bst.insert(12);
    bst.insert(18);

    cout << "Original Tree (In-order): ";
    bst.print_in_order();

    BinarySearchTree mirrored_tree = bst.create_mirror();
    cout << "Mirrored Tree (In-order): ";
    mirrored_tree.print_in_order();

    bst.update_to_sum();
    cout << "Updated Tree to Sum (In-order): ";
    bst.print_in_order();

    return 0;
}
