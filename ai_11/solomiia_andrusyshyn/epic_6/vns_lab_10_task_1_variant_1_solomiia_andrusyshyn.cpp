#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;       
    Node* next;     
    Node* prev;     
};

class DoubleLinkedList {
private:
    Node* head; 
    Node* tail; 

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void add(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr) { 
            head = newNode;
            tail = newNode;
        } else { 
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print_list() {
        if (head == nullptr) {
            cout << "Список порожній" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void delete_by_index(int index) {
        if (head == nullptr) {
            cout << "Список порожній, немає чого видаляти" << endl;
            return;
        }

        Node* current = head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex != index) {
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {
            cout << "Елемент з таким номером не знайдено" << endl;
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next; 
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev; 
        }

        delete current;
        cout << "Елемент видалено" << endl;
    }

    void push_front(int value) {
        Node* newNode = new Node{value, head, nullptr};
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode; 
        }
        head = newNode;
    }

    void save_to_file(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Помилка відкриття файлу" << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            file << current->data << " ";
            current = current->next;
        }
        file.close();
        cout << "Список збережено у файл" << endl;
    }

    void clear_list() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "Список очищено" << endl;
    }

    void list_restore(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Помилка відкриття файлу" << endl;
            return;
        }

        clear_list(); 
        int value;
        while (file >> value) {
            add(value); 
        }
        file.close();
        cout << "Список відновлено з файлу" << endl;
    }

    ~DoubleLinkedList() {
        clear_list();
    }
};

int main() {
    DoubleLinkedList list;

    for (int i = 1; i <= 5; i++) {
        list.add(i);
    }

    cout << "Список після додавання елементів:" << endl;
    list.print_list();

    list.push_front(0);
    cout << "Список після додавання елемента в початок:" << endl;
    list.print_list();

    list.delete_by_index(2);
    cout << "Список після видалення другого елемента:" << endl;
    list.print_list();

    list.save_to_file("list.txt");

    list.clear_list();
    cout << "Список після очищення:" << endl;
    list.print_list();

    list.list_restore("list.txt");
    cout << "Список після відновлення з файлу:" << endl;
    list.print_list();

    return 0;
}
