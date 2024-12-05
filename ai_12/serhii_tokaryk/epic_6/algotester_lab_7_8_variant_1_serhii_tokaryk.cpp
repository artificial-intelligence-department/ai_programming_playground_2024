#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void insert(int index, int n, const T* elements) {
        if (index < 0 || index > size) return;

        for (int i = 0; i < n; i++) {
            Node* newNode = new Node(elements[i]);

            if (index == 0) {
                newNode->next = head;
                if (head) head->prev = newNode;
                head = newNode;
                if (!tail) tail = head;
            } else {
                Node* current = head;
                for (int j = 0; j < index - 1; j++) current = current->next;

                newNode->next = current->next;
                if (current->next) current->next->prev = newNode;
                current->next = newNode;
                newNode->prev = current;

                if (!newNode->next) tail = newNode;
            }
            index++;
            size++;
        }
    }

    void erase(int index, int n) {
        if (index < 0 || index >= size || n <= 0) return;

        for (int i = 0; i < n; i++) {
            if (index >= size) break;

            Node* current = head;
            for (int j = 0; j < index; j++) current = current->next;

            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;

            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;

            delete current;
            size--;
        }
    }

    int getSize() const {
        return size;
    }

    T get(int index) const {
        if (index < 0 || index >= size) throw out_of_range("Index out of range");

        Node* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        return current->data;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size) throw out_of_range("Index out of range");

        Node* current = head;
        for (int i = 0; i < index; i++) current = current->next;
        current->data = value;
    }

    friend ostream& operator<<(ostream& os, const DoublyLinkedList& list) {
        Node* current = list.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};

int main() {
    DoublyLinkedList<int> list;
    int q;
    cin >> q;

    while (q--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, n;
            cin >> index >> n;
            int* elements = new int[n];
            for (int i = 0; i < n; i++) cin >> elements[i];
            list.insert(index, n, elements);
            delete[] elements;
        } else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        } else if (command == "size") {
            cout << list.getSize() << endl;
        } else if (command == "get") {
            int index;
            cin >> index;
            try {
                cout << list.get(index) << endl;
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            try {
                list.set(index, value);
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
        } else if (command == "print") {
            cout << list << endl;
        }
    }

    return 0;
}
