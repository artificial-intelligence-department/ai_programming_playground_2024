#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* createEmptyList() {
    return nullptr;
}

void addElement(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    if (!head) {
        cout << "Список порожній" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteKElements(Node*& head, int start, int k) {
    if (!head) return;
    Node* temp = head;
    Node* prev = nullptr;
    int index = 1;

    while (temp && index < start) {
        prev = temp;
        temp = temp->next;
        index++;
    }

    for (int i = 0; i < k && temp; ++i) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    if (prev) {
        prev->next = temp;
    } else {
        head = temp;
    }
}

void addBeforeKey(Node*& head, int key, int value) {
    Node* newNode = new Node(value);
    if (!head || head->data == key) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void saveToFile(Node* head, const string& filename) {
    ofstream file(filename);
    Node* temp = head;
    while (temp) {
        file << temp->data << " ";
        temp = temp->next;
    }
    file.close();
}

Node* loadFromFile(const string& filename) {
    ifstream file(filename);
    int value;
    Node* head = nullptr;
    Node* tail = nullptr;

    while (file >> value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    file.close();
    return head;
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* list = createEmptyList();

    addElement(list, 1);
    addElement(list, 2);
    addElement(list, 3);
    addElement(list, 4);
    addElement(list, 5);

    cout << "Список після створення: ";
    printList(list);

    deleteKElements(list, 2, 2);
    cout << "Список після видалення 2 елементів з позиції 2: ";
    printList(list);

    addBeforeKey(list, 4, 10);
    cout << "Список після додавання 10 перед 4: ";
    printList(list);

    saveToFile(list, "list.txt");
    cout << "Список записаний у файл 'list.txt'" << endl;

    deleteList(list);
    cout << "Список після знищення: ";
    printList(list);

    list = loadFromFile("list.txt");
    cout << "Список після відновлення з файлу: ";
    printList(list);

    deleteList(list);
    return 0;
}
