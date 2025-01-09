#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
};

void Show (Node* head){
   if (!head) return;
    cout << head -> data << " ";
    Show(head->next)
    }


 void Addlast(Node*& head, int value){
        Node* newnode = new Node{value, nullptr};
        if (head == nullptr){
            head = newnode;
        } else {
            Node* current = head;
            while (current -> next != nullptr){
                current = current -> next;
            }
            current -> next = newnode;
        }
    }

void Addfirst (Node*& head, int value){
    Node* newnode = new Node{value, nullptr};
    newnode -> next = head;
    head = newnode;
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
head = new Node{3, nullptr};
head -> next = new Node{4, nullptr};
Show(head);
Addlast(head,6);
cout << endl;
Addfirst(head,7);
Show(head);
cout << endl;
BubbleSort(head);
Show(head);
}
