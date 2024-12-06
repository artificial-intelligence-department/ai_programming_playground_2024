#include <iostream>

using namespace std;

template<typename T>
struct TreeNode {
    T key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : key(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    TreeNode<T>* root;
    int treeSize;

    void clear(TreeNode<T>* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    bool contains(TreeNode<T>* node, T value) {
        if (node == nullptr) return false;
        if (node->key == value) return true;
        if (value < node->key) return contains(node->left, value);
        else return contains(node->right, value);
    }

    void print(TreeNode<T>* node) {
        if (node == nullptr) return;
        print(node->left);
        cout << node->key << " ";
        print(node->right);
    }

public:
    BinaryTree() : root(nullptr), treeSize(0) {}

    ~BinaryTree() { clear(root); }

    void insert(T value) {
        if (!contains(root, value)) {
            if (root == nullptr) {
                root = new TreeNode<T>(value);
            } else {
                TreeNode<T>* current = root;
                while (true) {
                    if (value < current->key) {
                        if (current->left == nullptr) {
                            current->left = new TreeNode<T>(value);
                            break;
                        } else {
                            current = current->left;
                        }
                    } else {
                        if (current->right == nullptr) {
                            current->right = new TreeNode<T>(value);
                            break;
                        } else {
                            current = current->right;
                        }
                    }
                }
            }
            treeSize++;
        }
    }

    void containsCall(T value) {
        if (contains(root, value)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    void size() {
        cout << treeSize << endl;
    }

    void printCall() {
        print(root);
        cout << endl;
    }
};

int main() {
    int iterations;
    cin >> iterations;

    BinaryTree<int> tree;

    while (iterations--){
        string choice;
        cin >> choice;

        if (choice == "insert"){
            int value;
            cin >> value;
            tree.insert(value);

        }else if (choice == "contains"){
            int value;
            cin >> value;
            tree.containsCall(value);

        }else if (choice == "size"){
            tree.size();

        }else if (choice == "print"){
           tree.printCall();
           cout << endl;
        }
    }

    return 0;
}

