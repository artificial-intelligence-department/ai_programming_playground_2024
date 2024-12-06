#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};


// Task 1
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Task 2
bool compare(Node* h1, Node* h2) {
    while (h1 != NULL && h2 != NULL) {
        if (h1->data != h2->data)
            return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == NULL && h2 == NULL;
}

// Task 3
Node* add(Node* n1, Node* n2) {
    Node* result = NULL;
    Node* tail = NULL;
    int carry = 0;

    while (n1 != NULL || n2 != NULL || carry != 0) {
        int sum = carry;
        if (n1 != NULL) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != NULL) {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10;
        Node* newNode = new Node(sum % 10);

        if (result == NULL) {
            result = newNode;
            tail = result;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}



int main() {
    // Task 1
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    cout << "Вхідний список: ";
    printList(list1);
    list1 = reverse(list1);
    cout << "Обернений список: ";
    printList(list1);

    // Task 2
    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);

    // Task 3
    Node* num1 = new Node(9);
    num1->next = new Node(9);
    Node* num2 = new Node(1);
    Node* sum = add(num1, num2);
    cout << "Сума чисел: ";
    printList(sum);
    return 0;
}
