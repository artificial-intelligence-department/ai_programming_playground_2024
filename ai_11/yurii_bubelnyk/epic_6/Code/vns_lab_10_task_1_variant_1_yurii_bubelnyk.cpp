#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void addNode(Node*& head, int value, int position) {
    Node* newNode = new Node(value);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for(int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of range.\n";
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;

}

void deleteNode(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current->next != nullptr; i++) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void destroyList(Node*& head){
    while (head != nullptr) {
        Node* temp = head->next;
        head = head->next;
        cout << "List destroyed.\n";
    }
}
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void saveToFile(Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == nullptr) {
        perror("Error opening file for writing");
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        fprintf(file, "%d ", current->data);
        current = current->next;
    }

    fclose(file);
    cout << "List saved to " << filename << endl;
}


void restoreFromFile(Node*& head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        perror("Error opening file for reading");
        return;
    }

    destroyList(head); 

    int value;
    Node* tail = nullptr;

    while (fscanf(file, "%d", &value) == 1) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    fclose(file);
    cout << "List restored from " << filename << endl;
}

int main() {
    const char* filename = "list.txt";

    Node* head = nullptr;

    int value, choice;
    int index = 0;
    int count = 0;
    do{
        cout << "Choose option:\n\t1)Add element;\n\t2)Delete element;\n\t3)Show elements;\n\t4)Destroy list;\n\t5)Restor list;\n\t6)Exit.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value of element to be added to the list:\n";
            cin >> value;
            cout << "Enter index of the element:\n";
            cin >> index;
            addNode(head, value, index);
            saveToFile(head, filename);
            count++;
            break;
        case 2:
            cout << "Enter index of element to be deleted:\n";
            cin >> index;
            deleteNode(head, index);
            break;
        case 3:
            cout << "Initial list: ";
            displayList(head);
            break;
        case 4:
            destroyList(head);
            break;
        case 5:
            restoreFromFile(head, filename);
            break;
        case 6:
            return 1;
        default:
            break;
        }
    }while(choice != 6);
   
    
    return 0;
}
