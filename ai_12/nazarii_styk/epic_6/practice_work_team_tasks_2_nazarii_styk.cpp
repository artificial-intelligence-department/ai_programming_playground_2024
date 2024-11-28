#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int val) 
    {
        data = val;
        next = nullptr;
    }
};

bool compare(Node* h1, Node* h2) 
{
    while (h1 != nullptr && h2 != nullptr) 
    {
        if (h1->data != h2->data) 
        {
            return false;
        }
        h1 = h1->next; 
        h2 = h2->next; 
    }

    return h1 == nullptr && h2 == nullptr;
}

Node* append(Node* head, int value) 
{
    if (head == nullptr) 
    {
        return new Node(value);
    }
    Node* temp = head;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = new Node(value);
    return head;
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{
    Node* list1 = nullptr;
    list1 = append(list1, 1);
    list1 = append(list1, 2);
    list1 = append(list1, 3);

    Node* list2 = nullptr;
    list2 = append(list2, 1);
    list2 = append(list2, 2);
    list2 = append(list2, 3);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    if (compare(list1, list2)) 
    {
        cout << "Lists are the same." << endl;
    } 
    else 
    {
        cout << "Lists are different." << endl;
    }

    return 0;
}
