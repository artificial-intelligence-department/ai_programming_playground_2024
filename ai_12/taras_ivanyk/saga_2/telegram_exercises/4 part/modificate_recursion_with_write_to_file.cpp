#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

void recursion_file(Node* head){
    static ofstream file("modificate_recursion.txt");

    if(!head){
        file.close();
        return;
    }
    file << head -> data << " ";
    recursion_file(head -> next); // recursion 
}

void recursion_file(Node* head, string line){
    ifstream file("modificate_recursion.txt");

    while(getline(file, line)){
        cout << line << " ";
    }
    file.close();
}


int main(){

    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    head -> next = node2;
    node2 -> next = node3;

    node2 -> prev = head;
    node3 -> prev = node2;

    string line;
    
    recursion_file(head);          // overloaded functions
    recursion_file(head, line);

    delete[] head;
    delete[] node2;
    delete[] node3;

    return 0;
}