#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void append(Node *&head, int value)
{
    if (head == nullptr)
    {
        head = new Node({value, nullptr, nullptr});
        return;
    }
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    Node *newNode = new Node({value, current, nullptr});
    current->next = newNode;
}

//output using recursion 
void output(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    cout << head->data << " ";
    output(head->next);
}

//output using loop 
void output(Node *head, bool t)
{
    if (head == nullptr)
    {
        return;
    }
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//writing in file using recursion
void write_in_file(Node *head, ofstream &file)
{
    if (head == nullptr)
    {
        return;
    }
    file << head->data << " ";
    write_in_file(head->next, file);
}

//writing in file using loop
void write_in_file(Node *head)
{
    ofstream file("file2.txt", ios::out);
    if (head == nullptr)
    {
        return;
    }
    Node *current = head;
    while (current != nullptr)
    {
        file << current->data << " ";
        current = current->next;
    }
    file.close();
}

int main()
{
    Node *head = nullptr;
    for (int i = 0; i < 7; i++)
    {
        append(head, i);
    }
    output(head, true);
    output(head);
    ofstream file("file1.txt", ios::out);
    write_in_file(head, file);
    write_in_file(head);
    file.close();
    return 0;
}