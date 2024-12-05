#include <iostream>
#include <fstream>
using namespace std;

// Структура вузла двонаправленого списку
struct Node {
    int key;
    Node* next;
    Node* prev;

    Node(int value) : key(value), next(nullptr), prev(nullptr) {}
};

// Структура списку
struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // 1. Створення списку
    void createEmpty() {
        head = tail = nullptr;
    }

    // 2. Додавання елемента в кінець списку
    void addToEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 3. Знищення К елементів перед заданим номером
    void removeBefore(int position, int k) {
        if (!head || position <= 1) return; // Неможливо видалити перед першим елементом

        Node* current = head;
        for (int i = 1; i < position && current; ++i) {
            current = current->next;
        }

        if (!current) return;

        while (k-- > 0 && current->prev) {
            Node* toDelete = current->prev;
            if (toDelete->prev) {
                toDelete->prev->next = current;
            } else {
                head = current;
            }
            current->prev = toDelete->prev;
            delete toDelete;
        }
    }

    // 4. Друк списку
    void printList() {
        if (!head) {
            cout << "Список порожній" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 5. Запис списку у файл
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Помилка запису у файл" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            file << current->key << " ";
            current = current->next;
        }
        file.close();
        cout << "Список записаний у файл: " << filename << endl;
    }

    // 6. Знищення списку
    void destroyList() {
        while (head) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        tail = nullptr;
    }

    // 7. Відновлення списку з файлу
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Помилка читання з файлу" << endl;
            return;
        }
        destroyList();
        int value;
        while (file >> value) {
            addToEnd(value);
        }
        file.close();
        cout << "Список відновлений з файлу: " << filename << endl;
    }

    // Додавання К елементів у кінець списку
    void addKToEnd(int k) {
        for (int i = 0; i < k; ++i) {
            int value;
            cout << "Введіть значення для елемента " << (i + 1) << ": ";
            cin >> value;
            addToEnd(value);
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.createEmpty();

    // Початкове заповнення списку
    cout << "Створення списку" << endl;
    list.addToEnd(10);
    list.addToEnd(20);
    list.addToEnd(30);
    list.addToEnd(40);
    list.addToEnd(50);
    cout << "Початковий список: ";
    list.printList();

    // Видалення К елементів перед заданим номером
    int position, k;
    cout << "Введіть номер елемента для знищення К елементів перед ним: ";
    cin >> position;
    cout << "Введіть кількість елементів для знищення: ";
    cin >> k;
    list.removeBefore(position, k);
    cout << "Список після видалення: ";
    list.printList();

    // Додавання К елементів у кінець списку
    cout << "Введіть кількість елементів для додавання в кінець списку: ";
    cin >> k;
    list.addKToEnd(k);
    cout << "Список після додавання: ";
    list.printList();

    // Запис у файл
    string filename = "list.txt";
    list.saveToFile(filename);

    // Знищення списку
    list.destroyList();
    cout << "Список після знищення: ";
    list.printList();

    // Відновлення списку з файлу
    list.loadFromFile(filename);
    cout << "Список після відновлення: ";
    list.printList();

    // Остаточне знищення списку
    list.destroyList();
    cout << "Список остаточно знищений: ";
    list.printList();

    return 0;
}
