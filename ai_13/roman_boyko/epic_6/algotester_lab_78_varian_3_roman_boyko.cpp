#include <iostream>
using namespace std;

template <typename T>
class BinaryTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
    };
    Node *root = nullptr;
    size_t Size(const Node *node);

    template <typename Func>
    void DoForNode(const Node *node, Func func);

public:
    size_t Size();
    bool Insert(T &value);
    template <typename Func>
    void DoForAllElems(Func func);

    bool Find(const T &value);
};

template <typename T>
template <typename Func>
void BinaryTree<T>::DoForNode(const Node *node, Func func)
{
    if (node != nullptr)
    {
        if (node->left != nullptr)
        {
            DoForNode(node->left, func);
        }
        func(node->data);
        if (node->right != nullptr)
        {
            DoForNode(node->right, func);
        }
    }
}

template <typename T>
template <typename Func>
void BinaryTree<T>::DoForAllElems(Func func)
{
    DoForNode(root, func);
}

template <typename T>
void ShowAll(const T &value)
{
    cout << value << " ";
}

template <typename T>
void Show(const BinaryTree<T> &tree)
{
    tree.DoForAllElems(ShowAll<T>);
    cout << endl;
}

template <typename T>
size_t BinaryTree<T>::Size(const Node *node)
{
    return node == nullptr ? 0 : 1 + Size(node->left) + Size(node->right);
}

template <typename T>
size_t BinaryTree<T>::Size()
{
    return Size(root);
}

template <typename T>
bool BinaryTree<T>::Insert(T &value)
{
    if (root == nullptr)
    {
        root = new Node{value};
        return true;
    }

    Node *node = root;

    while (node != nullptr)
    {
        if (node->data == value)
        {
            return false;
        }
        else if (node->data < value)
        {
            if (node->right == nullptr)
            {
                node->right = new Node{value, nullptr, nullptr};
                return true;
            }
            node = node->right;
        }
        else
        {
            if (node->left == nullptr)
            {
                node->left = new Node{value, nullptr, nullptr};
                return true;
            }
            node = node->left;
        }
    }
    return false;
}

template <typename T>
bool BinaryTree<T>::Find(const T &value)
{
    Node *node = root;
    while (node != nullptr)
    {
        if (value > node->data)
        {
            node = node->right;
        }
        else if (value < node->data)
        {
            node = node->left;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int Q;
    int num;
    string ch;
    BinaryTree<int> tree;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> ch;
        if (ch == "insert")
        {
            cin >> num;
            tree.Insert(num);
        }
        else if (ch == "contains")
        {
            cin >> num;
            bool foundValue = tree.Find(num);
            if (foundValue)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else if (ch == "size")
        {
            cout << tree.Size() << endl;
        }
        else if (ch == "print")
        {
            tree.DoForAllElems(ShowAll<int>);
            cout << endl;
        }
    }
}