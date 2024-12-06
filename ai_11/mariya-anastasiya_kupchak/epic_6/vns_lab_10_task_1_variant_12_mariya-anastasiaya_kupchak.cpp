#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node 
{
    string key;
    Node* prev;
    Node* next;
};

Node* createList() 
{
    return nullptr; 
}

void printList(Node* head) 
{
    if (!head) 
    {
        cout << "Список порожній." << endl;
        return;
    }

    Node* current = head;
    while (current) 
    {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

void pushBack(Node*& head, const string& newKey) 
{
    Node* newNode = new Node{newKey, nullptr, nullptr};

    if (!head) 
    {
        head = newNode; 
        return;
    }

    Node* tail = head;
    while (tail->next) 
    {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->prev = tail;
}

void addAfter(Node*& head, const string& afterKey, const string& newKey) 
{
    Node* current = head;
    while (current && current->key != afterKey) 
    {
        current = current->next;
    }

    if (!current) 
    {
        cout << "Елемент з ключем \"" << afterKey << "\" не знайдено." << endl;
        return;
    }

    Node* newNode = new Node{newKey, current, current->next};
    if (current->next) 
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void deleteDuplicates(Node*& head) 
{
    Node* current = head;

    while (current) 
    {
        Node* runner = current->next;
        while (runner) 
        {
            if (runner->key == current->key) 
            {
                Node* duplicate = runner;
                runner = runner->next;

                if (duplicate->prev) duplicate->prev->next = duplicate->next;
                if (duplicate->next) duplicate->next->prev = duplicate->prev;
                if (duplicate == head) head = duplicate->next;

                delete duplicate;
            } 
            else 
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void writeToFile(Node* head, const string& filename) 
{
    ofstream file(filename, ios::out | ios::trunc);
    if (!file) 
    {
        cout << "Помилка відкриття файлу." << endl;
        return;
    }

    Node* current = head;
    while (current) 
    {
        file << current->key << endl;
        current = current->next;
    }
    file.close();
    cout << "Список записано у файл \"" << filename << "\"." << endl;
}

Node* readFromFile(const string& filename) 
{
    ifstream file(filename, ios::in);
    if (!file) 
    {
        cout << "Помилка відкриття файлу." << endl;
        return nullptr;
    }

    Node* head = nullptr;
    string key;
    while (getline(file, key)) 
    {
        pushBack(head, key);
    }

    file.close();
    cout << "Список відновлено з файлу \"" << filename << "\"." << endl;
    return head;
}

void deleteList(Node*& head) 
{
    while (head) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Список знищено." << endl;
}

int main() 
{
    Node* list = createList();

    cout << "Додавання елементів у список." << endl;
    pushBack(list, "apple");
    pushBack(list, "banana");
    pushBack(list, "cherry");
    printList(list);

    cout << "Додавання елемента після \"banana\"." << endl;
    addAfter(list, "banana", "grape");
    printList(list);

    cout << "Додавання елемента після \"cherry\"." << endl;
    addAfter(list, "cherry", "melon");
    printList(list);

    cout << "Спроба додати елемент після \"orange\" (неіснуючий ключ)." << endl;
    addAfter(list, "orange", "peach");
    printList(list);

    cout << "Знищення дублікатів." << endl;
    pushBack(list, "apple"); 
    pushBack(list, "grape");
    deleteDuplicates(list);
    printList(list);

    const string filename = "list.txt";

    cout << "Запис списку у файл." << endl;
    writeToFile(list, filename);

    cout << "Знищення списку." << endl;
    deleteList(list);
    printList(list);

    cout << "Відновлення списку з файлу." << endl;
    list = readFromFile(filename);
    printList(list);

    cout << "Знищення списку." << endl;
    deleteList(list);
    printList(list);

    return 0;
}
