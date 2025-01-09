#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr) {};
};

void printList(Node*& head){ //рекурсивно виводить лист
    if(!head){
        return;
    }

    cout << head->data << " ";
    printList(head->next);
}

void printList(Node*& head, ofstream& file){ // рекурсивно записує у файл
    if(!head){
        return;
    }

    file << head->data << " ";
    printList(head->next, file);
}

void printList(Node*& head, bool loop){ //виводить через цикл
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printList(Node*& head, bool loop, ofstream& file){ //записує у файл через цикл
    Node* temp = head;
    while(temp){
        file << temp->data << " ";
        temp = temp->next;
    }
    file << endl;
}

int main(){
    Node* head = new Node(4);
    head->next = new Node(3);
    head->next->next = new Node(1);

    ofstream file("list.txt");
    cout << "Ітеративно:" << endl;
    printList(head, true);
    printList(head, true, file);
    cout << "Рекурсивно:" << endl;
    printList(head);
    printList(head, file);
    file.close();


    return 0;
}

