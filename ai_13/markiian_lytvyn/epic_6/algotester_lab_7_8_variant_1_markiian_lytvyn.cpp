#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t list_size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

    ~DoubleLinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int index, const vector<T>& values) {
        Node<T>* current = (index == list_size) ? nullptr : getNodeAt(index);

        for (const T& value : values) {
            Node<T>* new_node = new Node<T>(value);

            if (!current) { 
                if (!tail) { 
                    head = tail = new_node;
                } else {
                    tail->next = new_node;
                    new_node->prev = tail;
                    tail = new_node;
                }
            } else if (!current->prev) { 
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            } else { 
                Node<T>* prev_node = current->prev;
                prev_node->next = new_node;
                new_node->prev = prev_node;
                new_node->next = current;
                current->prev = new_node;
            }
            ++list_size;
        }
    }

    void erase(int index, int amount) {
        Node<T>* current = getNodeAt(index);

        for (int i = 0; i < amount; ++i) {
            Node<T>* del = current;
            current = current->next;

            if (del->prev) {
                del->prev->next = del->next;
            } else {
                head = del->next;
            }

            if (del->next) {
                del->next->prev = del->prev;
            } else {
                tail = del->prev;
            }

            delete del;
            --list_size;
        }
    }

    size_t size() const {
        return list_size;
    }

    T get(int index) const {
        return getNodeAt(index)->data;
    }

    void set(int index, const T& value) {
        getNodeAt(index)->data = value;
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    Node<T>* getNodeAt(int index) const {
        Node<T>* current = (index < list_size / 2) ? head : tail;
        if (index < list_size / 2) {
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
        } else {
            for (int i = list_size - 1; i > index; --i) {
                current = current->prev;
            }
        }
        return current;
    }
};

int main() {
    DoubleLinkedList<int> list;
    int Q;
    cin >> Q;

    while (Q--) {
        string answer;
        cin >> answer;

        if (answer == "insert") {
            int index, N;
            cin >> index >> N;
            vector<int> values(N);
            for (int i = 0; i < N; ++i) {
                cin >> values[i];
            }
            list.insert(index, values);
        } 
        else if (answer == "erase") {
            int index, count;
            cin >> index >> count;
            list.erase(index, count);
        } 
        else if (answer == "size") {
            cout << list.size() << endl;
        } 
        else if (answer == "get") {
            int index;
            cin >> index;
            cout << list.get(index) << endl;
        } 
        else if (answer == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value); 
        } 
        else if (answer == "print") {
            list.print();
        }
    }

    return 0;
}