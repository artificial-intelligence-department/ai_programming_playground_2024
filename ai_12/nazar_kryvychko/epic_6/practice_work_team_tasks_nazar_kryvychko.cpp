#include <iostream>

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse the linked list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev and current one step forward
        current = next;
    }
    return prev;  // New head of the reversed list
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to compare two linked lists
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false; // Data mismatch
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr; // Both must reach the end
}

// Function to add two large numbers represented as linked lists
Node* add(Node* n1, Node* n2) {
    Node dummy(0);  // Dummy node to simplify the process
    Node* current = &dummy;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry) {
        int sum = carry;
        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }
        carry = sum / 10; // Update carry
        current->next = new Node(sum % 10); // Create new node
        current = current->next;
    }
    return dummy.next; // Return the next node to dummy
}

// TreeNode structure for binary tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to create a mirrored (flipped) copy of the tree
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode* new_root = new TreeNode(root->value);
    new_root->left = create_mirror_flip(root->right);
    new_root->right = create_mirror_flip(root->left);

    return new_root;
}

// Function to print tree nodes in in-order traversal
void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        std::cout << root->value << " ";
        printTree(root->right);
    }
}

// Function to update tree nodes' values as the sum of their subtrees
void tree_sum(TreeNode* root) {
    if (root == nullptr) return;

    int left_sum = 0;
    int right_sum = 0;

    if (root->left != nullptr) {
        left_sum += root->left->value;
    }
    if (root->right != nullptr) {
        right_sum += root->right->value;
    }

    tree_sum(root->left);
    tree_sum(root->right);

    if(!root->left && !root->right) return; 
    root->value = left_sum + right_sum;
}

int main() {
    // Linked List Operations
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    std::cout << "Original Linked List: ";
    printList(head);

    head = reverse(head);
    std::cout << "Reversed Linked List: ";
    printList(head);

    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);

    std::cout << "Are lists equal? " << (compare(list1, list2) ? "Yes" : "No") << std::endl;

    list2->next->next->data = 4;
    std::cout << "Are lists equal after modification? " << (compare(list1, list2) ? "Yes" : "No") << std::endl;

    Node* num1 = new Node(9);
    num1->next = new Node(9);
    num1->next->next = new Node(9);

    Node* num2 = new Node(1);
    num2->next = new Node(0);
    num2->next->next = new Node(0); 

    Node* sum = add(num1, num2);
    std::cout << "Sum of numbers: ";
    printList(sum); 

    // Binary Tree Operations

    //structure:
    //       1
    //     /   \
    //    2     3
    //   / \
    //  4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Original Tree: ";
    printTree(root);
    std::cout << std::endl;

    TreeNode* mirroredRoot = create_mirror_flip(root);
    std::cout << "Mirrored Tree: ";
    printTree(mirroredRoot);
    std::cout << std::endl;


    // structure:
    //       1
    //     /   \
    //    2     3
    //   / \
    //  4   5
    TreeNode* sumTreeRoot = new TreeNode(1);
    sumTreeRoot->left = new TreeNode(2);
    sumTreeRoot->right = new TreeNode(3);
    sumTreeRoot->left->left = new TreeNode(4);
    sumTreeRoot->left->right = new TreeNode(5);

    std::cout << "Tree before summing: ";
    printTree(sumTreeRoot);
    std::cout << std::endl;

    tree_sum(sumTreeRoot);
    std::cout << "Tree after summing subtrees: ";
    printTree(sumTreeRoot);
    std::cout << std::endl;

    return 0;
}
