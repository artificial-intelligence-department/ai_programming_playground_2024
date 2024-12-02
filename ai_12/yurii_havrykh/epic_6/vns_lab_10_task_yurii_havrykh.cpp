#include <iostream>

using namespace std;

class Node {
public:
    char data;
    Node *next;
    Node *prev;

    Node(char value) {
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

    void init(int listSize, char values[]);

    void erase_end(int count);

    void insert(int key, char element);

    void print();

private:
    Node *head;
    Node *tail;
    int size;
};

void LinkedList::init(int listSize, char values[]) {

    Node *current = new Node(values[0]);
    head = current;
    for (int j = 1; j < listSize; j++) {
        Node *newNode = new Node(values[j]);
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
        size++;
    }
    tail = current;
}

void LinkedList::insert(int key, char element) {
    Node *current = head;
    Node *prev = nullptr;

    while ((current) && (current->data != key)) {
        prev = current;
        current = current->next;
    }
    prev = current;
    current = current->next;
    if (prev) {
        Node *newNode = new Node(element);
        newNode->next = current;
        newNode->prev = prev;

        prev->next = newNode;
        
        if(prev==tail)
            tail=newNode;
        else current->prev = newNode;
    } else cout << "Key element not found";

}

void LinkedList::erase_end(int count) {

    Node *current = tail;

    for (int j = 0; j < count; j++) {
        Node *nextNode = current->prev;
        delete current;
        current = nextNode;
        size--;
    }
    tail=current;
    tail->next= nullptr;
}

void LinkedList::print() {
    printf("Head: %c \nTail: %c\n",head->data, tail->data);
    Node *current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {

    LinkedList list;
    cout << "n:";
    int n, count;
    cin >> n;
    char elements[n], key, newElement;
    cout << "Start elements:";
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    list.init(n, elements);

    list.print();

    cout << "Count elements to erase:";
    cin >> count;
    list.erase_end(count);
    list.print();

    cout << "Key and new element:";
    cin >> key >> newElement;
    list.insert(key, newElement);
    list.print();

    return 0;
}
