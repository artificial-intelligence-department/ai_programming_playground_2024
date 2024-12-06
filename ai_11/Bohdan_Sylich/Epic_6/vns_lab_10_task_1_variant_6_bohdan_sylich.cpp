#include <iostream>
#include <fstream>
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
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void addToStart(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void removeAt(int position) {
        if (!head) {
            cout << "Список порожній.\n";
            return;
        }
        Node* current = head;
        int index = 1;

        while (current && index < position) {
            current = current->next;
            index++;
        }

        if (!current) {
            cout << "Неправильна позиція.\n";
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
        cout << "Елемент на позиції " << position << " видалено.\n";
    }

    void print() {
        if (!head) {
            cout << "Список порожній.\n";
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Помилка відкриття файлу для запису.\n";
            return;
        }
        Node* current = head;
        while (current) {
            file << current->data << " ";
            current = current->next;
        }
        file.close();
        cout << "Список записано у файл " << filename << ".\n";
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Помилка відкриття файлу для читання.\n";
            return;
        }
        clear();
        int value;
        while (file >> value) {
            add(value);
        }
        file.close();
        cout << "Список відновлено із файлу " << filename << ".\n";
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "Список знищено.\n";
    }

    ~DoublyLinkedList() {
        clear();
    }
};

int main() {
    DoublyLinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);
    cout << "Список після додавання елементів:\n";
    list.print();

    list.addToStart(5);
    cout << "Список після додавання елемента на початок:\n";
    list.print();

    list.removeAt(2);
    cout << "Список після видалення елемента:\n";
    list.print();

    string filename = "list.txt";
    list.saveToFile(filename);

    list.clear();
    list.print();

    list.loadFromFile(filename);
    cout << "Список після відновлення:\n";
    list.print();

    list.clear();
    list.print();

    return 0;
}
