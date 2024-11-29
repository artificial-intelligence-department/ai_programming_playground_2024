#include <iostream>
using namespace std;

struct Node 
{
    int data;        
    Node* next;

     Node(int val) 
    {
        data = val;
        next = nullptr;
    }
};

Node* reverse(Node* head) 
{
    Node* prev = nullptr; 
    Node* current = head; 
    Node* next = nullptr; 

    while (current != nullptr) 
    {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;       
    }

    return prev;
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    head = reverse(head);
    cout << "Reversed List: ";
    printList(head);

    return 0;
}
