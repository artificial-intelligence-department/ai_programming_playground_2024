#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:

    // Конструктор
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Деструктор
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Додавання елемента в кінець списку
    void append(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Додавання елемента на початок списку
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Виведення всіх елементів списку
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};

int main() {
    DoublyLinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.prepend(5);
    list.prepend(0);

    list.print();

    return 0;
}
