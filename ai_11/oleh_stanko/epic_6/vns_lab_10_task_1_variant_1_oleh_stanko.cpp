#include <iostream>
#include <cstring>
#include <cstdarg>
#include <fstream>

using namespace std;

struct Node {
    char* data;
    Node* next;
    Node* prev;

    Node(const char* value) : data(strdup(value)), next(nullptr), prev(nullptr) {}
};

void createLL(Node*& head) {
    cout << "Creating the list..." << endl;
    const char* values[] = {"Node 1", "Node 2", "Node 3", "Node 4", "Node 5", "Node 6"};

    for (int i = 0; i < 6; i++) {
        Node* newNode = new Node(values[i]);

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
        } else {
            Node* tmp = head;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
            newNode->prev = tmp;
        }
    }
}

void deleteByData(Node*& head, const char* data) {
    cout << "Deleting element: " << data << " from the list..." << endl;
    if (head == nullptr) return;

    Node* tmp = head;
    while (tmp != nullptr) {
        if (strcmp(tmp->data, data) == 0) {
            Node* toDelete = tmp;
            if (toDelete == head) {
                head = toDelete->next;
                if (head != nullptr) head->prev = nullptr;
            } else {
                if (toDelete->prev != nullptr) {
                    toDelete->prev->next = toDelete->next;
                }
                if (toDelete->next != nullptr) {
                    toDelete->next->prev = toDelete->prev;
                }
            }
            free(toDelete->data);
            delete toDelete;
            return;
        }
        tmp = tmp->next;
    }
}

void printLL(Node* head) {
    cout << "Printing the list..." << endl;
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* tmp = head;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void addKElementsToBegining(Node*& head, int K, ...) {
    cout << "Adding " << K << " elements to the beginning of the list..." << endl;

    va_list args;
    va_start(args, K);

    for (int i = 0; i < K; i++) {
        const char* data = va_arg(args, const char*);
        Node* newNode = new Node(data);
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }
    va_end(args);
}

void writeLLToFile(Node* head, const char* filename) {
    cout << "Writing the list to file: " << filename << "..." << endl;
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Cannot open the file." << endl;
        exit(1);
    }

    Node* tmp = head;
    while (tmp != nullptr) {
        outFile << tmp->data << endl;
        tmp = tmp->next;
    }
}

void deleteLL(Node*& head) {
    cout << "Deleting the list..." << endl;
    while (head != nullptr) {
        Node* nextNode = head->next;
        free(head->data);
        delete head;
        head = nextNode;
    }
}

void fromFileToLL(Node*& head, const char* filename) {
    cout << "Loading the list from file: " << filename << "..." << endl;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Cannot open the file." << endl;
        exit(2);
    }

    string line;
    Node* tmp = nullptr;
    while (getline(inFile, line)) {
        Node* newNode = new Node(line.c_str());
        newNode->next = nullptr;
        newNode->prev = tmp;

        if (head == nullptr) {
            head = newNode;
        } else {
            tmp->next = newNode;
        }
        tmp = newNode;
    }
}

int main() {
    Node* head = nullptr;
    const char* filename = "file.txt";

    createLL(head);
    printLL(head);

    deleteByData(head, "Node 3");
    printLL(head);

    addKElementsToBegining(head, 3, "Node -1", "Node -2", "Node -3");
    printLL(head);

    writeLLToFile(head, filename);
    deleteLL(head);
    printLL(head);

    fromFileToLL(head, filename);
    printLL(head);

    deleteLL(head);
    printLL(head);
}
