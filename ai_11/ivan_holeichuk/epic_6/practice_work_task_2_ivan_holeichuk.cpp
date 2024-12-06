#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
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

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    Node* head3 = new Node(1);
    head3->next = new Node(4);
    head3->next->next = new Node(3);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    cout << "List 3: ";
    printList(head3);

    cout << "List 1 and List 2 are equal: " << (compare(head1, head2) ? "Yes" : "No") << endl;
    cout << "List 1 and List 3 are equal: " << (compare(head1, head3) ? "Yes" : "No") << endl;

    return 0;
}
