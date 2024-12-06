#include <iostream>
#include <cstring>
#include <cstdarg>

using namespace std;

struct node {
    char* data;
    node* next;
    node* prev;
};

void createLL(node*& head) {
    cout << "Створення списку..." << endl;
    const char* values[] = {"Node 1", "Node 2", "Node 3", "Node 4", "Node 5", "Node 6"};

    for(int i = 0; i < 6; i++){
        node* newNode = new node;
        newNode->data = strdup(values[i]);
        newNode->next = nullptr;

        if(head == nullptr){
            newNode->prev = nullptr;
            head = newNode;
        }else{
            node* tmp = head;
            while(tmp->next != nullptr){
                tmp = tmp->next;
            }

            tmp->next = newNode;
            newNode->prev = tmp;
        }
    }
}

void deleteByData(node*& head, const char* data) {
    cout << "Видалення елемента: " << data << " зі списку..." << endl;
    if(head == nullptr) 
        return;
    node* tmp = head;
    node* toDelete;

    while (tmp != nullptr) {
        if (strcmp(tmp->data, data) == 0) {
            toDelete = tmp;

            if (toDelete == head) {
                head = toDelete->next;
                head->prev = nullptr;
            }
            else {
                if (toDelete->prev != nullptr) {
                    toDelete->prev->next = toDelete->next;
                }
                if (toDelete->next != nullptr) {
                    toDelete->next->prev = toDelete->prev;
                }
            }

            free(toDelete->data); 
            delete toDelete;
            tmp = (head != nullptr) ? head : nullptr;
        } else {
            tmp = tmp->next;
        }
    }    
}

void printLL(node* head) {
    cout << "Друк списку..." << endl;

    if(head == nullptr){
        cout << "Список пустий." << endl;
        return;
    }

    node* tmp = head;
    while(tmp != nullptr){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void addKElementsToEnd(node*& head, int K, ...) {
    cout << "Додавання " << K << " елементів в кінець списку..." << endl;

    va_list args;
    va_start(args, K);

    for (int i = 0; i < K; i++) {
        const char* data = va_arg(args, const char*);  
        node* newNode = new node; 

        newNode->data = strdup(data); 
        newNode->next = nullptr;  
        newNode->prev = nullptr;  

        if (head == nullptr) {
            head = newNode;
        } 
        else {
            node* tmp = head;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = newNode;  
            newNode->prev = tmp; 
        }
    }

    va_end(args); 
}

void writeLLToFile(node*& head, const char* filename) {
    cout << "Запис списку в файл: " << filename << "..." << endl;
    FILE* f = fopen(filename, "w");
    if(f == nullptr){
        cerr << "Can't open the file.";
        exit(1);
    }

    node* tmp = head;
    while(tmp != nullptr){
        const char* buffer = tmp->data;
        fputs(buffer, f);
        fputs("\n", f);
        tmp = tmp->next;
    }
    fclose(f);
}

void deleteLL(node*& head) {
    cout << "Знищення списку..." << endl;
    node* tmp = head;
    while(tmp != nullptr){
        node* nextNode = tmp->next;
        free(tmp->data);
        delete(tmp);
        tmp = nextNode;
    }
    head = nullptr;
}

void fromFileToLL(node*& head, const char* filename) {
    cout << "Відновлення списку з файлу: " << filename << "..." << endl;
    FILE* f = fopen(filename, "r");
    if(f == nullptr){
        cerr << "Can't open the file.";
        exit(1);
    }

    char buffer[256];
    node* tmp = nullptr;
    while(fgets(buffer, sizeof(buffer), f)){
        buffer[strcspn(buffer, "\n")] = '\0';

        node* newNode = new node;
        newNode->data = strdup(buffer);
        newNode->next = nullptr;
        newNode->prev = tmp;

        if(head == nullptr){
            head = newNode;
        }else{
            tmp->next = newNode;
        }
        tmp = newNode;
    }
    fclose(f);
}

int main() {
    node* head = nullptr;
    const char* dataToDelete = "Node 4";
    const char* filename = "file.txt";

    createLL(head);
    printLL(head);

    deleteByData(head, dataToDelete);
    printLL(head);

    addKElementsToEnd(head, 3, "Node 7", "Node 8", "Node 9");
    printLL(head);

    writeLLToFile(head, filename);
    deleteLL(head);
    printLL(head);

    fromFileToLL(head, filename);
    printLL(head);

    deleteLL(head);
    printLL(head);
}
