#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void append(Node*& head, int value) {
    Node* newNode = createNode(value);
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

void prepend(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAfter(Node* prevNode, int value) {
    if (!prevNode) return;
    Node* newNode = createNode(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void bubbleSort(Node* head) {
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

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* createDNode(int value) {
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void appendD(DNode*& head, int value) {
    DNode* newNode = createDNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void prependD(DNode*& head, int value) {
    DNode* newNode = createDNode(value);
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}

void printListForward(DNode* head) {
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void printListBackward(DNode* tail) {
    DNode* temp = tail;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "nullptr" << endl;
}

void deleteDList(DNode*& head) {
    while (head) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* singleList = nullptr;
    append(singleList, 10);
    append(singleList, 20);
    prepend(singleList, 5);
    insertAfter(singleList, 15);
    cout << "Односпрямований список:" << endl;
    printList(singleList);

    bubbleSort(singleList);
    cout << "Відсортований односпрямований список:" << endl;
    printList(singleList);
    deleteList(singleList);

    DNode* doubleList = nullptr;
    appendD(doubleList, 30);
    appendD(doubleList, 40);
    prependD(doubleList, 20);
    prependD(doubleList, 10);
    cout << "Двоспрямований список (зліва направо):" << endl;
    printListForward(doubleList);

    DNode* tail = doubleList;
    while (tail && tail->next) {
        tail = tail->next;
    }

    cout << "Двоспрямований список (справа наліво):" << endl;
    printListBackward(tail);

    deleteDList(doubleList);

    return 0;
}
