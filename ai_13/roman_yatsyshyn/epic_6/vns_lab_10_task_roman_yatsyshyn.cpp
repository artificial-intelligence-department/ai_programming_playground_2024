#include <iostream>
#include <fstream>
using namespace std;

// Структура вузла списку
struct Node {
    int data;    
    Node* next;
};

// Функція створення порожнього списку
Node* createList() {
    return nullptr;
}

void addToTail(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void fillList(Node*& head) {
    for (int i = 1; i <= 10; ++i) {
        addToTail(head, i);
    }
}

// Функція друку списку
void printList(Node* head) {
    if (!head) {
        cout << "Список порожній." << endl;
        return;
    }
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функція додавання елемента в список з заданої позиції
void addElements(Node*& head, int position, int count) {
    Node* current = head;
    int currentIndex = 1;
    
    while (current && currentIndex < position) {
        current = current->next;
        currentIndex++;
    }

    for (int i = 0; i < count; i++) {
        Node* newNode = new Node;
        cout << "Введіть значення для нового елемента: ";
        cin >> newNode->data;
        newNode->next = current ? current->next : nullptr;
        if (current) {
            current->next = newNode;
        } else {
            head = newNode;
        }
        current = newNode;

        printList(head);
    }
}

// Функція видалення елемента зі списку за номером
void deleteElement(Node*& head, int position) {
    if (!head) {
        cout << "Список порожній." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    int currentIndex = 1;

    while (current->next && currentIndex < position - 1) {
        current = current->next;
        currentIndex++;
    }

    if (!current->next) {
        cout << "Неможливо видалити: позиція виходить за межі списку." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    printList(head);
}

// Функція запису списку у файл
void saveToFile(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Помилка відкриття файлу." << endl;
        return;
    }

    Node* current = head;
    while (current) {
        file << current->data << " ";
        current = current->next;
    }
    file.close();
}

// Функція знищення списку
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Список знищено." << endl;
}

// Функція відновлення списку з файлу
void restoreFromFile(Node*& head, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Помилка відкриття файлу." << endl;
        return;
    }

    deleteList(head);

    int value;
    Node* tail = nullptr;
    while (file >> value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    file.close();

    printList(head);
}



int main() {
    Node* list = createList();
    fillList(list);

    int choice, position, count;
    
    printList(list);
    
    cout << "Введіть номер елемента для видалення: ";
    cin >> position;
    deleteElement(list, position);

    cout << "Введіть позицію для додавання: ";
    cin >> position;
    cout << "Введіть кількість елементів для додавання: ";
    cin >> count;
    addElements(list, position, count);
    
    saveToFile(list, "list.txt");

    deleteList(list);

    printList(list);

    restoreFromFile(list, "list.txt");

    deleteList(list);
}
