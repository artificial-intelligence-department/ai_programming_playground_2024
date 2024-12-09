#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//5
void Show(Node* head){
    if (head==nullptr){
        cout<<"list is empty";
    }
    
    Node* current = head;
    while (current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}

//2
void PushBack (Node*& head, int data){
    if (head == nullptr){
        head = new Node {data, nullptr};
    }

    else{
    Node* current = head;

    while (current->next!=nullptr){
        current=current->next;
    }
    current->next = new Node{data, nullptr};
    }
}

//3
void PushFront (Node*& head, int data){
    if (head == nullptr){
        head = new Node {data, nullptr};
    }

    else{
        Node* New = new Node;
        New->data = data;
        New->next = head;
        head = New;
    }
}

//4
void Push(Node*& current, int data){
    if(current == nullptr){
        current = new Node {data, nullptr}; 
    }

    else{
        Node* New = new Node {data, current->next};
        current->next = New;
    }
}

//6
void BubbleSort (Node* head){
    if (head == nullptr) return;

    bool swapped;
    Node* ptr;
    Node* lastPtr = nullptr;

    do{
        swapped = false;
        ptr = head;

        while (ptr->next != lastPtr){
            if(ptr->data > ptr->next->data){
                swap(ptr->data, ptr->next->data);
                swapped = true;
            }
            ptr = ptr->next;
        }
        lastPtr = ptr;
    } while (swapped);
}

//7
void SelectionSort(Node* head) {
    if (head == nullptr) return;

    Node* current = head;
    while (current != nullptr) {
        Node* minNode = current;
        Node* next = current->next;
        while (next != nullptr) {
            if (next->data < minNode->data) {
                minNode = next;
            }
            next = next->next;
        }
        swap(current->data, minNode->data);
        current = current->next;
    }
}

int main(){
    Node* head = nullptr;
    Show(head);
    
    //1
    head = new Node {10, nullptr};
    head->next = new Node {5, nullptr};
    head->next->next = new Node {2, nullptr};
    Show(head);

    PushBack(head, 12);
    Show(head);

    PushFront(head, 6);
    Show(head);

    Push(head->next, 4);
    Show(head);

    // BubbleSort(head);
    // Show(head);

    SelectionSort(head);
    Show(head);    

    return 0;
}