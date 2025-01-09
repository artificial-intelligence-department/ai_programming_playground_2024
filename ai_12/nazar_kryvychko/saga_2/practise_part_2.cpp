#include <iostream>
#include <string>

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void prepend(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertAfter(Node* head, int target, int value) {
    Node* current = head;
    while (current && current->data != target) {
        current = current->next;
    }
    if (current) {
        Node* newNode = new Node{value, current->next};
        current->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void bubbleSort(Node*& head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

int main() {
    Node* head = nullptr;
    append(head, 3);
    append(head, 1);
    append(head, 4);
    prepend(head, 2);
    insertAfter(head, 3, 5);
    printList(head);
    bubbleSort(head);
    printList(head);
    return 0;
}
