#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

Node *createList()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int n;

    cout << "Enter number of elements in list: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "List is empty!" << "\n";
        return nullptr;
    }

    cout << "Enter " << n << " integer numbers:" << "\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

bool compare(Node *first, Node *second)
{
    bool same = true;
    int length1 = 0, length2 = 0;
    while (first != nullptr && second != nullptr)
    { 
        if (first->data != second->data)
        {
            same = false; 
        }
        first = first->next;
        second = second->next;
        if (first != nullptr)
        {
            length1++;
        }
        if (second != nullptr)
        {
            length2++;
        }
    }
    if ( length1 != length2)
    {
        same = false;
    }

    return same;
}

int main()
{
    Node *head1 = createList();

    cout << "First list: ";
    printList(head1);

    head1 = reverse(head1);

    cout << "Reversed list: ";
    printList(head1);

    Node *head2 = createList();

    cout << "Second list: ";
    printList(head2);

    if (compare(head1, head2))
    {
        cout << "Second list is the same as reversed list number one!" << "\n";
    }
    else
    {
        cout << "Second list isn't the same as reversed list number one!" << "\n";
    }

    return 0;
}