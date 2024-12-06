#include <iostream>
using namespace std;

// ��������� ��� ������
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// ��������� ��� ������
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ������ 1: ������ ������
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

// �������� ������� ��� ��������� ������
void printList(Node* head) {
	while (head != nullptr) { // ���� �� ����� ������
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ������ 2: ��������� ������
bool compare(Node* h1, Node* h2) {
	while (h1 != nullptr && h2 != nullptr) { // ���� ������ ������ �� ����������
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
	return h1 == nullptr && h2 == nullptr; // ��������, �� ������ ������ ����������
}

// ������ 3: ��������� ������� �����
Node* add(Node* n1, Node* n2) {
    Node* head = nullptr;
    Node* tail = nullptr;
    int carry = 0;

	while (n1 != nullptr || n2 != nullptr || carry != 0) {  // ���� � ����� ��� � ������������ �������
        int sum = carry;

        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

		carry = sum / 10; // ���������� �������
		Node* newNode = new Node(sum % 10); // ������� � ���������

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

// ������ 4: ³������������ ������
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

	TreeNode* left = create_mirror_flip(root->left); // ���������� ��������� ������������� ��� ����� ��������
	TreeNode* right = create_mirror_flip(root->right); // ���������� ��������� ������������� ��� ������� ��������

    root->left = right;
    root->right = left;

    return root;
}

// ������ 5: �������� ������� ������������ ����� ���� �������
int tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

	int leftSum = tree_sum(root->left); // ���� ����� ��������
	int rightSum = tree_sum(root->right); // ���� ������� ��������

	int totalSum = leftSum + rightSum; // ���� ��������

	if (root->left != nullptr || root->right != nullptr) { // ���� � �������
		root->data = totalSum; // �������� ���� ������� � ����������� �����
    }

    return totalSum + root->data;
}

// ������� ��� ��������� ������
void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

int main() {
    // ������ 1: ������ ������
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

    // ������ 2: ��������� ������
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

    // ������ 3: ��������� ������� �����
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

    // ������ 4: ³������������ ������
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

    // ������ 5: �������� ������� ������������ ����� ���� �������
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
