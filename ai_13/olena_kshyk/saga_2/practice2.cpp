#include <iostream>
#include <vector>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node *head;

public:
    LinkedList() : head(nullptr) {}
    void append(int value)
    {
        Node *NewNode = new Node(value);
        if (head == nullptr)
        {
            head = NewNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = NewNode;
    }

    void insert(int value, int index)
    {
        Node *NewNode = new Node(value);
        if (head == nullptr)
        {
            head = NewNode;
            return;
        }

        Node *current = head;
        for (int i = 0; i < index && current != nullptr; i++)
        {
            current = current->next;
        }
        current->next = current;
        current = NewNode;
    }

    void prepend(int value)
    {
        Node *NewNode = new Node(value);
        NewNode->next = head;
        head = NewNode;
    }

    void output()
    {
        Node *current = head;
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void bubble_sort()
    {
        if (head == nullptr)
        {
            return;
        }
        bool swapped;
        Node *current;
        Node *end = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != end)
            {
                if (current->data > current->next->data)
                {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
            end = current;
        } while (swapped);
    }
};

class DoublyLinkedList
{
private:
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void append(int value)
    {
        Node *NewNode = new Node(value);
        if (head == nullptr)
        {
            head = NewNode;
            tail = head;
            return;
        }
        tail->next = NewNode;
        NewNode->prev = tail;
        tail = NewNode;
    }

    void insert(int value, int index)
    {
        Node *current = head;

        for (int i = 0; i < index && current != nullptr; i++)
            current = current->next;

        Node *prevNode = (current != nullptr) ? current->prev : tail;
        Node *nextNode = current;

        Node *newNode = new Node(value);

        newNode->prev = prevNode;
        newNode->next = nextNode;

        if (prevNode)
            prevNode->next = newNode;
        else
            head = newNode;

        if (nextNode)
            nextNode->prev = newNode;
        else
            tail = newNode;

        prevNode = newNode;
    }

    void prepend(int value)
    {
        Node *NewNode = new Node(value);
        if (head == nullptr)
        {
            head = NewNode;
            tail = head;
            return;
        }

        NewNode->next = head;
        head->prev = NewNode;
        head = NewNode;
    }

    void output()
    {
        Node *current = head;
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void bubble_sort()
    {
        if (head == nullptr)
        {
            return;
        }
        bool swapped;
        Node *current;
        Node *end = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != end)
            {
                if (current->data > current->next->data)
                {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
            end = current;
        } while (swapped);
    }

    void reversed_output()
    {
        Node *current = tail;
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

main()
{
    LinkedList ll;
    DoublyLinkedList dll;
    for (int i = 0; i < 7; i++)
    {
        int value = rand() % 100;
        ll.append(value);
        dll.append(value);
    }
    cout << "original l-list" << endl;
    ll.output();
    ll.bubble_sort();
    cout << "sorted l-list" << endl;
    ll.output();

    cout << "original dl-list" << endl;
    dll.output();
    dll.bubble_sort();
    cout << "sorted dl-list" << endl;
    dll.output();

    cout << "from right to left" << endl;
    dll.reversed_output();
    return 0;
}