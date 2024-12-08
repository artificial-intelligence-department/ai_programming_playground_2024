#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node (int value) : data(value), next(nullptr) {};
};

void addToEnd(Node*& head, int value){
    Node* newNode = new Node(value);
    if(!head){
        head = newNode;
        return;
    }

    while(head->next){
        head = head->next;
    }

    head->next = newNode;
}

void addToFront(Node*& head, int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void addInMid(Node*& head, int index, int value){
    Node* newNode = new Node(value);
    if(index==0 || !head){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for(int i=0; i<index; i++){
        if(!temp->next){
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node*& head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSort(Node*& head){
    bool swapped;

    if(!head){
        return; 
    }
    do{
        Node* current = head;
        swapped = false;

        while(current->next){
            if (current->data > current->next->data){
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp; 
                swapped = true;
            }
            current = current->next;
        }
    }
    while(swapped);
}

int main(){
    Node* head = nullptr;
    addToFront(head, 5);
    addToEnd(head, 2);
    addToFront(head, 1);
    addInMid(head, 1, 10);
    printList(head);
    bubbleSort(head);
    cout << "Відсортований список:" << endl;
    printList(head);
    return 0;

}