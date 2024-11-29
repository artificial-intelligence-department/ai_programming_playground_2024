#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void createList()
    {
        head = nullptr;
    }

    void addElements(int startPosition, int k, int value)
    {
        for (int i = 0; i < k; ++i)
        {
            addElement(startPosition + i, value + i);
        }
    }

    void addElement(int position, int value)
    {
        Node *newNode = new Node{value, nullptr};

        if (position <= 0 || !head)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            int index = 0;
            while (temp->next && index < position - 1)
            {
                temp = temp->next;
                index++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteElement(int element)
    {
        int position = element - 1;
        if (!head)
        {
            cout << "Список порожній, видалення неможливе" << endl;
            return;
        }

        if (position <= 0)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
        }
        else
        {
            Node *temp = head;
            int index = 0;
            while (temp->next && index < position - 1)
            {
                temp = temp->next;
                index++;
            }
            if (!temp->next)
            {
                cout << "Некоректна позиція для видалення!" << endl;
                return;
            }
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }

    void printList() const
    {
        if (!head)
        {
            cout << "Список порожній" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void writeToFile(const string &filename) const
    {
        ofstream outFile(filename);
        if (outFile.is_open())
        {
            Node *temp = head;
            while (temp)
            {
                outFile << temp->data << " ";
                temp = temp->next;
            }
            outFile.close();
        }
        else
        {
            cerr << "Не вдалося відкрити файл для запису!" << endl;
            return;
        }
    }

    void restoreFromFile(const string &filename)
    {
        deleteList();
        ifstream inFile(filename);
        if (inFile.is_open())
        {
            int value;
            while (inFile >> value)
            {
                addElement(INT_MAX, value);
            }
            inFile.close();
        }
        else
        {
            cerr << "Не вдалося відкрити файл для читання!" << endl;
            return;
        }
    }

    void deleteList()
    {
        while (head)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }

    ~SinglyLinkedList()
    {
        deleteList();
    }
};

int main()
{
    SinglyLinkedList list;

    list.createList();

    int el;
    cout << "Введіть кількість елементів списку: ";
    cin >> el;

    for (int i = 0; i < el; i++)
    {
        int val;
        cout << "Введіть значення елемента №" << i + 1 << " : ";
        cin >> val;
        list.addElement(i, val);
    }
    list.printList();

    int delpos;
    cout << "Введіть позицію елемента який потрібно видалити: ";
    cin >> delpos;

    list.deleteElement(delpos);
    list.printList();

    int addpos, num, addval;
    cout << "Введіть позицію елемента після якого потрібно додати нові, ";
    cout << "скільки елементів додати та значення першого доданого: ";
    cin >> addpos >> num >> addval;

    list.addElements(addpos, num, addval);
    list.printList();

    list.writeToFile("list.txt");

    list.deleteList();
    list.printList();

    list.restoreFromFile("list.txt");
    list.printList();

    list.deleteList();

    remove("list.txt");

    return 0;
}
