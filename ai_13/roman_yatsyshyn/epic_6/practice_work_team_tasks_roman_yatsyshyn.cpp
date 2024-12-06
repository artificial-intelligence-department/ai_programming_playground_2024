#include <iostream>
using namespace std;

// Structures
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Functions
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

bool compare(Node* h1, Node* h2) {
    while (h1 && h2) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (n1 || n2 || carry) {
        int sum = carry;
        if (n1) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2) {
            sum += n2->data;
            n2 = n2->next;
        }
        carry = sum / 10;
        sum = sum % 10;

        Node* newNode = new Node(sum);
        if (!result) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return result;
}

TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) return nullptr;

    TreeNode* newRoot = new TreeNode(root->data);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

int tree_sum(TreeNode* root) {
    if (!root) return 0;

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    if (root->left || root->right) {
        root->data = leftSum + rightSum;
    }
    return root->data + (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
}

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {

    // Задача 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original list: ";
    printList(head);

    head = reverse(head);

    cout << "Reversed list: ";
    printList(head);

    // Задача 2
    Node* h1 = new Node(1);
    h1->next = new Node(2);
    h1->next->next = new Node(3);

    Node* h2 = new Node(1);
    h2->next = new Node(2);
    h2->next->next = new Node(3);

    if (compare(h1, h2)) {
        cout << "Lists are equal." << endl;
    } else {
        cout << "Lists are not equal." << endl;
    }

    // Задача 3 
    Node* n1 = new Node(9);
    n1->next = new Node(7);
    n1->next->next = new Node(3);

    Node* n2 = new Node(6);
    n2->next = new Node(8);
    n2->next->next = new Node(5);

    Node* result = add(n1, n2);

    cout << "Sum: ";
    printList(result);

    // Задача 4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    TreeNode* mirror = create_mirror_flip(root);

    cout << "Mirror tree: ";
    printTree(mirror);
    cout << endl;

    // Задача 5
    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    tree_sum(root);

    cout << "Tree after sum computation: ";
    printTree(root);
    cout << endl;

    return 0;
}

