#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Node {
    char key[100];  
    Node* next;  
    Node* prev;   
};


struct DoublyLinkedList {
    Node* head; 
    Node* tail; 

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void createEmptyList() {
        head = tail = nullptr;
    }

    void addElement(const char* key) {
        Node* newNode = new Node;
        strcpy(newNode->key, key);
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;

        if (head == nullptr) {
            head = newNode;
        }
    }

    void deleteElement(const char* key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (strcmp(temp->key, key) == 0) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }

                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                } else {
                    tail = temp->prev; 
                }

                delete temp;
                cout << "Елемент з ключем '" << key << "' видалено.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Елемент з ключем '" << key << "' не знайдений.\n";
    }


    void printList() {
        if (head == nullptr) {
            cout << "Список порожній.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    void saveToFile(const char* filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Не вдалося відкрити файл для запису.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            file << temp->key << endl;
            temp = temp->next;
        }
        file.close();
    }


    void loadFromFile(const char* filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Не вдалося відкрити файл для читання.\n";
            return;
        }
        char key[100];
        while (file.getline(key, 100)) {
            addElement(key);
        }
        file.close();
    }


    void destroyList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr;
        cout << "Список знищено.\n";
    }
};

int main() {
    DoublyLinkedList list;
    list.createEmptyList();
    list.addElement("element1");
    list.addElement("element2");
    list.addElement("element3");
    cout << "Список після додавання елементів:\n";
    list.printList();
    list.deleteElement("element2");
    cout << "Список після видалення елемента:\n";
    list.printList();
    list.addElement("element4");
    list.addElement("element5");
    cout << "Список після додавання нових елементів:\n";
    list.printList();
    list.saveToFile("list.txt");
    list.destroyList();
    list.loadFromFile("list.txt");
    cout << "Список після відновлення з файлу:\n";
    list.printList();
    list.destroyList();

    return 0;
}
