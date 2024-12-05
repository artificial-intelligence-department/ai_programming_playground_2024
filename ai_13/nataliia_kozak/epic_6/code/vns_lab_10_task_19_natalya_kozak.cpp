#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Структура для вузла двонаправленого списку
struct Node
{
    char *key;  // Ключове поле
    Node *next; // Вказівник на наступний елемент
    Node *prev; // Вказівник на попередній елемент
};

// Функція для створення порожнього списку
Node *createList()
{
    return nullptr;
}

// Функція для додавання елемента в початок списку
void addElement(Node *&head, const char *str)
{
    Node *newNode = new Node;
    newNode->key = new char[strlen(str) + 1];
    strcpy(newNode->key, str);
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr)
    {
        head->prev = newNode;
    }

    head = newNode;
}

// Функція для знищення елемента за індексом
void deleteElement(Node *&head, int index)
{
    if (head == nullptr)
    {
        cout << "Список порожній!" << endl;
        return;
    }

    Node *current = head;
    int count = 0;

    while (current != nullptr && count < index)
    {
        current = current->next;
        count++;
    }

    if (current == nullptr)
    {
        cout << "Елемент з таким індексом не знайдений!" << endl;
        return;
    }

    if (current->prev != nullptr)
    {
        current->prev->next = current->next;
    }
    else
    {
        head = current->next; // Якщо елемент на початку
    }

    if (current->next != nullptr)
    {
        current->next->prev = current->prev;
    }

    delete[] current->key;
    delete current;
}

// Функція для друку списку
void printList(Node *head)
{
    if (head == nullptr)
    {
        cout << "Список порожній!" << endl;
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

// Функція для запису списку у файл
void saveListToFile(Node *head, const char *filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cout << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        outFile << current->key << endl;
        current = current->next;
    }

    outFile.close();
    cout << "Список успішно збережено в файл!" << endl;
}

// Функція для відновлення списку з файлу
Node *loadListFromFile(const char *filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cout << "Не вдалося відкрити файл для читання!" << endl;
        return nullptr;
    }

    Node *head = nullptr;
    string line;

    while (getline(inFile, line))
    {
        addElement(head, line.c_str());
    }

    inFile.close();
    cout << "Список успішно відновлено з файлу!" << endl;
    return head;
}

// Функція для знищення списку
void destroyList(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete[] temp->key;
        delete temp;
    }
    cout << "Список знищено!" << endl;
}

int main()
{
    Node *list = createList();

    // Додавання елементів
    addElement(list, "hello");
    addElement(list, "world");
    addElement(list, "test");

    cout << "Список після додавання елементів:" << endl;
    printList(list);

    // Знищення елемента
    deleteElement(list, 1); // Видаляємо елемент з індексом 1 (world)

    cout << "Список після видалення елемента:" << endl;
    printList(list);

    // Запис у файл
    saveListToFile(list, "list.txt");

    // Знищення списку
    destroyList(list);

    cout << "Список після знищення:" << endl;
    printList(list);

    // Відновлення списку з файлу
    list = loadListFromFile("list.txt");

    cout << "Список після відновлення з файлу:" << endl;
    printList(list);

    // Знищення списку після завершення роботи
    destroyList(list);

    return 0;
}
