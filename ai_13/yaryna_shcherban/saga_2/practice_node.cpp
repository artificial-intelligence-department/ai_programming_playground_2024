#include <iostream>

using namespace std;

// Однонаправлений список
struct Node {
    int data;
    Node* next;
};

// Двонаправлений список
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Функції для однонаправленого списку
void insertAtEnd(Node*& head, int value);
void insertAtStart(Node*& head, int value);
void insertAtMiddle(Node*& head, int value, int position);
void displayList(Node* head);
void bubbleSort(Node*& head);

// Функції для двонаправленого списку
void insertAtEnd(DNode*& head, DNode*& tail, int value);
void insertAtStart(DNode*& head, DNode*& tail, int value);
void insertAtMiddle(DNode*& head, int value, int position);
void displayListLeftToRight(DNode* head);
void displayListRightToLeft(DNode* tail);
void bubbleSort(DNode*& head);

// Функції для однонаправленого списку
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtStart(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertAtMiddle(Node*& head, int value, int position) {
    if (position == 0 || !head) {
        insertAtStart(head, value);
        return;
    }
    Node* newNode = new Node{value, nullptr};
    Node* temp = head;
    for (int i = 1; i < position && temp->next; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void bubbleSort(Node*& head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Функції для двонаправленого списку
void insertAtEnd(DNode*& head, DNode*& tail, int value) {
    DNode* newNode = new DNode{value, nullptr, nullptr};
    if (!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtStart(DNode*& head, DNode*& tail, int value) {
    DNode* newNode = new DNode{value, nullptr, head};
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

void displayListLeftToRight(DNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void displayListRightToLeft(DNode* tail) {
    while (tail) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

void bubbleSort(DNode*& head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        DNode* current = head;
        while (current->next) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}



int main() {

    cout << "Однонаправлений список:\n";
    Node* singlyHead = nullptr;
    
    // Однонаправлені операції
    insertAtEnd(singlyHead, 3);
    insertAtEnd(singlyHead, 1);
    insertAtStart(singlyHead, 5);
    insertAtMiddle(singlyHead, 4, 2);
    displayList(singlyHead);

    cout << "\n Сортування однонаправленого списку (методом бульбашки):\n";
    bubbleSort(singlyHead);
    displayList(singlyHead);

    cout << "\n Двонаправлений список:\n";
    DNode* doublyHead = nullptr;
    DNode* doublyTail = nullptr;

    // Двонаправлені операції
    insertAtEnd(doublyHead, doublyTail, 3);
    insertAtEnd(doublyHead, doublyTail, 1);
    insertAtStart(doublyHead, doublyTail, 5);
    insertAtMiddle(doublyHead, 4, 2);
    displayListLeftToRight(doublyHead);

    cout << "\n Сортування двонаправленого списку (методом бульбашки):\n";
    bubbleSort(doublyHead);
    displayListLeftToRight(doublyHead);

    cout << "\n Виведення двонаправленого списку справа наліво:\n";
    displayListRightToLeft(doublyTail);

    return 0;
}