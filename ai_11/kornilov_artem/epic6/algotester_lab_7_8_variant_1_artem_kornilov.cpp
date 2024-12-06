#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

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

    void insert_before(int index, int listSize, int values[]);
    void insert_after(int index, int listSize, int values[]);
    void erase(int index, int count);
    int get(int index);
    void set(int index, int value);
    int getSize();
    void print();
    void saveToFile(const string& filename);
    void destroy();
    void restoreFromFile(const string& filename);

private:
    Node* head;
    Node* tail;
    int size;
};

// Insert nodes before the given index
void LinkedList::insert_before(int index, int listSize, int values[]) {

    if (index == 0) { // Insert at the beginning
        for (int i = listSize - 1; i >= 0; i--) {
            Node* newNode = new Node(values[i]);
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            if (!tail) { // If the list was empty
                tail = newNode;
            }
            size++;
        }
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    for (int i = 0; i < listSize; i++) {
        Node* newNode = new Node(values[i]);
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) {
            current->prev->next = newNode;
        }
        current->prev = newNode;
        size++;
    }
}

// Insert nodes after the given index
void LinkedList::insert_after(int index, int listSize, int values[]) {

    if (size == 0) {
        for (int i = 0; i < listSize; i++) {
            Node* newNode = new Node(values[i]);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    for (int i = 0; i < listSize; i++) {
        Node* newNode = new Node(values[i]);
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        current = newNode;
        size++;
    }
}

// Erase `count` nodes starting from the given index
void LinkedList::erase(int index, int count) {

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    for (int i = 0; i < count && current; i++) {
        Node* nextNode = current->next;
        Node* prevNode = current->prev;

        if (prevNode) {
            prevNode->next = nextNode;
        } else {
            head = nextNode; // If deleting the first node
        }

        if (nextNode) {
            nextNode->prev = prevNode;
        } else {
            tail = prevNode; // If deleting the last node
        }

        delete current;
        current = nextNode;
        size--;
    }
}

// Get the data at the given index
int LinkedList::get(int index) {

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Set the data at the given index
void LinkedList::set(int index, int value) {

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;
}

// Get the size of the list
int LinkedList::getSize() {
    return size;
}

// Print the list
void LinkedList::print() {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Main function to test the doubly linked list
int main() {
    LinkedList list;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string choice;
        cin >> choice;

        if (choice == "insert") {
            int index, N;
            cin >> index >> N;

            int* values = new int[N];
            for (int k = 0; k < N; k++) {
                cin >> values[k];
            }
            list.insert_before(index, N, values);
            delete[] values;
        }
        else if (choice == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        }
        else if (choice == "size") {
            cout << list.getSize() << endl;
        }
        else if (choice == "get") {
            int index;
            cin >> index;
            cout << list.get(index) << endl;  
        }
        else if (choice == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        }
        else if (choice == "print") {
            list.print();
        }
    }



    return 0;
}
