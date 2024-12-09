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
    DNode* next;
    DNode* prev;
};

//----------------------------------------------------------------------------

// Функції для роботи з однонаправленим списком
void addNodeToEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void addNodeToStart(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void addNodeAfter(Node* head, int afterValue, int newValue) {
    Node* temp = head;
    while (temp && temp->data != afterValue) temp = temp->next;
    if (temp) {
        Node* newNode = new Node{newValue, temp->next};
        temp->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null\n";
}

void bubbleSortList(Node*& head) {
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

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

// Функції для роботи з двонаправленим списком
void addNodeToEnd(DNode*& head, DNode*& tail, int value) {
    DNode* newNode = new DNode{value, nullptr, tail};
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void addNodeToStart(DNode*& head, DNode*& tail, int value) {
    DNode* newNode = new DNode{value, head, nullptr};
    if (!head) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
}

void printListForward(DNode* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "null\n";
}

void printListBackward(DNode* tail) {
    while (tail) {
        cout << tail->data << " <-> ";
        tail = tail->prev;
    }
    cout << "null\n";
}

//----------------------------------------------------------------------------

int main() {
    //------------------------------------------------------
    // Робота з однонаправленим списком
    Node* singleList = nullptr;

    addNodeToEnd(singleList, 10);
    addNodeToEnd(singleList, 20);
    addNodeToStart(singleList, 5);
    addNodeAfter(singleList, 10, 15);

    cout << "Однонаправлений список до сортування:\n";
    printList(singleList);

    bubbleSortList(singleList);
    cout << "Однонаправлений список після сортування:\n";
    printList(singleList);

    //------------------------------------------------------

    //------------------------------------------------------

    // Робота з двонаправленим списком
    DNode* doubleListHead = nullptr;
    DNode* doubleListTail = nullptr;

    addNodeToEnd(doubleListHead, doubleListTail, 10);
    addNodeToEnd(doubleListHead, doubleListTail, 20);
    addNodeToStart(doubleListHead, doubleListTail, 5);

    cout << "Двонаправлений список зліва направо:\n";
    printListForward(doubleListHead);

    cout << "Двонаправлений список справа наліво:\n";
    printListBackward(doubleListTail);

    //------------------------------------------------------

    return 0;
}
