#include <iostream>
#include <vector>
using namespace std;

//структура вузла списку
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

//вставка вузлів у список
Node* insert(Node* head, const vector<int>& values) {
    Node* current = nullptr;
    for (int value : values) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}

//виведення списку
void printLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//реверс списку
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

//порівняння списків
bool compare(Node* head1, Node* head2) {
    while (head1 && head2) {
        if (head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == nullptr && head2 == nullptr;
}

//додавання великих чисел
Node* add(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    int carry = 0;
    while (head1 || head2 || carry) {
        int sum = carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
    }
    return dummy->next;
}

//структура вузла дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

//віддзеркалення дерева
TreeNode* createMirrorFlip(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* newNode = new TreeNode(root->data);
    newNode->left = createMirrorFlip(root->right);
    newNode->right = createMirrorFlip(root->left);
    return newNode;
}

//обхід і виведення дерева
void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

//запис суми підвузлів
int treeSum(TreeNode* root) {
    if (!root) return 0;
    int leftSum = treeSum(root->left);
    int rightSum = treeSum(root->right);
    if (root->left || root->right) root->data = leftSum + rightSum;
    return root->data;
}

int main() {
    //завдання 1: реверс списку
    vector<int> values = {1, 2, 3, 4, 5};
    Node* list = insert(nullptr, values);
    cout << "Original list: ";
    printLL(list);
    Node* reversed = reverse(list);
    cout << "Reversed list: ";
    printLL(reversed);

    //завдання 2: порівняння списків
    cout << "Lists are " << (compare(list, reversed) ? "identical" : "different") << endl;

    //завдання 3: додавання великих чисел
    Node* num1 = insert(nullptr, {9, 9, 9});
    Node* num2 = insert(nullptr, {1});
    Node* sum = add(num1, num2);
    cout << "Sum of numbers: ";
    printLL(sum);

    //завдання 4: віддзеркалення дерева
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    cout << "Original tree: ";
    printTree(root);
    cout << endl;
    TreeNode* mirrored = createMirrorFlip(root);
    cout << "Mirrored tree: ";
    printTree(mirrored);
    cout << endl;

    //завдання 5: сума підвузлів
    cout << "Tree before sum update: ";
    printTree(root);
    cout << endl;
    treeSum(root);
    cout << "Tree after sum update: ";
    printTree(root);
    cout << endl;

    return 0;
}
