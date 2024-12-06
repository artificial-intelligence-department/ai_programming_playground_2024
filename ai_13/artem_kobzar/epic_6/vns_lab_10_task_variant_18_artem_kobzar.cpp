#include <iostream>
#include <cstring>
#include <cstdarg>

using namespace std;

struct Node {
    char* key; 
    Node* next; 
    Node* prev; 
};

void createList(Node*& head) {
    cout << "Creating list..." << endl;
    const char* elements[] = {"First", "Second", "Third", "Fourth", "Fifth", "Sixth"};

    for (int i = 0; i < 6; i++) {
        Node* newNode = new Node;
        newNode->key = strdup(elements[i]); 
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr; 
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next; 
            }
            temp->next = newNode;
            newNode->prev = temp; 
        }
    }
}

void deleteByKey(Node*& head, const char* key) {
    cout << "Deleting node with key: " << key << "..." << endl;
    if (head == nullptr) return;

    Node* current = head;
    while (current != nullptr) {
        if (strcmp(current->key, key) == 0) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            free(current->key);
            delete current; 
            return; 
        }
        current = current->next; 
    }
}

void addNodesToStart(Node*& head, int count, ...) {
    cout << "Adding " << count << " nodes to the start..." << endl;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        const char* key = va_arg(args, const char*);
        Node* newNode = new Node;
        newNode->key = strdup(key);
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    va_end(args);
}

void printList(Node* head) {
    cout << "List contents:" << endl;
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

void destroyList(Node*& head) {
    cout << "Destroying the list..." << endl;
    while (head != nullptr) {
        Node* temp = head->next;
        free(head->key);
        delete head;
        head = temp;
    }
}

int main() {
    Node* head = nullptr;
    const char* keyToDelete = "Fourth";

    createList(head);
    printList(head);

    deleteByKey(head, keyToDelete);
    printList(head);

    addNodesToStart(head, 3, "New1", "New2", "New3");
    printList(head);

    destroyList(head);
    printList(head);

    return 0;
}
