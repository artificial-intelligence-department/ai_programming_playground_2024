
#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr)
    {
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr)
    {
    }
};

// Task 1: Reverse a linked list
Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Task 2: Compare two linked lists
bool compare(Node *h1, Node *h2)
{
    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->data != h2->data)
            return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

// Task 3: Add two large numbers represented by linked lists
Node *add(Node *n1, Node *n2)
{
    Node *dummyHead = new Node(0);
    Node *current = dummyHead;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0)
    {
        int sum = carry;
        if (n1 != nullptr)
        {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr)
        {
            sum += n2->data;
            n2 = n2->next;
        }
        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }

    return dummyHead->next;
}

// Task 4: Create a mirror flip of a binary tree
TreeNode *create_mirror_flip(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    TreeNode *newRoot = new TreeNode(root->val);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

void printTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

// Task 5: Update each parent node with the sum of its child nodes
int calculateSums(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftSum = calculateSums(root->left);
    int rightSum = calculateSums(root->right);

    if (root->left || root->right)
        root->val = leftSum + rightSum;

    return root->val + (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
}

void tree_sum(TreeNode *root)
{
    calculateSums(root);
}

// Main function to demonstrate all tasks
int main()
{
    // Task 1: Reverse a linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    std::cout << "Original list: ";
    printList(head);
    head = reverse(head);
    std::cout << "Reversed list: ";
    printList(head);

    // Task 2: Compare two linked lists
    Node *list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node *list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);

    std::cout << "Lists are " << (compare(list1, list2) ? "equal" : "not equal") << "." << std::endl;

    // Task 3: Add two large numbers
    Node *num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    Node *num2 = new Node(6);
    num2->next = new Node(8);
    num2->next->next = new Node(2);

    Node *sum = add(num1, num2);
    std::cout << "Sum: ";
    printList(sum);

    // Task 4: Create a mirror flip of a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Original tree: ";
    printTree(root);
    std::cout << std::endl;

    TreeNode *mirrored = create_mirror_flip(root);
    std::cout << "Mirrored tree: ";
    printTree(mirrored);
    std::cout << std::endl;

    // Task 5: Update tree with sum of child nodes
    tree_sum(root);
    std::cout << "Tree with updated sums: ";
    printTree(root);
    std::cout << std::endl;

    return 0;
}
