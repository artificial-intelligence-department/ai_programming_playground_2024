#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry) {
        int sum = carry;

        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10;
        Node* newNode = new Node(sum % 10);

        if (result == nullptr) {
            result = newNode;
            tail = result;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return result;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* n1 = new Node(9);
    n1->next = new Node(7);
    n1->next->next = new Node(3);  // Number: 379

    Node* n2 = new Node(1);
    n2->next = new Node(5);
    n2->next->next = new Node(2);  // Number: 251

    cout << "Number 1: ";
    printList(n1);

    cout << "Number 2: ";
    printList(n2);

    Node* sum = add(n1, n2);

    cout << "Sum: ";
    printList(sum);

    return 0;
}
