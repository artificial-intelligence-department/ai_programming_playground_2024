#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// двозв'язний список
struct Node {
    string data; 
    Node* next;  
    Node* prev;  
};

// створення списку
Node* createList() {
    return nullptr; 
}

// друк списку
void printList(Node* head) {
    if (!head) { 
        cout << "List is empty!" << endl;
        return;
    }
    Node* current = head;
    while (current) { 
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// додавання елементів на початок списку
void addToBeginning(Node*& head, const string& value) {
    Node* newNode = new Node{value, head, nullptr};
    if (head) head->prev = newNode;
    head = newNode;
}

// видалення елемента зі списку за номером
void deleteByIndex(Node*& head, int index) {
    if (!head) {
        cout << "No elements for deleting." << endl;
        return;
    }
    Node* current = head;
    int currentIndex = 0;

    while (current && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (!current) {
        cout << "Element with index " << index << " was not found." << endl;
        return;
    }

    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;
    if (current == head) head = current->next;

    delete current;
    cout << "Element with index " << index << " deleted." << endl;
}

// запис списка у файл
void saveToFile(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error open file for writing." << endl;
        return;
    }
    Node* current = head;
    while (current) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
    cout << "Список записано у файл " << filename << endl;
}

// знищення списку
void destroyList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "List deleted." << endl;
}

// відновлення списку з файлу
void restoreFromFile(Node*& head, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error open file for reading." << endl;
        return;
    }

    destroyList(head); 

    string line;
    while (getline(file, line)) {
        addToBeginning(head, line);
    }
    file.close();
    cout << "List restored from file " << filename << endl;
}

// Головна функція
int main() {
    Node* list = createList();
    string filename = "list_data.txt";

    // 1. Створення списку
    cout << "Create list." << endl;
    addToBeginning(list, "el3");
    addToBeginning(list, "el2");
    addToBeginning(list, "el1");

    // 2. Друк списку
    cout << "Current list: ";
    printList(list);

    // 3. Додавання кількох елементів у початок
    cout << "Add elements to beginning." << endl;
    addToBeginning(list, "new1");
    addToBeginning(list, "new2");
    cout << "List after adding: ";
    printList(list);

    // 4. Видалення елемента за номером
    cout << "Delete element with index 2." << endl;
    deleteByIndex(list, 2);
    cout << "List after deleting the element: ";
    printList(list);

    // 5. Запис списку у файл
    saveToFile(list, filename);

    // 6. Знищення списку
    destroyList(list);
    cout << "List after deleting: ";
    printList(list);

    // 7. Відновлення списку з файлу
    restoreFromFile(list, filename);
    cout << "List after recovery: ";
    printList(list);

    // 8. Знищення списку
    destroyList(list);
    cout << "List after final deleting: ";
    printList(list);

    return 0;
}
