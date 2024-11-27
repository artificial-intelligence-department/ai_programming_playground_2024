#include <iostream>

template <typename T>
class BinaryTree
{
private:
    struct TreeNode
    {
        T data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(T value): data(value), left(nullptr), right(nullptr) {};
    };
    TreeNode* root;
    int size; 
    void Insert(TreeNode*& root, T value);
    void Print(const TreeNode* root) const;
    
public:
    BinaryTree();
    ~BinaryTree();
    void Insert(T value);
    bool Contains(T value) const;
    int Size() const;
    void Print() const;
    void FreeTree(TreeNode* root);
};

template <typename T>
BinaryTree<T>::BinaryTree(): root(nullptr), size(0) {}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    FreeTree(root);
    size = 0;
}

template <typename T>
void BinaryTree<T>::FreeTree(TreeNode* root)
{
    if (root != nullptr)
    {
        FreeTree(root->left);
        FreeTree(root->right);
        delete root;
        size = 0;
    }
}

template <typename T>
void BinaryTree<T>::Insert(TreeNode*& root, T value)
{
    if (root == nullptr)
    {
        root = new TreeNode(value);
        size++;
        return;
    }
    if (root->data == value)
        return;
    if (value < root->data)
    {
        if (root->left == nullptr)
        {
            root->left = new TreeNode(value);
            size++;
            return;
        }
        Insert(root->left, value);
    }
    if (value > root->data)
    {
        if (root->right == nullptr)
        {
            root->right = new TreeNode(value);
            size++;
            return;
        }
        Insert(root->right, value);
    }
}
template <typename T>
void BinaryTree<T>::Insert(T value)
{
    Insert(root, value);
}

template <typename T>
void BinaryTree<T>::Print(const TreeNode* root) const
{
    if (root != nullptr)
    {
        Print(root->left);
        std::cout << root->data << " ";
        Print(root->right);
    }
}
template <typename T>
void BinaryTree<T>::Print() const
{
    Print(root);
}

template <typename T>
bool BinaryTree<T>::Contains(T target) const
{
    TreeNode* current = root;
    while (current != nullptr)
    {
        if (current->data == target)
            return true;
        if (target > current->data)
            current = current->right;
        else
            current = current->left;
    }
    return false;
}

template <typename T>
int BinaryTree<T>::Size() const
{
    return size;
}

int main()
{
    int Q;
    std::cin >> Q;
    std::string question;
    BinaryTree<int> myTree;

    for(int i = 0; i < Q; i++)
    {
        std::cin >> question;
        if (question == "insert")
        {
            int value;
            std::cin >> value;
            myTree.Insert(value);
        }
        if (question == "contains")
        {
            int target;
            std::cin >> target;
            std::cout << (myTree.Contains(target) ? "Yes" : "No") << std::endl;
        }
        if (question == "size")
        {
            std::cout << myTree.Size() << std::endl;
        }
        if (question == "print")
        {
            myTree.Print();
            std::cout << std::endl;
        }
    }
    return 0;
}
