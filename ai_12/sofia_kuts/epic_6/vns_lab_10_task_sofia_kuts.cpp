#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key[100];          
    struct Node* next;      
    struct Node* prev;      
} Node;

Node* createList() {
    return NULL;
}

void addToEnd(Node** head, const char* key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void addToFront(Node** head, const char* key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void deleteNode(Node** head, const char* key) {
    Node* temp = *head;

    while (temp != NULL && strcmp(temp->key, key) != 0) {
        temp = temp->next;
    }

    if (temp != NULL) {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            *head = temp->next;  
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Список порожній.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

void saveToFile(Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        fprintf(file, "%s\n", temp->key);
        temp = temp->next;
    }
    fclose(file);
}

Node* loadFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return NULL;
    }
    Node* head = NULL;
    char key[100];
    while (fgets(key, sizeof(key), file)) {
        key[strcspn(key, "\n")] = '\0';  
        addToEnd(&head, key);
    }
    fclose(file);
    return head;
}

void destroyList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {
    Node* list = createList();
    
    addToEnd(&list, "apple");
    addToEnd(&list, "banana");
    addToEnd(&list, "cherry");
    printf("Список після додавання елементів:\n");
    printList(list);

    addToFront(&list, "kiwi");
    addToFront(&list, "grape");
    printf("Список після додавання елементів на початок:\n");
    printList(list);

    deleteNode(&list, "banana");
    printf("Список після знищення елемента 'banana':\n");
    printList(list);

    saveToFile(list, "list.txt");
    printf("Список записано у файл.\n");

    destroyList(&list);
    printf("Список знищено.\n");
    printList(list);

    list = loadFromFile("list.txt");
    printf("Список відновлено з файлу:\n");
    printList(list);

    destroyList(&list);
    printf("Список знищено.\n");

    return 0;
}
