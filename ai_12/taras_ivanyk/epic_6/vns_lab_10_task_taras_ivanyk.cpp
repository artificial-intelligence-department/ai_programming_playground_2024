#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    int key;
    Node* next;
    Node* prev;
    Node(int k) : key(k), next(nullptr), prev(nullptr) {};
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {};

    void CreateEmptyList(){
        head = tail = nullptr;
        cout << "Empty list was createn! " << endl;
    }
    void addToEnd(int key){
        Node* newNode = new Node(key);
        if(!head){
            head = tail = newNode;
        } else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void printList() {
        if (!head) {
            cout << "Список порожній." << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void deleteAfter(int position) {
        if (!head) {
            cout << "Список порожній. Видалення неможливе." << endl;
            return;
        }
        Node* temp = head;
        int index = 0;
        while (temp && index < position) {
            temp = temp->next;
            ++index;
        }

        if (temp && temp->next) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete->next) {
                toDelete->next->prev = temp;
            } else {
                tail = temp;
            }
            delete toDelete;
            cout << "Елемент після позиції " << position << " видалено." << endl;
        } else {
            cout << "Видалення неможливе. Немає елемента після заданої позиції." << endl;
        }
    }
    void addToStart(int K, int startKey) {
        for (int i = 0; i < K; ++i) {
            Node* newNode = new Node(startKey + i);
            if (!head) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        cout << K << " елементів додано на початок списку." << endl;
    }
     void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Помилка відкриття файлу для запису!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            file << temp->key << " ";
            temp = temp->next;
        }
        file.close();
        cout << "Список збережено у файл '" << filename << "'." << endl;
    }
    void destroyList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "Список знищено." << endl;
    }
     void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Помилка відкриття файлу для читання!" << endl;
            return;
        }
        destroyList(); 
        int key;
        while (file >> key) {
            addToEnd(key);
        }
        file.close();
        cout << "Список відновлено з файлу '" << filename << "'." << endl;
    }
    ~DoubleLinkedList() {
        destroyList();
    }
};

int main() {
    DoubleLinkedList list;

    list.CreateEmptyList();  
    list.addToEnd(10);
    list.addToEnd(20);
    list.addToEnd(30);
    cout << "Список після створення:" << endl;
    list.printList();

    list.addToStart(2, 50); 
    cout << "Список після додавання елементів у початок:" << endl;
    list.printList();

    list.deleteAfter(1); 
    cout << "Список після видалення елемента після позиції 1:" << endl;
    list.printList();

    list.saveToFile("list.txt"); // 4 (запис)

    list.destroyList(); 
    cout << "Список після знищення:" << endl;
    list.printList();

    list.loadFromFile("list.txt"); // відновлення списку
    cout << "Список після відновлення з файлу:" << endl;
    list.printList();

    list.destroyList(); 
    cout << "Список після остаточного знищення:" << endl;
    list.printList();

    return 0;
}
