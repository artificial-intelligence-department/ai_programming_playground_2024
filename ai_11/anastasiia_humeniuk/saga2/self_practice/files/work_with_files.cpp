#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data; 
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void printList(Node* head) {
    if (head == nullptr) {
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

void printList(Node* head, ofstream& outFile) {
    if (!outFile.is_open()) {
        cerr << "Cannot write to file" << endl;
        return;
    }
    if (head == nullptr) {
        return;
    }
    outFile << head->data << " ";
    printList(head->next, outFile);
}

void printList(Node* head, bool isIterative) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

void printList(Node* head, ofstream& outFile, bool isIterative) {
    if (!outFile.is_open()) {
        cerr << "Cannot write to file" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        outFile << current->data << " ";
        current = current->next;
    }
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(8);
    head->next->next = new Node(2);

    cout << "Рекурсивна функція: ";
    printList(head);
    cout << endl;

    ofstream outFile("recursive.txt");
    if (outFile.is_open()) {
        printList(head, outFile);
        outFile.close();
    } else {
        cerr << "Error" << endl;
    }

    cout << "Функція через цикл: ";
    printList(head, true);
    cout << endl;

    ofstream outFileIterative("iterative.txt");
    if (outFileIterative.is_open()) {
        printList(head, outFileIterative, true);
        outFileIterative.close();
    } else {
        cerr << "Error" << endl;
    }

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
