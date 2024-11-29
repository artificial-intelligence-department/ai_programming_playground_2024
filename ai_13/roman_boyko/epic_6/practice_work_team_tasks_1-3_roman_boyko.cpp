#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    size_t size;
    Node *head;
    void Reverse();

public:
    LinkedList();
    void Show() const;
    void AddElem(const T &value);
    void ShowBoth();
    size_t Size();
    bool compare(const LinkedList<T> &list2);
    LinkedList<T> add(const LinkedList<T> &list2);
};

template <typename T>
void LinkedList<T>::Show() const
{
    if (head == nullptr)
    {
        cout << "The list is empty!" << endl;
    }
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0)
{
}

template <typename T>
void LinkedList<T>::AddElem(const T &value)
{
    if (head == nullptr)
    {
        head = new Node{value, nullptr};
    }
    else
    {
        Node *cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = new Node{value, nullptr};
    }
    size++;
}

template <typename T>
void LinkedList<T>::Reverse()
{
    Node *curr = head;
    Node *next = nullptr;
    Node *prev = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

template <typename T>
void LinkedList<T>::ShowBoth()
{
    cout << endl;
    cout << "List before reverse: ";
    Show();
    cout << endl;
    cout << "List after reverse: ";
    Reverse();
    Show();
    Reverse();
}

template <typename T>
size_t LinkedList<T>::Size()
{
    return size;
}

template <typename T>
bool LinkedList<T>::compare(const LinkedList<T> &list2)
{
    if (size != list2.size)
    {
        return false;
    }
    else
    {
        Node *cur = head;
        Node *other = list2.head;
        if (head == nullptr && list2.head == nullptr)
        {
            return true;
        }
        while (cur != nullptr && other != nullptr)
        {
            if (cur->data != other->data)
            {
                return false;
            }
            cur = cur->next;
            other = other->next;
        }
    }
    return true;
}

template <typename T>
LinkedList<T> LinkedList<T>::add(const LinkedList<T> &list2)
{
    Node *cur = head;
    Node *other = list2.head;
    int sum = 0;
    LinkedList<T> res;

    while (cur != nullptr || other != nullptr || sum != 0)
    {
        int k = sum;
        if (cur != nullptr)
        {
            k += cur->data;
            cur = cur->next;
        }
        if (other != nullptr)
        {
            k += other->data;
            other = other->next;
        }

        res.AddElem(sum % 10);
        sum = k / 10;
    }
    return res;
}

int main()
{
    LinkedList<int> list1;
    LinkedList<int> list2;
    list1.Show();
    list1.AddElem(5);
    list1.AddElem(10);
    list1.AddElem(7);
    list1.AddElem(0);
    list1.AddElem(6);
    list1.AddElem(9);
    list2.AddElem(5);
    list2.AddElem(10);
    list2.AddElem(7);
    list2.AddElem(0);
    list2.AddElem(6);
    list2.AddElem(4);
    list2.ShowBoth();
    cout << endl;
    bool comp = list1.compare(list2);
    if (comp)
    {
        cout << "Lists are equal!" << endl;
    }
    else
    {
        cout << "Lists are not equal!" << endl;
    }
    LinkedList<int> adding = list1.add(list2);
    cout << "Sum: ";
    adding.Show();
}