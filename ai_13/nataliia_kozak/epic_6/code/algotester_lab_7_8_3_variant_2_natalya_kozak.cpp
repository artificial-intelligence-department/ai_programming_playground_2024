#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
template <typename T>
class BinaryTree
{
    
    int size = 0;
    bool search_recursive(Node<T> *current, T value)
    {
        if (current == nullptr)
            return false;
        if (current->data == value)
            return true;
        if (search_recursive(current->left, value) || search_recursive(current->right, value))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    Node<T> *root;
    BinaryTree()
    {
        root = nullptr;
    }
    void insert(T value)
    {
        if(search_recursive(root, value)) return;
        size++;
        Node<T> *newNode = new Node<T>(value);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        queue<Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node<T> *current = q.front();
            q.pop();

            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            else
            {
                q.push(current->left);
            }

            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            else
            {
                q.push(current->right);
            }
        }
    }
    void contains(T value){
        if(search_recursive(root, value)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    void tree_size(){
        cout << size << endl;
    }
};
template<typename T>
ostream &operator<<(ostream &os, BinaryTree<T> &t) // overload cout
{
    vector<T> v;
    if (t.root == nullptr) return os;  
    
    // Queue to store nodes for level order traversal
    queue<Node<T>*> q;  
    // Enqueue the root node
    q.push(t.root);    
    while (!q.empty()) {
        // Get the current level size
        int levelSize = q.size();  
        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            Node<T>* node = q.front();  
            v.push_back(node->data);
            q.pop();  
            
            // Enqueue left child if it exists
            if (node->left != nullptr)
                q.push(node->left);
            
            // Enqueue right child if it exists
            if (node->right != nullptr)
                q.push(node->right);
        }
    }
    sort(v.begin(), v.end());
    for(T i : v){
        os << i << ' ';
    }
    os << endl;
    return os;
}
int main()
{
    int Q, value;
    cin >> Q;
    string request;
    BinaryTree<int> tree;
    for (int i = 0; i < Q; i++)
    {
        cin >> request;
        if (request == "insert")
        {
            cin >> value;
            tree.insert(value);
        }
        else if (request == "contains")
        {
            cin >> value;
            tree.contains(value);
        }
        else if (request == "size")
        {
            tree.tree_size();
        }
        else
        { // print
            cout << tree << endl;
        }
    }
    return 0;
}