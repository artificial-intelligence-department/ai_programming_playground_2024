#include <iostream>
#include <fstream>

struct Node {
    int key;
    Node* next;

    Node(int k) : key(k), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Функція перевірки, чи список порожній
    bool isEmpty() const {
        return head == nullptr;
    }

    // Функція для додавання елементу в кінець списку
    void add(int key) {
        Node* newNode = new Node(key);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Функція для друку списку
    void print() const {
        if (isEmpty()) {
            std::cout << "Список порожній.\n";
            return;
        }
        Node* current = head;
        while (current) {
            std::cout << current->key << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Функція для видалення К елементів, починаючи з заданого номера
    void deleteKElementsFrom(int startPos, int k) {
        if (isEmpty()) {
            std::cout << "Список порожній. Видалення неможливе.\n";
            return;
        }

        if (startPos < 1) {
            std::cout << "Номер позиції повинен бути >= 1.\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        for (int i = 1; i < startPos && current; ++i) {
            prev = current;
            current = current->next;
        }

        for (int i = 0; i < k && current; ++i) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        if (prev) {
            prev->next = current;
        } else {
            head = current;
        }
    }

    // Функція для додавання елемента перед вузлом із заданим ключем
    void addBefore(int key, int newKey) {
        Node* newNode = new Node(newKey);
        if (isEmpty()) {
            std::cout << "Список порожній. Операція неможлива.\n";
            delete newNode;
            return;
        }

        if (head->key == key) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (current) {
            newNode->next = current;
            if (prev) {
                prev->next = newNode;
            }
        } else {
            std::cout << "Елемент із ключем " << key << " не знайдено.\n";
            delete newNode;
        }
    }

    // Функція для запису списку у файл
    void writeToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            std::cout << "Помилка запису у файл.\n";
            return;
        }
        Node* current = head;
        while (current) {
            file << current->key << " ";
            current = current->next;
        }
        file.close();
    }

    // Функція для відновлення списку з файлу
    void readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cout << "Помилка читання з файлу.\n";
            return;
        }

        clear();
        int key;
        while (file >> key) {
            add(key);
        }
        file.close();
    }

    // Функція для очищення списку
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~LinkedList() {
        clear();
    }
};

int main() {
    LinkedList list;

    // Додавання елементів
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);
    list.print();

    // Видалення К елементів із заданої позиції
    list.deleteKElementsFrom(2, 2);
    list.print();

    // Додавання елементу перед заданим ключем
    list.addBefore(40, 25);
    list.print();

    // Запис у файл
    list.writeToFile("list.txt");

    // Видалення списку
    list.clear();
    list.print();

    // Відновлення списку з файлу
    list.readFromFile("list.txt");
    list.print();

    // Знищення списку
    list.clear();
    list.print();

    return 0;
}
