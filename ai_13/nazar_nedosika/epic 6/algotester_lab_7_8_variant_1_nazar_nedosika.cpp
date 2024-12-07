#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    size_t list_size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int index, const vector<int>& values) {
        if (index < 0 || index > list_size) {
            throw out_of_range("Index out of range");
        }

        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }

        for (int value : values) {
            Node* new_node = new Node(value);

            if (!curr) {
                if (!head) {
                    head = tail = new_node;
                } else {
                    tail->next = new_node;
                    new_node->prev = tail;
                    tail = new_node;
                }
            } else if (!curr->prev) {
                new_node->next = curr;
                curr->prev = new_node;
                head = new_node;
            } else {
                new_node->next = curr;
                new_node->prev = curr->prev;
                curr->prev->next = new_node;
                curr->prev = new_node;
            }

            curr = new_node->next;
            ++list_size;
        }
    }

    void erase(int index, int count) {
        if (index < 0 || index >= list_size || count <= 0) {
            throw out_of_range("Invalid range");
        }

        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }

        for (int i = 0; i < count && curr; ++i) {
            Node* temp = curr;
            if (curr->prev) curr->prev->next = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
            if (curr == head) head = curr->next;
            if (curr == tail) tail = curr->prev;
            curr = curr->next;
            delete temp;
            --list_size;
        }
    }

    size_t size() const {
        return list_size;
    }

    int get(int index) const {
        if (index < 0 || index >= list_size) {
            throw out_of_range("Index out of range");
        }

        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->value;
    }

    void set(int index, int value) {
        if (index < 0 || index >= list_size) {
            throw out_of_range("Index out of range");
        }

        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        curr->value = value;
    }

    friend ostream& operator<<(ostream& os, const DoublyLinkedList& list) {
        Node* curr = list.head;
        while (curr) {
            os << curr->value;
            if (curr->next) os << " ";
            curr = curr->next;
        }
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;
    DoublyLinkedList dll;

    for (int q = 0; q < Q; ++q) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, N;
            cin >> index >> N;
            vector<int> values(N);
            for (int i = 0; i < N; ++i) {
                cin >> values[i];
            }
            dll.insert(index, values);
        } else if (command == "erase") {
            int index, count;
            cin >> index >> count;
            dll.erase(index, count);
        } else if (command == "size") {
            cout << dll.size() << endl;
        } else if (command == "get") {
            int index;
            cin >> index;
            cout << dll.get(index) << endl;
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            dll.set(index, value);
        } else if (command == "print") {
            cout << dll << endl;
        }
    }

    return 0;
}