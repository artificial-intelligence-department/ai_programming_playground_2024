#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };
    Node* root;
    size_t size(const Node* node) const {
        return node == nullptr ? 0 : 1 + size(node->left) + size(node->right);
    }
    void mirror_n(Node* node) {
        if (node == nullptr)
            return;

        swap(node->left, node->right);
        mirror_n(node->left);
        mirror_n(node->right);
    }
    T sum(Node* node) const {
        if (node == nullptr)
            return 0;

        T left_sum = sum(node->left);
        T right_sum = sum(node->right);

        return node->data + left_sum + right_sum;
    }
    void convert(Node* node) {
        if (node == nullptr)
            return;

        T left_sum = node->left ? sum(node->left) : 0;
        T right_sum = node->right ? sum(node->right) : 0;
        node->data = left_sum + right_sum;

        convert(node->left);
        convert(node->right);
    }
    Node* insert_n(Node* node, T value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert_n(node->left, value);
        else if (value > node->data)
            node->right = insert_n(node->right, value);
        return node;
    }
    bool find_n(const Node* node, const T& value) const {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;
        else if (value < node->data)
            return find_n(node->left, value);
        else
            return find_n(node->right, value);
    }
    void print(const Node* node) const {
        if (node == nullptr)
            return;

        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        clear(root);
    }
    void clear(Node* node) {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }
    size_t size() const {
        return size(root);
    }
    void insert(T value) {
        root = insert_n(root, value);
    }
    bool find(const T& value) const {
        return find_n(root, value);
    }
    void mirror() {
        mirror_n(root);
    }
    T sum_tree() const {
        return sum(root);
    }
    void convert() {
        convert(root);
    }
    void print() const {
        print(root);
        cout << endl;
    }
};

int main() {
    BinaryTree<int> tree;

    int values[] = {4, 1, 2, 3, 5, 6, 0};
    for (int value : values)
        tree.insert(value);

    cout << "Дерево: ";
    tree.print();

    cout << "Розмір дерева: " << tree.size() << endl;

    cout << "Сума вузлів: " << tree.sum_tree() << endl;

    tree.convert();
    cout << "Дерево після перетворення: ";
    tree.print();

    tree.mirror();
    cout << "Віддзеркалене дерево: ";
    tree.print();

    return 0;
}