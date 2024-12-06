#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Node {
    char* key;
    Node* prev;
    Node* next;
};

Node* createNode(const char* key) {
    Node* newNode = new Node;
    newNode->key = new char[strlen(key) + 1];
    strcpy(newNode->key, key);
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void addToHead(Node*& head, Node*& tail, const char* key) {
    Node* newNode = createNode(key);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addToTail(Node*& head, Node*& tail, const char* key) {
    Node* newNode = createNode(key);
    if (!tail) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteByKey(Node*& head, Node*& tail, const char* key) {
    Node* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (current->prev) current->prev->next = current->next;
            else head = current->next;
            if (current->next) current->next->prev = current->prev;
            else tail = current->prev;

            delete[] current->key;
            delete current;
            cout << "Element with key \"" << key << "\" deleted.\n";
            return;
        }
        current = current->next;
    }
    cout << "Element with key \"" << key << "\" not found.\n";
}

void printList(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* current = head;
    while (current) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

void saveToFile(Node* head, const char* filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Failed to open file for writing.\n";
        return;
    }
    Node* current = head;
    while (current) {
        file << current->key << endl;
        current = current->next;
    }
    file.close();
    cout << "List saved to file.\n";
}

void loadFromFile(Node*& head, Node*& tail, const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open file for reading.\n";
        return;
    }
    char buffer[256];
    while (file.getline(buffer, 256)) {
        addToTail(head, tail, buffer);
    }
    file.close();
    cout << "List loaded from file.\n";
}

void clearList(Node*& head, Node*& tail) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete[] temp->key;
        delete temp;
    }
    tail = nullptr;
    cout << "List cleared.\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int choice;
    char buffer[256];
    const char* filename = "list.txt";

    do {
        cout << "\n1. Add to head\n"
             << "2. Add to tail\n"
             << "3. Delete by key\n"
             << "4. Print list\n"
             << "5. Save to file\n"
             << "6. Load from file\n"
             << "7. Clear list\n"
             << "0. Exit\n"
             << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin.getline(buffer, 256);
                addToHead(head, tail, buffer);
                break;
            case 2:
                cout << "Enter key: ";
                cin.getline(buffer, 256);
                addToTail(head, tail, buffer);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin.getline(buffer, 256);
                deleteByKey(head, tail, buffer);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                saveToFile(head, filename);
                break;
            case 6:
                clearList(head, tail);
                loadFromFile(head, tail, filename);
                break;
            case 7:
                clearList(head, tail);
                break;
            case 0:
                clearList(head, tail);
                cout << "Program terminated.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
