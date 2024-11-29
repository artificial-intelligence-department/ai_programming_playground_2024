#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    char* data;
    Node* next;
    Node* prev;
};

Node* CreateNewNode(const char* str)
{   
    // 1. Виділяємо пам'ять
    Node* newNode = new Node;

    // 2. Копіюємо рядок у вузол
    newNode->data = new char[strlen(str) + 1];
    strcpy(newNode->data, str);

    // 3. Ініціалізуємо вказівники
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // 4. Повертаємо адресу нового вузла
    return newNode;
}

void AddNodeToFront(Node*& head, const char* str)
{
    // 1. Створюємо новий вузол
    Node* newNode = CreateNewNode(str);

    // 2. Якщо список не порожній — оновлюємо вказівники
    if(head != nullptr)
    {
        head->prev = newNode;
        newNode->next = head;
    }

    // Змінюємо голову списку
    head = newNode;
}

void DeleteNode(Node*& head, int index)
{
    if (head == nullptr)
    {
        return;
    }

    Node* current = head;
    int currentIndex = 0;

    while (current != nullptr && index > 0)
    {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr)
    {
        return;
    }
    
    if (current->prev != nullptr)
    {
        current->prev->next = current->next;
    }
    else
    {
        head = current->next;
    }
    if(current->next != nullptr)
    {
        current->next->prev = current->prev;
    }

    delete[] current->data;
    delete current;
    
}

void DeleteKNodes(Node*& head, int K, const int* indices)
{
    for (int i = 0; i < K; i++)
    {
        DeleteNode(head, indices[i]-1);
    }   
}

void AddKNodes(Node*& head, int K, const char** data)
{
    for (int i = 0; i < K; i++)
    {
        AddNodeToFront(head, data[i]);
    }
}

int main() 
{
    int K; // Кількість елементів щоб видалити та додати
    int* indices; // Масив індексів елементів щоб видалити
    Node* head = nullptr;

    AddNodeToFront(head, "Hello");
    AddNodeToFront(head, "World");
    AddNodeToFront(head, "How are you?");
    AddNodeToFront(head, "I am fine");
    AddNodeToFront(head, "Thank you");

    cout << "First list: ";
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    cout << "Enter the number of elements to delete and add: ";
    cin >> K;
    indices = new int[K];
    cout << "Enter the indices of elements to delete: ";
    for (int i = 0; i < K; i++)
    {
        cin >> indices[i];
    }

    DeleteKNodes(head, K, indices);

    const char* newData[] = {"Good", "Morning", "My", "Friend"};
    AddKNodes(head, K, newData);

    cout << "Second list: ";
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    delete[] indices;
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete[] temp->data;
        delete temp;
    }
    
    return 0;
}