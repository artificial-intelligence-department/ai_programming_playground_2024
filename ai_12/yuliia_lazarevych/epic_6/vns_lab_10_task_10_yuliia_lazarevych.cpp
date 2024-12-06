#include <iostream>
#include <fstream>
using namespace std;

//вузол двонаправленого списку
struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        destroy_list(); //знищення списку
    }

    bool is_empty() const {
        return head == nullptr;
    }

    // створення списку
    void create_list() {
        head = tail = nullptr;
        cout << "Список створено.\n";
    }

    //друк списку
    void print_list() const {
        if (is_empty()) {
            cout << "Список порожній.\n";
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->value << " <-> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    //додавання елемента у список
    void add_to_position(int value, int position) {
        Node* new_node = new Node(value);
        if (is_empty() || position <= 0) {
            //додаємо на початок
            new_node->next = head;
            if (head) head->prev = new_node;
            head = new_node;
            if (!tail) tail = head;
        } else {
            Node* current = head;
            int index = 0;
            while (current->next && index < position - 1) {
                current = current->next;
                index++;
            }
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next) current->next->prev = new_node;
            current->next = new_node;
            if (!new_node->next) tail = new_node;
        }
        cout << "Елемент " << value << " додано на позицію " << position << ".\n";
    }

    //видалення елементів зі списку
    void delete_from_end(int k) {
        while (k > 0 && tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
            delete temp;
            k--;
        }
        cout << k << " елементів видалено з кінця списку.\n";
    }

    //запис списку у файл
    void write_to_file(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Помилка відкриття файлу.\n";
            return;
        }
        Node* current = head;
        while (current) {
            file << current->value << " ";
            current = current->next;
        }
        file.close();
        cout << "Список записано у файл " << filename << ".\n";
    }

    //знищення списку
    void destroy_list() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "Список знищено.\n";
    }

    //відновлення списку з файлу
    void restore_from_file(const string& filename) {
        destroy_list(); //знищення поточного списку
        ifstream file(filename);
        if (!file) {
            cerr << "Помилка відкриття файлу.\n";
            return;
        }
        int value;
        while (file >> value) {
            add_to_position(value, -1); //додаємо в кінець
        }
        file.close();
        cout << "Список відновлено з файлу " << filename << ".\n";
    }
};

int main() {
    DoublyLinkedList list;

    //створення списку
    list.create_list();

    //додавання елемента у список
    list.add_to_position(10, 0);
    list.add_to_position(20, 1);
    list.add_to_position(30, 1);

    //друк списку
    list.print_list();

    //видалення елементів зі списку
    list.delete_from_end(2);
    list.print_list();

    //запис списку у файл
    list.write_to_file("list.txt");

    //знищення списку
    list.destroy_list();
    list.print_list();

    //відновлення списку з файлу
    list.restore_from_file("list.txt");
    list.print_list();

    //знищення списку
    list.destroy_list();

    return 0;
}
