#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* previous;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void print_list() const {
        if (!head) { // Чи порожній список?
            cout << "The list is empty" << endl;
            return;
        }
        Node* current = head;
        while (current) {       // Вивід списку
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void add(int value) {
        Node* newNode = new Node{value, nullptr, tail}; // Новий вузол
        if (!head) {
            head = tail = newNode;// Якщо список порожній, новий вузол стає і головою, і хвостом
        } else {
            tail->next = newNode; // Якщо список непорожній додаємо новий вузол після хвоста
            tail = newNode; // Новий список стає хвостом
        }
    }

    void push_front(int value) {
        Node* newNode = new Node{value, head, nullptr}; // Новий вузол
        if (!head) {
            head = tail = newNode; // Якщо список порожній, новий вузол стає і головою, і хвостом
        } else {
            head->previous = newNode; // Якщо список непорожній, оновлюємо попереднє посилання голови
            head = newNode; // Новий список стає head
        }
    }

    void delete_by_index(unsigned int index) { // Видалити індекс
        if (!head) return; // Якщо список порожній, нічого не роблю

        Node* current = head;
        unsigned int count = 0;  // лише 0 або додатні (для перебору ел. списку)

        while (current && count < index) { // Проходимо по списку до елемента з вказаним індексом
            current = current->next;
            count++;
        }

        if (!current) {
            cerr << "Index out of bounds" << endl; // це якщо індекс за списком
            return; // кінець :)
        }
            // Видаляємо елемент, оновлюючи посилання сусідніх вузлів
        if (current == head) { // Якщо це голова списку
            head = current->next; // голова стає некст ел
            if (head) head->previous = nullptr;
        } else {
            current->previous->next = current->next; // Попередній елемент тепер вказує на наступний.
        }

        if (current == tail) {// Якщо це хвіст списку
            tail = current->previous;// хвіст стає попереднім ел
        } else {
            current->next->previous = current->previous; // Наступний елемент тепер вказує на попередній
        }

        delete current;  // Видалити цей елемент
    }

    void save_to_file(const string& filename) const { //Зберегти 
        ofstream file(filename); // куди зберегти
        if (!file) {
            cerr << "Error: Unable to open file for writing!" << endl; //помилка :(
            return;
        }
        Node* current = head;
        while (current) {
            file << current->data << " ";  // Записуємо дані кожного вузла у файл
            current = current->next;
        }
        file.close();
        cout << "The list was saved to \"" << filename << "\"." << endl;
    }

    void clear_list() {
        while (head) {
            Node* temp = head;
            head = head->next;  // Видалення списку
            delete temp;
        }
        tail = nullptr;
    }

    void list_restore(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Unable to open file for reading!" << endl;
            return;
        }
        clear_list(); // Очищаємо поточний список
        int value;
        while (file >> value) {
            add(value);  // Додаємо елементи з файлу в список
        }
        file.close();
        cout << "The list was restored from \"" << filename << "\"." << endl;
    }

    ~DoubleLinkedList() {
        clear_list();
    }
};

int main() {
    DoubleLinkedList list;

    for (int value = 0; value < 10; ++value) {
        list.add(value);
    }
    cout << "The list:" << endl;
    list.print_list();

    list.push_front(99);
    cout << "The list after adding an element to the front:" << endl;
    list.print_list();

    list.delete_by_index(2);
    cout << "The list after deleting element at index 2:" << endl;
    list.print_list();

    list.save_to_file("list.txt");

    list.clear_list();
    cout << "The cleared list:" << endl;
    list.print_list();

    list.list_restore("list.txt");
    cout << "The list after recovery from file:" << endl;
    list.print_list();

    list.clear_list();
    cout << "List after final destruction:" << endl;
    list.print_list();

    return 0;
}
