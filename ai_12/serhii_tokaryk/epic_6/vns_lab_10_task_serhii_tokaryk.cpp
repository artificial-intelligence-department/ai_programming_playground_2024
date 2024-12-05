#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    char *pc;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _DblLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;

DblLinkedList* createDblLinkedList() {
    DblLinkedList *tmp = (DblLinkedList*)malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void deleteDblLinkedList(DblLinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp->pc); // Звільняємо пам'ять, виділену для рядка
        free(tmp);
        tmp = next;
    }
    free(*list);
    *list = NULL;
}

void pushFront(DblLinkedList *list, const char *data) {
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->pc = strdup(data); // Копіюємо рядок
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

void pushBack(DblLinkedList *list, const char *value) {
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->pc = strdup(value); // Копіюємо рядок
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

void* deleteNth(DblLinkedList *list, size_t index) {
    Node *tmp = list->head;
    size_t i = 0;
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
    if (!tmp) return NULL;
    if (tmp->prev) tmp->prev->next = tmp->next;
    if (tmp->next) tmp->next->prev = tmp->prev;
    if (!tmp->prev) list->head = tmp->next;
    if (!tmp->next) list->tail = tmp->prev;
    char *data = tmp->pc;
    free(tmp);
    list->size--;
    return data;
}

Node* getNth(DblLinkedList *list, size_t index) {
    Node *tmp = list->head;
    size_t i = 0;
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

void insert(DblLinkedList *list, size_t index, const char *value) {
    Node *elm = getNth(list, index);
    if (!elm) return;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->pc = strdup(value); // Копіюємо рядок
    newNode->prev = elm;
    newNode->next = elm->next;
    if (elm->next) elm->next->prev = newNode;
    elm->next = newNode;
    if (!elm->prev) list->head = elm;
    if (!elm->next) list->tail = elm;
    list->size++;
}

void listPrint(DblLinkedList *list) {
    Node *tmp = list->head;
    while (tmp) {
        printf("%s ", tmp->pc);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    DblLinkedList *list = createDblLinkedList();
    pushBack(list, "one");
    pushBack(list, "two");
    pushBack(list, "three");
    listPrint(list);

    deleteNth(list, 1);
    listPrint(list);

    Node *target = getNth(list, 1);
    if (target) {
        insert(list, 1, "inserted-before");
        insert(list, 2, "inserted-after");
    }
    listPrint(list);

    deleteDblLinkedList(&list);
    return 0;
}
