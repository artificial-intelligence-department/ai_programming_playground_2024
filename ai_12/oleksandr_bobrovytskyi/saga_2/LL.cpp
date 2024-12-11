#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value): data(value), next(nullptr) {} 
};

class SinglyLL
{   
    Node *head;

public:
    SinglyLL() : head(nullptr) {}

    void AddToEnd(int data)
    {
        Node *NewNode = new Node(data);
        NewNode->next = nullptr;
        if(head == nullptr)
        {
            head = NewNode;
            head->next = nullptr;
        }
        else
        {   
            Node *tail = head; 
            while(tail->next)
            {
                tail = tail->next;
            }

            tail->next = NewNode;
            NewNode->next = nullptr;
        }
    }

    void AddToStart(int data)
    {
        Node* newNode = new Node(data);
        if(!head)
        {
            head = newNode;
            head->next = nullptr;
        }
        newNode->next = head;
        head = newNode;
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

        while (current && position - 1 > 0)
        {
            current = current->next;
            position--;
        }

        if(!current)
        {
            cout << "Position is out of bounds" << endl;
            return;
        }

        Node *NewNode = new Node(data);
        
        NewNode->next = current->next;
        current->next = NewNode;
    }

    void PrintList()
    {
        if(head == nullptr)
        {
            cout << "List is clear" << endl;
            return;
        }

        Node *current = head;

        while(current)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void BubbleSort()
    {
        if(head == nullptr || head->next == nullptr)
        {
            return;
        }

        bool sorted = false;

        while(!sorted)
        {
            sorted = true;
            Node *current = head;
            Node *previous = nullptr;

            while(current->next)
            {
                if(current->data > current->next->data)
                {
                    Node *temp = current->next;
                    current->next = temp->next;
                    temp->next = current; 

                    if(previous)
                    {
                        previous->next = temp;
                    }
                    else
                    {
                        head = temp;
                    }

                    sorted = false;
                    previous = temp;
                }
                else
                {
                    previous = current;
                    current = current->next;
                }
            }  
        }
    }

    ~SinglyLL()
    {
        Node *temp;
        while(head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    SinglyLL LL;

    LL.AddToEnd(11);
    LL.AddToEnd(33);
    LL.AddToEnd(22);
    LL.AddToEnd(44);

    cout << "Original list: \n";
    LL.PrintList();

    cout << "\nAfter adding 15 at the beginning: \n";
    LL.AddToStart(15);
    LL.PrintList();

    cout << "\nAfter adding 66 at position 2: \n";
    LL.InsertAt(66, 2);
    LL.PrintList();

    cout << "\nAfter sorting: \n";
    LL.BubbleSort();
    LL.PrintList();

    return 0;
}