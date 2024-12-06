#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;

    Node(string val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add(string value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(int position) {
        if (!head) {
            cout << "Список порожній.\n";
            return;
        }

        Node* temp = head;
        int index = 1;

        while (temp && index < position) {
            temp = temp->next;
            index++;
        }

        if (!temp) {
            cout << "Елемент з номером " << position << " не знайдено.\n";
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Елемент з номером " << position << " видалено.\n";
    }

    void print() {
        if (!head) {
            cout << "Список порожній.\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Не вдалося відкрити файл.\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            file << temp->data << endl;
            temp = temp->next;
        }

        file.close();
        cout << "Список збережено у файл " << filename << ".\n";
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Не вдалося відкрити файл.\n";
            return;
        }

        clear();

        string line;
        while (getline(file, line)) {
            add(line);
        }

        file.close();
        cout << "Список відновлено з файлу " << filename << ".\n";
    }

    void clear() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }

        head = tail = nullptr;
        cout << "Список знищено.\n";
    }

    ~DoublyLinkedList() {
        clear();
    }
};

int main() {
    DoublyLinkedList list;
    string filename = "list.txt";

    list.add("Елемент 1");
    list.add("Елемент 2");
    list.add("Елемент 3");

    cout << "Список після створення:\n";
    list.print();

    int position;
    cout << "Введіть номер елемента, який хочете видалити: ";
    cin >> position;
    list.remove(position);
    cout << "Список після видалення елемента:\n";
    list.print();

    list.add("Елемент 4");
    cout << "Список після додавання нового елемента:\n";
    list.print();

    list.saveToFile(filename);

    list.clear();
    cout << "Список після знищення:\n";
    list.print();

    list.loadFromFile(filename);
    cout << "Список після відновлення з файлу:\n";
    list.print();

    list.clear();

    return 0;
}
