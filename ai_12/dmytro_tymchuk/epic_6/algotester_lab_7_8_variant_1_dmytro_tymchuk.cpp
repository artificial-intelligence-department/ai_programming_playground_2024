#include<iostream>
#include<string>
using namespace std;

struct tree_node
{
    int data;
    tree_node* left;
    tree_node* right;

    tree_node (int value): data(value), left(nullptr), right(nullptr){}; 
};

struct binary_tree
{
public:
    binary_tree(): root(nullptr){};
    

    void insert(int value)
    {
        root = insert(root, value);
    }

    bool contains(int value)
    {
        return contains(root, value);
    }

    int size_of_tree()
    {
        return size;
    }

    friend ostream& operator<<(ostream& os, const  binary_tree& tree) 
    {
        tree.print_tree(tree.root, os);
        return os;
    }

private:
    tree_node* root;
    int size = 0;
    
    //Виведення дерева
    void print_tree(tree_node* node, ostream& os) const 
    {
        if (node != nullptr) 
        {
            print_tree(node->left, os);

            os << node->data << " ";

            print_tree(node->right, os);
        }
    }

    //Вставити число
    tree_node* insert(tree_node* node, int value)
    {
        if (node == nullptr)
        {
            size++;
            return new tree_node(value);
        }

        if (value > node->data)
        {
            node->right = insert(node->right, value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        return node;
    }

    //знайти число
    bool contains (tree_node* node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (value > node->data)
        {
            return contains(node->right, value);
        }
        else if (value < node->data)
        {
            return contains(node->left, value);
        }

        return true;
    }

};


int main()
{
    binary_tree my_tree;

    int n;
    string s;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>s;
        if (s == "size")
        {
            cout<<my_tree.size_of_tree()<<endl;
        }
        else if (s == "print")
        {
            cout<<my_tree<<endl;
        }
        else if (s =="insert")
        {
            int value;
            cin>>value;
            my_tree.insert(value);
        }
        else if (s == "contains")
        {
            int value;
            cin>>value;
            if (my_tree.contains(value)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    
    return 0;
}

