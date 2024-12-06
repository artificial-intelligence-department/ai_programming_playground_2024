#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string key;
    Node* prev;
    Node* next;
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    void add(const string& key) {
        Node* newNode = new Node{ key, nullptr, nullptr };
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void addAfter(const string& afterKey, const string& newKey) {
        Node* current = head;
        while (current) {
            if (current->key == afterKey) {
                Node* newNode = new Node{ newKey, current, current->next };
                if (current->next) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                if (current == tail) {
                    tail = newNode;
                }
                return;
            }
            current = current->next;
        }
    }

    void remove(const string& key) {
        Node* current = head;
        while (current) {
            if (current->key == key) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    void save(const string& filename) {
        ofstream file(filename);
        if (!file) return;
        Node* current = head;
        while (current) {
            file << current->key << endl;
            current = current->next;
        }
    }

    void load(const string& filename) {
        ifstream file(filename);
        if (!file) return;
        string key;
        while (getline(file, key)) {
            add(key);
        }
    }

    ~List() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    List list;

    list.add("apple");
    list.add("banana");
    list.add("cherry");

    list.addAfter("banana", "orange");
    list.addAfter("cherry", "pear");

    list.print();

    list.remove("banana");

    list.print();

    list.save("list.txt");

    list.~List();

    List newList;
    newList.load("list.txt");

    newList.print();

    return 0;
}
