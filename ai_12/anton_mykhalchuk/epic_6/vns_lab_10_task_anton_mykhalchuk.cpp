#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

struct DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void print()
    {
        if (!tail)
            cout << "List is empty" << endl;
        else
        {
            Node *current = head;
            while (current)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void insertToEnd(vector<int> values)
    {
        for (int i = 0; i < values.size(); i++)
        {
            Node *newNode = new Node(values[i]);

            if (tail == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            size++;
        }
    }

    void eraseBefore(int index, int k)
    {
        if (index - k <= 0)
            return;

        Node *left = head;
        for (int i = 0; i < index - k - 1; i++)
        {
            left = left->next;
        }

        Node *toDelete = left->next;
        Node *newLeft = left;

        for (int i = 0; i < k; i++)
        {
            Node *tempNode = toDelete;
            toDelete = toDelete->next;
            delete tempNode;
        }

        newLeft->next = toDelete;
        toDelete->prev = newLeft;
    }

    void writeInFile()
    {
        ofstream file("lab10.txt");
        if (file.is_open())
        {
            Node *current = head;
            while (current)
            {
                file << current->data << " ";
                current = current->next;
            }
            file << endl;
            file.close();
            cout << "List saved to file 'lab10.txt'." << endl;
        }
        else
        {
            cout << "Failed to open file for writing." << endl;
        }
    }

    void deleteList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "List deleted." << endl;
    }

    void updateFromFile()
    {
        vector<int> fromFile;
        ifstream file("lab10.txt");
        if (file.is_open())
        {
            int number;
            while (file >> number)
            {
                fromFile.push_back(number);
            }
            cout << "List updated from file 'lab10.txt'." << endl;
        }
        else
        {
            cout << "Failed to open file for reading." << endl;
        }
        file.close();
        insertToEnd(fromFile);
    }
};

int main()
{
    DoublyLinkedList list;
    int k, indel;
    vector<int> initVec, addVec;

    cout << "Initialized list: " << endl;
    list.print();

    srand(time(0));

    for (int i = 0; i < 10; ++i)
    {
        int randomNumber = rand() % 100 + 1;
        initVec.push_back(randomNumber);
    }

    list.insertToEnd(initVec);

    cout << "Filled the list with random numbers: " << endl;
    list.print();

    cout << "Enter k: ";
    cin >> k;
    cout << "Enter index of element before which you want to delete elements: ";
    cin >> indel;

    list.eraseBefore(indel, k);
    cout << "List after deletion " << k << " elements before " << indel << "th. element:" << endl;
    list.print();

    for (int i = 0; i < k; ++i)
    {
        int randomNumber = rand() % 100 + 1;
        addVec.push_back(randomNumber);
    }

    list.insertToEnd(addVec);
    cout << "List after appending " << k << " elements to the end:" << endl;
    list.print();

    list.writeInFile();

    list.deleteList();
    cout << "Deletion of list: ";
    list.print();

    list.updateFromFile();
    list.print();

    list.deleteList();

    return 0;
}