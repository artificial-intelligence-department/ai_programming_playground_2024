#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Task 1: Reverse the list
Node* Reversal(Node* main) {
    Node* prev = nullptr;
    Node* curr = main;
    Node* next = nullptr;
    
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

void Print(Node* main) {
    Node* temp = main;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteList(Node* &head) {
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
}

//Task 2: Compare lists
bool Compare(Node* h1, Node* h2) {

    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return h1 == nullptr && h2 == nullptr;
}

// Task 3: Add numbers
Node* Add(Node* n1, Node* n2){
    Node* res = nullptr;
    Node* temp = nullptr;
    int strg = 0;

    while (n1 != nullptr || n2 != nullptr || strg > 0) {
        int sum = strg;
        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        strg = sum / 10;
        int data = sum % 10;

        Node* newNode = new Node(data);

        if (res == nullptr) {
            res = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return res;
}

int main() {
    // Task 1
    Node* main = new Node(4);
    main->next = new Node(3);
    main->next->next = new Node(2);
    main->next->next->next = new Node(1);

    cout << "Original list: ";
    Print(main);
    
    main = Reversal(main);
    
    cout << "Reversed list: ";
    Print(main);

    deleteList(main);

    // Task 2
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(5);

    if (Compare(head1, head2)) {
        cout << "Lists are equal\n";
    } else {
        cout << "Lists are different\n";
    }

    deleteList(head1);
    deleteList(head2);

    // Task 3
    Node* n1 = new Node(9);
    n1->next = new Node(7);
    n1->next->next = new Node(3);

    Node* n2 = new Node(6);
    n2->next = new Node(4);
    n2->next->next = new Node(8);

    Node* res = Add(n1, n2);

    cout << "Result: ";
    Print(res);

    deleteList(n1);
    deleteList(n2);

    return 0;
}