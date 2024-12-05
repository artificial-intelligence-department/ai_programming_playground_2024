#include <iostream>
#include <vector>
using namespace std;

template <class T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T value;
        Node *prev;
        Node *next;
        Node(T val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    size_t list_size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

    void insert(int index, const vector<T> &elements)
    {
        Node *current = head;

        for (int i = 0; i < index && current != nullptr; i++)
            current = current->next;

        Node *prevNode = (current != nullptr) ? current->prev : tail;
        Node *nextNode = current;

        for (auto val : elements)
        {
            Node *newNode = new Node(val);

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

        list_size += elements.size();
    }

    void erase(int index, int n)
    {
        Node *current = head;
        for (int i = 0; i < index && current != nullptr; i++)
            current = current->next;

        for (int i = 0; i < n && current != nullptr; i++)
        {
            Node *toDelete = current;
            if (current->prev)
                current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            if (toDelete == head)
                head = current->next;
            if (toDelete == tail)
                tail = current->prev;
            current = current->next;
            delete toDelete;
            list_size--;
        }
    }

    size_t size() const
    {
        return list_size;
    }

    T get(int index) const
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current->value;
    }

    void set(int index, T value)
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        current->value = value;
    }

    friend ostream &operator<<(ostream &os, const DoublyLinkedList &list)
    {
        Node *current = list.head;
        while (current != nullptr)
        {
            os << current->value << " ";
            current = current->next;
        }

        return os;
    }

    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
};

int main()
{
    DoublyLinkedList<int> dll;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;

        if (s == "insert")
        {
            int index, n;
            cin >> index >> n;
            vector<int> elements(n);
            for (int i = 0; i < n; i++)
                cin >> elements[i];
            dll.insert(index, elements);
        }
        else if (s == "erase")
        {
            int index, n;
            cin >> index >> n;
            dll.erase(index, n);
        }
        else if (s == "size")
        {
            cout << dll.size() << endl;
        }
        else if (s == "get")
        {
            int index;
            cin >> index;
            cout << dll.get(index) << endl;
        }
        else if (s == "set")
        {
            int index, value;
            cin >> index >> value;
            dll.set(index, value);
        }
        else if (s == "print")
        {
            cout << dll << endl;
        }
    }

    return 0;
}
