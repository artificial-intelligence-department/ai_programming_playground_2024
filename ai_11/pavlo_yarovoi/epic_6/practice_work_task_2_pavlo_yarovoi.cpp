#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void append(Node*& head, int value) {
    Node* newNode = new Node(value);
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

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    if (h1 != nullptr || h2 != nullptr) {
        return false;
    }

    return true;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    append(list1, 1);
    append(list1, 2);
    append(list1, 3);

    append(list2, 1);
    append(list2, 2);
    append(list2, 3);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    if (compare(list1, list2)) {
        cout << "Same." << endl;
    } else {
        cout << "Different." << endl;
    }

    append(list2, 4);

    cout << "\nNew List 2: ";
    printList(list2);

    if (compare(list1, list2)) {
        cout << "Same." << endl;
    } else {
        cout << "Different." << endl;
    }

    return 0;
}
