#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0; 

    while (n1 != nullptr || n2 != nullptr || carry > 0) {
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
        int data = sum % 10;

        Node* newNode = new Node(data);

        if (result == nullptr) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return result;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node* n1 = new Node(9);
    n1->next = new Node(7);
    n1->next->next = new Node(3);

    Node* n2 = new Node(6);
    n2->next = new Node(4);
    n2->next->next = new Node(8);

    Node* result = add(n1, n2);

    cout << "Результат додавання: ";
    printList(result);

    delete n1->next->next; delete n1->next; delete n1;
    delete n2->next->next; delete n2->next; delete n2;
    delete result->next->next; delete result->next; delete result;

    return 0;
}