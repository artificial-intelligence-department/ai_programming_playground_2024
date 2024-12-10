#include <iostream>
using namespace std;

// Структури для вузлів
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

struct DoubleNode {
    int data;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

//Linked list
void addToEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addToFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void addAfter(Node* prevNode, int value) {
    if (!prevNode) {
        cout << "Error" << endl;
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

// Double linked list
void addToEnd(DoubleNode*& head, int value) {
    DoubleNode* newNode = new DoubleNode(value);
    if (!head) {
        head = newNode;
    } else {
        DoubleNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void addToFront(DoubleNode*& head, int value) {
    DoubleNode* newNode = new DoubleNode(value);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addAfter(DoubleNode* prevNode, int value) {
    if (!prevNode) {
        cout << "Error" << endl;
        return;
    }
    DoubleNode* newNode = new DoubleNode(value);
    newNode->next = prevNode->next;
    if (prevNode->next) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    newNode->prev = prevNode;
}

void printListForward(DoubleNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printListBackward(DoubleNode* head) {
    if (!head) return;
    while (head->next) {
        head = head->next;
    }
    while (head) {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

void bubbleSort(DoubleNode* head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        DoubleNode* temp = head;
        while (temp && temp->next) {
            if (temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}


int main() {
// Linked list
    Node* sList = nullptr;
    addToEnd(sList, 10);
    addToEnd(sList, 20);
    addToEnd(sList, 30);
    addToFront(sList, 5);
    addAfter(sList->next, 25);
    cout << "Linked list: ";
    printList(sList);

    cout << "Linked list після сортування методом бульбашки: ";
    bubbleSort(sList);
    printList(sList);

// Double linked list
    DoubleNode* dList = nullptr;
    addToEnd(dList, 10);
    addToEnd(dList, 20);
    addToEnd(dList, 30);
    addToFront(dList, 5);
    addAfter(dList->next, 25);
    cout << "Double linked list (ліво на право): ";
    printListForward(dList);

    cout << "Double linked list (право на ліво): ";
    printListBackward(dList);

    cout << "Double linked list після сортування методом бульбашки: ";
    bubbleSort(dList);
    printListForward(dList);

    return 0;
}
