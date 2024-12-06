#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if (value < root->value)
        insert(root->left, value);
    else if (value > root->value) 
        insert(root->right, value);
}

bool search(Node* root, int value) {
    if (root == nullptr)
        return false;
    if (value == root->value)
        return true;
    else if (value < root->value)
        return search(root->left, value);
    else
        return search(root->right, value);
}

int size(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

void print(Node* root) {
    if (root == nullptr)
        return;
    print(root->left);
    cout << root->value << " ";
    print(root->right);
}

int main() {
    int Q;
    cin >> Q;
    Node* root = nullptr;

    while (Q--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int value;
            cin >> value;
            insert(root, value);
        } else if (command == "contains") {
            int value;
            cin >> value;
            if (search(root, value)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else if (command == "size") {
            cout << size(root) << endl;
        } else if (command == "print") {
            print(root);
            cout << endl;
        }
    }

    return 0;
}
