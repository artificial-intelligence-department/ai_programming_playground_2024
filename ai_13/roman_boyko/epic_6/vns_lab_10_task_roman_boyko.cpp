#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head;
    size_t size;

public:
    List();
    void Clear();
    void AddElem(const T &value);
    void Show() const;
    void RemoveElemByIndex(size_t index);
    void AddElemByIndex(size_t index, const T &value);
    bool WriteToFile(string filename);
    bool ReadFromFile(string filename);
};

template <typename T>
List<T>::List() : head(nullptr), size(0)
{
}

template <typename T>
void List<T>::AddElem(const T &value)
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
void List<T>::Show() const
{
    if (head == nullptr)
    {
        cout << "The list is empty!" << endl;
    }
    Node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

template <typename T>
void List<T>::RemoveElemByIndex(size_t index)
{
    if (index >= size || head == nullptr)
    {
        cout << "Index is incorrect!" << endl;
        return;
    }

    Node *temp = nullptr;
    if (index == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *cur = head;
        for (size_t i = 0; i < index - 1; i++)
        {
            cur = cur->next;
        }
        temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    size--;
}

template <typename T>
void List<T>::AddElemByIndex(size_t index, const T &value)
{
    if (index > size)
    {
        cout << "Incorrect index!" << endl;
        return;
    }
    Node *newElem = new Node{value, nullptr};
    if (index == 0)
    {
        newElem->next = head;
        head = newElem;
    }
    else
    {
        Node *cur = head;
        for (size_t i = 0; i < index - 1; i++)
        {
            cur = cur->next;
        }
        newElem->next = cur->next;
        cur->next = newElem;
    }
    size++;
}

template <typename T>
void List<T>::Clear()
{
    while (head != nullptr)
    {
        Node *cur = head;
        head = head->next;
        delete cur;
    }
    size = 0;
}

template <typename T>
bool List<T>::WriteToFile(string filename)
{
    ofstream fileStream(filename);
    if (!fileStream.is_open())
    {
        cout << "Error in writing to file!" << endl;
        return false;
    }
    Node *cur = head;
    while (cur != nullptr)
    {
        fileStream << cur->data << " ";
        cur = cur->next;
    }
    fileStream.close();
    return true;
}

template <typename T>
bool List<T>::ReadFromFile(string filename)
{
    ifstream fileStream(filename);
    if (!fileStream.is_open())
    {
        cout << "Error in reading from file!" << endl;
        return false;
    }
    Clear();
    size = 0;
    T elem;
    while (fileStream >> elem)
    {
        AddElem(elem);
    }
    fileStream.close();
    return true;
}

int main()
{
    string filename = "testing.txt";

    List<int> list1;
    list1.AddElem(5);
    list1.AddElem(6);
    list1.AddElem(2);
    list1.AddElem(9);
    list1.AddElem(19);
    list1.RemoveElemByIndex(1);
    list1.AddElemByIndex(2, 7);
    list1.Show();
    bool k = list1.WriteToFile(filename);
    list1.Clear();
    bool f = list1.ReadFromFile(filename);
    cout << endl;
    list1.Show();
}