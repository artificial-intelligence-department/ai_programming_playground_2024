#include <iostream>
#include <fstream>

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

    void addElement(T key, int position)
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

    void deleteLastKElements(int k)
    {
        while (k-- > 0 && tail)
        {
            Node<T> *temp = tail;
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
            else
                head = nullptr;
            delete temp;
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

    void saveToFile(const std::string &filename) const
    {
        std::ofstream file(filename);
        if (!file)
        {
            std::cerr << "Unable to open file.\n";
            return;
        }
        Node<T> *temp = head;
        while (temp)
        {
            file << temp->key << " ";
            temp = temp->next;
        }
        file.close();
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

    void restoreFromFile(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file)
        {
            std::cerr << "Unable to open file.\n";
            return;
        }

        clearList();

        T key;
        int i = 1;
        while (file >> key)
        {
            addElement(key, i++);
        }
        file.close();
    }

    ~DoublyLinkedList()
    {
        clearList();
    }
};

int main()
{
    DoublyLinkedList<int> list(5);
    list.printList();
    list.addElement(10, 1);
    list.printList();
    list.addElement(15, 2);
    list.addElement(16, 2);
    list.addElement(17, 2);
    list.addElement(18, 2);
    list.printList();
    list.deleteLastKElements(3);
    list.printList();

    list.saveToFile("list.txt");
    list.clearList();
    list.printList();

    list.restoreFromFile("list.txt");
    list.printList();

    list.clearList();

    return 0;
}