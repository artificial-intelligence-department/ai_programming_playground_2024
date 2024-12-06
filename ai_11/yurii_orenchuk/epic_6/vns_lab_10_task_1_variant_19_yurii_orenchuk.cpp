#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    char* data;
    Node* prev;
    Node* next;
    Node(const char* val) {
        data = new char[strlen(val) + 1];
        strcpy(data, val);
        prev = next = nullptr;
    }
    ~Node() {
        delete[] data;
    }

};

Node* createList() {
    return nullptr;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void addToBeginning(Node*& head, const char* value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}

void deleteByIndex(Node*& head, const vector<int>& indexes) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    vector<int> sortedIndexes = indexes;
    sort(sortedIndexes.rbegin(), sortedIndexes.rend());

    int cnt = 0;
    for (int index : sortedIndexes) {
        Node* curr = head;
        int currIndex = 0;

        while (curr && currIndex < index) {
            curr = curr->next;
            currIndex++;
        }

        if (!curr) {
            cout << "Index " << index << " is out of range.\n";
            continue;
        }

        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;

        if (curr == head) head = curr->next;

        delete curr;
        cnt++;
    }
    cout << "Deleted " << cnt << " elements\n";
}

void writeListToFile(Node* head, const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file\n";
        return;
    }
    Node* current = head;
    while (current) {
        file << current->data << endl;
        cout << "Writing node: " << current->data << endl;
        current = current->next;
    }

    file.close();
    cout << "Successfully wrote List into file\n";
}

void destroyList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Deleted the List\n";
}

Node* recoverList(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file\n";
        return nullptr;
    }

    Node* head = nullptr;
    Node* tail = nullptr;
    char buffer[256];
    while (file.getline(buffer, 256)) {
        Node* newNode = new Node(buffer);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    file.close();
    return head;
}

int main(){
    Node* head = createList();
    char* filename = "storage.txt";

    addToBeginning(head, "Node1");
    addToBeginning(head, "Node2");
    addToBeginning(head, "Node3");
    addToBeginning(head, "Node4");

    printList(head);

    vector<int> indexes = {1, 0};
    deleteByIndex(head, indexes);

    writeListToFile(head, filename);
    destroyList(head);
    head = recoverList(filename);
    printList(head);

    destroyList(head);

    return 0;
}