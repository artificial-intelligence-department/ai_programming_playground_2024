#include <iostream>
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
    void insert_at_beginning(int d)
    {
        Node *new_one = new Node;
        new_one->next = head;
        new_one->data = d;
        head = new_one;
    }
    void insert_at_position(int d, int i)
    {
        Node *new_one = new Node;
        new_one->data = d;
        if (head == nullptr)
        {
            head = new_one;
            return;
        }
        Node *current;
        current = head;
        for (int j = 0; j < i - 1; j++)
        {
            current = current->next;
        }
        new_one->next = current->next;
        current->next = new_one;
    }
    void bubble_sort() //  I know I can just switch data, but I wanted to practice switching nodes :)
    {
        if (head == nullptr || head->next == nullptr)
            return;
        Node *temp;
        Node *current;
        bool sorted = false;
        while (!sorted)
        {
            sorted = true;
            current = head;
            while (current->next != nullptr)
            {
                if (current->next->data < current->data)
                {
                    sorted = false;
                    temp = current;
                    current = current->next;
                    temp->next = current->next;
                    current->next = temp;
                    if (current->next = head)
                        head = current;
                }
                current = current->next;
            }
        }
    }
    void print()
    {
        Node *current = head;
        cout << endl;
        if (current == nullptr)
        {
            cout << "List is empty";
            return;
        }
        while (current != nullptr)
        {
            cout << current->data << ' ';
            current = current->next;
        }
    }
};
struct Node2
{
    int data = 0;
    Node2 *next = nullptr;
    Node2 *previous = nullptr;
};
struct DLL
{
    Node2 *head = nullptr;
    Node2 *tail = nullptr;
    void insert(int d)
    {
        Node2 *new_one = new Node2;
        new_one->data = d;
        if (tail == nullptr)
        {
            head = new_one;
            tail = new_one;
        }
        else
        {
            tail->next = new_one;
            new_one->previous = tail;
            tail = new_one;
        }
    }
    void print_backwards()
    {
        Node2 *current = tail;
        cout << endl;
        while (current != nullptr)
        {
            cout << current->data << ' ';
            current = current->previous;
        }
    }
};
int main()
{
    SLL SinglyLinkedList;
    SinglyLinkedList.insert(2);
    SinglyLinkedList.insert(1);
    SinglyLinkedList.insert(3);
    SinglyLinkedList.insert_at_beginning(4);
    SinglyLinkedList.insert_at_position(10, 2);
    SinglyLinkedList.bubble_sort();
    SinglyLinkedList.print();

    DLL DoublyLinkedList;
    DoublyLinkedList.insert(1);
    DoublyLinkedList.insert(10);
    DoublyLinkedList.insert(4);
    DoublyLinkedList.print_backwards();
}