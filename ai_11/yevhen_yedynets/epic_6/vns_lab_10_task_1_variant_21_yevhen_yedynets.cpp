#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
    Node(const string& value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    void add_to_start(const string& value) {
        Node* new_node = new Node(value);
        if (!head) head = tail = new_node;
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void add_to_end(const string& value) {
        Node* new_node = new Node(value);
        if (!tail) head = tail = new_node;
        else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void remove_before_and_after(const string& key) {
        Node* current = head;
        while (current && current->data != key) current = current->next;
        if (!current) return;
        if (current->prev) {
            Node* to_delete = current->prev;
            if (to_delete->prev) to_delete->prev->next = current;
            else head = current;
            current->prev = to_delete->prev;
            delete to_delete;
        }
        if (current->next) {
            Node* to_delete = current->next;
            if (to_delete->next) to_delete->next->prev = current;
            else tail = current;
            current->next = to_delete->next;
            delete to_delete;
        }
    }

    void print() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        for (Node* current = head; current; current = current->next)
            cout << current->data << " ";
        cout << "\n";
    }

    void write_to_file(const string& filename) const {
        ofstream file(filename);
        for (Node* current = head; current; current = current->next)
            file << current->data << "\n";
    }

    void clear() {
        while (head) {
            Node* next_node = head->next;
            delete head;
            head = next_node;
        }
        tail = nullptr;
    }

    void restore_from_file(const string& filename) {
        clear();
        ifstream file(filename);
        string line;
        while (getline(file, line)) add_to_end(line);
    }
};

int main() {
    DoublyLinkedList list;
    list.add_to_start("Element1");
    list.add_to_end("Element2");
    list.add_to_end("Element3");
    list.add_to_end("KeyElement");
    list.add_to_end("Element4");
    list.add_to_end("Element5");

    cout << "Initial list: ";
    list.print();

    list.remove_before_and_after("KeyElement");
    cout << "After removing elements before and after 'KeyElement': ";
    list.print();

    list.add_to_start("StartElement1");
    list.add_to_start("StartElement2");
    list.add_to_end("EndElement1");
    list.add_to_end("EndElement2");
    cout << "After adding K elements: ";
    list.print();

    list.write_to_file("list.txt");

    list.clear();
    cout << "After clearing the list: ";
    list.print();

    list.restore_from_file("list.txt");
    cout << "After restoring from file: ";
    list.print();

    list.clear();
    cout << "After final clearing: ";
    list.print();

    return 0;
}
