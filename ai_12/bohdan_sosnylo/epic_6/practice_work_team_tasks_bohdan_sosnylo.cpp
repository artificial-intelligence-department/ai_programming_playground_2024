#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr) {}
};

Node* addNode(Node* head, const vector<int>& value) {
    if (value.empty()) return nullptr;
    Node* newNode = new Node(value[0]);
    head = newNode;
    Node* current = head;
    for (int i = 1; i < value.size(); i++) {
        Node* temp = new Node(value[i]);
        current->next = temp;
        current = temp;
    }
    return head;
}

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
    head = prev;
    return head;
}

bool compare(Node* head1, Node* head2) {
    Node* current1 = head1;
    Node* current2 = head2;
    while (current1 && current2) {
        if (current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return current1 == nullptr && current2 == nullptr;
}

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* tail = nullptr;
    int per = 0;

    while (n1 != nullptr || n2 != nullptr || per != 0) {
        int sum = per;

        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        per = sum / 10;
        int digit = sum % 10;

        Node* newNode = new Node(digit);

        if (result == nullptr) {
            result = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode; // Необхідно оновити tail
    }

    return result;
}

void printlist(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
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
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode(root->data);
    newNode->left = create_mirror_flip(root->right);
    newNode->right = create_mirror_flip(root->left);

    return newNode;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int treeSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    
    int leftSum = treeSum(root->left);
    int rightSum = treeSum(root->right);

    return root->data + leftSum + rightSum;
}

int main() {
    vector<int> list1_values = {2, 4, 3};
    vector<int> list2_values = {5, 6, 4};

    Node* list1 = nullptr;
    Node* list2 = nullptr;

    list1 = addNode(list1, list1_values);
    list2 = addNode(list2, list2_values);

    cout << "List 1: ";
    printlist(list1);

    cout << "List 2: ";
    printlist(list2);

    Node* result = add(list1, list2);

    cout << "Sum of List 1 and List 2: ";
    printlist(result);

    result = reverse(result);

    cout << "Reversed sum: ";
    printlist(result);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original Tree: ";
    printTree(root);
    cout << endl;

    TreeNode* mirroredRoot = create_mirror_flip(root);

    cout << "Mirrored Tree: ";
    printTree(mirroredRoot);
    cout << endl;

    cout << "Sum of Tree Nodes: " << treeSum(root) << endl;

    return 0;
}
