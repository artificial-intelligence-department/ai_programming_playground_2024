#include <iostream>
using namespace std;

// Структура вузла
struct Node {
    int data;
    Node* next;
};

// Функція для створення нового вузла
Node* createNode(int data) {
    return new Node{data, nullptr};
}

// Функція для створення списку з масиву
Node* createList(const int arr[], int size) {
    if (size == 0) return nullptr;
    Node* head = createNode(arr[0]);
    Node* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Функція для друку списку
void printList(Node* head, bool reverse = false) {
    if (reverse) {
        if (!head) return;
        printList(head->next, true);
        cout << head->data;
    } else {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Реверс списку
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Порівняння двох списків
bool compare(Node* h1, Node* h2) {
    while (h1 && h2) {
        if (h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return !h1 && !h2;
}

// Додавання великих чисел
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (n1 || n2 || carry) {
        int sum = carry + (n1 ? n1->data : 0) + (n2 ? n2->data : 0);
        carry = sum / 10;
        sum %= 10;

        Node* newNode = createNode(sum);
        if (!result) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    return result;
}

int main() {
    // Створення списку з масиву
    int arr1[] = {1, 2, 3, 4, 5};
    Node* list1 = createList(arr1, 5);

    cout << "Original list: ";
    printList(list1);

    // Реверс списку
    Node* reversedList = reverse(list1);
    cout << "Reversed list: ";
    printList(reversedList);

    // Порівняння списків
    cout << "Lists are " << (compare(list1, reversedList) ? "equal." : "not equal.") << endl;

    // Додавання великих чисел
    int num1[] = {9, 9, 9};
    int num2[] = {1};
    Node* number1 = createList(num1, 3);
    Node* number2 = createList(num2, 1);

    Node* sum = add(number1, number2);
    cout << "Sum of numbers: ";
    printList(sum, true);  // Виводимо в прямому порядку
    cout << endl;

    return 0;
}
