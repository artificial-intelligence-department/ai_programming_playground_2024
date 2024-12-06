#include <iostream>
using namespace std;

// Визначення структури для зв'язаного списку
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Визначення структури для бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Завдання №1 - Реверс списку
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Завдання №2 - Порівняння списків
bool compare(Node* h1, Node* h2) {
    bool identical = true;
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            cout << "Mismatch found: " << h1->data << " != " << h2->data << endl;
            identical = false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1 != nullptr || h2 != nullptr) {
        cout << "Lists are of different lengths." << endl;
        identical = false;
    }
    return identical;
}

void printComparison(Node* h1, Node* h2) {
    printList(h1);
    printList(h2);
    if (compare(h1, h2)) {
        cout << "Lists are identical" << endl;
    } else {
        cout << "Lists are different" << endl;
    }
}

// Завдання №3 - Додавання великих чисел
Node* add(Node* n1, Node* n2) {
    Node* dummy = new Node(0);
    Node* p = dummy;
    int carry = 0;

    cout << "Adding numbers: " << endl;
    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry;
        if (n1 != nullptr) {
            cout << n1->data << " ";
            sum += n1->data;
            n1 = n1->next;
        } else {
            cout << "0 ";
        }
        
        if (n2 != nullptr) {
            cout << "+ " << n2->data << " = ";
            sum += n2->data;
            n2 = n2->next;
        } else {
            cout << "+ 0 = ";
        }
        cout << sum % 10 << " (carry " << sum / 10 << ")" << endl;

        carry = sum / 10;
        p->next = new Node(sum % 10);
        p = p->next;
    }
    return dummy->next;
}

// Завдання №4 - Віддзеркалення дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* new_root = new TreeNode(root->val);
    new_root->left = create_mirror_flip(root->right);
    new_root->right = create_mirror_flip(root->left);
    return new_root;
}

// Завдання №5 - Записати кожному батьківському вузлу суму підвузлів
int tree_sum(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return root->val;

    int left_sum = tree_sum(root->left);
    int right_sum = tree_sum(root->right);
    int original_val = root->val;
    root->val = left_sum + right_sum;

    return original_val + root->val;
}

void printTree(TreeNode* root, int level = 0) {
    if (root == nullptr) return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; ++i) cout << "   ";
    cout << root->val << endl;
    printTree(root->left, level + 1);
}

int main() {
    // Демонстрація реверсу списку
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout << "Original list: ";
    printList(head);
    head = reverse(head);
    cout << "Reversed list: ";
    printList(head);

    // Порівняння двох списків
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(4);  // Місцева відмінність для демонстрації
    cout << "Comparison of lists:" << endl;
    printComparison(list1, list2);

    // Додавання великих чисел
    Node* num1 = new Node(2);
    num1->next = new Node(4);
    num1->next->next = new Node(3);
    Node* num2 = new Node(5);
    num2->next = new Node(6);
    num2->next->next = new Node(4);
    cout << "Numbers being added: ";
    printList(num1);
    printList(num2);
    Node* sum = add(num1, num2);
    cout << "Sum: ";
    printList(sum);

    // Віддзеркалення бінарного дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << "Original tree:" << endl;
    printTree(root);
    TreeNode* mirrored_root = create_mirror_flip(root);
    cout << "Mirrored tree:" << endl;
    printTree(mirrored_root);

    // Записати суму підвузлів
    tree_sum(root);
    cout << "Tree with sum of subnodes:" << endl;
    printTree(root);

    return 0;
}
