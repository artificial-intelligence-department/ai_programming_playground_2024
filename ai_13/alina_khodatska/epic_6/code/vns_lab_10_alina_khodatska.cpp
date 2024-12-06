#include <iostream>
#include <cstring> // для функцій strcpy_s, strlen
#include <fstream> // для роботи з файлами

struct Node { // Структура для представлення елемента списку
    char* data;
    Node* next;
    Node* prev;

    // Конструктор
    Node(const char* str) {
		data = new char[strlen(str) + 1]; // strlen повертає довжину рядка str
		strcpy_s(data, strlen(str) + 1, str); // strcpy_s копіює рядок str в data
		next = prev = nullptr;  // nullptr - це константа, яка вказує на нуль-вказівник
    }

    // Деструктор
    ~Node() {
        delete[] data;
    }
};

class DoublyLinkedList { // Клас для представлення двоспрямованого списку
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    void add(const char* data) { // Додавання елемента у кінець списку
		Node* newNode = new Node(data); // Створення нового елемента
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(const char* key) { // Видалення елемента зі списку
		Node* current = head; // Починаємо з голови списку
        while (current) { 
			if (strcmp(current->data, key) == 0) {  // strcmp порівнює два рядки
                if (current->prev)
                    current->prev->next = current->next;
                if (current->next)
                    current->next->prev = current->prev;
                if (current == head)
                    head = current->next;
                if (current == tail)
                    tail = current->prev;
                Node* toDelete = current;
                current = current->next;
                delete toDelete;
            }
            else {
                current = current->next;
            }
        }
    }

    void addAfter(const char* key, const char* data) { // Додавання елемента після заданого ключа
        Node* current = head; 
        while (current) { 
			if (strcmp(current->data, key) == 0) {  // пошук ключа
                Node* newNode = new Node(data);
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next)
                    current->next->prev = newNode;
                current->next = newNode;
                if (current == tail)
                    tail = newNode;
                break;
            }
            current = current->next;
        }
    }

    void print() const { // Друк списку
        if (!head) {
            std::cout << "List is empty\n";
            return;
        }
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    void saveToFile(const char* filename) const { // Запис списку у файл
		std::ofstream outFile(filename); // відкриття файлу для запису
        Node* current = head; 
        while (current) {
            outFile << current->data << "\n";
            current = current->next;
        }
        outFile.close();
    }

    void loadFromFile(const char* filename) { // Відновлення списку з файлу
        clear();
        std::ifstream inFile(filename);
		char buffer[256]; // буфер для зчитування рядків з файлу (буфер - це масив символів)
        while (inFile.getline(buffer, 256)) {
            add(buffer);
        }
        inFile.close();
    }

    void clear() { // Знищення списку
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = tail = nullptr;
    }
};

int main() {
	DoublyLinkedList list;  // double linked list - використовується для зберігання списку елементів

    // Додавання елементів у список
    list.add("apple");
    list.add("banana");
    list.add("cherry");

    // Друк списку
    std::cout << "List after adding items: ";
    list.print();

    // Додавання елемента після заданого ключа
    list.addAfter("banana", "blueberry");

    std::cout << "List after adding 'blueberry' after 'banana': ";
    list.print();

    // Видалення елемента зі списку
    list.remove("banana");

    std::cout << "List after 'banana' removal: ";
    list.print();

    // Запис списку у файл
    list.saveToFile("list.txt");

    // Знищення списку
    list.clear();
    std::cout << "List after destruction: ";
    list.print();

    // Відновлення списку з файлу
    list.loadFromFile("list.txt");

    std::cout << "List after recovery from file: ";
    list.print();

    // Знищення списку
    list.clear();
    std::cout << "List after destruction: ";
    list.print();

    return 0;
}
