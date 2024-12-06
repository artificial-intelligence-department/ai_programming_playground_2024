#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp ->data << " ";
        temp = temp ->next;
    }
    cout<<endl;
}

void insert(Node*& head, int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
    }else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool compare(Node* h1,Node* h2){
    while(h1 != nullptr && h2 != nullptr){
        if(h1->data != h2->data){
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

Node* add(Node* n1,Node* n2){
    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while(n1 != nullptr || n2 != nullptr){
        int sum = carry;
        if(n1 != nullptr){
            sum += n1->data;
            n1 = n1->next;
        }
        if(n2 != nullptr){
            sum += n2->data;
            n2 = n2->next;
        }
        carry = sum / 10;
        sum = sum % 10;

        Node* newNode = new Node(sum);
        if(result == nullptr){
            result = newNode;
            tail = result;
    }else{
        tail->next = newNode;
        tail = tail->next;
    }
    }
    if (carry > 0) {
        tail->next = new Node(carry);
    }
    return result;
}

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root){
    if(root == nullptr){
        return nullptr;
    }
    TreeNode* newRoot = new TreeNode(root->data);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);
    return newRoot;
}

void printTree(TreeNode* root){
    if(root != nullptr){
        printTree(root->left);
        cout<<root->data<<" ";
        printTree(root->right);
    }
}


TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
        return root;
    }else{
        root->right = insert(root->right, value);
    }
    return root;
}

int tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }
    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);
    root->data = leftSum + rightSum;
    return root->data;
}

int main(){
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    insert(head1,1);
    insert(head1,2);
    insert(head1,3);
    insert(head1,4);
    insert(head1,5);

    insert(head2,1);
    insert(head2,2);
    insert(head2,3);
    insert(head2,4);
    insert(head2,5);

    cout<<"Список 1:"<<endl;
    printList(head1);

    cout<<"Список 2:"<<endl;
    printList(head2);

    if(compare(head1,head2)){
        cout<<"Списки ідентичні"<<endl;
    }else{
        cout<<"Списки різні"<<endl;
    }
    head1 = reverse(head1);

    cout<<"Обернений перший список: "<<endl;
    printList(head1);

    if(compare(head1,head2)){
        cout<<"Списки однакові"<<endl;
    }else{
        cout<<"Списки різні"<<endl;
    }

    Node* result = add(head1,head2);

    cout<<"Сума додавання: ";
    printList(result);

    TreeNode* root = nullptr;

    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    cout << "Оригінальне дерево: ";
    printTree(root);
    cout << endl;


    tree_sum(root);

    cout << "Дерево після обчислення суми: ";
    printTree(root);
    cout << endl;


    return 0;
}