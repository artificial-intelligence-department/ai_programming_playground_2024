#include <iostream>
#include <algorithm>
#include <vector>
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
        T sum;
    };
    Node *root = nullptr;
    size_t Size(const Node *node);
    void MirrorNode(Node *node);
    T Sum(Node *node);
    template <typename Func>
    void DoForNode(const Node *node, Func func);

public:
    size_t Size();
    bool Insert(T &value);
    template <typename Func>
    void DoForAllElems(Func func);
    void Mirror();
    T SumTree();
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
                node->right = new Node{value, nullptr, nullptr, 0};
                return true;
            }
            node = node->right;
        }
        else
        {
            if (node->left == nullptr)
            {
                node->left = new Node{value, nullptr, nullptr, 0};
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

template <typename T>
void BinaryTree<T>::MirrorNode(Node *node)
{
    if (node->left != nullptr)
    {
        MirrorNode(node->left);
    }
    if (node->right != nullptr)
    {
        MirrorNode(node->right);
    }
    swap(node->left, node->right);
}

template <typename T>
void BinaryTree<T>::Mirror()
{
    MirrorNode(root);
}

template <typename T>
T BinaryTree<T>::Sum(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    T leftSum = Sum(node->left);
    T rightSum = Sum(node->right);

    node->sum = node->data + leftSum + rightSum;
    cout << "Sum at node " << node->data << ": " << node->sum << endl;

    return node->sum;
}

template <typename T>
T BinaryTree<T>::SumTree()
{
    return Sum(root);
}

int main()
{
    BinaryTree<int> tree;
    int values[8] = {1, 7, 3, 4, 0, 9, 6, 5};
    for (int num : values)
    {
        tree.Insert(num);
    }
    cout << "Normal tree: ";
    tree.DoForAllElems(ShowAll<int>);
    cout << endl;
    tree.SumTree();
    cout << endl
         << "Mirrored tree: ";
    tree.Mirror();
    tree.DoForAllElems(ShowAll<int>);
}