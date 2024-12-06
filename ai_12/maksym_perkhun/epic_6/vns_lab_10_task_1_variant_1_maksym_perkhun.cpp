#include<iostream>
#include <cstring>  
#include <cstdio>

using namespace std;

struct Node{
    char* text;
    Node* next;
    Node* prev;
};

Node* createNode(const char* value) {
    Node* newNode = new Node();
    newNode->text = new char[strlen(value) + 1];  
    strcpy(newNode->text, value);               
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void deleteNode(Node* node) {
    delete[] node->text;
    delete node; 
}


void append(Node*& head, Node*& tail, const char* value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = tail = newNode;
    } 
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printList(Node* head){
    if (!head){
        cout << "Список порожній" << endl;
        return;
    }
    Node* current = head;
    while(current){
        cout << current -> text << " ";
        current = current -> next;
    }
    cout << endl;

}

void deleteFirstK(Node*& head, Node*& tail, int k) {
    while (head && k--) {
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        deleteNode(temp);
    }
}

void addAfter(Node*& head, Node*& tail, char symbol, const char* value) {
    Node* current = head;
    while (current) {
        if (current->text[0] == symbol) {
            Node* newNode = createNode(value);
            newNode->next = current->next;
            newNode->prev = current;

            if (current->next) {
                current->next->prev = newNode;
            } 
            else {
                tail = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void saveToFile(Node* head, const char* filename) {
    FILE* fileStream = fopen(filename, "w");
    if (!fileStream) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    Node* current = head;
    while (current) {
        fprintf(fileStream, "%s\n", current->text);
        current = current->next;
    }
    fclose(fileStream);
}

void restoreFromFile(Node*& head, Node*& tail, const char* filename) {
    FILE* fileStream = fopen(filename, "r");
    if (!fileStream) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return;
    }
    char buffer[256];  
    while (fscanf(fileStream, "%255s", buffer) != EOF) {
        append(head, tail, buffer);
    }
    fclose(fileStream);
}

void deleteList(Node*& head, Node*& tail) {
    while (head) {
        Node* temp = head;
        head = head->next;
        deleteNode(temp);
    }
    tail = nullptr;
}


int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    append(head, tail, "apple");
    append(head, tail, "banana");
    append(head, tail, "cherry");
    append(head, tail, "orange");
    cout << "Початковий список: ";
    printList(head);

    int k;
    cout << "Введіть кількість перших елементів, які треба видалити - ";
    cin >> k;
    deleteFirstK(head, tail, k);
    cout << "Cписок після видалення перших 2 елементів: ";
    printList(head);

    char c;
    cout << "Введіть cимвол з якого починається елемент після якого треба додати елемент - ";
    cin >> c;
    addAfter(head, tail, c, "peach");
    cout << "Список після вставлення елементу: ";
    printList(head);

    saveToFile(head, "list.txt");
    cout << "Список записано у файл." << endl;

    deleteList(head, tail);
    cout << "Після знищення списку: ";
    printList(head);

    restoreFromFile(head, tail, "list.txt");
    cout << "Список після відновлення з файлу: ";
    printList(head);

    deleteList(head, tail);
    cout << "Після остаточного знищення списку: ";
    printList(head);
    return 0;
}