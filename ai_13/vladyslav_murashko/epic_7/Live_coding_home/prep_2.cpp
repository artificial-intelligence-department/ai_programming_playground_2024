#include <iostream>

using namespace std;

struct Human
{
    string name;
    int age;
    Human()
    {
        name = "";
        age = 0;
    }
    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

struct Node
{
    Node *prev;
    Human value;
    Node *next;
    Node(Human value)
    {
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

struct SingleNode
{
    Human value;
    SingleNode *next;
    SingleNode(Human value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    SingleNode *head;

public:
    LinkedList() { head = nullptr; }
    LinkedList(Human value)
    {
        head = new SingleNode(value);
    }

    void addStart(Human value)
    {
        auto tmp = head;
        head = new SingleNode(value);
        head->next = tmp;
    }

    void addEnd(Human value)
    {
        if (head == nullptr)
        {
            head = new SingleNode(value);
            return;
        }
        auto tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new SingleNode(value);
    }

    void insert(Human value, int position)
    {
        if (head == nullptr)
        {
            head = new SingleNode(value);
            return;
        }
        auto tmp = head;
        for (size_t i = 1; i < position - 1; i++)
        {
            if (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            else
            {
                tmp->next = new SingleNode(value);
                return;
            }
        }
        auto tmp2 = tmp->next;
        tmp->next = new SingleNode(value);
        tmp->next->next = tmp2;
    }

    int count()
    {
        if (head == nullptr)
        {
            return 0;
        }
        int count = 1;
        auto tmp = head;
        while (tmp->next != nullptr)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    void printList()
    {
        auto tmp = head;
        while (tmp->next != nullptr)
        {
            cout << "Name: " << tmp->value.name << "\tAge: " << tmp->value.age << endl;
            tmp = tmp->next;
        }
        cout << "Name: " << tmp->value.name << "\tAge: " << tmp->value.age << endl;
    }

    SingleNode *elementAt(int index)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        auto tmp = head;
        for (size_t i = 0; i < index; i++)
        {
            if (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            else
            {
                return nullptr;
            }
        }
        return tmp;
    }

    void sortByAge()
    {
        for (size_t i = 0; i < this->count() - 1; i++)
        {
            for (size_t j = i; j < this->count(); j++)
            {
                if (this->elementAt(i)->value.age > this->elementAt(j)->value.age)
                {
                    swap(this->elementAt(i)->value, this->elementAt(j)->value);
                }
            }
        }
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = head;
    }
    DoublyLinkedList(Human value)
    {
        head = new Node(value);
        tail = head;
    }

    void addStart(Human value)
    {
        auto tmp = head;
        head = new Node(value);
        head->next = tmp;
        if (tmp != nullptr)
        {
            tmp->prev = head;
        }
        else
        {
            tail = head;
        }
    }

    void addEnd(Human value)
    {
        auto tmp = tail;
        tail = new Node(value);
        tail->prev = tmp;
        if (tmp != nullptr)
        {
            tmp->next = tail;
        }
        else
        {
            head = tail;
        }
    }

    void insert(Human value, int position)
    {
        if (position < 2)
        {
            this->addStart(value);
            return;
        }
        if (position > this->count())
        {
            this->addEnd(value);
            return;
        }
        if (head == nullptr)
        {
            head = new Node(value);
            tail = head;
            return;
        }
        if (position <= this->count() / 2)
        {
            auto tmp = head;
            for (size_t i = 1; i < position - 1; i++)
            {
                if (tmp->next != nullptr)
                {
                    tmp = tmp->next;
                }
            }
            auto tmp2 = tmp->next;
            tmp->next = new Node(value);
            tmp->next->prev = tmp;
            tmp->next->next = tmp2;
            tmp2->prev = tmp->next;
            return;
        }
        else
        {
            auto tmp = tail;
            for (size_t i = this->count(); i > position; i--)
            {
                tmp = tmp->prev;
            }
            auto tmp2 = tmp->prev;
            tmp->prev = new Node(value);
            tmp->prev->next = tmp;
            tmp->prev->prev = tmp2;
            tmp2->next = tmp->prev;
            return;
        }
    }

    int count()
    {
        if (head == nullptr)
        {
            return 0;
        }
        int count = 1;
        auto tmp = head;
        while (tmp->next != nullptr)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    void printList()
    {
        auto tmp = head;
        while (tmp->next != nullptr)
        {
            cout << "Name: " << tmp->value.name << "\tAge: " << tmp->value.age << endl;
            tmp = tmp->next;
        }
        cout << "Name: " << tmp->value.name << "\tAge: " << tmp->value.age << endl;
    }

    void printListReverse()
    {
        auto tmp = tail;
        while (tmp->prev != nullptr)
        {
            cout << "Name: " << tmp->value.name << "\tAge: " << tmp->value.age << endl;
            tmp = tmp->prev;
        }
        cout << "Name: " << tmp->value.name << "\tAge: " << tmp->value.age << endl;
    }

    Human *elementAt(int index)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        auto tmp = head;
        for (size_t i = 0; i < index; i++)
        {
            if (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            else
            {
                return nullptr;
            }
        }
        return &tmp->value;
    }

    void sortByAge()
    {
        for (size_t i = 0; i < this->count() - 1; i++)
        {
            for (size_t j = i; j < this->count(); j++)
            {
                if (this->elementAt(i)->age > this->elementAt(j)->age)
                {
                    swap(*this->elementAt(i), *this->elementAt(j));
                }
            }
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.addEnd(Human("Ivan", 20));
    list.addStart(Human("Mark", 10));
    list.addEnd(Human("Oleg", 27));
    list.insert(Human("Anastasya", 35), 2);

    list.printList();

    cout << "-------------\n";

    list.sortByAge();
    list.printListReverse();

    return 0;
}