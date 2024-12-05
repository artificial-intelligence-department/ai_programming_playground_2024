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

Node* createList() {
    return nullptr;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

void addElement(Node*& head, const char* newKey, char startChar) {
    Node* current = head;
    while (current) {
        if (current->key[0] == startChar) {
            Node* newNode = createNode(newKey);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    cout << "Елемент із символом '" << startChar << "' не знайдено.\n";
}

void deleteFirstKElements(Node*& head, int k) {
    while (k-- > 0 && head) {
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete[] temp->key;
        delete temp;
    }
}

void writeListToFile(Node* head, const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл для запису.\n";
        return;
    }
    Node* current = head;
    while (current) {
        file << current->key << endl;
        current = current->next;
    }

    file.close();
}

Node* readListFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл для читання.\n";
        return nullptr;
    }
    Node* head = nullptr;
    Node* tail = nullptr;
    char buffer[256];
    while (file.getline(buffer, 256)) {
        Node* newNode = createNode(buffer);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    file.close();

    return head;
}

void destroyList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete[] temp->key;
        delete temp;
    }
}

int main() {
    Node* list = createList();

    list = createNode("Denys");
    list->next = createNode("Bodnar");
    list->next->prev = list;
    list->next->next = createNode("Chinazes");
    list->next->next->prev = list->next;

    cout << "Початковий список:\n";
    printList(list);

    deleteFirstKElements(list, 2);
    cout << "Список після видалення перших 2 елементів:\n";
    printList(list);

    addElement(list, "Sanchizes", 'C');
    cout << "Список після додавання елемента:\n";
    printList(list);

    writeListToFile(list, "test.txt");

    destroyList(list);
    cout << "Список знищено.\n";

    list = readListFromFile("test.txt");
    cout << "Список після відновлення з файлу:\n";
    printList(list);

    destroyList(list);

    return 0;
}
