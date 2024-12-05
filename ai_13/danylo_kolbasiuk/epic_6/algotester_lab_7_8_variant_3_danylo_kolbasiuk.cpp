#include <iostream>
template <class T>
class BinarySearchTreeNode
{
    public:
    T val;
    BinarySearchTreeNode* l;
    BinarySearchTreeNode* r;
    BinarySearchTreeNode(T& value)
    {
        val=value;
        l=nullptr;
        r=nullptr;
    }
};
template <class T> 
class BinarySearchTree
{
    BinarySearchTreeNode<T>* root;
    public:
    BinarySearchTree() {root=nullptr;}
    void insert(T value)
    {
        root = insert(root,value);
    }
    bool contains(T value)
    {
        return contains(root, value);
    }
    void size_of_tree()
    {
        std::cout << size_of_tree(root) << std::endl;
    }
    void print_tree()
    {
        print_tree(root);
    }
    BinarySearchTreeNode<T>* insert(BinarySearchTreeNode<T>* node, T& value)
    {
        if(node==nullptr)
        {
            return new BinarySearchTreeNode<T>(value);
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
    bool contains(BinarySearchTreeNode<T>* node, T& value)
    {
        if(node == nullptr)
        {
            return false;
        }
        if(node->val == value)
        {
            return true;
        }
        else if (node->val > value)
        {
            return contains(node->l, value);
        }
        else
        {
            return contains(node->r, value);
        }
    }
    size_t size_of_tree(BinarySearchTreeNode<T>* node)
    {
        int size=0;
        if(node!=nullptr)
        {
            size++;
            size+=size_of_tree(node->l);
            size+=size_of_tree(node->r);
        }
        return size;
    }
    void print_tree(BinarySearchTreeNode<T>* node)
    {
        if(node!=nullptr)
        {
            print_tree(node->l);
            std::cout << node->val << " ";
            print_tree(node->r); 
        }
    }
};

int main()
{
    BinarySearchTree<int> binarytree;

    int N;
    std::string function;
    std::cin >> N;
    for(int i=0; i<N; i++)
    {   
        int value;
        std::cin >> function;
        if(function=="insert")
        {
            std::cin >> value;
            binarytree.insert(value);
        }
        else if(function=="contains")
        {
            std::cin >> value;
            if(binarytree.contains(value))
            {
                std::cout << "Yes" << std::endl;
            }
            else
            {
                std::cout << "No" << std::endl;
            }
        }
        else if(function=="size")
        {
            binarytree.size_of_tree();
        }
        else if(function=="print")
        {
            binarytree.print_tree();
        }
    }
}