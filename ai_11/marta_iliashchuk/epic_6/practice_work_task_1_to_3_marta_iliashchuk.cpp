#include <iostream>
using namespace std;

struct Node {
    int nodeValue;
    Node* nextNodeValue;


    Node(int value) : nodeValue(value), nextNodeValue(nullptr) {}
};

// Task 1: Reversing linked list
Node* reverse(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->nextNodeValue;
        current->nextNodeValue = prev; // 1 -> nullptr, next - current...4 - >... 2 ->...
        prev = current;
        current = next;
    }

    return prev;
}

// Task 2: Comparing two linked lists
// Going through all elements while element = element
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->nodeValue != h2->nodeValue) {
            return false;
        }
        h1 = h1->nextNodeValue;
        h2 = h2->nextNodeValue;
    }
    return h1 == nullptr && h2 == nullptr;
}

void addToList(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* x = head;
        while (x->nextNodeValue != nullptr) {
            x = x->nextNodeValue;
        }
        x->nextNodeValue = newNode;
    }
}

// Task 3: Adding two linked lists
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* x = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry;
        if (n1 != nullptr) {
            sum += n1->nodeValue;
            n1 = n1->nextNodeValue;
        }

        if (n2 != nullptr) {
            sum += n2->nodeValue;
            n2 = n2->nextNodeValue;
        }

        carry = sum / 10;
        int digit = sum % 10;

        addToList(result, digit);
    }

    return result;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->nodeValue << " ";
        head = head->nextNodeValue;
    }
    cout << endl;
}

void printElements(Node* head) {
    head = reverse(head);
    while (head != nullptr) {
        cout << head->nodeValue;
        head = head->nextNodeValue;
    }
    cout << endl;
}

// Free memory
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->nextNodeValue;
        delete temp;
    }
}

int main() {
    Node* head = nullptr; 
    addToList(head, 1);
    addToList(head, 2);
    addToList(head, 3);
    addToList(head, 4);

    cout << "Task 1" << endl;
    printList(head);

    head = reverse(head);

    cout << "Reversed list: " << endl;
    printList(head);

    Node* h1 = nullptr; 
    addToList(h1, 1);
    addToList(h1, 3);
    addToList(h1, 7);
    addToList(h1, 5);

    cout << endl << "Task 2: " << endl;
    cout << "First list: " << endl;
    printList(h1);

    Node* h2 = nullptr; 
    addToList(h2, 1);
    addToList(h2, 4);
    addToList(h2, 7);

    cout << "Second list: " << endl;
    printList(h2);

    if (compare(h1, h2)) {
        cout << "=" << endl;
    } else {
        cout << "!=" << endl;
    }

    cout << endl << "Task 3: " << endl;
    Node* result = add(h1, h2);

    cout << "Number: ";
    printElements(h1);
    cout << "Next number: ";
    printElements(h2);
    cout << "Sum: ";
    printElements(result);

// Free memory
    clearList(head);
    clearList(h1);
    clearList(h2);
    clearList(result);

    return 0;
}