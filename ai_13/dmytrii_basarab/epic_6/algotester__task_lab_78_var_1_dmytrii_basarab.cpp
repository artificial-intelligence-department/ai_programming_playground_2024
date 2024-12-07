#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

// Глобальні змінні для списку
Node* head = nullptr;
Node* tail = nullptr;
size_t listSize = 0;

// Додавання елементів на задану позицію
void insert(int index, const vector<int>& values) {
    if (index < 0 || index > listSize) {
        cerr << "Неправильне число" << endl;
    }

    for (int val : values) {
        Node* newNode = new Node{val};

        if (index == 0) { // Вставка на початок
            if (head == nullptr) {// Коли елементів нема
                tail = newNode;
                head = tail;
            } else {// Коли 1 елемент то перед тим вставояєм 
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        } else if (index == listSize) { // Вставка в кінець
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else { // Вставка в середину
            Node* current = head;
            for (int i = 0; i < index; ++i) {// Доходим до потібного індексу
                current = current->next;
            }
            newNode->next = current;// Тре його вставити перед елеметом ло якого ми дойшли
            newNode->prev = current->prev;
            if (current->prev) {// То коли ми в 0 індексі
                current->prev->next = newNode;
            }
            current->prev = newNode;
        }

        ++index;
        ++listSize;
    }
}

// Видалення елементів, починаючи з індексу
void erase(int index, int n) {
    if (index < 0 || index >= listSize || n < 0 || index + n > listSize) {
        cerr << "Неправильне число" << endl;
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
// Доходим до індекса
    for (int i = 0; i < n; ++i) {//повторюєм скільки тре
        Node* toDelete = current;
        if (current->prev) {// Зєднуєм вперед
            current->prev->next = current->next;
        } else {// Якшо то перший елемент
            head = current->next;
        }
        if (current->next) { // Зєднуєм назад
            current->next->prev = current->prev;
        } else { // Якшо то останній елемент
            tail = current->prev;
        }
        current = current->next; // Ідем далі
        delete toDelete;
        --listSize;
    }
}

// Отримання значення елемента за індексом
int get(int index) {
    if (index < 0 || index >= listSize) {
        cerr << "Неправильне число" << endl;
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    } // Просто доходим як в минулих циклах до елемента і видааєм дані
    return current->value;
}

// Модифікація значення елемента за індексом
void set(int index, int value) {
    if (index < 0 || index >= listSize) {
        cerr << "Неправильне число" << endl;
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->value = value;
}

// Друк списку
void printList() {
    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// Обробка запитів
void processQueries() {
    int Q;
    cin >> Q;

    while (--Q >= 0) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, N;
            cin >> index >> N;
            vector<int> values(N);
            for (int i = 0; i < N; ++i) {
                cin >> values[i];
            }
            insert(index, values);

        } else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            erase(index, n);

        } else if (command == "size") {
            cout << listSize << endl;

        } else if (command == "get") {
            int index;
            cin >> index;
            cout << get(index) << endl;

        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            set(index, value);
            
        } else if (command == "print") {
            printList();

        } else {
            cerr << "Невідома команда: " << command << endl;
        }
    }
}

int main() {
    processQueries();
//коли ми ту роботу свою закінчили то виходим з функції і очищаєм память з хіпу
    // Очищення пам'яті
    while (head != nullptr) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return 0;
}
