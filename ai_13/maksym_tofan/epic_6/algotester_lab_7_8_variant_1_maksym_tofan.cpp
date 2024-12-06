#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Операції для роботи з деревом
enum Command {
    ADD,
    TREE_SIZE,
    DISPLAY,
    SEARCH,
    INVALID
};

// Функція для отримання операції на основі команди
Command getCommand(const string& command) {
    if (command == "insert") return ADD;
    if (command == "size") return TREE_SIZE;
    if (command == "print") return DISPLAY;
    if (command == "contains") return SEARCH;
    return INVALID;
}

template<typename T = int>
class BinaryTree {
private:
    // Вузол дерева
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;
    int totalElements;

    // Рекурсивне знищення дерева
    void deleteTree(TreeNode* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    // Рекурсивна вставка елемента в дерево
    void addNode(TreeNode* node, T value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
                totalElements++;
            } else {
                addNode(node->left, value);
            }
        } else if (value > node->data) {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
                totalElements++;
            } else {
                addNode(node->right, value);
            }
        }
    }

    // Рекурсивний пошук елемента в дереві
    bool findNode(TreeNode* node, T value) {
        if (node == nullptr) return false;
        if (value == node->data) return true;
        if (value < node->data) return findNode(node->left, value);
        return findNode(node->right, value);
    }

    // Виведення дерева 
    void inOrderDisplay(TreeNode* node, ostream& os) const {
        if (node != nullptr) {
            inOrderDisplay(node->left, os);
            os << node->data << " ";
            inOrderDisplay(node->right, os);
        }
    }

public:
    BinaryTree() : root(nullptr), totalElements(0) {}

    ~BinaryTree() {
        deleteTree(root);
    }

    // Додавання елемента в дерево
    void insert(T value) {
        if (root == nullptr) {
            root = new TreeNode(value);
            totalElements++;
        } else {
            addNode(root, value);
        }
    }

    // Пошук елемента в дереві
    bool contains(T value) {
        return findNode(root, value);
    }

    // Отримання розміру дерева
    int size() const {
        return totalElements;
    }

   
    friend ostream& operator<<(ostream& os, const BinaryTree& tree) {
        tree.inOrderDisplay(tree.root, os);
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;
    BinaryTree<int> tree;

    // Обробка запитів
    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        Command operation = getCommand(command);

        switch (operation) {
            case ADD: {
                int value;
                cin >> value;
                tree.insert(value);
                break;
            }
            case TREE_SIZE: {
                cout << tree.size() << endl;
                break;
            }
            case SEARCH: {
                int value;
                cin >> value;
                cout << (tree.contains(value) ? "Yes" : "No") << endl;
                break;
            }
            case DISPLAY: {
                cout << tree << endl;
                break;
            }
            default:
                break;
        }
    }
}
