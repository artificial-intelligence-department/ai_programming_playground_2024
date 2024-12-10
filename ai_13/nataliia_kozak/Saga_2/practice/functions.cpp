#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
    int data = 0;
    Node *next = nullptr;
};
struct SLL
{
    Node *head = nullptr;
    void insert(int d)
    {
        Node *new_one = new Node;
        if (head == nullptr)
        {
            head = new_one;
            head->data = d;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        };
        current->next = new_one;
        new_one->data = d;
    }
    void recursive_print(Node *current, fstream& file)
    {
        file << current->data << ',';
        if (current->next != nullptr)
            recursive_print(current->next, file);
    }
    void recursive_print(Node *current)
    {
        cout << current->data << ' ';
        if(current->next != nullptr) recursive_print(current->next);
    }
    void loop_print(fstream& file)
    {
        file.seekp(0);
        Node* current;
        current = head;
        while(current != nullptr)
        {
            file << current->data << ',';
            current = current->next;
        }
    }
};
int main()
{
    SLL SinglyLinkedList;
    SinglyLinkedList.insert(2);
    SinglyLinkedList.insert(1);
    SinglyLinkedList.insert(3);
    fstream aFile("aFile.txt", ios::out | ios::trunc);
    SinglyLinkedList.recursive_print(SinglyLinkedList.head, aFile);
    
    SinglyLinkedList.recursive_print(SinglyLinkedList.head);
    SinglyLinkedList.loop_print(aFile);
    aFile.close();
}