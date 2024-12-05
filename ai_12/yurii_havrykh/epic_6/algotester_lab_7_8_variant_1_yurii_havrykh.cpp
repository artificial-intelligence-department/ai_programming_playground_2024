#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {

public:
    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node *current = head;
        while (current) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insert(int index, int listSize, int values[]);

    void erase(int index, int count);

    int get(int index);

    void set(int index, int value);

    int getSize();

    void print();

private:
    Node *head;
    Node *tail;
    int size;
};

void LinkedList::insert(int index, int listSize, int values[]) {
    if (index < 0 || index > size || listSize <= 0) return;

    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    for (int j = listSize - 1; j >= 0; j--) {
        Node *newNode = new Node(values[j]);
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

void LinkedList::erase(int index, int count) {
    if (index < 0 || index >= size || count <= 0) return;

    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    for (int j = 0; j < count && current; j++) {
        Node *nextNode = current->next;
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

int LinkedList::get(int index) {
    if (index < 0 || index >= size) {
        return 0;
    }

    Node *current = head;

    // find node at index
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

void LinkedList::set(int index, int value) {
    if (index < 0 || index >= size) {
        return;
    }

    Node *current = head;

    // find node at index
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->data = value;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::print() {
    Node *current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Choice(LinkedList &list, const string &choice) {
    if (choice == "insert") {
        int index, n;
        cin >> index >> n;
        int elements[n];
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
        int value;
        cin >> index >> value;
        list.set(index, value);
    } else if (choice == "size") {
        cout << list.getSize() << endl;
    } else {
        list.print();
    }
}

int main() {

    LinkedList list;

    int q;
    cin >> q;
    string choice;
    for (int i = 0; i < q; i++) {
        cin >> choice;
        Choice(list, choice);
    }

    return 0;
}
