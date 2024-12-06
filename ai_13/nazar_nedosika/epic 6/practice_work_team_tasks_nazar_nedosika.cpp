#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* next;
};

// 1
Node* reverse(Node* head)
{
    Node* prev = NULL;  
    Node* curr = head;  
    Node* next = NULL;  

    while (curr != NULL) 
    {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;
        curr = next;
    }
    return prev;
}

void print(Node* head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void print_reversed(Node* head)
{
    head = reverse(head);
    print(head);
    head = reverse(head);
}

// 2
bool compare(Node* h1, Node* h2)
{
    if (h1->next == NULL && h2->next == NULL)
    {
        return h1->value == h2->value;
    }
    if (h1->next == NULL || h2->next == NULL) // different lengths
    {
        return false;
    }
    return compare(h1->next, h2->next) && h1->value == h2->value;
}

// 3
Node* add(Node* n1, Node* n2)
{
    Node* head = new Node {0, NULL};
    Node* n = head;
    int carry = 0;
    while (n1 && n2)
    {
        n->value = n1->value + n2->value + carry;
        if (n->value > 9) 
        {
            carry = n->value / 10;
            n->value -= 10;
        }
        else carry = 0;
        n->next = new Node {0, NULL};
        n = n->next;
        n1 = n1->next;
        n2 = n2->next;
    }
    while (n1)
    {
        n->value = n1->value + carry;
        if (n->value > 9) 
        {
            carry = n->value - 10;
            n->value -= 10;
        }
        else carry = 0;
        n->next = new Node {0, NULL};
        n = n->next;
        n1 = n1->next;
    }
    while (n2)
    {
        n->value = n2->value + carry;
        if (n->value > 9) 
        {
            carry = n->value - 10;
            n->value -= 10;
        }
        else carry = 0;
        n->next = new Node {0, NULL};
        n = n->next;
        n2 = n2->next;
    }
    if (carry)
    {
        n->value = carry;
    }
    return head;
}

void print_as_number(Node* head)
{
    int n = 0;
    int i = 1;
    while (head != NULL)
    {
        n += head->value * i;
        i *= 10;
        head = head->next;
    }
    cout << n << endl;
}

// 4
struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* flip(TreeNode* root)
{
    if (!(root->left) && !(root->right))
    {
        return new TreeNode {root->value, NULL, NULL};
    }
    if (!(root->left))
    {
        return new TreeNode {root->value, flip(root->right), NULL};
    }
    if (!(root->right))
    {
        return new TreeNode {root->value, NULL, flip(root->left)};
    }
    return new TreeNode {root->value, flip(root->right), flip(root->left)};
}

TreeNode* sum(TreeNode* root)
{
    TreeNode* sl, * sr;
    if (!(root->left) && !(root->right))
    {
        return new TreeNode {root->value, NULL, NULL};
    }
    if (!(root->left))
    {
        sr = sum(root->right);
        return new TreeNode {sr->value, NULL, sr};
    }
    if (!(root->right))
    {
        sl = sum(root->left);
        return new TreeNode {sl->value, sl, NULL};
    }
    sl = sum(root->left);
    sr = sum(root->right);
    return new TreeNode {sl->value + sr->value, sl, sr};
}

void print(TreeNode* root)
{
    if (!(root->left) && !(root->right))
    {
        cout << "[ " << root->value << " ]";
        return;
    }
    if (!(root->left))
    {
        cout << "[ " << root->value << ", , ";
        print(root->right);
        cout << " ]";
        return;
    }
    if (!(root->right))
    {
        cout << "[ " << root->value << ", ";
        print(root->left);
        cout << ", ]";
        return;
    }
    cout << "[ " << root->value << ", ";
    print(root->left);
    cout << ", "; 
    print(root->right);
    cout << " ]";
}

int main()
{
    // 1
    Node* c = new Node {3, NULL};
    Node* b = new Node {2, c};
    Node* a = new Node {1, b};
    Node* head = a;
    print(head); // 1 2 3
    head = reverse(head);
    print(head); // 3 2 1
    head = reverse(head); // 1 2 3
    print(head);
    print_reversed(head); // 3 2 1

    delete c; delete b; delete a;
    // 2 
    Node* c1 = new Node {3, NULL};
    Node* b1 = new Node {2, c1};
    Node* a1 = new Node {1, b1};
    Node* h1 = a1;
    Node* c2 = new Node {3, NULL};
    Node* b2 = new Node {2, c2};
    Node* a2 = new Node {1, b2};
    Node* h2 = a2;
    Node* c3 = new Node {4, NULL};
    Node* b3 = new Node {2, c3};
    Node* a3 = new Node {1, b3};
    Node* h3 = a3;
    cout << compare(h1, h2) << " " << compare(h1, h3) << " " << compare(h2, h3) << " " << compare(h2, h2) << endl; // 1 0 0 1

    delete c1; delete b1; delete a1;
    delete c2; delete b2; delete a2;
    delete c3; delete b3; delete a3;
    // 3
    c1 = new Node {1, NULL};
    b1 = new Node {2, c1};
    a1 = new Node {3, b1};
    h1 = a1; 
    c2 = new Node {9, NULL};
    b2 = new Node {2, c2};
    a2 = new Node {7, b2};
    h2 = a2; 
    print_as_number(h1); // 123
    print_as_number(h2); // 927
    print_as_number(add(h1, h2)); // 1050

    delete c1; delete b1; delete a1;
    delete c2; delete b2; delete a2;
    // 4
    TreeNode* n6 = new TreeNode {6, NULL, NULL};
    TreeNode* n5 = new TreeNode {5, NULL, NULL};
    TreeNode* n4 = new TreeNode {4, NULL, NULL};
    TreeNode* n3 = new TreeNode {3, NULL, NULL};
    TreeNode* n2 = new TreeNode {2, n3, n4};
    TreeNode* n1 = new TreeNode {1, n5, n6};
    TreeNode* root = new TreeNode {0, n1, n2};
    print(root);
    cout << endl;
    root = flip(root);
    print(root);
    cout << endl;
    
    // 5
    root = sum(root);
    print(root);
    cout << endl;
}
