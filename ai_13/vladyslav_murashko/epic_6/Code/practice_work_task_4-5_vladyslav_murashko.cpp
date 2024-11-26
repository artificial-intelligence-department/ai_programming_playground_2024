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

    Node<T> mirror()
    {
        return *create_mirror_flip(copyTree(root));
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

    BinarySearchTree &operator=(const BinarySearchTree &other)
    {
        if (this != &other)
        {
            clear(root);
            root = copyTree(other.root);
        }
        return *this;
    }

    Node<T> convertTreeToSum(){
        tree_sum(root);
        return *root;
    }

private:
    Node<T> *root;

    void clear(Node<T> *node)
    {
        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    Node<T> *copyTree(Node<T> *node)
    {
        if (node == nullptr)
            return nullptr;

        Node<T> *newNode = new Node<T>(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

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

    Node<T> *create_mirror_flip(Node<T> *node)
    {
        if (!node)
        {
            return nullptr;
        }
        Node<T> *temp = node->left;
        node->left = node->right;
        node->right = temp;

        create_mirror_flip(node->left);
        create_mirror_flip(node->right);

        return node;
    }

    T tree_sum(Node<T> *node)
    {
        if (!node)
        {
            return 0;
        }
        if(!node->left && !node->right){
            return node->data;
        }
        node->data = tree_sum(node->left) + tree_sum(node->right);

        return node->data;
    }
};

int main()
{
    BinarySearchTree<int> tree;
    tree.insert(4);
    cout << "Root 4\n";
    tree.insert(1);
    cout << "Insert 1\n";
    tree.insert(2);
    cout << "Insert 2\n";
    tree.insert(3);
    cout << "Insert 3\n";
    tree.insert(4);
    cout << "Insert 4\n";
    tree.insert(5);
    cout << "Insert 5\n";
    tree.insert(6);
    cout << "Insert 6\n";
    tree.insert(0);
    cout << "Insert 0\n";

    cout << "Tree - " << tree << endl;

    cout << "Mirror - "<< tree.mirror() << endl;

    cout << "Tree converted to sum - " << tree.convertTreeToSum() << endl;

    return 0;
}