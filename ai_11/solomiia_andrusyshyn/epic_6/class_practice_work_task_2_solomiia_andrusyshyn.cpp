#include <iostream>
using namespace std;

struct Node {
    int data;         
    Node* next;       

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

bool compareLists(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) { 
            return false;
        }
        head1 = head1->next; 
        head2 = head2->next;
    }

    if (head1 == nullptr && head2 == nullptr) {
        return true;
    } else {
        return false;
    }
}

void addToStart(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode; 
}

void addToEnd(Node*& head, int value) {
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
    Node* list1 = nullptr; 
    addToEnd(list1, 1);
    addToEnd(list1, 2);
    addToEnd(list1, 3);

    Node* list2 = nullptr; 
    addToStart(list2, 3);
    addToStart(list2, 2);
    addToStart(list2, 1);

    if (compareLists(list1, list2)) {
        cout << "Списки однакові" << endl;
    } else {
        cout << "Списки різні" << endl;
    }

    return 0;
}
