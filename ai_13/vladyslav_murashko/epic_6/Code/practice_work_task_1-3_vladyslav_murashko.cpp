#include <iostream>
#include <cmath>

template <class T>
struct Node
{
    T key;
    Node *prev;
    Node *next;

    Node(T k) : key(k), prev(nullptr), next(nullptr) {}
};

template <class T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    DoublyLinkedList(T key)
    {
        Node<T> *newNode = new Node<T>(key);
        head = tail = newNode;
    }

    void insert(T key, int position)
    {
        Node<T> *newNode = new Node<T>(key);
        if (position <= 0)
        {
            std::cerr << "Invalid position.\n";
            delete newNode;
            return;
        }

        if (position == 1)
        {
            newNode->next = head;
            if (head)
                head->prev = newNode;
            head = newNode;
            if (!tail)
                tail = head;
        }
        else
        {
            Node<T> *temp = head;
            int i = 1;
            while (temp && i < position - 1)
            {
                temp = temp->next;
                i++;
            }

            if (!temp)
            {
                std::cerr << "Position out of range.\n";
                delete newNode;
                return;
            }

            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next)
                temp->next->prev = newNode;
            temp->next = newNode;

            if (newNode->next == nullptr)
                tail = newNode;
        }
    }

    void printList() const
    {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node<T> *temp = head;
        while (temp)
        {
            std::cout << temp->key << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void clearList()
    {
        Node<T> *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void push(T key)
    {
        Node<T> *newTail = new Node<T>(key);
        if (tail)
        {
            newTail->prev = tail;
            tail->next = newTail;
            tail = newTail;
        }
        else
            head = tail = newTail;
    }

    DoublyLinkedList<T> copy() const
    {
        DoublyLinkedList<T> newList;
        Node<T> *temp = head;
        while (temp)
        {
            newList.push(temp->key);
            temp = temp->next;
        }
        return newList;
    }

    DoublyLinkedList<T> getReverse()
    {
        DoublyLinkedList<T> copy = this->copy();
        Node<T> *temp = copy.head;
        while (temp)
        {
            std::swap(temp->next, temp->prev);
            temp = temp->prev;
        }
        std::swap(copy.tail, copy.head);
        return copy;
    }

    bool compare(const DoublyLinkedList<T> &list) const
    {
        Node<T> *tmp1 = head;
        Node<T> *tmp2 = list.head;
        while (tmp1 && tmp2)
        {
            if (tmp1->key != tmp2->key)
            {
                return false;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        if (tmp1 || tmp2)
        {
            return false;
        }
        return true;
    }

    DoublyLinkedList<T> add(const DoublyLinkedList<T> &list) const
    {
        DoublyLinkedList<T> result;
        long long sum;
        long long num1 = 0, num2 = 0;
        Node<T> *tmp1 = head;
        Node<T> *tmp2 = list.head;
        int i = 0;
        while (tmp1)
        {
            num1 += tmp1->key * pow(10, i);
            tmp1 = tmp1->next;
            i++;
        }
        int j = 0;
        while (tmp2)
        {
            num2 += tmp2->key * pow(10, j);
            tmp2 = tmp2->next;
            j++;
        }
        i = (i > j) ? i : j;
        sum = num1 + num2;
        if (sum / (long long)pow(10, i) == 1)
        {
            i++;
        }
        for (; i > 0; i--)
        {
            result.insert((sum % (long long)pow(10, i)) / (long long)pow(10, i - 1), 1);
        }
        return result;
    }

    ~DoublyLinkedList()
    {
        clearList();
    }
};

int main()
{

    DoublyLinkedList<int> list(5);
    list.push(6);
    list.push(7);

    std::cout << "list - ";
    list.printList();
    std::cout << "!list - ";
    list.getReverse().printList();

    std::cout << "list == list - " << (list.compare(list) ? "True" : "False") << std::endl;
    std::cout << "list == !list - " << (list.compare(list.getReverse()) ? "True" : "False") << std::endl;

    std::cout << "list + !list - ";
    list.add(list.getReverse()).printList();

    return 0;
}