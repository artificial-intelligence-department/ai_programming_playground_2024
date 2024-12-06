#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* nextNode;
    
    Node(int data) : value(data), nextNode(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* previous = nullptr; 
    Node* current = head;     
    Node* following = nullptr; 
    
    while (current != nullptr) {
        following = current->nextNode; 
        current->nextNode = previous; 
        previous = current;          
        current = following;          
    }
    
    return previous; 
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->nextNode;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->nextNode = new Node(2);
    head->nextNode->nextNode = new Node(3);
    head->nextNode->nextNode->nextNode = new Node(4);

    cout << "Початковий список: ";
    displayList(head);

    head = reverseList(head);

    cout << "Перевернутий список: ";
    displayList(head);

    return 0;
}
