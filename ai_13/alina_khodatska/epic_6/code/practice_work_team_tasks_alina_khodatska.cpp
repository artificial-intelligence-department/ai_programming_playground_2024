#include <iostream>
using namespace std;

// Структура для списку
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Структура для дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Задача 1: Реверс списку
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

	while (curr != nullptr) { 
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Допоміжна функція для виведення списку
void printList(Node* head) {
	while (head != nullptr) { // Поки не кінець списку
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Задача 2: Порівняння списків
bool compare(Node* h1, Node* h2) {
	while (h1 != nullptr && h2 != nullptr) { // Поки обидва списки не закінчились
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
	return h1 == nullptr && h2 == nullptr; // Перевірка, чи обидва списки закінчились
}

// Задача 3: Додавання великих чисел
Node* add(Node* n1, Node* n2) {
    Node* head = nullptr;
    Node* tail = nullptr;
    int carry = 0;

	while (n1 != nullptr || n2 != nullptr || carry != 0) {  // Поки є цифри або є непереносима одиниця
        int sum = carry;

        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

		carry = sum / 10; // Переносима одиниця
		Node* newNode = new Node(sum % 10); // Одиниця в результаті

        if (head == nullptr) {
            head = newNode;
            tail = head;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

// Задача 4: Віддзеркалення дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

	TreeNode* left = create_mirror_flip(root->left); // Рекурсивно створюємо віддзеркалення для лівого піддерева
	TreeNode* right = create_mirror_flip(root->right); // Рекурсивно створюємо віддзеркалення для правого піддерева

    root->left = right;
    root->right = left;

    return root;
}

// Задача 5: Записати кожному батьківському вузлу суму підвузлів
int tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

	int leftSum = tree_sum(root->left); // Сума лівого піддерева
	int rightSum = tree_sum(root->right); // Сума правого піддерева

	int totalSum = leftSum + rightSum; // Сума піддерева

	if (root->left != nullptr || root->right != nullptr) { // Якщо є підвузли
		root->data = totalSum; // Записуємо суму підвузлів у батьківський вузол
    }

    return totalSum + root->data;
}

// Функція для виведення дерева
void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

int main() {
    // Задача 1: Реверс списку
    cout << "Task 1: \n";
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    head = reverse(head);

    cout << "Reversed list: ";
    printList(head);
    cout << endl;

    // Задача 2: Порівняння списків
    cout << "Task 2: \n";
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    if (compare(head, head2)) {
        cout << "Lists are equal" << endl;
    }
    else {
        cout << "Lists are not equal" << endl;
    }
    cout << endl;

    // Задача 3: Додавання великих чисел
    cout << "Task 3: \n";
    Node* n1 = new Node(9);
    n1->next = new Node(7);
    n1->next->next = new Node(3); // 379

    Node* n2 = new Node(1);
    n2->next = new Node(8); // 81

    Node* result = add(n1, n2);

    cout << "Sum: ";
    printList(result);
    cout << endl;

    // Задача 4: Віддзеркалення дерева
    cout << "Task 4: \n";
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    root = create_mirror_flip(root);

    cout << "Mirrored tree: ";
    printTree(root);
    cout << endl;

    // Задача 5: Записати кожному батьківському вузлу суму підвузлів
    cout << "Task 5: \n";
    TreeNode* treeRoot = new TreeNode(10);
    treeRoot->left = new TreeNode(5);
    treeRoot->right = new TreeNode(15);
    treeRoot->left->left = new TreeNode(3);
    treeRoot->left->right = new TreeNode(7);

    cout << "Original tree: ";
    printTree(treeRoot);
    cout << endl;

    tree_sum(treeRoot);

    cout << "Tree after summing subtrees: ";
    printTree(treeRoot);
    cout << endl;

    return 0;
}
