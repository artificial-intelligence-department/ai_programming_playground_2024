#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int num) : data(num), next(nullptr) {}
};

struct NodeD {
    int data;
    NodeD* next;
    NodeD* prev;
    NodeD(int num) : data(num), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
    NodeD* head;
    NodeD* tail;
    int size;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void pushBack(int num) {
        if(head == nullptr) {
            head = new NodeD(num);
            tail = head;
        } else {
            NodeD* newNode = new NodeD(num);
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pushFront(int num) {
        if(head == nullptr) {
            head = new NodeD(num);
            tail = head;
        } else {
            NodeD* newNode = new NodeD(num);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void push(int num, int pos) {
        if(pos > size+1) {
            cout << "Incorrect index!\n";
            return;
        } 
        if(pos == 0) pushFront(num);
        else if(pos == size+1) pushBack(num);
        else {
            NodeD *cur = head;
            NodeD *newNode = new NodeD(num);
            for(int i = 1; i < pos; i++) 
                cur = cur->next;
            newNode->next = cur->next;
            newNode->prev = cur;
            cur->next = newNode;
            newNode->next->prev = newNode;
            size++;
        }
    }

    void printLR() {
        if(head == nullptr) cout << "The list is empty!\n";
        else {
            NodeD* cur = head;
            while(cur != nullptr) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << "\n";
        }
    }

    void printRL() {
        if(head == nullptr) cout << "The list is empty!\n";
        else {
            NodeD* cur = tail;
            while(cur != nullptr) {
                cout << cur->data << " ";
                cur = cur->prev;
            }
            cout << "\n";
        }
    }

    void bubbleSort() {
        if(size==0 || size==1) return;
        for(int i = size-1; i > 0; i--) {
            NodeD* cur = head;
            for(int j = 0; j < i; j++) {
                if(cur->data > cur->next->data) {
                    int temp = cur->data;
                    cur->data = cur->next->data;
                    cur->next->data = temp;
                }
                cur = cur->next;
            }
        }
    }
};

class LinkedList {
    Node* head;
    int size;
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }
    
    void print() {
        if(head == nullptr) cout << "The list is empty!\n";
        else {
            Node* cur = head;
            while(cur != nullptr) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << "\n";
        }
    }

    void pushBack(int num) {
        if(head == nullptr) {
            head = new Node(num);
        } else {
            Node* cur = head;
            while(cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = new Node(num);
        }
        size++;
    }

    void pushFront(int num) {
        if(head == nullptr) {
            head = new Node(num);
        } else {
            Node* newNode = new Node(num);
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void push(int num, int pos) {
        if(pos > size+1) {
            cout << "Incorrect index!\n";
            return;
        } 
        if(pos == 0) pushFront(num);
        else if(pos == size+1) pushBack(num);
        else {
            Node *cur = head;
            Node *newNode = new Node(num);
            for(int i = 1; i < pos; i++) 
                cur = cur->next;
            newNode->next = cur->next;
            cur->next = newNode;
            size++;
        }
    }

    void bubbleSort() {
        if(size==0 || size==1) return;
        for(int i = size-1; i > 0; i--) {
            Node* cur = head;
            for(int j = 0; j < i; j++) {
                if(cur->data > cur->next->data) {
                    int temp = cur->data;
                    cur->data = cur->next->data;
                    cur->next->data = temp;
                }
                cur = cur->next;
            }
        }
    }
};

int main() {
    LinkedList list;
    list.pushBack(2);
    list.pushBack(21);
    list.pushFront(4);
    list.pushFront(5);
    list.push(7, 2);
    list.print();
    list.bubbleSort();
    list.print();
    cout << "--------------\n";

    DoublyLinkedList listD;
    listD.pushBack(9);
    listD.pushBack(13);
    listD.pushBack(18);
    listD.printLR();
    listD.printRL();
    listD.pushFront(10);
    listD.pushFront(0);
    listD.printLR();
    listD.printRL();
    listD.push(4, 2);
    listD.push(7, 4);
    listD.printLR();
    listD.printRL();
    listD.bubbleSort();
    listD.printLR();
    listD.printRL();
    return 0;
}