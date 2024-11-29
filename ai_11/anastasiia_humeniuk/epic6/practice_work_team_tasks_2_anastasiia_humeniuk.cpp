#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

bool compare(Node* h1, Node* h2) {

    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return h1 == nullptr && h2 == nullptr;
}

void push(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void pushToEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    Node* head1 = nullptr;
    pushToEnd(head1, 1);
    pushToEnd(head1, 2);
    pushToEnd(head1, 3);

    Node* head2 = nullptr;
    push(head2, 3);
    push(head2, 2);
    push(head2, 1);

    if (compare(head1, head2)) {
        cout << "Списки однакові" << endl;
    } else {
        cout << "Списки різні" << endl;
    }

    delete head1;
    delete head2;

    return 0;
}
