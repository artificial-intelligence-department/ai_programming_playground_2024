#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

enum Operation {
    INSERT,
    SIZE,
    PRINT,
    CONTAINS,
    UNKNOWN
};

Operation getOperation(const string& command) {
    if (command == "insert") return
         INSERT;
    if (command == "size") return 
        SIZE;
    if (command == "print") return 
        PRINT;
    if (command == "contains") return 
        CONTAINS;
    return UNKNOWN;
}

template<typename T = int>
class binaryTree {
private:
    struct Node {
        T wid;
        Node* left;
        Node* right;
        Node(T val) : wid(val), left(nullptr), right(nullptr) {}
    };

    Node* kor;
    int killusl;

   
    void insertRecursively(Node* node, T wid) {
        if (wid < node->wid) {
            if (node->left == nullptr) {
                node->left = new Node(wid);
                killusl++;
            } else {
                insertRecursively(node->left, wid);
            }
        } else if (wid > node->wid) {
            if (node->right == nullptr) {
                node->right = new Node(wid);
                killusl++;
            } else {
                insertRecursively(node->right, wid);
            }
        }
    }

    bool containsRecursively(Node* node, T wid) {
        if (node == nullptr) 
            return false;
        if (wid == node->wid) 
            return true;
        if (wid < node->wid) 
            return containsRecursively(node->left, wid);
        return containsRecursively(node->right, wid);
    }

    void printTree(Node* node, ostream& os) const {
        if (node != nullptr) {
            printTree(node->left, os);
            os << node->wid << " ";
            printTree(node->right, os);
        }
    }

public:
    binaryTree() : kor(nullptr), killusl(0) {}

   

    void insert(T wid) {
        if (kor == nullptr) {
            kor = new Node(wid);
            killusl++;
        } else {
            insertRecursively(kor, wid);
        }
    }

    bool contains(T wid) {
        return containsRecursively(kor, wid);
    }

    int getSize() const {
        return killusl;
    }

    
    friend ostream& operator<<(ostream& os, const binaryTree& tree) {
        tree.printTree(tree.kor, os);
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;
    binaryTree<int> tree;

    for (int i = 0; i < Q; i++) {
        string option;
        cin >> option;
        Operation operation = getOperation(option);

        switch (operation) {
            case INSERT: {
                int wid;
                cin >> wid;
                tree.insert(wid);
                break;
            }
            case SIZE: {
                cout << tree.getSize() << endl;
                break;
            }
            case CONTAINS: {
                int wid;
                cin >> wid;
                cout << (tree.contains(wid) ? "Yes" : "No") << endl;
                break;
            }
            case PRINT: {
                cout << tree << endl;
                break;
            }
            default:
                break;
        }
    }
}
