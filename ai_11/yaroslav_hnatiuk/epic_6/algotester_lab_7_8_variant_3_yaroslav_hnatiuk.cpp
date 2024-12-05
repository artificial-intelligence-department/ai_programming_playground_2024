#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    long long treeSize;

    void clear(TreeNode* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BinaryTree() : root(nullptr), treeSize(0) {}

    ~BinaryTree() {
        clear(root);
    }

    void insert(int value) {
        if (contains(value, root) == false) {
            if (root == nullptr) {
                root = new TreeNode{value};
                treeSize++;
                return;
            } 

            TreeNode *current = root;
            while(true) {
                if (value > current->key) {
                    if (current->right != nullptr) current = current->right;
                    else {
                        current->right = new TreeNode{value};
                        treeSize++;
                        return;
                    }

                } else if (value < current->key) {
                    if (current->left != nullptr) current = current->left;
                    else {
                        current->left = new TreeNode{value};
                        treeSize++;
                        return;
                    }
                }
            }
        }
    }

    void containsCall(int value) {
        if (contains(value, root) == true) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }

    bool contains(int value, TreeNode *current) {
        if (current == nullptr) {
            return false; 
        }
        if (value == current->key) {
            return true; 
        }
        if (value < current->key) {
            return contains(value, current->left); 
        } else {
            return contains(value, current->right);
        }
    }

    void size() {
        cout << treeSize << endl;
    }

    void printCall() {     
        print(root);    
    }

    void print(TreeNode* node) {
        if (node == nullptr) return;
        print(node->left);   
        cout << node->key << " "; 
        print(node->right);   
    }

};

int main() {
    int Q;
    cin >> Q;
    BinaryTree tree;
    
    while (Q--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int value;
            cin >> value;
            tree.insert(value);

        } else if (command == "contains") {
            int value;
            cin >> value;
            tree.containsCall(value);

        } else if (command == "size"){
            tree.size();

        } else if (command == "print") {
           tree.printCall();
           cout << endl;
        }
    }

    return 0;
}
