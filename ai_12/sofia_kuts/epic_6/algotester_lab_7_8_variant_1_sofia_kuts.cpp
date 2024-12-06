#include <iostream>
#include <stdexcept>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

    Node* getNode(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int getSize() const {
        return size;
    }

    void insert(int index, int n, const T* values) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of bounds");
        }
        Node* prevNode = (index == 0) ? nullptr : getNode(index - 1);
        Node* nextNode = (index == size) ? nullptr : getNode(index);

        for (int i = 0; i < n; ++i) {
            Node* newNode = new Node(values[i]);
            if (prevNode) {
                prevNode->next = newNode;
                newNode->prev = prevNode;
            } else {
                head = newNode;
            }
            prevNode = newNode;
        }

        if (prevNode) {
            prevNode->next = nextNode;
        }
        if (nextNode) {
            nextNode->prev = prevNode;
        } else {
            tail = prevNode;
        }

        size += n;
    }

    void erase(int index, int n) {
        if (index < 0 || index >= size || index + n > size) {
            throw std::out_of_range("Index out of bounds");
        }

        Node* startNode = getNode(index);
        Node* endNode = (index + n < size) ? getNode(index + n) : nullptr;
        Node* prevNode = startNode->prev;

        for (int i = 0; i < n; ++i) {
            Node* temp = startNode;
            startNode = startNode->next;
            delete temp;
        }

        if (prevNode) {
            prevNode->next = endNode;
        } else {
            head = endNode;
        }

        if (endNode) {
            endNode->prev = prevNode;
        } else {
            tail = prevNode;
        }

        size -= n;
    }

    T get(int index) const {
        return getNode(index)->data;
    }

    void set(int index, T value) {
        getNode(index)->data = value;
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list) {
        Node* current = list.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};

int main() {
    int Q;
    std::cin >> Q;

    DoublyLinkedList<int> list;

    while (Q--) {
        std::string command;
        std::cin >> command;

        if (command == "insert") {
            int index, n;
            std::cin >> index >> n;
            int* values = new int[n];
            for (int i = 0; i < n; ++i) {
                std::cin >> values[i];
            }
            list.insert(index, n, values);
            delete[] values;
        } else if (command == "erase") {
            int index, n;
            std::cin >> index >> n;
            list.erase(index, n);
        } else if (command == "size") {
            std::cout << list.getSize() << std::endl;
        } else if (command == "get") {
            int index;
            std::cin >> index;
            std::cout << list.get(index) << std::endl;
        } else if (command == "set") {
            int index, value;
            std::cin >> index >> value;
            list.set(index, value);
        } else if (command == "print") {
            std::cout << list << std::endl;
        }
    }

    return 0;
}
