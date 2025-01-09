#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node (int value) : data(value), next(nullptr), prev(nullptr) {};
};

void addToEnd(Node*& head, Node*& tail, int value){
    Node* newNode = new Node(value);
    if(!head){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void addToFront(Node*& head, Node*& tail, int value){
    Node* newNode = new Node(value);
    if(!head){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void addInMid(Node*& head, Node*& tail, int index, int value) {
    if (index == 0 || !head) {
        addToFront(head, tail, value);
        return;
    }

    Node* current = head;
    Node* prevNode = nullptr;

    for (int i = 0; i < index; i++) {
        prevNode = current;
        current = current->next;
        if(!current) break;
    }

    Node* newNode = new Node(value);

    if(!current){
        tail = newNode;
    }
    else{
        newNode->next = current;
        current->prev = newNode;
    }
    newNode->prev = prevNode;
    prevNode->next = newNode;
}

void printFromStart(Node*& head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printFromEnd(Node*& tail){
    Node* temp = tail;
    while(temp){
        cout << temp->data << " ";
        temp = temp->prev;
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
    Node* tail = nullptr;
    addToFront(head,tail,7);
    addToEnd(head,tail,2);
    addToEnd(head,tail,10);
    addInMid(head,tail,3,5);
    cout << "Список, виведений зліва направо:" << endl;
    printFromStart(head);
    cout << "Список, виведений справа наліво:" << endl;
    printFromEnd(tail);
    cout << "Відсортований список:" << endl;
    bubbleSort(head);
    printFromStart(head);
       
    return 0;

}