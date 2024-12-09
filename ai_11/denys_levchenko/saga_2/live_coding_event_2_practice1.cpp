#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data, Node* next) : data(data), next(next) { } 
    Node() : next(nullptr) {}
};


void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void addinend(Node*& head, int value) {
    Node* newNode = new Node(value, nullptr);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addinstart(Node*& head, int value) {
    Node* newNode = new Node(value, head);
    head = newNode;
}

void addinmiddle(Node* head, int value) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }

    int middle;
    if (length % 2 == 0) {
        middle = (length / 2) - 1;
    } else {
        middle = length / 2;
    }

    Node* newNode = new Node(value, nullptr);
    Node* temp = head;
    for (int i = 0; i < middle; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


Node* createlist() {
    Node* head = new Node(1, nullptr);
    head->next = new Node(3, nullptr);
    head->next->next = new Node(2, nullptr);
    head->next->next->next = new Node(5, nullptr);
    head->next->next->next->next = new Node(9, nullptr);
    head->next->next->next->next->next = new Node(5, nullptr);
    // head->next->next->next->next->next->next = new Node(6, nullptr);
    return head;
}

void bubbleSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    
    bool swapped;
    Node* current;
    Node* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}





int main(){
    Node* head = createlist();
    cout << "Initial list:" << endl;
    printList(head);

    addinend(head, 6);
    cout << "List after adding 6:" << endl;
    printList(head);
    delete head;  

    head = createlist();
    addinstart(head, 0);
    cout << "List after adding 0:" << endl;
    printList(head);
    delete head;

    head = createlist();
    addinmiddle(head, 7);
    cout << "List after adding 7 in the middle:" << endl;
    printList(head);
    delete head;

    head = createlist();
    bubbleSort(head);
    cout << "Sorted list:" << endl;
    printList(head);
    delete head;


    return 0;
}
