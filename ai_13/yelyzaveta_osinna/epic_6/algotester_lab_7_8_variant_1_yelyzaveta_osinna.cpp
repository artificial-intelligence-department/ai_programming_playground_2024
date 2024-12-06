#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
using namespace std;

// Структура вузла двозв'язного списку
struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
};

// Клас двозв'язного списку
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    size_t listSize;

    // Отримання вузла за індексом
    Node* getNodeAt(int index) const {
        if (index < 0 || index >= listSize) {
            throw out_of_range("Index out of range");
        }
        Node* current;
        if (index < listSize / 2) {
            current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
        } else {
            current = tail;
            for (int i = listSize - 1; i > index; --i) {
                current = current->prev;
            }
        }
        return current;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    // Вставка на позицію index
    void insert(int index, int n, const int* values) {
        if (index < 0 || index > listSize) {
            throw out_of_range("Index out of range");
        }

        for (int i = 0; i < n; ++i) {
            Node* newNode = new Node(values[i]);
            if (index == 0) {
                // Вставка на початок
                newNode->next = head;
                if (head) head->prev = newNode;
                head = newNode;
                if (!tail) tail = newNode;
            } else if (index == listSize) {
                // Вставка в кінець
                newNode->prev = tail;
                if (tail) tail->next = newNode;
                tail = newNode;
            } else {
                // Вставка в середину
                Node* nextNode = getNodeAt(index);
                Node* prevNode = nextNode->prev;
                newNode->next = nextNode;
                newNode->prev = prevNode;
                prevNode->next = newNode;
                nextNode->prev = newNode;
            }
            index++;
            listSize++;
        }
    }

    // Видалення n елементів з позиції index
    void erase(int index, int n) {
        if (index < 0 || index >= listSize || n <= 0) {
            throw out_of_range("Invalid arguments for erase");
        }
        for (int i = 0; i < n; ++i) {
            if (index >= listSize) break;
            Node* target = getNodeAt(index);
            if (target->prev) target->prev->next = target->next;
            if (target->next) target->next->prev = target->prev;
            if (target == head) head = target->next;
            if (target == tail) tail = target->prev;
            delete target;
            listSize--;
        }
    }

    // Розмір списку
    size_t size() const {
        return listSize;
    }

    // Отримання значення за індексом
    int get(int index) const {
        return getNodeAt(index)->value;
    }

    // Модифікація значення за індексом
    void set(int index, int value) {
        getNodeAt(index)->value = value;
    }

    // Перевантаження оператора << для виводу списку
    friend ostream& operator<<(ostream& os, const DoublyLinkedList& list) {
        Node* current = list.head;
        while (current) {
            os << current->value << " ";
            current = current->next;
        }
        return os;
    }
};

int main() {
    DoublyLinkedList list;
    int Q;
    cin >> Q;

    // Буфер для збереження результатів
    ostringstream outputBuffer;

    while (Q--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, N;
            cin >> index >> N;
            int* values = new int[N];
            for (int i = 0; i < N; ++i) {
                cin >> values[i];
            }
            try {
                list.insert(index, N, values);
            } catch (out_of_range& e) {
                outputBuffer << "Error: " << e.what() << endl;
            }
            delete[] values;
        } else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            try {
                list.erase(index, n);
            } catch (out_of_range& e) {
                outputBuffer << "Error: " << e.what() << endl;
            }
        } else if (command == "size") {
            outputBuffer << list.size() << endl;
        } else if (command == "get") {
            int index;
            cin >> index;
            try {
                outputBuffer << list.get(index) << endl;
            } catch (out_of_range& e) {
                outputBuffer << "Error: " << e.what() << endl;
            }
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            try {
                list.set(index, value);
            } catch (out_of_range& e) {
                outputBuffer << "Error: " << e.what() << endl;
            }
        } else if (command == "print") {
            outputBuffer << list << endl;
        }
    }

    // Вивід усіх результатів одним блоком
    cout << "\n" << outputBuffer.str();

    return 0;
}

