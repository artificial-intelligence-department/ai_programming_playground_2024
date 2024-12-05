#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int key;
    Node* next;
};

// Функція для створення порожнього списку
Node* createList() {
    return nullptr;  // Створюємо порожній список
}

// Функція для друку списку
void printList(Node* head) {
    if (!head) {
        cout << "Список порожній" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Функція для додавання елемента в список
void addElement(Node*& head, int value, int position) {
    Node* newNode = new Node{value, nullptr};  // Створюємо новий вузол
    if (position == 0 || !head) {  // Додавання на початок списку
        newNode->next = head;  // Новий вузол вказує на поточну голову
        head = newNode;  // Оновлюємо голову списку
        return;
    }

    Node* temp = head;  // Починаємо з голови
    for (int i = 0; i < position - 1 && temp->next; ++i) {
        temp = temp->next;  // Переходимо до вузла перед позицією вставки
    }
    newNode->next = temp->next;  // Новий вузол вказує на наступний вузол
    temp->next = newNode;  // Поточний вузол вказує на новий вузол
}

// Функція для видалення елемента зі списку
void deleteElement(Node*& head, int position) {
    if (!head) return;

    Node* temp = head;
    if (position == 0) {
        head = head->next;
        delete temp;
        return;
    }

    for (int i = 0; temp && i < position - 1; ++i) {
        temp = temp->next;
    }
    if (!temp || !temp->next) return;

    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

// Функція для запису списку у файл
void writeToFile(Node* head, const string& filename) {
    ofstream file(filename);
    
    // Перевірка, чи вдалося відкрити файл
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл для запису: " << filename << endl;
        return;
    }

    Node* temp = head;
    while (temp) {
        file << temp->key << endl;
        temp = temp->next;
    }
    file.close();  // Закриваємо файл після запису
}

// Функція для відновлення списку з файлу
Node* readFromFile(const string& filename) {
    ifstream file(filename);
    
    // Перевірка, чи вдалося відкрити файл
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл: " << filename << endl;
        return nullptr;
    }

    Node* head = nullptr;
    Node* tail = nullptr;
    int value;

    while (file >> value) {
        Node* newNode = new Node{value, nullptr};
        
        if (!head) {
            head = tail = newNode;  // Якщо список порожній, новий вузол стає головою
        } else {
            tail->next = newNode;  // Додаємо новий вузол в кінець списку
            tail = newNode;        // Оновлюємо tail
        }
    }

    file.close();  // Закриваємо файл після зчитування
    return head;   // Повертаємо голову списку
}

// Функція для знищення списку
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* list = createList();
    
    addElement(list, 10, 0);  // Додавання елементів
    addElement(list, 20, 1);
    addElement(list, 30, 2);
    printList(list);

    deleteElement(list, 1);  // Видалення елемента
    printList(list);

    writeToFile(list, "list.txt");  // Запис у файл
    deleteList(list);
    printList(list);  // Список порожній

    list = readFromFile("list.txt");  // Відновлення з файлу
    printList(list);

    deleteList(list);  // Очищення пам'яті
    return 0;
}
