#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void append(Node*& head, int value) {
    Node* newNode = createNode(value);
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
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void writeListToFilePlain(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        file << temp->data << " ";
        temp = temp->next;
    }
    file.close();
    cout << "Список записано у файл " << filename << " у текстовому форматі." << endl;
}

void writeListToFileCSV(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        file << temp->data;
        if (temp->next) file << ",";
        temp = temp->next;
    }
    file.close();
    cout << "Список записано у файл " << filename << " у форматі CSV." << endl;
}

void readListFromFilePlain(Node*& head, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }
    int value;
    while (file >> value) {
        append(head, value);
    }
    file.close();
    cout << "Список зчитано з файлу " << filename << " у текстовому форматі." << endl;
}

void readListFromFileCSV(Node*& head, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }
    string line;
    while (getline(file, line, ',')) {
        append(head, stoi(line));
    }
    file.close();
    cout << "Список зчитано з файлу " << filename << " у форматі CSV." << endl;
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* singleList = nullptr;

    append(singleList, 10);
    append(singleList, 20);
    append(singleList, 30);

    cout << "Початковий список:" << endl;
    printList(singleList);

    writeListToFilePlain(singleList, "list_plain.txt");
    writeListToFileCSV(singleList, "list.csv");

    deleteList(singleList);

    readListFromFilePlain(singleList, "list_plain.txt");
    cout << "Список після зчитування з plain text:" << endl;
    printList(singleList);

    deleteList(singleList);

    readListFromFileCSV(singleList, "list.csv");
    cout << "Список після зчитування з CSV:" << endl;
    printList(singleList);

    deleteList(singleList);

    return 0;
}
