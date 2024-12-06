#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;

    Node(string d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList() : head(nullptr) {}

    ~DoubleLinkedList() {
        destroy();
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void add(const string& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteFirstKElement(int k) {
        for (int i = 0; i < k && head; ++i) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            delete temp;
        }
    }

    void addAfter(char startChar, const string& data) {
        Node* current = head;
        while (current) {
            if (!current->data.empty() && current->data[0] == startChar) {
                Node* newNode = new Node(data);
                newNode->next = current->next;
                if (current->next) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                newNode->prev = current;
                return;
            }
            current = current->next;
        }
        cout << "Елемент, що починається на '" << startChar << "', не знайдено." << endl;
    }

    void print() const {
        if (isEmpty()) {
            cout << "Список порожній." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "None" << endl;
    }

    void toFile(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Помилка запису у файл." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            outFile << current->data << endl;
            current = current->next;
        }
        outFile.close();
    }

    void fromFile(const string& filename) {
        destroy();
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Помилка відкриття файлу." << endl;
            return;
        }
        string line;
        while (getline(inFile, line)) {
            add(line);
        }
        inFile.close();
    }

    void destroy() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoubleLinkedList dll;

    // створення списку
    dll.add("apple");
    dll.add("banana");
    dll.add("cherry");
    dll.add("durian");

    cout << "Список після створення:" << endl;
    dll.print();

    // видалення перших K елементів
    int k = 2;
    dll.deleteFirstKElement(k);
    cout << "\nСписок після видалення перших " << k << " елементів:" << endl;
    dll.print();

    // додавання елемента після елемента на 'c'
    dll.addAfter('c', "cranberry");
    cout << "\nСписок після додавання елемента після елемента, що починається на 'c':" << endl;
    dll.print();

    // запис в файл
    string filename = "doubly_linked_list.txt";
    dll.toFile(filename);
    cout << "\nСписок записано у файл: " << filename << endl;

    // знищення списку
    dll.destroy();
    cout << "\nСписок після знищення:" << endl;
    dll.print();

    // відновлення списку з файлу
    dll.fromFile(filename);
    cout << "\nСписок після відновлення з файлу:" << endl;
    dll.print();

    // знищення списку остаточно
    dll.destroy();
    cout << "\nСписок після остаточного знищення:" << endl;
    dll.print();

    return 0;
}
