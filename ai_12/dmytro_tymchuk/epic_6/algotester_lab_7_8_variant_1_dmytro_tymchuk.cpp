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

    void print()
    {
        print(root);
    }

private:
    tree_node* root;
    int size = 0;
    

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

    void print( tree_node* node)
    {
        if (node == nullptr) return;

        print( node->left);
        
        cout<<node->data<<" ";

        print(node->right);
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
            my_tree.print();
            cout<<endl;
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
