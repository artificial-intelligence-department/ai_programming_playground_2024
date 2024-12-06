#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {

private:
    Node* root;
    Node* insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {}

    return node;
}


    bool contains(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        }
        if (value < node->value) {
            return contains(node->left, value);
        }
        return contains(node->right, value);
    }

    int size(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + size(node->left) + size(node->right);
    }

    void printInOrder(Node* node, ostream& os) const {
        if (node != nullptr) {
            printInOrder(node->left, os);
            os << node->value << " ";
            printInOrder(node->right, os);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) {
        return contains(root, value);
    }

    int size() {
        return size(root);
    }

    friend ostream& operator<<(ostream& os, const BinarySearchTree& tree) {
        tree.printInOrder(tree.root, os);
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;

    BinarySearchTree tree;
    vector<string> results;

    for (int i = 0; i < Q; ++i) {
        string query;
        cin >> query;

        if (query == "insert") {
            int value;
            cin >> value;
            tree.insert(value);
        } else if (query == "contains") {
            int value;
            cin >> value;
            if (tree.contains(value)) {
                results.push_back("Yes");
            } else {
                results.push_back("No");
            }
        } else if (query == "size") {
            results.push_back(to_string(tree.size()));
        } else if (query == "print") {
            ostringstream os;
            os << tree;
            results.push_back(os.str());
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
