#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node 
{
public:
    string data;
    Node* next;
    Node* prev;

    Node(string data) 
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList 
{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() 
    {
        head = tail = nullptr;
    }

    void atBeginning(string data) 
    {
        Node* newNode = new Node(data);
        if (head == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void atEnd(string data) 
    {
        Node* newNode = new Node(data);
        if (head == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteNode(Node* node) 
    {
        if (node == nullptr) 
        {
            return;
        }

        if (node == head) 
        {
            head = node->next;
        } 
        else 
        {
            node->prev->next = node->next;
        }

        if (node == tail) 
        {
            tail = node->prev;
        } 
        else 
        {
            node->next->prev = node->prev;
        }

        delete node;
    }

    void deleteNode(string data) 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            if (current->data == data) 
            {
                deleteNode(current);
                return;
            }
            current = current->next;
        }
        cout << "Node not found!" << "\n";
    }

    void printList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    void writeToFile(const string& lab10) 
    {
        ofstream file(lab10);
        Node* current = head;

        while (current != nullptr) 
        {
            file << current->data << "\n";
            current = current->next;
        }
        file.close();
    }

    void readFromFile(const string& lab10) 
    {
        ifstream file(lab10);
        string data;

        while (getline(file, data)) 
        {
            atEnd(data);
        }
        file.close();
    }
};

int main() 
{
    DoublyLinkedList list;

    list.atEnd("A");
    list.atEnd("B");
    list.atBeginning("X");
    list.atEnd("C");

    list.printList();

    list.deleteNode("B");

    list.printList();

    list.writeToFile("lab10.txt");

    Node* current = list.head;
    while (current != nullptr) 
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    list.head = list.tail = nullptr;

    list.readFromFile("lab10.txt");

    list.printList();

    return 0;
}