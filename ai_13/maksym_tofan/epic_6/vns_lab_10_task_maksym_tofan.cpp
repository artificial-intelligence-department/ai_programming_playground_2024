#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура вузла списку
struct Node {
    string data;
    Node* prev;
    Node* next;
};

// Функція для створення нового вузла
Node* createNode(const string& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Функція для додавання елемента після вузла зі вказаним символом
void addAfter(Node*& head, char symbol, const string& value) {
    Node* current = head;
    while (current) {
        if (!current->data.empty() && current->data[0] == symbol) {
            Node* newNode = createNode(value);
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
    cout << "Елемент з символом '" << symbol << "' не знайдено.\n";
}

// Функція для знищення K перших елементів
void deleteFirstK(Node*& head, int k) {
    for (int i = 0; i < k && head; ++i) {
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
    }
}

// Функція для друку списку
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функція для запису списку у файл
void saveToFile(Node* head, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Не вдалося відкрити файл для запису.\n";
        return;
    }
    Node* current = head;
    while (current) {
        outFile << current->data << endl;
        current = current->next;
    }
    outFile.close();
}

// Функція для відновлення списку з файлу
void loadFromFile(Node*& head, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Не вдалося відкрити файл для читання.\n";
        return;
    }
    string line;
    Node* tail = nullptr;
    while (getline(inFile, line)) {
        Node* newNode = createNode(line);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
    }
    inFile.close();
}

// Функція для очищення всього списку
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    // Створення списку
    head = createNode("apple");
    head->next = createNode("banana");
    head->next->prev = head;
    head->next->next = createNode("cherry");
    head->next->next->prev = head->next;

    cout << "Початковий список: ";
    printList(head);

    // Додавання елемента
    addAfter(head, 'b', "blueberry");
    cout << "Після додавання 'blueberry' після 'banana': ";
    printList(head);

    // Знищення K перших елементів
    deleteFirstK(head, 2);
    cout << "Після видалення 2 перших елементів: ";
    printList(head);

    // Запис у файл
    saveToFile(head, "list.txt");
    cout << "Список записано у файл 'list.txt'.\n";

    // Очищення списку
    deleteList(head);
    cout << "Список очищено.\n";

    // Відновлення списку з файлу
    loadFromFile(head, "list.txt");
    cout << "Список відновлено з файлу: ";
    printList(head);

    // Очищення пам'яті
    deleteList(head);



    return 0;
}




