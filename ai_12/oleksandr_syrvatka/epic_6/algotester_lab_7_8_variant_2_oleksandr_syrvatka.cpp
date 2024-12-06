#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template<typename T>
class LinkedList {

public:
    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node<T> *current = head;
        while (current) {
            Node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insert(int index, int listSize, T values[]);

    void erase(int index, int count);

    int get(int index);

    void set(int index, T value);

    int getSize();

    void print();

private:
    Node<T> *head;
    Node<T> *tail;
    int size;
};

template<class T>
void LinkedList<T>::insert(int index, int listSize, T values[]) {
    if (index < 0 || index > size || listSize <= 0) return;

    Node<T> *current = head;
    Node<T> *prev = nullptr;

    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    for (int j = listSize - 1; j >= 0; j--) {
        Node<T> *newNode = new Node<T>(values[j]);
        newNode->next = current;
        if (current) {
            current->prev = newNode;
        } else {
            tail = newNode;
        }
        current = newNode;
        size++;
    }

    if (prev) {
        prev->next = current;
        current->prev = prev;
    } else {
        head = current;
    }
    if (!current->next) {
        tail = current;
    }
}


template<class T>
void LinkedList<T>::erase(int index, int count) {
    if (index < 0 || index >= size || count <= 0) return;

    Node<T> *current = head;
    Node<T> *prev = nullptr;

    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    for (int j = 0; j < count && current; j++) {
        Node<T> *nextNode = current->next;
        if (nextNode) {
            nextNode->prev = current->prev;
        } else {
            tail = prev;
        }
        delete current;
        current = nextNode;
        size--;
    }

    if (prev) {
        prev->next = current;
    } else {
        head = current;
    }
}



template<class T>
int LinkedList<T>::get(int index) {
    if (index < 0 || index >= size) {
        return 0;
    }

    Node<T> *current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

template<class T>
void LinkedList<T>::set(int index, T value) {
    if (index < 0 || index >= size) {
        return;
    }

    Node<T> *current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::print() {
    Node<T> *current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template<typename T>
void Choice(LinkedList<T> &list, const string &choice) {
    if (choice == "insert") {
        int index, n;
        cin >> index >> n;
        T elements[n];
        for (int i = 0; i < n; i++) {
            cin >> elements[i];
        }
        list.insert(index, n, elements);
    } else if (choice == "erase") {
        int index, count;
        cin >> index >> count;
        list.erase(index, count);
    } else if (choice == "get") {
        int index;
        cin >> index;
        cout << list.get(index) << endl;
    } else if (choice == "set") {
        int index;
        T value;
        cin >> index >> value;
        list.set(index, value);
    } else if (choice == "size") {
        cout << list.getSize() << endl;
    } else {
        list.print();
    }
}

int main() {

    LinkedList<int> list;

    int q;
    cin >> q;
    string choice;
    for (int i = 0; i < q; i++) {
        cin >> choice;
        Choice(list, choice);
    }

    return 0;
}