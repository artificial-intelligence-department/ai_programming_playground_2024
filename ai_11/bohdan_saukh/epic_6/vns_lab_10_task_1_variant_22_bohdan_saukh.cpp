#include <iostream>
#include <cstring>
#include <fstream> 

using namespace std;

struct ListNode {
    char* value;
    ListNode* nextNode;
    ListNode* prevNode;

    ListNode(const char* val) : value(strdup(val)), nextNode(nullptr), prevNode(nullptr) {}
};

class LinkedList {
public:

    void appendToList(ListNode*& head, const char* value) {
        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->nextNode != nullptr) {
                current = current->nextNode;
            }
            current->nextNode = newNode;
            newNode->prevNode = current;
        }
    }

    void deleteNode(ListNode*& head, const char* key) {
        if (head == nullptr) {
            cout << "The list is empty. Nothing to delete." << endl;
            return;
        }

        if (strcmp(head->value, key) == 0) {
            ListNode* temp = head;
            head = head->nextNode;
            if (head != nullptr) {
                head->prevNode = nullptr;
            }
            delete[] temp->value;
            delete temp;
            return;
        }

        ListNode* current = head;
        while (current != nullptr && strcmp(current->value, key) != 0) {
            current = current->nextNode;
        }

        if (current == nullptr) {
            cout << "Value \"" << key << "\" not found in the list." << endl;
            return;
        }

        if (current->nextNode != nullptr) {
            current->nextNode->prevNode = current->prevNode;
        }
        if (current->prevNode != nullptr) {
            current->prevNode->nextNode = current->nextNode;
        }
        delete[] current->value;
        delete current;
    }

    void addBefore(ListNode*& head, const char* key, const char* newValue) {
        ListNode* current = head;
        while (current != nullptr && strcmp(current->value, key) != 0) {
            current = current->nextNode;
        }

        if (current == nullptr) {
            cout << "Value \"" << key << "\" not found in the list." << endl;
            return;
        }

        ListNode* newNode = new ListNode(newValue);
        if (current->prevNode == nullptr) {
            newNode->nextNode = head;
            head->prevNode = newNode;
            head = newNode;
        } else {
            newNode->nextNode = current;
            newNode->prevNode = current->prevNode;
            current->prevNode->nextNode = newNode;
            current->prevNode = newNode;
        }
    }

    void printList(ListNode* head) const {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }

        while (head != nullptr) {
            cout << head->value << " ";
            head = head->nextNode;
        }
        cout << endl;
    }
    
    void writeToFile(ListNode* head, const char* filename) const {
        ofstream file(filename);
        
        if (!file) {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        ListNode* current = head;
        while (current != nullptr) {
            file << current->value << endl;
            current = current->nextNode;
        }

        file.close();
        cout << "List successfully written to " << filename << endl;
    }
    
    void deleteList(ListNode*& head) {
        ListNode* current = head;
        ListNode* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->nextNode;
            delete[] current->value;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        cout << "List successfully deleted!" << endl;
    }
    
    void restoreFromFile(ListNode*& head, const char* filename) {
        ifstream file(filename);
        
        if (!file) {
            cout << "Error opening file for reading!" << endl;
            return;
        }

        char line[1000];
        while (file.getline(line, sizeof(line))) {
            appendToList(head, line);
        }

        file.close();
        cout << "List successfully restored from " << filename << endl;
    }
};

int main() {
    LinkedList list;
    ListNode* head = nullptr;

    list.appendToList(head, "One");
    list.appendToList(head, "Two");
    list.appendToList(head, "Three");

    cout << "Original list: ";
    list.printList(head);

    list.deleteNode(head, "Two");
    cout << "After deleting 'Two': ";
    list.printList(head);

    list.addBefore(head, "Three", "New");
    cout << "After adding 'New' before 'Tree': ";
    list.printList(head);
    
    list.writeToFile(head, "output.txt");
    
    list.deleteList(head);
    list.printList(head);
    
    list.restoreFromFile(head, "output.txt");
    list.printList(head);
    
    list.deleteList(head);
    
    return 0;
}