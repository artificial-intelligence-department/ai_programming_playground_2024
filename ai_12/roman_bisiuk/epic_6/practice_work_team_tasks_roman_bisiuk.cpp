#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

Node *reverse(Node *head)
{
    Node *previous = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

bool compare(Node *h1, Node *h2)
{
    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->data != h2->data)
        {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

Node *add(Node *n1, Node *n2)
{
    Node dummy(0);
    Node *current = &dummy;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry)
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
    return dummy.next;
}

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode *create_mirror_flip(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    TreeNode *new_root = new TreeNode(root->value);
    new_root->left = create_mirror_flip(root->right);
    new_root->right = create_mirror_flip(root->left);

    return new_root;
}

void tree_sum(TreeNode *root)
{
    if (root == nullptr)
        return;

    int left_sum = 0;
    int right_sum = 0;

    if (root->left != nullptr)
    {
        left_sum += root->left->value;
    }
    if (root->right != nullptr)
    {
        right_sum += root->right->value;
    }

    tree_sum(root->left);
    tree_sum(root->right);

    if (!root->left && !root->right)
        return;
    root->value = left_sum + right_sum;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printTree(TreeNode *root)
{
    if (root != nullptr)
    {
        printTree(root->left);
        cout << root->value << " ";
        printTree(root->right);
    }
}

int main()
{
    Node *head = new Node(7);
    head->next = new Node(9);
    head->next->next = new Node(11);
    head->next->next->next = new Node(12);

    cout << "Linked List with no changes: ";
    printList(head);

    head = reverse(head);
    cout << "Reversed Linked List: ";
    printList(head);

    Node* list1 = new Node(2);
    list1->next = new Node(6);
    list1->next->next = new Node(7);

    Node* list2 = new Node(3);
    list2->next = new Node(5);
    list2->next->next = new Node(8);

    cout << "Are lists equal? " << (compare(list1, list2) ? "Yes" : "No") << endl;

    list2->next->next->data = 4;
    cout << "Are lists equal after changes? " << (compare(list1, list2) ? "Yes" : "No") << endl;

    Node* num1 = new Node(5);
    num1->next = new Node(6);
    num1->next->next = new Node(7);

    Node* num2 = new Node(1);
    num2->next = new Node(2);
    num2->next->next = new Node(1); 

    Node* sum = add(num1, num2);
    cout << "Sum: ";
    printList(sum); 

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);

    cout << "Original Tree: ";
    printTree(root);
    cout << endl;

    TreeNode* mirroredRoot = create_mirror_flip(root);
    cout << "Mirrored Tree: ";
    printTree(mirroredRoot);
    cout << endl;

    TreeNode* sumTreeRoot = new TreeNode(1);
    sumTreeRoot->left = new TreeNode(2);
    sumTreeRoot->right = new TreeNode(3);
    sumTreeRoot->left->left = new TreeNode(4);
    sumTreeRoot->left->right = new TreeNode(5);

    cout << "Tree before summing subtrees: ";
    printTree(sumTreeRoot);
    cout << endl;

    tree_sum(sumTreeRoot);
    cout << "Tree after: ";
    printTree(sumTreeRoot);
    cout << endl;

    return 0;
}