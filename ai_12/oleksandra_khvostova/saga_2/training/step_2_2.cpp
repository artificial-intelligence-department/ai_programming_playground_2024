#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* previous;
    Node* next;
};

//5
void Show(Node* head){
    if(head == nullptr){
        cout<<"list is empty";
        cout<<endl;
    }

    else{
        Node* current = head;
        while(current != nullptr){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }

}

//7
void Reversed(Node* head){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
    }

    else{
        Node* current = head;
        while(current->next != nullptr){
            current=current->next;
        }

        while(current != nullptr){
            cout<<current->data<<" ";
            current=current->previous;
        }

        cout<<endl;
    }
}

//2
void PushBack (Node*& head, int data){
    if(head == nullptr){
        head = new Node {data, nullptr, nullptr};
    }

    else{
        Node* current = head;
        while (current->next != nullptr){
            current = current-> next;
        }
        Node* New = new Node {data, current, nullptr};
        current->next = New;
    }
}

//3
void PushFront (Node*& head, int data){
    if(head == nullptr){
        head = new Node {data, nullptr, nullptr};
    }

    else{
        Node* New = new Node {data, nullptr, head};
        head->previous = New;
        head = New;
    }
}

//4
void PushAfter (Node*& current, int data){
    if (current == nullptr){
        current = new Node {data, nullptr, nullptr};
    }

    else{
        Node* New = new Node{data, current, current->next};
        current->next->previous = New;
        current->next = New;
    }
}

//5
void BubbleSort(Node* head) {
    if (head == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

int main(){
    Node* head = nullptr;
    Show(head);

    head = new Node{2, nullptr, nullptr};
    Show(head);

    PushBack(head, 3);
    Show(head);

    PushFront(head, 10);
    Show(head);

    PushAfter(head->next, 8);
    Show(head);

    BubbleSort(head);
    Show(head);
    Reversed(head);

    return 0;
}