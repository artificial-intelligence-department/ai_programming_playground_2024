#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

struct Node {
    int key;
    shared_ptr<Node> next;
};

class LinkedList {
private:
    shared_ptr<Node> head;

public:
    LinkedList() : head(nullptr) {}

    // 1. Додавання елемента в список
    void addElement(int key, int position = -1) {
        auto newNode = make_shared<Node>();
        newNode->key = key;
        newNode->next = nullptr;

        if (!head || position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        auto current = head;
        int index = 0;
        while (current->next && (position == -1 || index < position - 1)) {
            current = current->next;
            index++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // 2. Видалення K елементів із заданого номера
    void deleteElements(int position, int k) {
        if (!head) return;

        auto current = head;
        shared_ptr<Node> prev = nullptr;

        for (int i = 0; i < position && current; ++i) {
            prev = current;
            current = current->next;
        }

        for (int i = 0; i < k && current; ++i) {
            if (prev) prev->next = current->next;
            else head = current->next;

            current = current->next;
        }
    }

    // 3. Друк списку
    void printList() const {
        if (!head) {
            cout << "Список порожній" << endl;
            return;
        }

        auto current = head;
        while (current) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 4. Запис списку у файл
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Помилка відкриття файлу для запису!" << endl;
            return;
        }

        auto current = head;
        while (current) {
            file << current->key << " ";
            current = current->next;
        }
    }

    // 5. Відновлення списку з файлу
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Помилка відкриття файлу для читання!" << endl;
            return;
        }

        head = nullptr;
        int key;
        while (file >> key) {
            addElement(key);
        }
    }

    // 6. Знищення списку
    void clearList() {
        head = nullptr;
    }
};

int main() {
    LinkedList list;

    // 1. Створення списку
    cout << "Створення списку:" << endl;
    list.addElement(10);
    list.addElement(20);
    list.addElement(30);
    list.addElement(40);
    list.printList();

    // 2. Додавання елемента у список
    cout << "Додавання елемента в список:" << endl;
    list.addElement(25, 2); // Додаємо 25 на позицію 2
    list.printList();

    // 3. Видалення елементів зі списку
    cout << "Видалення 2 елементів, починаючи з позиції 1:" << endl;
    list.deleteElements(1, 2);
    list.printList();

    // 4. Запис у файл
    cout << "Запис списку у файл 'list.txt':" << endl;
    list.saveToFile("list.txt");

    // 5. Знищення списку
    cout << "Знищення списку:" << endl;
    list.clearList();
    list.printList();

    // 6. Відновлення списку з файлу
    cout << "Відновлення списку з файлу 'list.txt':" << endl;
    list.loadFromFile("list.txt");
    list.printList();

    // 7. Знищення списку остаточно
    cout << "Остаточне знищення списку:" << endl;
    list.clearList();
    list.printList();

    return 0;
}
