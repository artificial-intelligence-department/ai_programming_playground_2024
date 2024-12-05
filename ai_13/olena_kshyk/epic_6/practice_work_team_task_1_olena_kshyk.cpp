#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void append(int value, Node *&head)
{
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
        current = current->next;

    current->next = newNode;
    newNode->prev = current;
}

Node *reverse(Node *head)
{
    Node *current = head;
    Node *tail;
    while (current != nullptr)
    {
        swap(current->next, current->prev);
        tail = current;
        current = current->prev;
    }
    swap(head, tail);
    return head;
}

void printList(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
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

bool compare(Node *h1, Node *h2)
{
    Node *c1 = h1;
    Node *c2 = h2;

    bool result = true;
    while (c1 != nullptr && c2 != nullptr)
    {
        if (c1->data != c2->data)
        {
            result = false;
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }

    if (result && (c1 != nullptr || c2 != nullptr))
        result = false;
    return result;
}

Node *add(Node *n1, Node *n2)
{
    Node *head = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0)
    {
        int val1 = (n1 != nullptr) ? n1->data : 0;
        int val2 = (n2 != nullptr) ? n2->data : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        append(sum % 10, head);

        // Перехід до наступних вузлів
        if (n1 != nullptr)
            n1 = n1->next;
        if (n2 != nullptr)
            n2 = n2->next;
    }

    head = reverse(head);
    return head;
}

int main()
{
    vector<int> v = {1, 6, 3, 7, 5};
    Node *head = nullptr;
    Node *head2 = nullptr;

    for (auto el : v)
    {
        append(el, head);
        append(el, head2);
    }

    cout << "Original list: " << endl;
    printList(head);
    head = reverse(head);
    cout << "Reversed list: " << endl;
    printList(head);

    if (compare(head, head2))
        cout << "Lists are equal" << endl;
    else
        cout << "Lists aren't equal" << endl;

    cout << "The sum of two lists: " << endl;
    Node *sum = add(head, head2);
    printList(sum);

    return 0;
}