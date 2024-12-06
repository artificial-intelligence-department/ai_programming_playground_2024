#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

bool compare(Node* h1, Node* h2) {
    while (h1 && h2) {
        if (h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* tail = nullptr;
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
        int digit = sum % 10;
        Node* newNode = new Node(digit);
        if (!result) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return result;
}

Node* createListFromArray(int arr[], int size) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < size; ++i) {
        Node* newNode = new Node(arr[i]);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    Node* list1 = createListFromArray(arr1, 5);
    cout << "Original List: ";
    printList(list1);
    list1 = reverse(list1);
    cout << "Reversed List: ";
    printList(list1);

    int arr2[] = {1, 2, 3, 4, 5};
    Node* list2 = createListFromArray(arr2, 5);
    cout << "Lists are " << (compare(list1, list2) ? "equal" : "not equal") << "." << endl;

    int num1[] = {9, 9, 9};
    int num2[] = {1};
    Node* number1 = createListFromArray(num1, 3);
    Node* number2 = createListFromArray(num2, 1);
    cout << "Number 1: ";
    printList(number1);
    cout << "Number 2: ";
    printList(number2);
    Node* sum = add(number1, number2);
    cout << "Sum: ";
    printList(sum);
    return 0;
}
