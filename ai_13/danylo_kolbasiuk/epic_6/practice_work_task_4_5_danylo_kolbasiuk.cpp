#include <iostream>

class BinarySearchTreeNode
{
    public:
    int val;
    BinarySearchTreeNode* l;
    BinarySearchTreeNode* r;
    BinarySearchTreeNode(int value)
    {
        val=value;
        l=nullptr;
        r=nullptr;
    }
};

class BinarySearchTree
{
    BinarySearchTreeNode* root;
    public:
    BinarySearchTree() {root=nullptr;}
    void tree_sum()
    {
        tree_sum(root);
    }
    void insert(int value)
    {
        root = insert(root,value);
    }
    void print_tree()
    {
        print_tree(root);
        std::cout << std::endl;
    }
    BinarySearchTree mirror_flip()
    {
        BinarySearchTree tree2;
        tree2.root=mirror_flip(root);
        return tree2;
    }
    BinarySearchTreeNode* insert(BinarySearchTreeNode* node, int value)
    {
        if(node==nullptr)
        {
            return new BinarySearchTreeNode(value);
        }
        else if (node->val == value)
        {
            return node;
        }
        else if (node->val > value)
        {
            node->l = insert(node->l, value);
        }
        else
        {
            node->r = insert(node->r, value);
        }
        return node;
    }
    void print_tree(BinarySearchTreeNode* node)
    {
        if(node!=nullptr)
        {
            print_tree(node->l);
            std::cout << node->val << " ";
            print_tree(node->r); 
        }
    }
    BinarySearchTreeNode* mirror_flip(BinarySearchTreeNode* node)
    {
        if(node==nullptr)
        {
            return nullptr;
        }
        BinarySearchTreeNode* mirrornode=new BinarySearchTreeNode(node->val);
        mirrornode->l=mirror_flip(node->r);
        mirrornode->r=mirror_flip(node->l);
        return mirrornode;
    }
    int tree_sum(BinarySearchTreeNode* root)
    {
        if (root!=nullptr)
        {
            int sum=0;
            sum+=tree_sum(root->l);
            sum+=tree_sum(root->r);
            if (sum>0)
            {
                root->val=sum;
                return sum;
            }
            else
            {
                return root->val;
            }
        }
        else 
        {
            return 0;
        }
    }
};

int main()
{
    BinarySearchTree binarytree;
    binarytree.insert(7);
    binarytree.insert(5);
    binarytree.insert(9);
    binarytree.insert(2);
    binarytree.insert(6);
    binarytree.insert(8);
    binarytree.print_tree();
    BinarySearchTree tree2=binarytree.mirror_flip();
    tree2.print_tree();
    binarytree.tree_sum();
    binarytree.print_tree();
}
