#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

template <class T>
struct binary_search_tree {
public:
    binary_search_tree() : root(nullptr) {};

    void insert(T value) {
        root = insert(root, value);
    }

    bool contains(T value) {
        return contains(root, value);
    }

    int size() {
        return size(root);
    }

    void print() {
        cout << *this << endl;
    }

    friend ostream& operator<<(ostream& os, const binary_search_tree<T>& tree) {
        tree.inorderTraverse(tree.root, os);
        return os;
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, T value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool contains(TreeNode* node, T value) {
        if (node == nullptr) {
            return false;
        }
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

    int size(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + size(node->left) + size(node->right);
    }

    void inorderTraverse(TreeNode* node, ostream& os) const {
        if (node != nullptr) {
            inorderTraverse(node->left, os);  
            os << node->data << " ";          
            inorderTraverse(node->right, os); 
        }
    }
};

int main() {
    binary_search_tree<int> binary_tree;
    int q;
    cin >> q; // Кількість команд
    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;

        if (command == "insert") { 
            int value;
            cin >> value;
            binary_tree.insert(value);

        } else if (command == "size") { 
            cout << binary_tree.size() << endl;

        } else if (command == "contains") { 
            int value;
            cin >> value;
            cout << (binary_tree.contains(value) ? "Yes" : "No") << endl;

        } else if (command == "print") 
        {
            binary_tree.print();
        }
    }

    return 0;
}
