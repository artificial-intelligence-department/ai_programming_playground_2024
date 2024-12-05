#include <iostream>

using namespace std;

// Структура для елементу списку
struct Node {
    int data; // Якесь значення
    Node* next; // вказівник на наступний елемент
};

// Функція для реверсування списку
Node* reverse(Node* head) {
    Node* prev = nullptr; // попередній елемент
    Node* current = head; // поточний елемент
    Node* next = nullptr; // наступний елемент

    // Ітеративно змінюємо напрямок кожного покажчика
    while (current != nullptr) {
        next = current->next; // зберігаємо вказівник на наступний елемент
        current->next = prev; // змінюємо напрямок покажчика
        prev = current; // рухаємося вперед
        current = next; // переходимо до наступного елемента
    }

    return prev;
}

// Для виведення списку
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " "; // виводимо значення елемента
        temp = temp->next; // переходимо до наступного елемента
    }
    cout << endl;
}

// Функція для створення нового елемента списку
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

int main() {
    // Створюємо список
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    cout << "Original list: ";
    printList(head); // Виведення початкового списку

    // Реверсування списку
    head = reverse(head);

    cout << "Reversed list: ";
    printList(head); // Виведення оберненого списку

    return 0;
}
