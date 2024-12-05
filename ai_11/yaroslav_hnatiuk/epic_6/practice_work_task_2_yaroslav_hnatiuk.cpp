#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        TreeNode* root;

        void DeleteTree (TreeNode* current) {
            if (current == nullptr) return;
            DeleteTree (current->left);
            DeleteTree (current->right);
            delete current;
        }

    public:
        BinaryTree() : root(nullptr) {}

        ~BinaryTree() {DeleteTree(root);}

    void create(int* values, int valuesNum) {
        int start = 0;

        if (root == nullptr) {
            root = new TreeNode(values[0]);
            start++;
        }

        TreeNode* current = root;
        for (int i = start; i < valuesNum; i++) {
            current = root;
            while (current != nullptr) {
                if (values[i] > current->key) {
                    if (current->right == nullptr) {
                        current->right = new TreeNode(values[i]);
                        break;
                    } else current = current->right;
                    
                } else if (values[i] < current->key) {
                    if (current->left == nullptr) {
                        current->left = new TreeNode(values[i]);
                        break;
                    } else current = current->left;

                } else break;
            }
        }
        return;
    }

    void funcCall(string action) {
        if (action == "print") {
            print(root);
            cout << endl;

        } else if (action == "flip") {
            flip(root);

        } else if (action == "sum") {
            sum(root);
            unique(root);

        } else cout << "Wrong input\n";

        return;
    }

    void flip(TreeNode* current) {
        if (current == nullptr) return;

        flip(current->right);
        flip(current->left);
        
        TreeNode* temp = current->right;
        current->right = current->left;
        current->left = temp;
    }

    void sum(TreeNode* current) {
        if (current == nullptr) return;

        sum(current->left);
        sum(current->right);

        if (current->left != nullptr && current->right != nullptr) {
            current->key = current->left->key + current->right->key;

        } else if (current->left != nullptr) {
            current->key = current->left->key;

        } else if (current->right != nullptr) {
            current->key = current->right->key;
        }

        return;
    }

    void unique(TreeNode* current) {
        if (current == nullptr) return;

        unique(current->left);
        unique(current->right);

        if (current->left != nullptr && current->key == current->left->key) {
            TreeNode* temp = current->left;

            if (temp->left != nullptr) {
                current->left = temp->left;
            } else {
                current->left = temp->right;
            }

            delete temp;
        }

        if (current->right != nullptr && current->key == current->right->key) {
            TreeNode* temp = current->right;

            if (temp->left != nullptr) {
                current->right = temp->left;
            } else {
                current->right = temp->right;
            }

            delete temp;
        }
    }


    void print(TreeNode* current) {
        if (current == nullptr) return;

        print(current->left);
        cout << current->key << " ";
        print(current->right);

        return;
    }
};

int main() {
    BinaryTree tree;

    int actionsNum;
    cout << "Enter number of actions: ";
    cin >> actionsNum;

    while (actionsNum--) {
        string action;
        cout << "Enter action: ";
        cin >> action;

        if (action == "create") {
            int valuesNum;
            cout << "Enter number of values: ";
            cin >> valuesNum;

            int* values = new int[valuesNum];
            cout << "Enter values: ";
            for (int i = 0; i < valuesNum; i++) cin >> values[i];

            tree.create(values, valuesNum);
            delete[] values;

        } else tree.funcCall(action);
    }

    return 0;
}