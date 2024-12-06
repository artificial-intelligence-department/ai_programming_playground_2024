#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

bool compare(Node* h1, Node* h2) {
    while (h1 && h2) {
        if (h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

int main() {
    Node* h1 = new Node(1);
    h1->next = new Node(2);
    h1->next->next = new Node(3);

    Node* h2 = new Node(1);
    h2->next = new Node(2);
    h2->next->next = new Node(3);

    cout << (compare(h1, h2) ? "Lists are equal" : "Lists are not equal") << endl;

    h2->next->next->data = 4;
    cout << (compare(h1, h2) ? "Lists are equal" : "Lists are not equal") << endl;

    return 0;
}
