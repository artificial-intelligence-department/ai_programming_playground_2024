#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

void recursion_print(Node* head){
    if(!head){
        return;
    }
    cout << head -> data << " ";

    recursion_print(head -> next);
}


int main(){

    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    head -> next = node2;
    node2 -> next = node3;

    node2 -> prev = head;
    node3 -> prev = node2;
    
    recursion_print(head);

    delete[] head;
    delete[] node2;
    delete[] node3;

    return 0;
}