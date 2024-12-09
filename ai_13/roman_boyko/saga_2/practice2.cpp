#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;
    size_t size;

public:
    List();
    void pushBack(const T &value);
    void pushMiddle(int index, const T &value);
    void pushFront(const T &value);

    void Show() const;
    void ShowReverse() const;

    void BubbleSort();
};

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
void List<T>::pushBack(const T &value)
{
    if (size == 0)
    {
        head = new Node{value, nullptr, nullptr};
        tail = head;
    }
    else
    {
        tail->next = new Node{value, nullptr, tail};
        tail = tail->next;
    }
    size++;
}

template <typename T>
void List<T>::pushFront(const T &value)
{
    if (size == 0)
    {
        head = new Node{value, nullptr, nullptr};
        tail = head;
    }
    else
    {
        Node *newNode = new Node{value, head, nullptr};
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void List<T>::pushMiddle(int index, const T &value)
{
    if (index < 0 || index > size)
    {
        cout << "Incorrect index inputed!" << endl;
        return;
    }
    if (index == 0)
    {
        pushFront(value);
    }
    if (index == size)
    {
        pushBack(value);
    }
    Node *cur = head;
    for (int i = 0; i < index - 1; i++)
    {
        cur = cur->next;
    }
    Node *newNode = new Node{value, cur->next, cur};
    cur->next->prev = newNode;
    cur->next = newNode;
    size++;
}

template <typename T>
void List<T>::Show() const
{
    if (size == 0)
    {
        cout << "The list is empty!" << endl;
    }
    else
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
}

template <typename T>
void List<T>::ShowReverse() const
{
    if (size == 0)
    {
        cout << "The list is empty!" << endl;
    }
    else
    {
        Node *cur = tail;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->prev;
        }
    }
}

template <typename T>
void List<T>::BubbleSort()
{
    Node *cur;
    for (int i = 0; i < size - 1; i++)
    {
        cur = head;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (cur->data > cur->next->data)
            {
                swap(cur->data, cur->next->data);
            }
            cur = cur->next;
        }
    }
}

int main()
{
    int index;
    List<int> list1;
    list1.pushBack(5);
    list1.pushBack(6);
    list1.pushBack(7);
    list1.pushBack(8);
    list1.pushBack(9);
    list1.pushBack(10);
    list1.pushFront(1);
    cout << "\nEnter index where you want to add elem: ";
    cin >> index;
    list1.pushMiddle(index, 12);
    cout << endl;
    list1.Show();
    list1.BubbleSort();
    cout << endl;
    list1.Show();
    cout << endl;
    list1.ShowReverse();
    cout << endl;
}