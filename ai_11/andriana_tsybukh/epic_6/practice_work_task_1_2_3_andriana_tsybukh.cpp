#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// task 1
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// task 2
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return (h1 == nullptr && h2 == nullptr);
}

// task 3
Node* add(Node* n1, Node* n2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
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
        current->next = new Node(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // task 1
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    list1->next->next->next = new Node(4);

    cout << "Original list: ";
    printList(list1);

    list1 = reverse(list1);
    cout << "Reversed list: ";
    printList(list1);

    // task 2
    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);

    Node* list3 = new Node(1);
    list3->next = new Node(2);
    list3->next->next = new Node(3);

    cout << "Lists are " << (compare(list2, list3) ? "equal" : "not equal") << endl;

    // task 3
    Node* num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    Node* num2 = new Node(5);
    num2->next = new Node(4);
    num2->next->next = new Node(8);

    cout << "Sum list: ";
    Node* sum = add(num1, num2);
    printList(sum);

    return 0;
}
