#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;


    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addNodeAtStart(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addNode(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeElementAfter(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value && current->next != nullptr) {
                Node* x = current->next;
                current->next = x->next;
                if (x->next != nullptr) {
                    x->next->prev = current;
                } else {
                    tail = current; 
                }
                delete x;
                return;
            }
            current = current->next;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

// Free memory deconstructor
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* x = head;
            head = head->next;
            delete x;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    cout << "Original list: ";
    list.printList();

    
    list.removeElementAfter(2);
    cout << "List after removing element after 2: ";
    list.printList();

   
    int K = 3;
    for (int i = 0; i < K; ++i) {
        list.addNodeAtStart(10 + i); 
    }
    cout << "List after adding 3 elements at the start: ";
    list.printList();

    return 0;
}