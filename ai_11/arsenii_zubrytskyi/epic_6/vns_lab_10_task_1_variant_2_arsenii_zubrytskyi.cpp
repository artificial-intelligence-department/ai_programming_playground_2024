#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура елемента списку
struct Node {
    int key;        // Ключове поле
    Node* next;     // Вказівник на наступний елемент
};

// Функція для створення порожнього списку
Node* createList() {
    return nullptr;  // Порожній список
}

// Функція для друку списку
void printList(Node* head) {
    if (head == nullptr) {
        cout << "Список порожній." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Функція для додавання елемента в список
void addNode(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->key = value;
    newNode->next = head;
    head = newNode;
}

// Функція для знищення елемента за номером
void deleteNode(Node*& head, int position) {
    if (head == nullptr) return;

    Node* temp = head;

    // Якщо видаляється перший елемент
    if (position == 1) {
        head = temp->next;
        delete temp;
        return;
    }

    // Знайдемо попередній елемент
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    // Якщо позиція неправильна
    if (temp == nullptr || temp->next == nullptr) return;

    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

// Функція для запису списку в файл
void saveListToFile(Node* head, const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        Node* temp = head;
        while (temp != nullptr) {
            file << temp->key << " ";
            temp = temp->next;
        }
        file.close();
    }
    else {
        cout << "Не вдалося відкрити файл для запису." << endl;
    }
}

// Функція для знищення списку
void deleteList(Node*& head) {
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
}

// Функція для відновлення списку з файлу
void restoreListFromFile(Node*& head, const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        int value;
        while (file >> value) {
            addNode(head, value);
        }
        file.close();
    } else {
        cout << "Не вдалося відкрити файл для зчитування." << endl;
    }
}

int main() {
    Node* list = createList();
    
    // Додавання елементів
    addNode(list, 10);
    addNode(list, 20);
    addNode(list, 30);

    cout << "Список після додавання елементів: ";
    printList(list);

    // Видалення елемента з позиції 2
    deleteNode(list, 2);
    cout << "Список після видалення елемента на позиції 2: ";
    printList(list);

    // Запис списку в файл
    saveListToFile(list, "list.txt");

    // Знищення списку
    deleteList(list);
    cout << "Після знищення списку: ";
    printList(list);

    // Відновлення списку з файлу
    restoreListFromFile(list, "list.txt");
    cout << "Список після відновлення з файлу: ";
    printList(list);

    // Знищення списку
    deleteList(list);
    return 0;
}
