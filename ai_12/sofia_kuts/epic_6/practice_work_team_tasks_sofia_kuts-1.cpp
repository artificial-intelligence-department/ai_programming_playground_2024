#include <iostream>
using namespace std;
// Структура для зв'язаного списку
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

// Структура для бінарного дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

// завдання №1

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// завдання №2

bool compare(Node* h1, Node* h2) {
    while (h1 != NULL && h2 != NULL) {
        if (h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == NULL && h2 == NULL;
}

// завдання №3

Node* add(Node* n1, Node* n2) {
    Node* result = NULL;
    Node* tail = NULL;
    int carry = 0;

    while (n1 != NULL || n2 != NULL || carry) {
        int sum = carry;
        if (n1 != NULL) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != NULL) {
            sum += n2->data;
            n2 = n2->next;
        }

        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        if (result == NULL) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return result;
}

// завдання №4

TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) return NULL;

    TreeNode* newRoot = new TreeNode(root->data);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

// завдання №5

int tree_sum(TreeNode* root) {
    if (!root) return 0;

    if (!root->left && !root->right) return root->data;

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    root->data += leftSum + rightSum;

    return root->data;
}

int main() {
    
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    cout << "Вихідний список: ";
    printList(head1);
    head1 = reverse(head1);
    cout << "Реверсований список: ";
    printList(head1);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    cout << "Списки однакові? " << (compare(head1, head2) ? "Так" : "Ні") << endl;

    Node* num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    Node* num2 = new Node(6);
    num2->next = new Node(4);
    num2->next->next = new Node(8);

    cout << "Число 1: ";
    printList(num1);
    cout << "Число 2: ";
    printList(num2);

    Node* sum = add(num1, num2);
    cout << "Сума: ";
    printList(sum);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Оригінальне дерево: ";
    printTree(root);
    cout << endl;

    TreeNode* mirrored = create_mirror_flip(root);
    cout << "Віддзеркалене дерево: ";
    printTree(mirrored);
    cout << endl;

    tree_sum(root);
    cout << "Дерево з сумами: ";
    printTree(root);
    cout << endl;

    return 0;
}
