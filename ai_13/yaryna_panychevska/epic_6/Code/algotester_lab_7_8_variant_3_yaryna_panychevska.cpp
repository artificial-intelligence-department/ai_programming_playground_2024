#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int Value;
    TreeNode* Right;
    TreeNode* Left;

    TreeNode(int v) {
        Value = v;
        Right = NULL;
        Left = NULL;
    }
};

struct BinarySearchTree {
public:
    BinarySearchTree() : Root(NULL) {}

    void insert(int v) {
        Root = insert(Root, v);
    }

    void contains(int v) {
        contains(Root, v);
    }

    int size() {
        return size(Root);
    }

    friend ostream& operator<<(ostream& cout, const BinarySearchTree& tree) {
        tree.print(tree.Root, cout);
        cout << endl;
        return cout;
    }

private:
    TreeNode* Root;

    TreeNode* insert(TreeNode* Node, int v) {
        if (Node == NULL) {
            return new TreeNode(v);
        }

        if (v < Node->Value) {
            Node->Left = insert(Node->Left, v);
        }
        else if (v > Node->Value) {
            Node->Right = insert(Node->Right, v);
        }

        return Node;
    }

    void contains(TreeNode* Node, int v) {
        if (Node == NULL) {
            cout << "No" << endl;
            return;
        }

        if (Node->Value == v) {
            cout << "Yes" << endl;
            return;
        }

        if (v > Node->Value) {
            contains(Node->Right, v);
        }
        else {
            contains(Node->Left, v);
        }
    }

    int size(TreeNode* Node) const {
        if (Node == NULL) {
            return 0;
        }
        return 1 + size(Node->Left) + size(Node->Right);
    }

    void print(TreeNode* Node, ostream& cout) const {
        if (Node != NULL) {
            print(Node->Left, cout);
            cout << Node->Value << " ";
            print(Node->Right, cout);
        }
    }
};

int main() {
    BinarySearchTree myTree;

    int actions;
    cin >> actions;

    for (int i = 0; i < actions; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            int value;
            cin >> value;
            myTree.insert(value);
        }
        else if (command == "contains") {
            int searchvalue;
            cin >> searchvalue;
            myTree.contains(searchvalue);
        }
        else if (command == "size") {
            cout << myTree.size() << endl;
        }
        else if (command == "print") {
            cout << myTree;
        }
    }

    return 0;
}

