#include <iostream>
using namespace std;

// Клас вузла дерева
template <typename T>
class TreeNode {
public:
    T value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
};

// Клас двійкового дерева пошуку
template <typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;
    int treeSize;

    // Допоміжна функція для вставки
    TreeNode<T>* insert(TreeNode<T>* node, T val) {
        if (!node) {
            treeSize++;
            return new TreeNode<T>(val);
        }
        if (val < node->value)
            node->left = insert(node->left, val);
        else if (val > node->value)
            node->right = insert(node->right, val);
        return node;
    }

    // Допоміжна функція для перевірки наявності елемента
    bool contains(TreeNode<T>* node, T val) const {
        if (!node) return false;
        if (val == node->value) return true;
        if (val < node->value) return contains(node->left, val);
        return contains(node->right, val);
    }

    // Допоміжна функція для друку дерева
    void print(TreeNode<T>* node, ostream& os) const {
        if (!node) return;
        print(node->left, os);
        os << node->value << " ";
        print(node->right, os);
    }

    // Допоміжна функція для видалення всіх вузлів дерева
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

    // Операція вставки
    void insert(T val) {
        root = insert(root, val);
    }

    // Операція перевірки наявності
    bool contains(T val) const {
        return contains(root, val);
    }

    // Отримання розміру
    int size() const {
        return treeSize;
    }

    // Перегрузка оператора <<
    friend ostream& operator<<(ostream& os, const BinarySearchTree<T>& tree) {
        tree.print(tree.root, os);
        return os;
    }
};

// Головна функція
int main() {
    int Q;
    cin >> Q;

    BinarySearchTree<int> bst;
    while (Q--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int value;
            cin >> value;
            bst.insert(value);
        } else if (command == "contains") {
            int value;
            cin >> value;
            cout << (bst.contains(value) ? "Yes" : "No") << endl;
        } else if (command == "size") {
            cout << bst.size() << endl;
        } else if (command == "print") {
            cout << bst << endl;
        }
    }

    return 0;
}
