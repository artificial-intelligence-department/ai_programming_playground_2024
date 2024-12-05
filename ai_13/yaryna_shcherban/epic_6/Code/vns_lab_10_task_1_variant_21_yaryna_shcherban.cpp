#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

// Структура-вузол двонаправленого списку
struct Node {
    char* pc;            
    Node* next;          
    Node* prev;          
};

// Структура для зберігання двонаправленого списку
struct DblLinkedList {
    size_t size;         
    Node* head;          
    Node* tail;          
};

// Створення порожнього двонаправленого списку
DblLinkedList* createDblLinkedList() {
    DblLinkedList* list = new DblLinkedList;
    list->size = 0;
    list->head = list->tail = nullptr;
    return list;
}

// Видалення списку та всіх його елементів
void deleteDblLinkedList(DblLinkedList* list) {
    Node* current = list->head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        delete[] current->pc; 
        delete current;        
        current = next;
    }
    
    delete list;
}

// Додавання елемента в кінець списку
void pushBack(DblLinkedList* list, const char* value) {
    Node* newNode = new Node;
    newNode->pc = new char[strlen(value) + 1];
    strcpy(newNode->pc, value);
    newNode->next = nullptr;
    newNode->prev = list->tail;

    if (list->tail != nullptr) {
        list->tail->next = newNode;
    }
    list->tail = newNode;
    if (list->head == nullptr) {
        list->head = newNode;
    }
    list->size++;
}

// Додавання елемента на початок списку
void pushFront(DblLinkedList* list, const char* value) {
    Node* newNode = new Node;
    newNode->pc = new char[strlen(value) + 1];
    strcpy(newNode->pc, value);
    newNode->prev = nullptr;
    newNode->next = list->head;

    if (list->head != nullptr) {
        list->head->prev = newNode;
    }
    list->head = newNode;
    if (list->tail == nullptr) {
        list->tail = newNode;
    }
    list->size++;
}

// Видалення елемента з початку списку
const char* popFront(DblLinkedList* list) {
    if (list->head == nullptr) {
        throw runtime_error("List is empty!");
    }

    Node* temp = list->head;
    const char* data = temp->pc;
    list->head = list->head->next;

    if (list->head != nullptr) {
        list->head->prev = nullptr;
    } else {
        list->tail = nullptr;
    }

    delete temp;
    list->size--;
    return data;
}

// Видалення елемента з кінця списку
const char* popBack(DblLinkedList* list) {
    if (list->tail == nullptr) {
        throw runtime_error("List is empty!");
    }

    Node* temp = list->tail;
    const char* data = temp->pc;
    list->tail = list->tail->prev;

    if (list->tail != nullptr) {
        list->tail->next = nullptr;
    } else {
        list->head = nullptr;
    }

    delete temp;
    list->size--;
    return data;
}

// Видалення елементів перед і після елементу із заданим ключем
void deleteAroundKey(DblLinkedList* list, const char* key) {
    Node* current = list->head;
    // Знайти вузол з ключем
    while (current != nullptr) {
        if (strcmp(current->pc, key) == 0) {
            // Видалити попередній елемент
            if (current->prev != nullptr) {
                Node* toDelete = current->prev;
                current->prev = toDelete->prev;
                if (toDelete->prev != nullptr) {
                    toDelete->prev->next = current;
                } else {
                    list->head = current; // Якщо видаляємо перший елемент
                }
                delete[] toDelete->pc;
                delete toDelete;
                list->size--;
            }
            // Видалити наступний елемент
            if (current->next != nullptr) {
                Node* toDelete = current->next;
                current->next = toDelete->next;
                if (toDelete->next != nullptr) {
                    toDelete->next->prev = current;
                } else {
                    list->tail = current; // Якщо видаляємо останній елемент
                }
                delete[] toDelete->pc;
                delete toDelete;
                list->size--;
            }
            return; // Виходимо після видалення
        }
        current = current->next;
    }
    cout << "Key not found!" << endl;
}

// Виведення списку на екран
void listPrint(DblLinkedList* list) {
    if (list->head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = list->head;
    while (current != nullptr) {
        cout << current->pc << " ";
        current = current->next;
    }
    cout << endl;
}

// Запис списку в файл
void writeFile(DblLinkedList* list, const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error opening file!");
    }

    Node* current = list->head;
    while (current != nullptr) {
        file << current->pc << endl;
        current = current->next;
    }
}

// Відновлення списку з файлу
void readFile(DblLinkedList* list, const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error opening file!");
    }

    string line;
    while (getline(file, line)) {
        pushBack(list, line.c_str());
    }
}

int main() {
    DblLinkedList* list = createDblLinkedList();

    // Створення списку з файлу
    try {
        readFile(list, "test.txt");
        cout << "List after reading from file:" << endl;
        listPrint(list);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    // Додавання елементів на початок і в кінець
    pushFront(list, "Hello");
    pushBack(list, "World");
    pushBack(list, "Additional");
    pushBack(list, "Data");
    pushFront(list, "NewStart");
    cout << "List after pushing front and back:" << endl;
    listPrint(list);

    // Видалення елементів
    try {
        cout << "Pop front: " << popFront(list) << endl;
        cout << "Pop back: " << popBack(list) << endl;
        cout << "List after pop operations:" << endl;
        listPrint(list);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    // Видалення елементів перед і після заданого ключа
    const char* key = "Hello"; // Задання ключа для видалення
    deleteAroundKey(list, key);
    cout << "List after deleting around key '" << key << "':" << endl;
    listPrint(list);

    // Запис списку в файл
    try {
        writeFile(list, "output.txt");
        cout << "List written to output.txt" << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    // Видалення списку
    deleteDblLinkedList(list);
    return 0;
}