#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


Node* reverse(Node*& head){ // task 1 
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while(current!=nullptr){
        next = current->next;
        current->next = prev;
        prev = current; 
        current = next;
    }

    return prev;
}

bool compare(Node *h1, Node *h2){ // task 2
    while(h1!=nullptr && h2!=nullptr){
        if(h1->data != h2->data){
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

void addToList(Node*& head, int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = newNode;
    } else{
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

}

Node* add(Node *n1, Node *n2){ // task 3
    Node* res = nullptr;
    Node* temp = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0){
        int sum = carry; 
        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10; 
        int digit = sum % 10;

        addToList(res, digit);
    }

    return res;
}

void printList(Node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printNums(Node* head){
    head = reverse(head);
    while(head != nullptr){
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; 
    addToList(head, 1);
    addToList(head, 2);
    addToList(head, 3);
    addToList(head, 4);

    cout << "Task 1" << endl;
    printList(head);
    
    head = reverse(head);

    cout << "Reversed list: " << endl;
    printList(head);

    Node* h1 = nullptr; 
    addToList(h1, 1);
    addToList(h1, 2); 
    addToList(h1, 3);
    addToList(h1, 4);

    cout << endl << "Task 2" << endl;
    cout << "First list: " << endl;
    printList(h1);

    Node* h2 = nullptr; 
    addToList(h2, 1);
    addToList(h2, 2);
    addToList(h2, 8);

    cout << "Second list: " << endl;
    printList(h2);
    
    if (compare(h1,h2)){
        cout << "The lists are equal" << endl;
    }
    else{
        cout << "The lists are not equal" << endl;
    }

    cout << endl << "Task 3" << endl;
    Node* res = add(h1, h2);

    cout << "First number: ";
    printNums(h1);
    cout << "Second number: ";
    printNums(h2);
    cout << "Sum: ";
    printNums(res);

    return 0;
}