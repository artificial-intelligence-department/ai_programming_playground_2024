#include <iostream>
#include <string>

using namespace std;

// Шаблонний клас вузла дерева
template <typename T>
struct TreeNode {
    T value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
};

// Шаблонний клас двійкового дерева пошуку
template <typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;
    int treeSize;

    // Рекурсивна функція вставки
    TreeNode<T>* insert(TreeNode<T>* node, T value) {
        if (!node) {
            treeSize++;
            return new TreeNode<T>(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Рекурсивна функція пошуку
    bool contains(TreeNode<T>* node, T value) const {
        if (!node) return false;
        if (value == node->value) return true;
        if (value < node->value) return contains(node->left, value);
        return contains(node->right, value);
    }

    // Рекурсивна функція для інфіксного обходу
    void inorder(TreeNode<T>* node, ostream& os) const {
        if (!node) return;
        inorder(node->left, os);
        os << node->value << " ";
        inorder(node->right, os);
    }

    // Рекурсивне видалення дерева
    void clear(TreeNode<T>* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    // Конструктор
    BinarySearchTree() : root(nullptr), treeSize(0) {}

    // Деструктор
    ~BinarySearchTree() {
        clear(root);
    }

    // Функція вставки
    void insert(T value) {
        root = insert(root, value);
    }

    // Функція пошуку
    bool contains(T value) const {
        return contains(root, value);
    }

    // Функція визначення розміру
    int size() const {
        return treeSize;
    }

    // Перевантаження оператора виведення
    friend ostream& operator<<(ostream& os, const BinarySearchTree& tree) {
        tree.inorder(tree.root, os);
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;

    BinarySearchTree<int> bst;

    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            int value;
            cin >> value;
            bst.insert(value);
        } else if (command == "contains") {
            int value;
            cin >> value;
            if (bst.contains(value)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (command == "size") {
            cout << bst.size() << endl;
        } else if (command == "print") {
            cout << bst << endl;
        }
    }

    return 0;
}
