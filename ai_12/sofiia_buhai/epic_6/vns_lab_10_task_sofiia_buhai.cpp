#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>



class Node {
public:
    char* data;
    Node* prev;
    Node* next;

    Node(char* &value) {
        data = value;
        prev=nullptr;
        next = nullptr;
    }
};


class LinkedList {

public:
    LinkedList() {
        size = 0;
        head = nullptr;
        tail=nullptr;
    }

// Створення списку.
    void create(LinkedList *list){
        int n = 4;
        size = n;
        char* elements[n] = {"sgyd", "lnaswer", "nskjdhdi", "aaaaaaa"};
        for(int i = 0; i < n; i++){
            char* value = elements[i];
        Node* newNode = new Node(value);
        newNode->data = strdup(value);
        newNode->next = nullptr;

        if(head == NULL){
            newNode->prev = nullptr;
            head = newNode;
        }else{
            Node* tmp = head;
            while(tmp->next != nullptr){
                tmp = tmp->next;
            }

            tmp->next = newNode;
            newNode->prev = tmp;
        }
    }
    }

void insert(char index_char, char* value) {
    Node* current = head;
    int index = size+2;

    for (int i = 0; i < size; i++) {
        if (current && *(current->data) == index_char) { 
            index = i+1;
            break;
        }
        if (current) {
            current = current->next;
        }
    }
    if(index == size+2) return;

    Node* newNode = new Node(value);

    if (index == size+1) { 
        if (tail) {
            tail->next = newNode;
        }
        newNode->prev = tail;
        tail = newNode;
        if (!head) {
            head = newNode;
        }
    } else { // Вставка в середину списку
        Node* current = head;
        for (int i = 0; i < index - 1; i++) { // Знайти елемент перед позицією вставки
            current = current->next;
        }
        Node* nextNode = current->next;
        current->next = newNode;
        newNode->prev = current;
        newNode->next = nextNode;
        if (nextNode) {
            nextNode->prev = newNode;
        }
    }

    size++; // Збільшити розмір списку
}




// Знищення елемента зі списку.
    void erase(int K){
        if (K <= 0 || K > size) {
            return;
        }
        Node* current = head;
        for (int i = 0; i < K; i++) {
            if (!current) break;
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
            head = current;
            size--;
        }
        head = current;
        if (head) {
            head->prev = nullptr;
        }
    }

    
// Друк списку.
    void print(){
        Node* current = head;
        if(current==nullptr){
            std::cerr << "Немає елементів у списку\n";
            return;
        }
        while(current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }


// Запис списку у файл.
    void write_to_file(const char* name){
        std::ofstream f(name);
        if (!f.is_open()) {
            std::cerr << "Не вдалося відкрити файл для запису" << std::endl;
            return;
        }
        Node* current = head;
        while(current) {
            f << current->data << "\n";
            current = current->next;
        }
        f.close();
    }


// Знищення списку.
    void deleteList(LinkedList **list){
        Node *tmp = (*list)->head;
        Node *next = NULL;
        while (tmp) {
            next = tmp->next;
            delete tmp;
            tmp = next;
            head = tmp;
            size--;
        }
    }


// Відновлення списку з файлу.
    LinkedList from_file(const char* name){
        std::ifstream f(name);
        if(!name){
            std::cerr << "Error opening file";
            return *this;
        }
        char string[50];
        while(f >> string){
            char* value = string;
            Node* newNode = new Node(value);
            newNode->data = strdup(value);
            newNode->next = nullptr;
            
            if(head == NULL){
                newNode->prev = nullptr;
                head = newNode;
            }else{
                Node* tmp = head;
                while(tmp->next != nullptr){
                    tmp = tmp->next;
                }
                tmp->next = newNode;
                newNode->prev = tmp;
            }
        }
        f.close();
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {  
        Node* current = list.head;
    
        while(current) {
            os << current->data << " ";
            current = current->next;
        }
        os << std::endl;
        return os;
    }

private:
    Node* head;
    Node* tail;
    int size;
};








int main(){
    const char* name = "File with list. txt";
    LinkedList* l = new LinkedList();

    l->create(l);
    //std::cout << "" << list;
    l->print();

    std::cout << "Введіть елемент, який хочете ввести : ";
    char value[50];
    scanf("%s", value);
    while(getchar() != '\n');
    std::cout << "Введіть символ, за яким знайти елемент : ";
    char index_char;
    scanf("%c", &index_char);
    while(getchar() != '\n');
    l->insert(index_char, value);
    l->print();

    std::cout << "Введіть кількість елементів, які потрібно видалити із початку списку: ";
    int K;
    std::cin >> K;
    while(getchar() != '\n');
    l->erase(K);
    l->print();

    std::cout << "Видалений список:\n";
    l->write_to_file(name);
    l->deleteList(&l);
    l->print();

    std::cout << "Відновлений список з файлу:\n";
    l->from_file(name);
    l->print();

    return 0;
}