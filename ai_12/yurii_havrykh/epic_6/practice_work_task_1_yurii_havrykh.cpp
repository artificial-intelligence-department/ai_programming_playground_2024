#include <iostream>
#include<math.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {

public:
    Node *head;

    LinkedList() {
        size = 0;
        head = nullptr;
    }

    ~LinkedList() {
        Node *current = head;
        while (current) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void init(int listSize, int values[]);

    void reverse();

    int add();

    void print();

private:

    int size;
};

void LinkedList::init(int listSize, int values[]) {

    Node *current = new Node(values[0]);
    head = current;
    for (int j = 1; j < listSize; j++) {
        Node *newNode = new Node(values[j]);
        current->next = newNode;
        current = newNode;
        size++;
    }
}

void LinkedList::reverse() {
    Node *prev = head;
    Node *current = prev->next;
    prev->next = nullptr;
    Node *nextNode = current->next;
    while (nextNode) {
        current->next = prev;
        prev = current;
        current = nextNode;
        nextNode = current->next;
    }
    current->next = prev;
    head = current;
}

int LinkedList::add() {
    int rez = 0;
    int digit = 0;
    Node *current = head;
    while (current) {
        rez += current->data * pow(10, digit);
        current = current->next;
        digit++;
    }
    return rez;
}

void LinkedList::print() {
    printf("Head: %d\n", head->data);
    Node *current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

bool compare(Node *h1, Node *h2) {
    while ((h1 != nullptr) && (h2 != nullptr)) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if ((h1 == h2) && (h2 == nullptr))
        return true;
    else
        return false;
}

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode* new_root = new TreeNode(root->value);
    new_root->left = create_mirror_flip(root->right);
    new_root->right = create_mirror_flip(root->left);

    return new_root;
}

void tree_sum(TreeNode* root) {
    if (root == nullptr) return;

    int left_sum = 0;
    int right_sum = 0;

    tree_sum(root->left);
    tree_sum(root->right);

    if (root->left != nullptr) {
        left_sum += root->left->value;
    }
    if (root->right != nullptr) {
        right_sum += root->right->value;
    }


    if(!root->left && !root->right) return;
    root->value = left_sum + right_sum;
}

void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->value << " ";
        printTree(root->right);
    }
}

int main() {
    //Linked List
    LinkedList list_1;
    int size_1 = 4;
    int elements[] = {1, 2, 3, 4};
    list_1.init(size_1, elements);
    cout << "ll1:" << endl;
    list_1.print();
    list_1.reverse();
    cout << "Reversed ll1:" << endl;
    list_1.print();

    LinkedList list_2;
    int size_2 = 4;
    int elements2[] = {4, 3, 2, 1};
    list_2.init(size_2, elements2);
    cout << "ll2:" << endl;
    list_2.print();

    bool is_equal = compare(list_1.head, list_2.head);
    if (is_equal)
        cout << "lists are equal" << endl;
    else
        cout << "Lists aren't equal" << endl;
    cout << "sum of ll1: " << list_1.add() << endl;

    //TREE

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(5);

    cout << "Tree: ";
    printTree(root);
    cout << endl;

    TreeNode* mirroredRoot = create_mirror_flip(root);
    cout << "Mirrored Tree: ";
    printTree(mirroredRoot);
    cout << endl;

    TreeNode* sumTreeRoot = new TreeNode(2);
    sumTreeRoot->left = new TreeNode(1);
    sumTreeRoot->right = new TreeNode(4);
    sumTreeRoot->right->left = new TreeNode(3);
    sumTreeRoot->right->right = new TreeNode(5);

    cout << "Tree before summing: ";
    printTree(sumTreeRoot);
    cout << endl;

    tree_sum(sumTreeRoot);
    cout << "Tree after summing: ";
    printTree(sumTreeRoot);
    cout << endl;

    return 0;
}
