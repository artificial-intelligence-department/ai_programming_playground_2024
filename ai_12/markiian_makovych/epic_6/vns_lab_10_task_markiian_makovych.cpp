#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Node
{

    char *data;
    Node *next;
    Node *prev;
};
class List
{
private:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~List()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
    }
    void printList()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
        }
    }

    void pushFront(const char *element)
    {
        char *value = strdup(element);
        if (head == nullptr && tail == nullptr)
        {
            head = new Node{value, nullptr, nullptr};
            tail = head;
        }
        else
        {
            head->prev = new Node{value, head, nullptr};
            head = head->prev;
        }
    }

    void removeElement(const char *value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (!strcmp(current->data, value))
            {
                if (current == head)
                {
                    if (head == tail)
                    {
                        head = nullptr;
                        tail = nullptr;
                        delete head;
                    }
                    else
                    {
                        Node *temp = head;
                        head = head->next;
                        delete temp;
                    }
                }
                else if (current == tail)
                {
                    Node *temp = tail;
                    tail = tail->prev;
                    delete temp;
                }
                else
                {

                    Node *temp = current;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    current = current->next;
                    delete temp;
                }
            }
            current = current->next;
        }
    }
    void addListToFile(const char *fileName)
    {
        ofstream fileIn;

        fileIn.open(fileName);

        Node *current = head;

        while (current != nullptr)
        {
            fileIn << current->data << endl;
            current = current->next;
        }
        fileIn.close();
    }
    void deleteList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
    void printListFromFile(const char *fileName)
    {
        ifstream fileOut;
        fileOut.open(fileName);
        char element[256];
        while (fileOut >> element)
        {

            pushFront(element);
        }
        printList();

        fileOut.close();
    }
};

int main()
{

    char fileName[100] = "test.txt";
    List list;

    list.pushFront("you");
    list.pushFront("are");
    list.pushFront("How");
    list.pushFront("Hello");
    list.printList();
    cout << endl;
    list.removeElement("are");
    list.removeElement("Hello");
    list.printList();
    list.addListToFile(fileName);
    cout << endl;
    list.deleteList();
    list.printList();
    list.printListFromFile(fileName);
    list.deleteList();
    cout << endl;
    list.printList();

    return 0;
}