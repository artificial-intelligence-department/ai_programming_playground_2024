#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int value): data(value), next(nullptr), prev(nullptr) {} 
};

class DoublyLL
{   
    Node *head;
    Node *tail;

public:

    DoublyLL() : head(nullptr), tail(nullptr) {}

    void AddToEnd(int data)
    {   
        Node *NewNode = new Node(data);
        if(head == nullptr)
        {
            head = tail = NewNode;
            return;
        }

        tail->next = NewNode;
        NewNode->prev = tail;
        tail = NewNode; 
    }

    void AddToStart(int data)
    {
        Node *NewNode = new Node(data); 
        if(head == nullptr)
        {
            head = tail = NewNode;
            return;
        }

        NewNode->next = head;
        head->prev = NewNode;
        head = NewNode;
    }

    void InsertAt(int data, int position)
    {
        if(position < 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if(position == 0)
        {
            AddToStart(data);
            return;
        }

        Node *current = head;

        for(int i = 0; current && i < position - 1; i++)
        {
            current = current->next;
        }

        if(!current)
        {
            cout << "Position is out of bounds" << endl; 
        }

        Node *NewNode = new Node(data);
        NewNode->prev = current;
        NewNode->next = current->next;
        if(current->next)
        {
            current->next->prev = NewNode;
        }
        else
        {
            tail = NewNode;
        }
        current->next = NewNode;
    }

    void LeftPrintDLL()
    {
        Node *current = head; 
        while(current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void RightPrintDLL()
    {
        Node *current = head;

        while(current->next)
        {
            current = current->next;
        }

        while(current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void BubbleSort()
    {
        if(!head || !head->next)
        {   
            cout << "List is to short" << endl;
            return;
        }

        bool sorted = false;

        while(!sorted)
        {
            sorted = true;

            Node *current = head;

            while(current->next)
            {
                if(current->data > current->next->data)
                {
                    Node *temp = current->next;

                    if(temp->next)
                    {
                        temp->next->prev = current;
                        current->next = temp->next;
                    }
                    else
                    {   
                        tail = current;
                        current->next = nullptr;
                    }

                    if(current->prev)
                    {
                        current->prev->next = temp;
                    }
                    else
                    {
                        head = temp;
                    }

                    temp->prev = current->prev;
                    current->prev = temp;
                    temp->next = current;

                    sorted = false;
                }
                else
                {
                    current = current->next;
                }
            } 
        }
    }
};

int main()
{   
    DoublyLL DLL;

    DLL.AddToEnd(10);
    DLL.AddToEnd(30);
    DLL.AddToEnd(20);
    DLL.AddToEnd(40);

    cout << "Original list: \n";
    DLL.LeftPrintDLL();

    cout << "\nAfter adding 99 at the beginning: \n";
    DLL.AddToStart(99);
    DLL.LeftPrintDLL();

    cout << "\nAfter adding 25 at position 3: \n";
    DLL.InsertAt(25, 3);
    DLL.LeftPrintDLL();

    cout << "\nAfter sorting: \n";
    DLL.BubbleSort();
    DLL.LeftPrintDLL();

    cout << "\nList form rght to left: \n";
    DLL.RightPrintDLL();

    return 0;
}