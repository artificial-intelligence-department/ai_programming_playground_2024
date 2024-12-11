#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node* prev;
};

void Show (Node* head){
   Node* current = head;
    while (current !=nullptr){
        cout << current -> data << " ";
        current = current -> next;
    }
}
void Showback (Node* tail){
   Node* current = tail;
    while (current !=nullptr){
        cout << current -> data << " ";
        current = current -> prev;
    }
}
    void Addlast(Node*& head, Node*& tail, int value){
        Node* newnode = new Node{value, nullptr, nullptr};
        if (head == nullptr){
            head = tail = newnode;
        } else {
             newnode->prev = tail;
            newnode->prev = tail;
            tail = newnode;  
        }
    }
void Addfirst (Node*& head, Node*& tail, int value){
   Node* newnode = new Node{value, nullptr, nullptr};
   if (head == nullptr){
            head = tail = newnode;
        } else {
             newnode->next = head;
            head->prev = newnode;
            head = newnode;  
        }
    }

void BubbleSort(Node* head) {
    if (head == nullptr) return; 
    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped); 
}
int main (){
Node* head = nullptr;
Node* tail = nullptr;
Addlast(head, tail, 6);
Addlast(head, tail, 7);
cout << endl;
Show(head);
cout << endl;
Showback(tail);
}
