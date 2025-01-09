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

void printListRecursive(Node* head) {
    if (!head) {
        cout << "nullptr" << endl;
        return;
    }
    cout << head->data << " -> ";
    printListRecursive(head->next);
}

void writeListToFileRecursive(Node* head, ofstream& file) {
    if (!head) return;
    file << head->data;
    if (head->next) file << " ";
    writeListToFileRecursive(head->next, file);
}

void saveListToFileRecursive(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }
    writeListToFileRecursive(head, file);
    file.close();
    cout << "Список рекурсивно записано у файл " << filename << "." << endl;
}

void printListIterative(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void saveListToFileIterative(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        file << temp->data;
        if (temp->next) file << " ";
        temp = temp->next;
    }
    file.close();
    cout << "Список ітеративно записано у файл " << filename << "." << endl;
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

    cout << "Список (рекурсивно):" << endl;
    printListRecursive(singleList);

    cout << "Список (ітеративно):" << endl;
    printListIterative(singleList);

    saveListToFileRecursive(singleList, "list_recursive.txt");
    saveListToFileIterative(singleList, "list_iterative.txt");

    deleteList(singleList);

    return 0;
}
