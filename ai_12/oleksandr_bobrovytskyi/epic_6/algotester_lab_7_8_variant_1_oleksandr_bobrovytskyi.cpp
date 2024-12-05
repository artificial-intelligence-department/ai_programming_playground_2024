#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insert(vector<int> &data, int position)
    {
        Node *current = head;
        Node *previous = nullptr;
        int index = 0;

        for (int i = 0; i < position && current; i++)
        {
            previous = current;
            current = current->next;
        }

        for (int i = 0; i < data.size(); i++)
        {
            Node *NewNode = new Node(data[i]);

            if (!previous)
            {
                NewNode->next = head;
                if (head)
                {
                    head->prev = NewNode;
                }
                head = NewNode;
                previous = head;
            }
            else
            {
                NewNode->next = current;
                NewNode->prev = previous;
                previous->next = NewNode;
                if (current != nullptr)
                {
                    current->prev = NewNode;
                }

                previous = NewNode;
            }
            size++;            
        }

        if (current == nullptr)
        {
            tail = previous;
        }
    }

    void erase(int index, int num)
    {
        Node *current = head;
        for (int i = 0; i < index && current != nullptr; i++)
        {
            current = current->next;
        }

        for (int i = 0; i < num && current != nullptr; i++)
        {
            Node *Next = current->next;

            if (current->prev != nullptr)
            {
                current->prev->next = Next;
            }
            else
            {
                head = Next;
            }

            if (Next != nullptr)
            {
                Next->prev = current->prev;
            }
            else
            {
                tail = current->prev;
            }

            delete current;
            current = Next;
            size--;
        }
    }

    int getSize()
    {
        return size;
    }

    int get(int index)
    {
        Node *current = head;
        for (int i = 0; i < index && current != nullptr; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    void set(int index, int NewValue)
    {
        Node *current = head;
        for (int i = 0; i < index && current != nullptr; i++)
        {
            current = current->next;
        }

        current->data = NewValue;
    }

    friend ostream &operator<<(ostream &os, const DoublyLinkedList &list)
    {
        Node *current = list.head;
        while (current != nullptr)
        {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }

    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    int num, index, value;
    int numOfActions;
    string command;

    cin >> numOfActions;

    for (int i = 0; i < numOfActions; i++)
    {
        cin >> command;

        if (command == "insert")
        {
            cin >> index;
            cin >> num;
            vector<int> values(num);
            for (int i = 0; i < num; i++)
            {
                cin >> values[i];
            }
            list.insert(values, index);
        }
        else if (command == "erase")
        {
            cin >> index >> num;
            list.erase(index, num);
        }
        else if (command == "size")
        {
            cout << list.getSize() << endl;
        }
        else if (command == "get")
        {
            cin >> index;
            cout << list.get(index) << endl;
        }
        else if (command == "set")
        {
            cin >> index >> value;
            list.set(index, value);
        }
        else if (command == "print")
        {
            cout << list;
        }
    }

    return 0;
}