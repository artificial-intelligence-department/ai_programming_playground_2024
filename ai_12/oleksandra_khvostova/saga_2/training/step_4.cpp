#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* previous;
    Node* next;
};

void Write(Node* head){
    Node* current = head;
    cout<<current->data<<" ";
    current = current->next;
    if (current!=nullptr) {
        Write(current);
    }
    else{
        return;
    }
}

void WriteRecursive(ofstream& OutFile, Node* current){
    if (current!=nullptr) {
        OutFile<<current->data<<endl;
        WriteRecursive(OutFile, current->next);
    }
    else{
        return;
    }
}

void Write(Node* head, const string& filename){
    ofstream OutFile(filename);
    Node* current = head;
    WriteRecursive(OutFile, current);
    OutFile.close();
}

void Write(Node* head, int count){
    Node* current = head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* head = nullptr;
    head = new Node{1, nullptr, nullptr};
    head->next = new Node {2, head, nullptr};
    head->next->next = new Node{3, head->next, nullptr};

    Write(head);
    Write(head, "try.txt");
    cout<<endl;
    Write(head, 1);

    return 0;
}