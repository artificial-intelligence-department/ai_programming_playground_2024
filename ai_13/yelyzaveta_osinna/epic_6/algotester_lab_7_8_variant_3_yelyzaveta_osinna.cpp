#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Вузол дерева
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// Клас двійкового дерева пошуку
class BinarySearchTree {
private:
    Node* root;
    int tree_size;

    // Вставка елемента
    Node* insert(Node* node, int value) {
        if (!node) {
            tree_size++;
            return new Node(value);
        }
        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        return node;
    }

    // Перевірка наявності елемента
    bool contains(Node* node, int value) const {
        if (!node) return false;
        if (node->value == value) return true;
        if (value < node->value)
            return contains(node->left, value);
        return contains(node->right, value);
    }

    // Рекурсивний обхід дерева для виводу
    void inOrderTraversal(Node* node, ostream& out) const {
        if (!node) return;
        inOrderTraversal(node->left, out);
        out << node->value << " ";
        inOrderTraversal(node->right, out);
    }

public:
    BinarySearchTree() : root(nullptr), tree_size(0) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) const {
        return contains(root, value);
    }

    int size() const {
        return tree_size;
    }

    friend ostream& operator<<(ostream& out, const BinarySearchTree& tree) {
        tree.inOrderTraversal(tree.root, out);
        return out;
    }
};

int main() {
    int Q;
    cin >> Q;
    BinarySearchTree bst;
    ostringstream output; // Буфер для збереження результатів

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
            output << (bst.contains(value) ? "Yes" : "No") << endl;
        } else if (command == "size") {
            output << bst.size() << endl;
        } else if (command == "print") {
            output << bst << endl;
        }
    }

    // Вивід зібраних результатів одним блоком
    cout  << "\n" << output.str();

    return 0;
}
