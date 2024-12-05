#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string data;
    Node *next;
    Node *prev;

    Node(string d) : data(d), next(nullptr), prev(nullptr) {}
};

Node *createList()
{
    return nullptr;
}

void addElement(Node *&head, string data, int position)
{
    Node *NewNode = new Node(data);
    if (head == nullptr)
    {
        head = NewNode;
        return;
    }

    if (position == 0)
    {
        NewNode->next = head;
        head->prev = NewNode;
        head = NewNode;
        return;
    }

    Node *temp = head;
    int index = 0;

    while (temp->next && index < position - 1)
    {
        temp = temp->next;
        index++;
    }

    NewNode->next = temp->next;
    NewNode->prev = temp;
    if (temp->next)
    {
        temp->next->prev = NewNode;
    }
    temp->next = NewNode;
}

void printList(Node *head)
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteElement(Node *&head, string key)
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }

    Node *temp = head;

    while (temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "No elment is found for key: " << key << endl;
        return;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;
    if (temp == head)
        head = temp->next;

    delete temp;

}

void writeToFile(Node *head, string filename)
{
    ofstream file;
    file.open(filename);

    if (!file.is_open())
    {
        cout << "Error: unable to open the file" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        file << temp->data << endl;
        temp = temp->next;
    }

    file.close();
}

void deleteList(Node *&head)
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        Node *NextNode = temp->next;
        delete temp;
        temp = NextNode;
    }
    cout << "List is deleted" << endl;
    head = nullptr;
}

Node *restoreFromFile(string Filename)
{   
    string key;

    ifstream file;
    file.open(Filename);

    if (!file.is_open())
    {
        cout << "Error: unable to open the file" << endl;
        return nullptr;
    }

    Node *head = nullptr;
    Node *current = nullptr;

    while(getline(file, key))
    {
        Node* newNode = new Node(key);
        if(head == nullptr)
        {
            head = current = newNode;
        }
        else
        {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
    }

    cout << "list is restored " << endl;

    file.close(); 

    return head;
}

int main()
{
    Node *head = createList();
    string key, filename;
    int pos;

    filename = "C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/epic_6/list.txt";

    addElement(head, "a", 0);
    addElement(head, "b", 1);
    addElement(head, "c", 2);
    addElement(head, "d", 3);
    cout << "Original list: " << endl;
    printList(head);

    cout << "Enter a key to delete elements containing it: ";
    cin >> key;

    deleteElement(head, key);

    cout << "List after deletion of elments containing key: " << endl;
    printList(head);

    cout << "Enter the position for inserting new element: ";
    cin >> pos;

    addElement(head, "e", pos);

    cout << "List after adding new element: " << endl;
    printList(head);

    writeToFile(head, filename);

    deleteList(head);
    printList(head);

    head = restoreFromFile(filename);
    printList(head);

    deleteList(head);

    return 0;
}