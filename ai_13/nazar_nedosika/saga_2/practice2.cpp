#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct DoubleNode {
    int data;
    DoubleNode* prev;
    DoubleNode* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

DoubleNode* createDoubleNode(int value) {
    DoubleNode* newNode = new DoubleNode();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void append(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void prepend(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAfter(Node* prevNode, int value) {
    if (prevNode == nullptr) {
        return;
    }
    Node* newNode = createNode(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSort(Node* head) {
    if (head == nullptr) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;
    do {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void appendDouble(DoubleNode*& head, int value) {
    DoubleNode* newNode = createDoubleNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    DoubleNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void prependDouble(DoubleNode*& head, int value) {
    DoubleNode* newNode = createDoubleNode(value);
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertAfterDouble(DoubleNode* prevNode, int value) {
    if (prevNode == nullptr) {
        return;
    }
    DoubleNode* newNode = createDoubleNode(value);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

void printListForward(DoubleNode* head) {
    DoubleNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printListBackward(DoubleNode* tail) {
    DoubleNode* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void bubbleSortDouble(DoubleNode* head) {
    if (head == nullptr) return;
    bool swapped;
    DoubleNode* ptr1;
    DoubleNode* lptr = nullptr;
    do {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Node* head = nullptr;
    DoubleNode* doubleHead = nullptr;

    append(head, 3);
    append(head, 1);
    append(head, 4);
    append(head, 2);

    printList(head);
    prepend(head, 5);
    
    printList(head);
    insertAfter(head->next, 6);
    printList(head);
    bubbleSort(head);
    printList(head);

    appendDouble(doubleHead, 3);
    appendDouble(doubleHead, 1);
    appendDouble(doubleHead, 4);
    appendDouble(doubleHead, 2);

    printListForward(doubleHead);
    prependDouble(doubleHead, 5);
    printListForward(doubleHead);
    insertAfterDouble(doubleHead->next, 6);

    printListForward(doubleHead);
    bubbleSortDouble(doubleHead);
    printListForward(doubleHead);
    printListBackward(doubleHead);
    return 0;
}