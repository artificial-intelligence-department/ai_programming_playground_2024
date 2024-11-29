#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string key;
    Node* prev;
    Node* next;

    Node(const string& value) : key(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void createEmptyList() {
        head = tail = nullptr;
    }

    void append(const string& key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void prepend(const string& key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void printList() const {
        if (!head) {
            cout << "Список порожній!" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->key << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void deleteByKey(const string& key) {
        if (!head) {
            cout << "Список порожній! Видалення неможливе." << endl;
            return;
        }

        Node* current = head;
        while (current && current->key != key) {
            current = current->next;
        }

        if (!current) {
            cout << "Елемент із ключем '" << key << "' не знайдено." << endl;
            return;
        }

        if (current == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else if (current == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Елемент із ключем '" << key << "' видалено." << endl;
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Помилка відкриття файлу для запису." << endl;
            return;
        }

        Node* current = head;
        while (current) {
            file << current->key << endl;
            current = current->next;
        }

        file.close();
        cout << "Список збережено у файл '" << filename << "'." << endl;
    }

    void restoreFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Помилка відкриття файлу для читання." << endl;
            return;
        }

        destroyList();

        string key;
        while (getline(file, key)) {
            append(key);
        }

        file.close();
        cout << "Список відновлено з файлу '" << filename << "'." << endl;
    }

    void destroyList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "Список знищено." << endl;
    }

    ~DoublyLinkedList() {
        destroyList();
    }
};

int main() {
    DoublyLinkedList list;
    list.createEmptyList();

    list.append("Елемент1");
    list.append("Елемент2");
    list.append("Елемент3");
    list.printList();

    list.prepend("НовийЕлемент");
    list.printList();

    string keyToDelete;
    cout << "Введіть ключ для видалення: ";
    cin >> keyToDelete;
    list.deleteByKey(keyToDelete);
    list.printList();

    list.saveToFile("list.txt");
    list.destroyList();
    list.printList();

    list.restoreFromFile("list.txt");
    list.printList();

    list.destroyList();
    list.printList();

    return 0;
}
