#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Node {
    char* data;
    Node* prev;
    Node* next;

    Node(const char* value) : prev(nullptr), next(nullptr) {
        data = new char[strlen(value) + 1];
        strcpy(data, value);
    }

    ~Node() {
        delete[] data;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    void addToHead(const char* value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteByIndices(int index, int k) {
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index; i++) {
            temp = temp->next;
        }
        for (int i = 0; temp != nullptr && i < k; i++) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void saveToFile(const char* filename) {
        ofstream outFile(filename);
        Node* temp = head;
        while (temp) {
            outFile << temp->data << endl;
            temp = temp->next;
        }
    }

    void loadFromFile(const char* filename) {
        ifstream inFile(filename);
        string line;
        while (getline(inFile, line)) {
            addToHead(line.c_str());
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.addToHead("First");
    list.addToHead("Second");
    list.addToHead("Third");

    list.printList();

    list.deleteByIndices(1, 2);
    list.printList();

    list.saveToFile("list.txt");
    list.clear();

    list.loadFromFile("list.txt");
    list.printList();

    return 0;
}
