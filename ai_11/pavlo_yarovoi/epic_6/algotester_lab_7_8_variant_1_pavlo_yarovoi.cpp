#include <iostream>
#include <cstring>
using namespace std;

template<typename Type>
class DoublyLinkedList {
    struct Node {
        Type data;
        Node* prev;
        Node* next;
        Node(Type value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Insert(int index, Type arr[], int N) {
        if (index < 0 || index > size) return;
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        for (int i = 0; i < N; ++i) {
            Node* newNode = new Node(arr[i]);
            if (!head) {
                head = tail = newNode;
            } else if (!current) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                if (current->prev) {
                    current->prev->next = newNode;
                } else {
                    head = newNode;
                }
                current->prev = newNode;
            }
        }
        size += N;
    }

    void Erase(int index, int n) {
        if (index < 0 || index >= size || n <= 0) return;
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        for (int i = 0; i < n && current; ++i) {
            Node* toDelete = current;
            current = current->next;
            if (toDelete->prev) {
                toDelete->prev->next = toDelete->next;
            } else {
                head = toDelete->next;
            }
            if (toDelete->next) {
                toDelete->next->prev = toDelete->prev;
            } else {
                tail = toDelete->prev;
            }
            delete toDelete;
        }
        size -= n;
    }

    int Size() const {
        return size;
    }

    Type Get(int index) const {
        if (index < 0 || index >= size) throw out_of_range("Index out of range");
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void Set(int index, Type value) {
        if (index < 0 || index >= size) throw out_of_range("Index out of range");
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = value;
    }

    friend ostream& operator<<(ostream& os, const DoublyLinkedList& list) {
        Node* current = list.head;
        while (current) {
            os << current->data << ' ';
            current = current->next;
        }
        return os;
    }
};

int main() {
    DoublyLinkedList<int> list;

    int Q;
    cin >> Q;

    char ident[10];

    while (Q--) {
        cin >> ident;

        if (strcmp(ident, "insert") == 0) {
            int index, N;
            cin >> index >> N;
            int* arr = new int[N];
            for (int i = 0; i < N; ++i) {
                cin >> arr[i];
            }
            list.Insert(index, arr, N);
            delete[] arr;

        } else if (strcmp(ident, "erase") == 0) {
            int index, n;
            cin >> index >> n;
            list.Erase(index, n);

        } else if (strcmp(ident, "size") == 0) {
            cout << list.Size() << endl;

        } else if (strcmp(ident, "get") == 0) {
            int index;
            cin >> index;
            try {
                cout << list.Get(index) << endl;
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }

        } else if (strcmp(ident, "set") == 0) {
            int index, value;
            cin >> index >> value;
            try {
                list.Set(index, value);
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }

        } else if (strcmp(ident, "print") == 0) {
            cout << list << endl;
        }
    }

    return 0;
}
