// 2 частина: що вартує попрактикувати - це струтури, однонапрямлені списки і вказівники (як атрибут структури на наступний елемент в списку, або попередній) :
// - створення однонаправленого з списку структур ✅
// - додавання нового вузла списку в кінець списку ✅
// - додавання нового вузла списку на початок списку ✅
// - додавання нового вузла списку в середині списку ✅
// - виведення значень з структури у списку ✅
// - сортування однонаправленого списку методом бульбашки ✅
// - подивитись як ще можна сортувати однонаправлений список ✅
// - всі такі самі дії з двонаправленим списком ✅
// - виведення значень у двонаправленому списку  з ліва на право і з права на ліво ✅
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// - створення однонаправленого з списку структур ✅
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}

// - додавання нового вузла списку в кінець списку ✅
void AddNewNodeToEnd(Node*& head, int value)
{
    Node* newNode = CreateNode(value);
    
    if (!head)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;     
}

// - додавання нового вузла списку на початок списку ✅
void AddNewNodeToStart(Node*& head, int value)
{
    Node* newNode = CreateNode(value);
    newNode->next = head;
    head = newNode;
}

// - додавання нового вузла списку в середині списку ✅
void AddNewNodeToMid(Node*& head, int value, int position)
{
    Node* newNode = CreateNode(value);
    Node* temp = head;

    for(int i = 1; i < position - 1 && temp->next; ++i)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

}

// - виведення значень з структури у списку ✅
void PrintList(Node* head)
{
    Node* temp = head;

    while(temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next; 
    }
    cout << "nullptr" << endl;
}

// - сортування однонаправленого списку методом бульбашки ✅
void BubbleSort(Node* head) 
{
    if (!head)
    { 
        return;
    }
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) 
        {
            if (current->data > current->next->data) 
            {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}



// - всі такі самі дії з двонаправленим списком ✅
// - створення двонапрваленого з списку структур ✅
struct DoubleNode 
{
    int data;
    DoubleNode* next;
    DoubleNode* prev;
};

DoubleNode* createDoubleNode(int value) 
{
    DoubleNode* newNode = new DoubleNode();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}
// - додавання нового вузла списку в кінець списку ✅
void AddNewDoubleNodeToEnd(DoubleNode*& head, int value)
{
    DoubleNode* newNode = createDoubleNode(value);
    if (!head)
    {
        head = newNode;
        return;
    }

    DoubleNode* temp = head;

    while (temp->next) 
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// - додавання нового вузла списку на початок списку ✅
void AddNewDoubleNodeToStart(DoubleNode*& head, int value)
{
    DoubleNode* newNode = createDoubleNode(value);
    newNode->next = head;

    if (head)
    { 
        head->prev = newNode;
    }
    head = newNode;
}

// - додавання нового вузла списку в середині списку ✅
void AddNewDoubleNodeToMid(DoubleNode* head, int value, int position) 
{
    if (!head || position <= 1) 
    {
        cout << "Неможливо додати у вказану позицію." << endl;
        return;
    }

    DoubleNode* newNode = createDoubleNode(value);
    DoubleNode* temp = head;

    for (int i = 1; i < position - 1 && temp->next; ++i) 
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) 
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// - виведення значень у двонаправленому списку  з ліва на право і з права на ліво ✅
void PrintLeftToRight(DoubleNode* head) 
{
    DoubleNode* temp = head;
    while (temp) 
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void PrintRightToLeft(DoubleNode* head) 
{
    if (!head) return;
    DoubleNode* temp = head;
    while (temp->next) 
    {
        temp = temp->next;
    }
    while (temp) 
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "nullptr" << endl;
}


int main()
{
    // Однонаправлений список
    Node* singleList = nullptr;

    // Додавання вузлів
    AddNewNodeToStart(singleList, 5);
    AddNewNodeToEnd(singleList, 10);
    AddNewNodeToStart(singleList, 1);
    AddNewNodeToMid(singleList, 7, 2);

    cout << "Однонаправлений список після додавання елементів: " << endl;
    PrintList(singleList);

    // Сортування
    BubbleSort(singleList);
    cout << "Однонаправлений список після сортування: " << endl;
    PrintList(singleList);

    // Двонаправлений список
    DoubleNode* doubleList = nullptr;

    // Додавання вузлів
    AddNewDoubleNodeToStart(doubleList, 20);
    AddNewDoubleNodeToEnd(doubleList, 15);
    AddNewDoubleNodeToStart(doubleList, 25);
    AddNewDoubleNodeToMid(doubleList, 18, 2);

    cout << "Двонаправлений список зліва направо: " << endl;
    PrintLeftToRight(doubleList);

    cout << "Двонаправлений список справа наліво: " << endl;
    PrintRightToLeft(doubleList);

    return 0;
}
