#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* reverse(Node* head) 
{
    Node* prev = nullptr;
    Node* current = head;

    while (current) 
    {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
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

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int val1 = (n1 != nullptr) ? n1->data : 0;
        int val2 = (n2 != nullptr) ? n2->data : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        Node* newNode = new Node(digit);
        if (result == nullptr) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (n1 != nullptr) {
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            n2 = n2->next;
        }
    }

    return result;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) {
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->data);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

int tree_sum(TreeNode* root) 
{
    if (!root) 
    {
        return 0;
    }

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    root->data += leftSum + rightSum;
    return root->data;
}

void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main() {
    // Робота з однозв’язними списками
    Node* list1 = new Node(2);
    list1->next = new Node(4);
    list1->next->next = new Node(3);

    Node* list2 = new Node(5);
    list2->next = new Node(6);
    list2->next->next = new Node(4);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Node* sumList = add(list1, list2);
    cout << "Sum of List 1 and List 2: ";
    printList(sumList);

    cout << "Are List 1 and List 2 equal? " << (compare(list1, list2) ? "Yes" : "No") << endl;

    Node* reversedList1 = reverse(list1);
    cout << "Reversed List 1: ";
    printList(reversedList1);

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->left = new TreeNode(1);

    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << "\nOriginal Tree: ";
    printTree(root);

    TreeNode* mirroredRoot = create_mirror_flip(root);
    cout << "\nMirrored Tree: ";
    printTree(mirroredRoot);

    tree_sum(root);
    cout << "\nTree after subtree sums (Preorder): ";
    printTree(root);

    return 0;
}

