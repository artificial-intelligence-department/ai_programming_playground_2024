#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Node
{
    char *key;
    Node *prev;
    Node *next;
};

void add_el(Node *&head, char *&key)
{
    Node *newNode = new Node{key, nullptr, nullptr};
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
}

Node *create_list()
{
    Node *head = nullptr;
    cout << "Enter 5 key words for list: " << endl;
    for (int i = 0; i < 5; i++)
    {
        char *key = new char[256];
        cin.getline(key, 256);
        add_el(head, key);
    }
    return head;
}

void print_list(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

void delete_el(Node *&head, char *&key)
{
    Node *current = head;
    while (current != nullptr && strcmp(key, current->key) != 0)
    {
        current = current->next;
    }
    if (current == nullptr)
        return; 
    if (current->prev != nullptr)
    {
        current->prev->next = current->next;
    }
    else
    {
        head = current->next;
    }
    if (current->next != nullptr)
    {
        current->next->prev = current->prev;
    }

    delete current;
}

void add_new(Node *&head, char *&target_key, int k)
{
    Node *current = head;
    while (current != nullptr && strcmp(target_key, current->key) != 0)
    {
        current = current->next;
    }
    if (current == nullptr)
        return;

    cout << "Enter " << k << " new key words: " << endl;
    for (int i = 0; i < k; ++i)
    {
        char *newKey = new char[256];
        cin.getline(newKey, 256);
        Node *newNode = new Node{newKey, current, current->next};
        if (current->next != nullptr)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
        current = newNode;
    }
}

void list_to_file(Node *head, const string &name)
{
    ofstream F1(name);
    Node *current = head;
    while (current != nullptr)
    {
        F1 << current->key << endl;
        current = current->next;
    }
}

Node *list_from_file(const string &name)
{
    ifstream F2(name);
    Node *head = nullptr;
    string key;
    while (getline(F2, key))
    {
        char *ckey = new char[key.size() + 1];
        strcpy(ckey, key.c_str());
        add_el(head, ckey);
    }
    return head;
}

void delete_list(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *list = create_list();
    cout << "Initial list:" << endl;
    print_list(list);

    char *del_key = new char[256];
    cout << "Enter key to delete: " << endl;
    cin.getline(del_key, 256);
    delete_el(list, del_key);
    cout << "After deleting element: " << endl;
    print_list(list);

    int k;
    cout << "Enter k: ";
    cin >> k;
    cin.ignore();
    char *add_key = new char[256];
    cout << "Enter key: " << endl;
    cin.getline(add_key, 256);
    add_new(list, add_key, k);
    cout << "After adding k elements after key: " << endl;
    print_list(list);

    list_to_file(list, "list.txt");
    delete_list(list);
    cout << "After destroying the list: " << endl;
    print_list(list);

    list = list_from_file("list.txt");
    cout << "After loading the list from file: " << endl;
    print_list(list);

    delete_list(list);
    return 0;
}