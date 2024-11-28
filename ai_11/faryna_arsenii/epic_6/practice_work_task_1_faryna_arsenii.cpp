#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {};
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
    return prev;
}

// for printing list
void printList(Node* head){
    Node* current = head;

    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// for creating list to allow user write elements to revers them
Node* createList(){
    int n, value;
    cout << "Enter the number of elements in the list to make reverse: ";
    cin >> n;

    if (n <= 0){
        return nullptr;
    }

    cout << "Enter the value for Node 1: ";
    cin >> value;
    Node* head = new Node(value);
    Node* temp = head;

    for (int i = 2; i <= n; i++){
        cout << "Enter the value for Node " << i << ": ";
        cin >> value;
        temp->next = new Node(value);
        temp = temp->next;
    }   

    return head;
}

int main (){

    Node* head = createList();

    cout << "User's list: ";
    printList(head);

    head = reverse(head);

    cout << "Reversed list is: ";
    printList(head);

    while (head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}