#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() { clear(); }

    void insert(int index, int n, T* values) {
        if (index < 0 || index > size) {
            cout << "Error: Index out of range" << endl;
            return;
        }

        Node* current = head;
        Node* prevNode = nullptr;

        for (int i = 0; i < index; ++i) {
            prevNode = current;
            current = current->next;
        }

        for (int i = 0; i < n; ++i) {
            Node* newNode = new Node(values[i]);

            if (!head) {
                head = tail = newNode;
            } else if (!prevNode) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                newNode->next = current;
                newNode->prev = prevNode;
                if (prevNode) prevNode->next = newNode;
                if (current) current->prev = newNode;
            }

            prevNode = newNode;
            if (!current) tail = newNode;
        }

        size += n;
    }

    void erase(int index, int n) {
        if (index < 0 || index >= size || n <= 0) {
            cout << "Error: Invalid index or number of elements" << endl;
            return;
        }

        Node* current = head;

        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        for (int i = 0; i < n && current; ++i) {
            Node* toDelete = current;
            if (toDelete->prev) toDelete->prev->next = toDelete->next;
            if (toDelete->next) toDelete->next->prev = toDelete->prev;

            if (toDelete == head) head = toDelete->next;
            if (toDelete == tail) tail = toDelete->prev;

            current = current->next;
            delete toDelete;
            size--;
        }
    }

    int getSize() const {
        return size;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of range" << endl;
            return T(); 
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->value;
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of range" << endl;
            return;
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->value = value;
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }

        head = tail = nullptr;
        size = 0;
    }

    friend ostream& operator<<(ostream& os, const DoublyLinkedList<T>& list) {
        Node* current = list.head;
        while (current) {
            os << current->value << " ";
            current = current->next;
        }
        return os;
    }
};

int main() {
    DoublyLinkedList<int> list;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, n;
            cin >> index >> n;
            int* elements = new int[n];
            for (int j = 0; j < n; ++j) cin >> elements[j];
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
            int value = list.get(index);
            if (index >= 0 && index < list.getSize()) {
                cout << value << endl;
            }
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        } else if (command == "print") {
            list.print();
        }
    }

    return 0;
}
