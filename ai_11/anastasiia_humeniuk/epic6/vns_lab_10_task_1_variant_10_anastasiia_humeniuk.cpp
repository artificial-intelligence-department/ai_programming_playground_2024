#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void pushToEnd(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insert(Node*& head, Node*& tail, int pos, int value) {
    Node* newNode = new Node(value);

    if (pos == 0 || head == nullptr) { 
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
        if (tail == nullptr)
            tail = head;
        return;
    }

    Node* current = head;
    for (int i = 0; current && i < pos - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        pushToEnd(head, tail, value);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next) 
        current->next->prev = newNode;
    current->next = newNode;

    if (!newNode->next)
        tail = newNode;
}

void deleteFromEnd(Node*& head, Node*& tail, int k) {
    while (k > 0 && tail) {
        Node* temp = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; 
        }
        delete temp;
        k--;
    }
}

void printList(Node* head) {
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void writeListToFile(Node* head, const string& filename) {
    ofstream file(filename, ios::out);
    if (!file) {
        cout << "Can not open the file!" << endl;
        return;
    }

    while (head) {
        file << head->data << " ";
        head = head->next;
    }

    file.close();
    cout << "List was written." << endl;
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void restore(Node*& head, Node*& tail, const string& filename) {
    ifstream file(filename, ios::in);
    if (!file) {
        cout << "Can not open the file!" << endl;
        return;
    }

    int value;
    while (file >> value) {
        pushToEnd(head, tail, value);
    }

    file.close();
    cout << "List was restored" << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    pushToEnd(head, tail, 1);
    pushToEnd(head, tail, 2);
    pushToEnd(head, tail, 3);
    pushToEnd(head, tail, 4);

    cout << "List: ";
    printList(head);

    insert(head, tail, 2, 99);
    cout << "List after insertion 99 at second placr: ";
    printList(head);

    deleteFromEnd(head, tail, 2);
    cout << "List after removal 2 elements: ";
    printList(head);

    writeListToFile(head, "list.txt");

    deleteList(head);
    tail = nullptr;

    cout << "List after free: ";
    printList(head);

    restore(head, tail, "list.txt");
    cout << "List after restore: ";
    printList(head);

    deleteList(head);
    tail = nullptr;

    return 0;
}
