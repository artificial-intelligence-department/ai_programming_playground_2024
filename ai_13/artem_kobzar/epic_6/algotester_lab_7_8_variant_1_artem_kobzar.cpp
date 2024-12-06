#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <class T>
class LinkedList {
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int index, const vector<T>& arr) {
        if (index == 0) {
            for (int i = arr.size() - 1; i >= 0; --i) {
                Node<T>* newNode = new Node<T>(arr[i]);
                newNode->next = head;
                head = newNode;
            }
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1 && current; ++i) {
                current = current->next;
            }

            for (const T& value : arr) {
                Node<T>* newNode = new Node<T>(value);
                newNode->next = current->next;
                current->next = newNode;
                current = newNode;
            }
        }
    }

    void erase(int index, int n) {
        if (index == 0) {
            for (int i = 0; i < n && head; ++i) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1 && current; ++i) {
                current = current->next;
            }

            for (int i = 0; i < n && current && current->next; ++i) {
                Node<T>* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
        }
    }

    int size() const {
        int count = 0;
        Node<T>* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    T get(int index) const {
        Node<T>* current = head;
        for (int i = 0; i < index && current; ++i) {
            current = current->next;
        }
        return current ? current->data : T();
    }

    void set(int index, T value) {
        Node<T>* current = head;
        for (int i = 0; i < index && current; ++i) {
            current = current->next;
        }
        if (current) current->data = value;
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> list;
    string opt;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        cin >> opt;
        if (opt == "insert") {
            int index, size;
            cin >> index >> size;
            vector<int> arr(size);
            for (int j = 0; j < size; ++j) {
                cin >> arr[j];
            }
            list.insert(index, arr);
        } else if (opt == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        } else if (opt == "size") {
            cout << list.size() << endl;
        } else if (opt == "get") {
            int index;
            cin >> index;
            cout << list.get(index) << endl;
        } else if (opt == "set") {
            int index, a;
            cin >> index >> a;
            list.set(index, a);
        } else if (opt == "print") {
            list.print();
        }
    }

    return 0;
}
