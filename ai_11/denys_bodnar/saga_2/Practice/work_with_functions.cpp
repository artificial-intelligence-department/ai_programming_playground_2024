#include <iostream>
#include <fstream> // Для роботи з файлами
#include <string>

using namespace std;

// Структура вузла для списку
struct Node {
    int data;
    Node* next;
};

// Функція для створення нового вузла
Node* createNode(int value) {
    return new Node{value, nullptr};
}

// Додати вузол у кінець списку
void addNodeToEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Рекурсивний обхід списку та вивід у консоль
void printListRecursively(Node* head) {
    if (!head) return;
    cout << head->data << " -> ";
    printListRecursively(head->next);
}

// Рекурсивний обхід списку з записом у файл
void printListToFileRecursively(Node* head, ofstream& outFile) {
    if (!head) return;
    outFile << head->data << " ";
    printListToFileRecursively(head->next, outFile);
}

// Циклічний обхід списку та вивід у консоль (перевантаження)
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null\n";
}

// Циклічний обхід списку з записом у файл (перевантаження)
void printListToFile(Node* head, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        while (head) {
            outFile << head->data << " ";
            head = head->next;
        }
        outFile.close();
        cout << "Дані списку записано у файл: " << filename << endl;
    } else {
        cout << "Не вдалося відкрити файл для запису: " << filename << endl;
    }
}

int main() {
    // Створення списку
    Node* list = nullptr;
    addNodeToEnd(list, 10);
    addNodeToEnd(list, 20);
    addNodeToEnd(list, 30);
    addNodeToEnd(list, 40);

    // Рекурсивний обхід списку
    cout << "Список (рекурсивно):\n";
    printListRecursively(list);
    cout << "null\n";

    // Запис у файл рекурсивно
    string recursiveFile = "list_recursive.txt";
    ofstream outFileRecursive(recursiveFile);
    if (outFileRecursive.is_open()) {
        printListToFileRecursively(list, outFileRecursive);
        outFileRecursive.close();
        cout << "Список записано у файл (рекурсивно): " << recursiveFile << endl;
    } else {
        cout << "Не вдалося відкрити файл для запису: " << recursiveFile << endl;
    }

    // Циклічний обхід списку
    cout << "Список (циклічно):\n";
    printList(list);

    // Запис у файл циклічно
    string cyclicFile = "list_cyclic.txt";
    printListToFile(list, cyclicFile);

    return 0;
}
