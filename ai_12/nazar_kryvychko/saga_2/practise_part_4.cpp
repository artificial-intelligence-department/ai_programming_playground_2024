#include <iostream>
#include <fstream>
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

void printList(Node* head) {
    if (!head) return;
    std::cout << head->data << " ";
    printList(head->next);
}

void printList(Node* head, std::ofstream& file) {
    if (!head) return;
    file << head->data << " ";
    printList(head->next, file);
}

void printListIterative(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void printListIterative(Node* head, std::ofstream& file) {
    Node* current = head;
    while (current) {
        file << current->data << " ";
        current = current->next;
    }
    file << std::endl;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);

    std::cout << "Recursive console output: ";
    printList(head);
    std::cout << std::endl;

    std::ofstream outFileRecursive("D:\\nulp\\OP\\AllEpics\\saga_2\\practise\\list_recursive.txt");
    if (outFileRecursive.is_open()) {
        printList(head, outFileRecursive);
        outFileRecursive.close();
        std::cout << "Data written recursively to file: list_recursive.txt" << std::endl;
    }

    std::cout << "Iterative console output: ";
    printListIterative(head);

    std::ofstream outFileIterative("list_iterative.txt");
    if (outFileIterative.is_open()) {
        printListIterative(head, outFileIterative);
        outFileIterative.close();
        std::cout << "Data written iteratively to file: list_iterative.txt" << std::endl;
    }

    return 0;
}
