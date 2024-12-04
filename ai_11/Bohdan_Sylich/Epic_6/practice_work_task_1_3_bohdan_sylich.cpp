#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    int carry = 0;

    while (n1 || n2 || carry) {
        int sum = carry;
        if (n1) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2) {
            sum += n2->data;
            n2 = n2->next;
        }
        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

void printList(Node* head) {
    while (head) {
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
    n2->next = new Node(8);

    Node* result = add(n1, n2);

    printList(result);

    return 0;
}
