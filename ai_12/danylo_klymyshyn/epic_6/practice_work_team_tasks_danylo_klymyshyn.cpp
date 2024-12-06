#include <iostream>
#include <algorithm>

struct Node{
    int value;
    Node *next_el;
    Node *prev;
};
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode;
    newNode->value = root->value;
    newNode->left = create_mirror_flip(root->right);
    newNode->right = create_mirror_flip(root->left);

    return newNode;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->value << " ";
    printTree(root->left);
    printTree(root->right);
}

void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if (value < root->value) {
            insert(root->left, value);
        } else {
            insert(root->right, value);
        }
    }
}




void createList(Node*& head, Node*& tail, int n){

tail = nullptr;
std::cout << "Enter 1 element: ";
int el;
std::cin >> el;


head = new Node {el, nullptr};
Node* current = head;
for(int i = 0;i < n-1; ++i){
    
    std::cout << "Enter " << i + 2 << " element: ";
    std::cin >> el;    
    current->next_el = new Node {el, nullptr}; 
    current->next_el->prev = current;
    current = current->next_el;
}

tail = current;
}


void printList(Node *head){

Node *current = head;


while(current != nullptr){
    std::cout << current->value << ' ';
    current = current->next_el;
}
    return;
}


Node* reverse(Node*& head) {
    if (head == nullptr || head->next_el == nullptr) {
        return head;
    }

    Node* left = head;
    Node* right = head;

    while (right->next_el != nullptr) {
        right = right->next_el;
    }

    while (left != right && left->prev != right) {
        std::swap(left->value, right->value);
        left = left->next_el;
        right = right->prev;
    }

    return head;
}



bool compare(Node *h1, Node *h2){


bool check = true;
while(h1 != nullptr && h2 != nullptr){
    if(h1->value != h2->value)
        check = false;
    h1 = h1->next_el;
    h2 = h2->next_el;
}


if(h1 != nullptr || h2 != nullptr)
    check = false;
    return check;
}


Node* add(Node *n1, Node *n2) {
    reverse(n1);
    reverse(n2);

    Node* result = new Node{0, nullptr, nullptr};
    Node* head = result;

    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry;
        if (n1 != nullptr) {
            sum += n1->value;
            n1 = n1->next_el;
        }
        if (n2 != nullptr) {
            sum += n2->value;
            n2 = n2->next_el;
        }

        result->value = sum % 10;
        carry = sum / 10;

        if (n1 != nullptr || n2 != nullptr || carry != 0) {
            result->next_el = new Node{0, nullptr, result};
            result = result->next_el;
        }
    }

    reverse(head);
    return head;
}


int tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_sum = tree_sum(root->left);
    int right_sum = tree_sum(root->right);
    if (root->left != nullptr || root->right != nullptr) {
        root->value += left_sum + right_sum;
    }
    return root->value + left_sum + right_sum;
}







int main(){


Node* head = nullptr;
Node* tail = nullptr;
Node* head2 = nullptr;
Node* tail2 = nullptr;



Node* h1 = nullptr;
Node* t1 = nullptr;

Node* h2 = nullptr;
Node* t2 = nullptr;

int n;
std::cout << "Enter number of nods: ";
std::cin >> n;

createList(head, tail, n);

printList(head);
Node* x = reverse(head);
std::cout << "\nYour reversed list: " << std::endl;
printList(head);


int k;
std::cout << "\nEnter number of nods for your second list: ";
std::cin >> k;
createList(head2, tail2, k);

bool check_result = compare(head, head2);
if(check_result)
    std::cout << "Your lists are similiar.";
else
    std::cout << "Your lists are different.";

std::cout << "\nHow long is your first number? ";
int n1;
std::cin >> n1;
std::cout << "\nHow long is your second number? ";
int n2;
std::cin >> n2;

std::cout << "\tYour first number: " << std::endl;
createList(h1, t1, n1);
std::cout << "\tYour second number: " << std::endl;
createList(h2, t2, n2);


Node* res = add(h1, h2);

printList(res);


TreeNode* root = nullptr;
    
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 17);

    std::cout << "\nOriginal tree (preorder traversal): ";
    printTree(root);
    std::cout << std::endl;

    TreeNode* mirrorTree = create_mirror_flip(root);

    std::cout << "\nMirrored tree (preorder traversal): ";
    printTree(mirrorTree);
    std::cout << std::endl;



    tree_sum(root);

    std::cout << "Tree after updating parent nodes with subtrees sum (preorder traversal): ";
    printTree(root);
    std::cout << std::endl;






    return 0;
}