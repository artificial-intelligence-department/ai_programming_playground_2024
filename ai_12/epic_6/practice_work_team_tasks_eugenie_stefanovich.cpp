#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct node { 
    int data;
    node* next;
};

struct Node { 
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void createLL(node*& head, vector<int>& vec) {
    cout << "Створення списку..." << endl;
    node* tail = nullptr; 

    for (int i = 0; i < vec.size(); i++) {
        node* newNode = new node;
        newNode->data = vec[i];
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;  
            tail = newNode; 
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void reverseLL(node*& head){
    node* current = head;
    node* next = nullptr;
    node* prev = nullptr;

    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void printLL(node* head) {
    cout << "Друк списку..." << endl;

    if(head == nullptr){
        cout << "Список пустий." << endl;
        return;
    }

    node* tmp = head;
    while(tmp != nullptr){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

bool compare(node* h1, node* h2){
    node* tmp1 = h1;
    node* tmp2 = h2;

    while(tmp1 != nullptr && tmp2 != nullptr){
        if(tmp1->data != tmp2->data) return false;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    if(tmp1 != tmp2) return false;  
    return true;
} 

node* add(node* h1, node* h2){
    int a = 0;
    int sum, x, y;
    node* h = nullptr;
    node* current = nullptr;

    while(h1 != nullptr || h2 != nullptr){
        if(h1 == nullptr){
            x = 0;
        }else{
            x = h1->data;
        }
        if(h2 == nullptr){
            y = 0;
        }else{
            y = h2->data;
        }

        sum = x + y + a;
        a = sum / 10;
        node* tmp = new node;
        tmp->data = sum % 10;
        tmp->next = nullptr;

        if(h == nullptr){
            h = tmp;
            current = tmp;
        }else{
            current->next = tmp;
            current = tmp;
        }

        if(h1 != nullptr) h1 = h1->next;
        if(h2 != nullptr) h2 = h2->next;
    }

    if (a > 0) {
        node* tmp = new node;
        tmp->data = a;
        tmp->next = nullptr;
        current->next = tmp;
    }

    return h;   
}

void freeLL(node*& head){
    while(head != nullptr){
        node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void insertIntoTree(Node*& root, int value){
    if(root == nullptr) {
        root = new Node(value);
        return;
    }

    if(value < root->data){
        insertIntoTree(root->left, value);
    }else{
        insertIntoTree(root->right, value);
    }
}

Node* mirror(Node* root){
    if(root == nullptr){
        return nullptr;
    }

    Node* mirroredNode = new Node(root->data);

    mirroredNode->left = mirror(root->right);
    mirroredNode->right = mirror(root->left);

    return mirroredNode;
}

void sumTree(Node* root){
    if(root == nullptr) return;

    sumTree(root->left);
    sumTree(root->right);

    if(root->left != nullptr || root->right != nullptr){
        int leftValue = (root->left != nullptr) ? root->left->data : 0;
        int rightValue = (root->right != nullptr) ? root->right->data : 0;
        root->data = leftValue + rightValue;
    }
}

void printTree(Node* root){
    if(root == nullptr) return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

void freeTree(Node*& root){
    if(root == nullptr) return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    vector<int> vec1 = {3, 7, 9}; 
    vector<int> vec2 = {2, 4, 8}; 

    node* head1 = nullptr;
    node* head2 = nullptr;

    cout << "------------------------------------------" << endl;
    cout << "               LINKED LISTS" << endl;

    createLL(head1, vec1);
    cout << "Перший список: ";
    printLL(head1);

    createLL(head2, vec2);
    cout << "Другий список: ";
    printLL(head2);

    node* result = add(head1, head2);
    cout << "Результат додавання: ";
    printLL(result);

    reverseLL(head1);
    cout << "Перший список після реверсу: ";
    printLL(head1);

    reverseLL(head2);
    cout << "Другий список після реверсу: ";
    printLL(head2);

    bool isEqual = compare(head1, head2);
    cout << "Чи рівні списки: " << (isEqual ? "Так" : "Ні") << endl;
    freeLL(head1);
    freeLL(head2);

    cout << "------------------------------------------" << endl;
    cout << "                  TREES" << endl;

    Node* root = nullptr;
    vector<int> treeValues = {4, 2, 6, 1, 3, 5, 7};
    int len = treeValues.size();
    for(int i = 0; i < len; i++){
        insertIntoTree(root, treeValues[i]);
    }
    cout << "Оригінальне дерево (виведене по рівнях): ";
    printTree(root);
    cout << endl;

    sumTree(root);
    cout << "Дерево після обчислення сум підвузлів: ";
    printTree(root);
    cout << endl;

    Node* mirroredRoot = mirror(root);
    cout << "Дерево після дзеркального відображення: ";
    printTree(mirroredRoot);
    cout << endl;

    freeTree(root);
    freeTree(mirroredRoot);
} 
