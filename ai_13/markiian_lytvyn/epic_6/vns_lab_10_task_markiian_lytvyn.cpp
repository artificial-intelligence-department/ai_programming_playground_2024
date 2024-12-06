#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;
    Node(const string& data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void add_begin(const string& data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = tail = new_node;
        } 
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    void add_end(const string& data) {
        Node* new_node = new Node(data);
        if (!tail) {
            head = tail = new_node;
        } 
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    void delete_value(const string& value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;

                delete current;
                cout << "Вузол зі значенням \"" << value << "\" видалений." << endl;
                return;
            }
            current = current->next;
        }
    }
    void delete_id(int id) {
        if (!head) {
            cout << "Список порожній." << endl;
            return;
        }
        Node* current = head;
        int current_id = 0;

        while (current && current_id < id) {
            current = current->next;
            current_id++;
        }
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == head) head = current->next;
        if (current == tail) tail = current->prev;

        delete current;
        cout << "Елемент з індексом " << id << " видалений." << endl;
    }
    void print() {
        if (!head) {
            cout << "Список порожній." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void save(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            return;
        }
        Node* current = head;
        while (current) {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
        cout << "Список збережено. \"" << filename << "\"" << endl;
    }
    void restore(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            return;
        }
        clear();
        string data;
        while (getline(file, data)) {
            add_end(data);
        }
        file.close();
        cout << "Список видалено. \"" << filename << "\"" << endl;
    }
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "Список очищений." << endl;
    }
    ~DoublyLinkedList() {
        clear();
    }
};

int main() {
    DoublyLinkedList list;
    string filename = "vns_lab_10_markiian_lytvyn.txt";

    cout << "Створення списку." << endl;
    list.add_begin("1");
    list.add_begin("2");
    list.add_begin("3");
    list.add_begin("4");
    list.add_begin("5");
    list.add_begin("6");
    list.add_begin("7");
    list.add_begin("8");
    list.add_begin("9");
    list.add_begin("10");

    cout << "Список: ";
    list.print();

    cout << "Додавання елементів на початок списку." << endl;
    list.add_begin("11");
    list.add_begin("12");
    cout << "Список: ";
    list.print();


    int K;
    cout << "Введіть індекс K:";
    cin >> K;
    cout << "Видалення елементів з індексом K." << endl;
    list.delete_id(K);
    cout << "Список: ";
    list.print();


    cout << "Видалення вузла зі значенням \"4\"." << endl;
    list.delete_value("4");
    cout << "Список: ";
    list.print();

    list.save(filename);
    list.clear();
    cout << "Список після очищення: ";
    list.print();

    list.restore(filename);
    cout << "Список після відновлення: ";
    list.print();

    list.clear();
    cout << "Список після остаточного очищення: ";
    list.print();

    return 0;
}
