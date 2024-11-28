#include <iostream>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    TreeNode* root;
public:
    BinaryTree(){
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void print() {
        print(root);
    }

    void size() {
        int sz = size(root);
        cout << sz << endl;
    }

    bool contains(int value) {
        return contains(root, value);
    }

    TreeNode* insert(TreeNode* node, int value) {
        if(node == nullptr) {
            return new TreeNode(value);
        }

        if(value < node->data) {
            node->left = insert(node->left, value);
        } else if(value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool contains(TreeNode* node, int value) {
        if(node == nullptr) {
            return false;
        }

        if(value == node->data) {
            return true;
        } else if(value < node->data) {
            return contains(node->left, value);
        } else{
            return contains(node->right, value);
        }
    }

    void print(TreeNode* node) {
        if(node != nullptr) {
            print(node->left);
            cout << node->data << " ";
            print(node->right);
        }
    }

    int size(TreeNode* node) {
        if(node != nullptr) {
            int sum = 1;
            sum += size(node->left);
            sum += size(node->right);

            return sum;
        } else{
            return 0;
        }
    }

};

int main() {

    BinaryTree tree;

    int Q;
    string opt;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> opt;
        if(opt == "insert") {
            int num;
            cin >> num;
            tree.insert(num);
        } else if(opt == "contains") {
            int num;
            cin >> num;
            if(tree.contains(num)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if(opt == "print") {
            tree.print();
            cout << endl;
        } else if(opt == "size") {
            tree.size();
        }
    }


    return 0;
}