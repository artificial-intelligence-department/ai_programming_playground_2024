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
    cout << endl;
}

Node *createList()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int n;

    cout << "Введіть кількість елементів у списку: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Список порожній!" << endl;
        return nullptr;
    }

    cout << "Введіть " << n << " цілих чисел:" << endl;
    for (int i = 0; i < n; ++i)
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

bool compare(Node *h1, Node *h2)
{
    bool same = true;
    int length1 = 0, length2 = 0;
    while (h1 != nullptr && h2 != nullptr)
    { 
        if (h1->data != h2->data)
        {
            same = false; 
        }
        h1 = h1->next;
        h2 = h2->next;
        if (h1 != nullptr){
            length1++;
        }
        if (h2 != nullptr){
            length2++;
        }
    }
    if ( length1 != length2){
        same = false;
    }

    return same;
}

int main()
{
    Node *head1 = createList();

    cout << "Початковий список: ";
    printList(head1);

    head1 = reverse(head1);

    cout << "Реверсований список: ";
    printList(head1);

    Node *head2 = createList();

    cout << "Другий список: ";
    printList(head2);

    if (compare(head1, head2))
    {
        cout << "Другий список дорівнює реверсованому першому списку." << endl;
    }
    else
    {
        cout << "Другий список не дорівнює реверсованому першому списку." << endl;
    }

    return 0;
}
