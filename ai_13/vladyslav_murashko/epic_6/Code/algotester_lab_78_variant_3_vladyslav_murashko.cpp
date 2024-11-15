#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;

    template <class U>
    friend ostream &operator<<(ostream &os, const Node<U> &el)
    {
        if (el.left != nullptr)
        {
            os << *el.left;
        }
        os << el.data << " ";
        if (el.right != nullptr)
        {
            os << *el.right;
        }
        return os;
    }

    Node(T value) : data(value), left(nullptr), right(nullptr)
    {
    }
};

template <class T>
class BinarySearchTree
{
private:
    Node<T> *root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T value)
    {
        root = insertNode(root, value);
    }

    bool search(T value)
    {
        return searchNode(root, value);
    }

    void remove(T value)
    {
        root = removeNode(root, value);
    }

    int count()
    {
        return countNodes(root);
    }

    template <class U>
    friend ostream &operator<<(ostream &os, const BinarySearchTree<U> &el)
    {
        if (el.getRoot() != nullptr)
        {
            os << *el.getRoot();
        }
        return os;
    }

    const Node<T> *getRoot() const
    {
        return this->root;
    }

private:
    int countNodes(Node<T> *node)
    {
        int count = 0;
        if (node != nullptr)
        {
            count++;
            count += countNodes(node->left);
            count += countNodes(node->right);
        }
        return count;
    }

    Node<T> *insertNode(Node<T> *node, int value)
    {
        if (node == nullptr)
        {
            return new Node<T>(value);
        }
        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    bool searchNode(Node<T> *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (value == node->data)
        {
            return true;
        }
        else if (value < node->data)
        {
            return searchNode(node->left, value);
        }
        else
        {
            return searchNode(node->right, value);
        }
    }

    Node<T> *removeNode(Node<T> *node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (value < node->data)
        {
            node->left = removeNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = removeNode(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }

            Node<T> *temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
        return node;
    }

    Node<T> *findMin(Node<T> *node)
    {
        while (node && node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
};

int main()
{
    int Q;
    cin >> Q;
    string input;
    cin.ignore();
    BinarySearchTree<int> tree = BinarySearchTree<int>();
    for (size_t i = 0; i < Q; i++)
    {
        string command;
        int value;
        getline(cin, input);
        command = input.substr(0, input.find(" "));
        if (command == "insert")
        {
            value = stoi(input.substr(input.find(" ") + 1));
            tree.insert(value);
        }
        else if (command == "contains")
        {
            value = stoi(input.substr(input.find(" ") + 1));
            cout << (tree.search(value) ? "Yes\n" : "No\n");
        }
        else if (command == "remove")
        {
            value = stoi(input.substr(input.find(" ") + 1));
            tree.remove(value);
        }
        else if (command == "size")
        {
            cout << tree.count() << endl;
        }
        else if (command == "print")
        {
            cout << tree << endl;
        }
        else
        {
            i--;
        }
    }
    return 0;
}