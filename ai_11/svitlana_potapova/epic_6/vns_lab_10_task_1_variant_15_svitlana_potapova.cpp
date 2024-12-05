#include <iostream> 
#include <cstring>
#include <fstream>
using namespace std;

struct Node{
    char data[100];
    Node* next;
    Node* prev; 
};

void addToList(Node*& head, Node*& tail, const char* key){
    Node* newNode = new Node;
    strcpy(newNode->data, key); 
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode; 
    }
}

void printList(Node* head){
    if(head == nullptr){
        cout << "The list is empty" << endl;
        return;
    }
    
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteElements(Node*& head, Node*& tail, int K){
    while(K>0 && tail!= nullptr){
        Node* del = tail;
        tail = tail->prev;

        if(tail != nullptr){
            tail->next = nullptr;
        } else{
            head = nullptr;
        }

        delete del; 
        K--;
    }
}

void addAfterKey(Node*& head, Node*& tail, const char* key, const char* toAdd){
    Node* temp = head; 

    while(temp != nullptr &&  strcmp(temp->data, key) != 0){
        temp = temp->next;
    }

    if(temp == nullptr){
        cout << key << " is not found in the list" << endl;
        return;
    }

    Node* newNode = new Node;
    strcpy(newNode->data, toAdd);

    newNode->next = temp->next;
    newNode ->prev = temp;
    
    if(temp->next != nullptr){
        temp->next->prev = newNode;
    } else{
        tail = newNode;
    }

    temp->next = newNode; 
}

void writeToFile(Node*& head, const char* filename){
    ofstream f(filename);
    if (!f.is_open()){
        cout << "Error oppening file" << endl;
        return;
    }

    while(head != nullptr){
        f << head->data << " ";
        head = head->next;
    }

    f.close();
}

void deleteList(Node*& head){
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cout << "The list was deleted" << endl;
}

void restoreList(Node*& head, Node*& tail, const char* filename){
    ifstream f(filename);
    if (!f.is_open()){
        cout << "Error oppening file" << endl;
        return;
    }

    char key[100]; 
    while(f >> key){
        addToList(head, tail, key);
    }

    f.close();
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    const char* filename = "DoublyLinkedList.txt";
    int K;

    cout << "Enter K:" << endl;
    cin >> K;

    addToList(head, tail, "Paris");
    addToList(head, tail, "Amsterdam");
    addToList(head, tail, "Vienna");
    addToList(head, tail, "London");

    printList(head);

    cout << "The list after deleting elements: " << endl;
    deleteElements(head, tail, K);
    printList(head);

    cout << "The list after adding element: " << endl;
    addAfterKey(head, tail, "Paris", "Berlin");
    printList(head);

    writeToFile(head, filename);
    deleteList(head);
    printList(head);

    cout << "The list was restored: " << endl;
    restoreList(head, tail, filename);
    printList(head);
    deleteList(head);

  
    return 0;
}
