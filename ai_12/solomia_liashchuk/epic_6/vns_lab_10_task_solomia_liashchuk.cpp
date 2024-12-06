#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node* next;
    Node* prev;
    string key;

    Node(const string& value)
    {
        key = value;
        next = nullptr;
        prev = nullptr;
    }
};

void addEnd(Node*& head, const string& value) 
{
    Node* newNode = new Node(value);

    if(head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* current = head;
    while(current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void deleteElements(Node*& head, const string& targetKey)
{
    Node* current = head;

    while(current != nullptr && current->key != targetKey)
    {
        current = current->next;
    }

    if(current == nullptr)
    {
        cout << "Error: Key not found" << endl;
        return;
    }

    if(current->prev != nullptr)
    {
        Node* toDelete = current->prev;

        if(toDelete->prev != nullptr)
        {
            toDelete->prev->next = current;
        }
        else
        {
            head = current; 
        }

        current->prev = toDelete->prev;
        delete toDelete;
    }

    if(current->next != nullptr)
    {
        Node* toDelete = current->next;

        if(toDelete->next != nullptr)
        {
            toDelete->next->prev = current;
        }

        current->next = toDelete->next;
        delete toDelete;
    }
}

void printList(Node* head)
{
    Node* current = head;

    while(current != nullptr)
    {
        cout << current->key << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

void addToStart(Node*& head, const string& value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    if(head != nullptr)
    {
        head->prev = newNode;
    }

    head = newNode;
}

int main()
{
    Node* head = nullptr;
    addEnd(head, "Блакитний");
    addEnd(head, "Червоний");
    addEnd(head, "Чорний");
    addEnd(head, "Рожевий");

    cout << "Початковий список:" << endl;
    printList(head);

    deleteElements(head, "Beta");
    cout << "Список після видалення елементів перед і після 'Beta':" << endl;
    printList(head);

    addToStart(head, "Start");
    cout << "Список після додавання елемента на початок:" << endl;
    printList(head);

    return 0;
}