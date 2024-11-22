#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev; 
}
bool compare(Node* h1, Node* h2) {
    while (h1 && h2) {
        if (h1->data != h2->data) return false;
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
        int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry;
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
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
struct TreeNode {   //  вузол дерева
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) return nullptr;

    TreeNode* newRoot = new TreeNode(root->data);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}
int tree_sum(TreeNode* root) {
    if (!root) return 0;

    if (!root->left && !root->right) return root->data;

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    root->data += leftSum + rightSum;
    return root->data;
}
void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    Node* reversedHead = reverse(head);
    cout << "Reversed list: ";
    printList(reversedHead);

    // Задача 2: Порівняння списків
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);

    cout << "Are lists equal? " << (compare(list1, list2) ? "Yes" : "No") << endl;

    Node* num1 = new Node(9);     // Додавання великих чисел
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    Node* num2 = new Node(6);
    num2->next = new Node(4);
    num2->next->next = new Node(5);

    Node* sumList = add(num1, num2);
    cout << "Sum of numbers: ";
    printList(sumList);

    TreeNode* tree = new TreeNode(1);   //  Віддзеркалення дерева
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);

    cout << "Original tree (pre-order): ";
    printTree(tree);
    cout << endl;

    TreeNode* mirroredTree = create_mirror_flip(tree);
    cout << "Mirrored tree (pre-order): ";
    printTree(mirroredTree);
    cout << endl;

    tree_sum(tree);                                         // Додавання сум підвузлів
    cout << "Tree with subtree sums (pre-order): ";
    printTree(tree);
    cout << endl;

    return 0;
}
