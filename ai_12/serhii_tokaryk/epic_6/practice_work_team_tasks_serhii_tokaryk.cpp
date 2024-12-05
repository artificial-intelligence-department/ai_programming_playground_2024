#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* previous = nullptr;
    Node* current = head;
    Node* following = nullptr;
    while (current != nullptr) {
        following = current->next;
        current->next = previous;
        previous = current;
        current = following;
    }
    return previous;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool listsEqual(Node* h1, Node* h2) {
    while (h1 && h2) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

Node* addLists(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node** tail = &result;
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
        *tail = new Node(sum % 10);
        tail = &((*tail)->next);
    }
    return result;
}

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* mirrorTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    TreeNode* mirrored = new TreeNode(root->data);
    mirrored->left = mirrorTree(root->right);
    mirrored->right = mirrorTree(root->left);
    return mirrored;
}

void printTree(TreeNode* root) {
    if (root) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

TreeNode* insertIntoTree(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }
    if (value < root->data) {
        root->left = insertIntoTree(root->left, value);
    } else {
        root->right = insertIntoTree(root->right, value);
    }
    return root;
}

int calculateSubtreeSum(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;
    int leftSum = calculateSubtreeSum(root->left);
    int rightSum = calculateSubtreeSum(root->right);
    root->data = leftSum + rightSum;
    return root->data;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    append(list1, 1);
    append(list1, 2);
    append(list1, 3);
    append(list2, 1);
    append(list2, 2);
    append(list2, 3);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    cout << (listsEqual(list1, list2) ? "Lists are identical" : "Lists are different") << endl;

    list1 = reverseList(list1);
    cout << "Reversed List 1: ";
    printList(list1);

    Node* sumList = addLists(list1, list2);
    cout << "Sum List: ";
    printList(sumList);

    TreeNode* root = nullptr;
    root = insertIntoTree(root, 4);
    root = insertIntoTree(root, 2);
    root = insertIntoTree(root, 6);
    root = insertIntoTree(root, 1);
    root = insertIntoTree(root, 3);
    root = insertIntoTree(root, 5);
    root = insertIntoTree(root, 7);

    cout << "Original Tree: ";
    printTree(root);
    cout << endl;

    calculateSubtreeSum(root);
    cout << "Tree after subtree sums: ";
    printTree(root);
    cout << endl;

    return 0;
}
