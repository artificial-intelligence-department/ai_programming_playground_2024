#include <iostream>
using namespace std;

// ------------------------------------
// Задача 1 - Реверс списку
// ------------------------------------
struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// ------------------------------------
// Задача 2 - Порівняння списків
// ------------------------------------
bool compare(Node* h1, Node* h2) {
    while (h1 && h2) {
        if (h1->value != h2->value) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

// ------------------------------------
// Задача 3 - Додавання великих чисел
// ------------------------------------
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (n1 || n2 || carry) {
        int sum = carry + (n1 ? n1->value : 0) + (n2 ? n2->value : 0);
        carry = sum / 10;
        Node* newNode = new Node(sum % 10);

        if (!result) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    return result;
}

// ------------------------------------
// Задача 4 - Віддзеркалення дерева
// ------------------------------------
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* newRoot = new TreeNode(root->value);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);
    return newRoot;
}

// ------------------------------------
// Задача 5 - Сума підвузлів
// ------------------------------------
int calculateSum(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->value;

    int leftSum = calculateSum(root->left);
    int rightSum = calculateSum(root->right);
    root->value = leftSum + rightSum;

    return root->value;
}

void tree_sum(TreeNode* root) {
    calculateSum(root);
}

// ------------------------------------
// Основна програма
// ------------------------------------
int main() {
    // Задача 1: Реверс списку
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original List: ";
    printList(head);

    Node* reversed = reverse(head);
    cout << "Reversed List: ";
    printList(reversed);

    // Задача 2: Порівняння списків
    Node* list1 = new Node(1);
    list1->next = new Node(2);

    Node* list2 = new Node(1);
    list2->next = new Node(2);

    cout << "Lists are " << (compare(list1, list2) ? "equal" : "not equal") << endl;

    // Задача 3: Додавання великих чисел
    Node* num1 = new Node(3);
    num1->next = new Node(7);
    num1->next->next = new Node(9);

    Node* num2 = new Node(9);
    num2->next = new Node(2);

    Node* sumList = add(num1, num2);
    cout << "Sum List: ";
    printList(sumList);

    // Задача 4: Віддзеркалення дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode* mirrored = create_mirror_flip(root);
    cout << "Original Tree Root: " << root->value << ", Mirrored Tree Root: " << mirrored->value << endl;

    // Задача 5: Сума підвузлів
    tree_sum(root);
    cout << "Root Value After Summing: " << root->value << endl;

    return 0;
}
