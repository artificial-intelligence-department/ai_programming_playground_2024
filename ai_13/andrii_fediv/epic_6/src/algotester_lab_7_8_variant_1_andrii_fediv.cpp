#include <iostream>

using namespace std;

template <class T>
class DCL
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
    };

    Node *first;
    Node *last;

public:
    int size;

    class Inode
    {
    private:
        Node *node;

    public:
        Inode(Node *node) : node(node) {};

        Node *operator*()
        {
            return this->node;
        }

        Inode operator+(int index)
        {
            while (index--)
                this->node = this->node->next;
            return *this;
        }
    };

    DCL() : first(nullptr), last(nullptr), size(0) {}

    Inode begin()
    {
        return Inode(first);
    }

    DCL &operator<<(string separator)
    {
        Node *node = this->first;
        while (node != nullptr)
        {
            cout << node->data << separator;
            node = node->next;
        }
        cout << endl;
        return *this;
    }

    //  position after witch and value
    void insert(int index, T data)
    {
        Node *node = new Node{data, nullptr, nullptr};
        if (this->size == 0)
        {
            this->first = this->last = node;
        }
        else if (index == 0)
        {
            node->next = this->first;
            first->prev = node;
            first = node;
        }
        else if (index == size)
        {
            node->prev = this->last;
            last->next = node;
            last = node;
        }
        else
        {
            Inode pointer = this->begin() + index;
            node->next = *pointer;
            node->prev = (*pointer)->prev;
            (*pointer)->prev->next = node;
            (*pointer)->prev = node;
        }
        ++size;
    }

    void delNodes(Inode pointer, int n)
    {
        for (int i = 0; i < n; i++)
        {
            Node *toDelete = *pointer;
            pointer = pointer + 1;
            if (toDelete->prev)
                toDelete->prev->next = toDelete->next;
            else
                first = toDelete->next;

            if (toDelete->next)
                toDelete->next->prev = toDelete->prev;
            else
                last = toDelete->prev;
            delete toDelete;
            --size;
        }
    }
};

int main()
{
    DCL<int> list;

    int q;
    cin >> q;
    while (q--)
    {
        string line;
        cin >> line;
        if (line == "insert")
        {
            int index, N;
            cin >> index >> N;
            cin.ignore();
            while (N--)
            {
                int n;
                cin >> n;
                list.insert(index, n);
                index++;
            }
        }
        else if (line == "erase")
        {
            int index, N;
            cin >> index >> N;
            list.delNodes(list.begin() + index, N);
        }
        else if (line == "size")
        {
            cout << list.size << endl;
        }
        else if (line == "get")
        {
            int i;
            cin >> i;
            cout << (*(list.begin() + i))->data << endl;
        }
        else if (line == "set")
        {
            int i, value;
            cin >> i >> value;
            (*(list.begin() + i))->data = value;
        }
        else if (line == "print")
        {
            list << " ";
        }
    }
    return 0;
}
