
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string key;
    Node *next;
    Node *prev;

    Node(const string &k) : key(k), next(nullptr), prev(nullptr)
    {
    }
};

class DoublyLinkedList
{
  private:
    Node *head;
    Node *tail;

  public:
    DoublyLinkedList() : head(nullptr), tail(nullptr)
    {
    }

    void createList(const string &key)
    {
        clear();
        addElementAfter(head, key);
    }

    void addElementsAround(const string &key, const string &value, int k)
    {
        Node *target = find(key);
        if (!target)
        {
            cout << "Елемент з ключем \"" << key << "\" не знайдено." << endl;
            return;
        }

        for (int i = 0; i < k; ++i)
        {
            addElementBefore(target, value + "_before" + to_string(i + 1));
        }

        for (int i = 0; i < k; ++i)
        {
            addElementAfter(target, value + "_after" + to_string(i + 1));
        }
    }

    void deleteByPosition(int position)
    {
        if (position < 1)
        {
            cout << "Номер має бути більше нуля." << endl;
            return;
        }

        Node *current = head;
        int index = 1;

        while (current && index < position)
        {
            current = current->next;
            index++;
        }

        if (!current)
        {
            cout << "Елемент з номером " << position << " не знайдено." << endl;
            return;
        }

        deleteNode(current);
    }

    void printList() const
    {
        Node *current = head;
        while (current)
        {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    void saveToFile(const string &filename) const
    {
        ofstream outFile(filename);
        if (!outFile)
        {
            cout << "Не вдалося відкрити файл для запису." << endl;
            return;
        }

        Node *current = head;
        while (current)
        {
            outFile << current->key << endl;
            current = current->next;
        }

        outFile.close();
        cout << "Список збережено у файл \"" << filename << "\"" << endl;
    }

    void loadFromFile(const string &filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cout << "Не вдалося відкрити файл для читання." << endl;
            return;
        }

        clear();
        string key;
        while (getline(inFile, key))
        {
            addElementAfter(tail, key);
        }

        inFile.close();
        cout << "Список відновлено з файлу \"" << filename << "\"" << endl;
    }

    void clear()
    {
        while (head)
        {
            deleteNode(head);
        }
    }

    ~DoublyLinkedList()
    {
        clear();
    }

  private:
    Node *find(const string &key) const
    {
        Node *current = head;
        while (current)
        {
            if (current->key == key)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void addElementBefore(Node *node, const string &key)
    {
        Node *newNode = new Node(key);
        newNode->next = node;

        if (node)
        {
            newNode->prev = node->prev;
            if (node->prev)
            {
                node->prev->next = newNode;
            }
            node->prev = newNode;
            if (node == head)
            {
                head = newNode;
            }
        }
        else
        {
            head = tail = newNode;
        }
    }

    void addElementAfter(Node *node, const string &key)
    {
        Node *newNode = new Node(key);
        newNode->prev = node;

        if (node)
        {
            newNode->next = node->next;
            if (node->next)
            {
                node->next->prev = newNode;
            }
            node->next = newNode;
            if (node == tail)
            {
                tail = newNode;
            }
        }
        else
        {
            head = tail = newNode;
        }
    }

    void deleteNode(Node *node)
    {
        if (!node)
            return;

        if (node->prev)
        {
            node->prev->next = node->next;
        }
        else
        {
            head = node->next;
        }

        if (node->next)
        {
            node->next->prev = node->prev;
        }
        else
        {
            tail = node->prev;
        }

        delete node;
    }
};

int main()
{
    DoublyLinkedList list;
    list.createList("start");

    list.addElementsAround("start", "new", 2);
    list.printList();

    list.deleteByPosition(2);
    list.printList();

    list.saveToFile("list.txt");
    list.clear();

    list.loadFromFile("list.txt");
    list.printList();

    return 0;
}
