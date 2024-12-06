#include <iostream>
#include <fstream>
using namespace std;

// Структура для двонаправленого списку
struct Node {
    int data;          // Значення вузла
    Node* next;        // Вказівник на наступний вузол
    Node* prev;        // Вказівник на попередній вузол
    Node(int val) : data(val), next(nullptr), prev(nullptr) {} // Конструктор для ініціалізації вузла
};

class DoublyLinkedList {
private:
    Node* head;  // Вказівник на голову списку
    Node* tail;  // Вказівник на хвіст списку

public:
    // Конструктор для ініціалізації порожнього списку
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Деструктор для очищення списку при знищенні об'єкта
    ~DoublyLinkedList() {
        clear();
    }

    // 1. Створення порожнього списку
    void createList() {
        head = nullptr;
        tail = nullptr;
        cout << "Список створено" << endl;
    }

    // 2. Друк списку
    void printList() const {
        if (head == nullptr) {
            cout << "Список порожній" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 3. Додавання елемента у список
    void addAtEnd(int data) {
        Node* newNode = new Node(data);  // Створення нового вузла
        if (tail == nullptr) {
            head = tail = newNode;  // Якщо список порожній, новий вузол стає головою і хвостом
        } else {
            tail->next = newNode;   // Додаємо новий вузол після хвоста
            newNode->prev = tail;   // Вказуємо попередній вузол для нового вузла
            tail = newNode;         // Новий вузол стає новим хвостом
        }
        cout << "Додано елемент " << data << " у кінець списку" << endl;
    }

    // 3. Знищення елемента зі списку
    void deleteAtPosition(int position) {
        if (head == nullptr) return; // Якщо список порожній, нічого не робимо
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position; i++) {
            temp = temp->next; // Переходимо до вузла на позиції
        }
        if (temp == nullptr) return; // Якщо вузла на такій позиції не існує, нічого не робимо
        if (temp->prev != nullptr) temp->prev->next = temp->next; // Якщо це не голова списку, змінюємо вказівник попереднього вузла
        if (temp->next != nullptr) temp->next->prev = temp->prev; // Якщо це не хвіст списку, змінюємо вказівник наступного вузла
        if (temp == head) head = temp->next; // Якщо це голова списку, змінюємо голову
        if (temp == tail) tail = temp->prev; // Якщо це хвіст списку, змінюємо хвіст
        cout << "Видалено елемент на позиції " << position << endl;
        delete temp; // Видаляємо вузол
    }

    // 4. Здійснення змін у списку
    void modifyAndPrint(int deleteCount, int targetPosition, int addCount, int addValue) {
        for (int i = 0; i < deleteCount; ++i) {
            deleteAtPosition(targetPosition - deleteCount + i); // Знищуємо задану кількість елементів перед заданою позицією
        }
        printList(); // Друк списку після видалення
        for (int i = 0; i < addCount; ++i) {
            addAtEnd(addValue); // Додаємо задану кількість елементів у кінець списку
        }
        printList(); // Друк списку після додавання
    }

    // 5. Запис списку у файл
    void writeToFile(const string& filename) const {
        ofstream file(filename); // Відкриваємо файл для запису
        Node* temp = head;
        while (temp != nullptr) {
            file << temp->data << " "; // Записуємо дані у файл
            temp = temp->next;
        }
        file.close(); // Закриваємо файл
        cout << "Список записано у файл " << filename << endl;
    }

    // 6. Знищення списку
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current; // Видаляємо поточний вузол
            current = next;
        }
        head = tail = nullptr; // Очищаємо вказівники на голову і хвіст
        cout << "Список очищено" << endl;
    }

    // 8. Відновлення списку з файлу
    void readFromFile(const string& filename) {
        clear(); // Очищаємо поточний список
        ifstream file(filename); // Відкриваємо файл для читання
        int data;
        while (file >> data) {
            addAtEnd(data); // Додаємо дані з файлу у кінець списку
        }
        file.close(); // Закриваємо файл
        cout << "Список відновлено з файлу " << filename << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // 1. Створення списку
    list.createList();
    list.printList();

    // Додавання елементів у список
    list.addAtEnd(1);
    list.addAtEnd(2);
    list.addAtEnd(3);
    list.addAtEnd(4);
    list.printList();

    // 4. Виконання змін у списку та друк після кожної зміни
    list.modifyAndPrint(2, 2, 2, 5); // Знищити 2 елементи перед 2-м і додати 2 елементи зі значенням 5

    // 5. Запис списку у файл
    list.writeToFile("list.txt");

    // 6. Знищення списку
    list.clear();
    list.printList(); // Має вивести "Список порожній"

    // 8. Відновлення списку з файлу
    list.readFromFile("list.txt");
    list.printList();

    // 10. Знищити список
    list.clear();
    list.printList(); // Має вивести "Список порожній"

    return 0;
}
