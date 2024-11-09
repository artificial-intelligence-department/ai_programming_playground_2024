#include <iostream>
#include <vector>
#include <limits>

using namespace std;

template <typename T>
// bynary search tree
struct BSTNode
{
    T data;
    BSTNode *lchild;
    BSTNode *rchild;

    BSTNode(T value): data(value), lchild(nullptr), rchild(nullptr) {};
};

template <class T>
class BST
{
private:
    BSTNode<T> *root;

public:
    int size;

    BST() : root(nullptr), size(0) {}

    string bSearch(T value, BSTNode<T> *node)
    {
        if (node == nullptr)
            return "No";
        if (value == node->data)
            return "Yes";
        if (value > node->data)
            return bSearch(value, node->rchild);
        return bSearch(value, node->lchild);
    }

    string bSearch(T value){
        return bSearch(value, this->root);
    }

    BSTNode<T> *insert(BSTNode<T> *node, int value)
    {
        if (node == nullptr)
        {
            this->size++;
            return new BSTNode<T>(value);
        }
        if (value < node->data)
        {
            node->lchild = insert(node->lchild, value);
        }
        else if (value > node->data)
        {
            node->rchild = insert(node->rchild, value);
        }
        return node;
    }

    void insert(int value)
    {
        this->root = insert(this->root, value);
    }
///////////////////////////////////////////////////
    void setplace(BSTNode<T> *node, T value)
    {
        if (node->data > value)
        {
            if (node->lchild == nullptr)
            {
                BSTNode<T> *newNode = new BSTNode<T>(value);
                node->lchild = newNode;
                this->size++;
                return;
            }
            else
                setplace(node->lchild, value);
        }
        else if (node->data < value)
        {
            if (node->rchild == nullptr)
            {
                BSTNode<T> *newNode = new BSTNode<T>(value);
                node->rchild = newNode;
                this->size++;
                return;
            }
            else
                setplace(node->rchild, value);
        }
        else
            return;
    }

    void setplace(T value)
    {
        if (this->data == -999 && this->lchild == nullptr && this->rchild == nullptr)
        {
            this->data = value;
            this->size++;
        }
        else
            setplace(this, value);
    };
//////////////////////////////////////////////////
    void print(BSTNode<T> *node, string separator)
    {
        if (node == nullptr)
            return;
        print(node->lchild, separator);
        cout << node->data << separator;
        print(node->rchild, separator);
    };

    BST& operator<<(string separator)
    {
        print(this->root, separator);
        cout << endl;
        return *this;
    };
};

int main()
{
    BST<int> tree;
    int q;
    cin >> q;
    while (q--)
    {
        string line;
        cin >> line;
        if (line == "insert")
        {
            int n;
            cin >> n;
            // tree.setplace(n);
            tree.insert(n);
        }
        else if (line == "contains")
        {
            int n;
            cin >> n;
            cout << tree.bSearch(n) << endl;
        }
        else if (line == "size")
        {
            cout << tree.size << endl;
        }
        else if (line == "print")
        {
            tree << " ";
        }
    }
    return 0;
}