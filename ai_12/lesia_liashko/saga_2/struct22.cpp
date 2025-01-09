#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Node {
    int data;       
    Node* next;     
};

void addNode(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode; 
    } else {
        Node* temp = head;
        while (temp->next) { 
            temp = temp->next;
        }
        temp->next = newNode; 
}}

void printList(const Node* node) {
    ofstream OutFile ("somenode.txt", ios::app);
    if(OutFile.is_open()){
     if (!node) return; 
     OutFile << node->data << " ";
     printList(node->next);
    } else {
        cout << "error";
    } OutFile.close();
    
}

void printList(const Node* node, bool useLoop) {
    ofstream OutFile ("somenode.txt", ios::app);
    if (OutFile.is_open()){
        while (node) { 
        OutFile << node->data << " ";
        node = node->next; 
    }
    }else {
        cout << "error";
    }
    OutFile.close();
}

int main() {
    Node* head = nullptr;

    addNode(head, 10);
    addNode(head, 20);
    addNode(head, 30);
    addNode(head, 40);

    std::cout << "List (recursive): ";
    printList(head);
    std::cout << std::endl;

    std::cout << "List (loop): ";
    printList(head, true);
    std::cout << std::endl;

    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
