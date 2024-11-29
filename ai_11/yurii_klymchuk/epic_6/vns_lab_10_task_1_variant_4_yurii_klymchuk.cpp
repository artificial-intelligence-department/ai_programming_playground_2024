#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//структура для створення елемента з'язного списку
struct Node {
    int key;
    Node* next;      
};

//структура для додавання нового елемента у список
void AddNewNode(Node*& head, int key, int position) {
    //cтворюємо нову ноду
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = nullptr;

    //якщо позиція 0 ставимо як початок списку
    if (head == nullptr || position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    //записуємо новий елемент у список
    Node* temp = head;
    int currentPosition = 0;
    while (temp->next != nullptr && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }
    newNode->next = temp->next;
    //додавання елемента у випадку коли його позиція поза межами списку
    temp->next = newNode;
}

//видалення елемента списку за позицією
void DeleteNode(Node*& head, int position) {
    //перевірка на наявність елементів
    if (head == nullptr) {
        cout << "The list is empty\n";
        return;
    }
    //якщо позиція 0, зміщуємо початок списку перед видаленням
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    //шукаємо вказівник на необхідну позицію
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "The position you entered is out of range of the list, it`s impossible to delete the element\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

//функція для додавання кількох елементів 
void AddKNodes(Node*& head, int startPosition, int K) {
    for (int i = 0; i < K; i++) {
        int key;
        cout << "Enter the value for the new element" << (i + 1) << ": ";
        cin >> key;
        //викликаємо функцію для додавання для кожного нового елемента
        AddNewNode(head, key, startPosition + i);
    }
}

//вивід списку
void PrintList(Node* head) {
    //перевірка на наявність елементів
    if (head == nullptr) {
        cout << "The list is empty\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->key << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

//запис списку у файл
void WriteToFile(Node* head, const string& filename) {
    ofstream List_file(filename);
    if (!List_file) {
        cerr << "Error while opening the file\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        List_file << temp->key << " ";
        temp = temp->next;
    }
    List_file.close();

    cout << "The list is successfully written to the file\n";
}

//видалення списку
void DeleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "The list is successfully deleted\n";
}

//відновлення списку з файлу
void RestoreFromFile(Node*& head, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error while opening the file\n";
        return;
    }

    int key;
    DeleteList(head);//видаляємо старий список
    while (file >> key) {
        AddNewNode(head, key, 0); //додаємо кожеш елемент з файлу
    }
    file.close();
    cout << "The list is successfully restored from the file\n";
}

int main() {
    Node* list = nullptr; //створюємо пустий список
    int user_choice, key, position, k; //вводимо змінні для користувача

    //реалізація меню
    do {
        cout << "\nWelcome to linked list programme:\n"
        << "1.Add an element to the list\n"
        << "2.Delete an element\n"
        << "3.Print the list\n"
        << "4.Add K element to the list\n"
        << "5.Add the list to the file\n"
        << "6.Delete the list\n"
        << "7.Restore the list from the file\n"
        << "8.Exit\n"
        << "Your choice: ";
        cin >> user_choice;

        switch (user_choice) {
            case 1:
                cout << "Enter the new element: ";
                cin >> key;
                cout << "Enter the position of this element: ";
                cin >> position;
                AddNewNode(list, key, position);
                break;
            case 2:
                cout << "Enter the position of the element to delete: ";
                cin >> position;
                DeleteNode(list, position);
                break;
            case 3:
                PrintList(list);
                break;
            case 4:
                cout << "Enter the position from where we will be adding elements: ";
                cin >> position;
                cout << "Enter the number of elements to add: ";
                cin >> k;
                AddKNodes(list, position, k);
                break;
            case 5:
                WriteToFile(list, "list.txt");
                break;
            case 6:
                DeleteList(list);
                break;
            case 7:
                RestoreFromFile(list, "list.txt");
                break;
            case 8:
                cout << "Exiting the programme\n";
                break;
            default:
                cout << "Incorrect choice, try again\n";
        }
    }while(user_choice != 8);

    DeleteList(list);
    return 0;
}
