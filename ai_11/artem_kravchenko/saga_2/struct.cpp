#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* create_node(int value){
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    return new_node;
}

void delete_list(Node* head){
    while (head != nullptr)
    {
        Node* current = head;
        head = head->next;
        delete current;
    }
    
}

void new_el_in_back(Node*& head, int value){
    Node* new_node = create_node(value);
    if (head == nullptr)
    {
        head = new_node;
        return;
    }
    Node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new_node;
}

void new_el_in_start(Node*& head, int value){
    Node* new_node = create_node(value);
    new_node->next = head;
    head = new_node;
}
void print(Node* head){
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void new_el_in_middle(Node*& head, int value, int pos){
    if (pos == 0)
    {
        new_el_in_start(head, value);
        return;
    }
    
    Node* current = head;
    int count = 0;
    while (current != nullptr && count < pos - 1)
    {
        current = current->next;
        count++;
    }
    if (current == nullptr)
    {
        cerr << "позиція за межами списку" << endl;
        return;
    }
    Node* new_node = create_node(value);
    new_node->next = current->next;
    current->next = new_node;
    
}

void sort_buble(Node* head){
    bool truha;
    do
    {
        truha = false;
        Node* current = head;
        while (current->next)
        {
            if (current->data > current->next->data)
            {
                swap(current->data, current->next->data);
                truha = true;
            }
            current = current->next;
        }
        
    } while (truha);
    
}

struct Dnode
{
    int data;
    Dnode* next;
    Dnode* prev;
};

Dnode* create_Dnode(int value){
    Dnode* new_node = new Dnode();
    new_node->data = value;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    return new_node; 
}

void new_in_back(Dnode*& head, int value){
    Dnode* new_node = create_Dnode(value);
    if (head == nullptr)
    {
        head = new_node;
        return;
    }
    Dnode* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev;
}

void new_in_start(Dnode*& head, int value){
    Dnode* new_node = create_Dnode(value);
    new_node->next = head;
    if (head != nullptr)
    {
        head->prev = new_node;
    }
    
    head = new_node;
}

void print_dnode(Dnode* head){
    Dnode* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void sort_dnode_buble(Dnode* head){
    bool truha;
    do
    {
        truha = false;
        Dnode* current = head;
        Dnode* last = nullptr;
        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                swap(current->data, current->next->data);
                truha = true;
            }
            current = current->next;
        }
        last = current;
    } while (truha);
    
}

void delete_dnode(Dnode* head){
    Dnode* current = head;
    while (current != nullptr)
    {
        Dnode* next_n = current->next;
        delete current;
        current = next_n;
    }
    head = nullptr;
}
int main(){
    Node* head = nullptr;
    new_el_in_back(head, 43);
    new_el_in_back(head, 23);
    new_el_in_back(head, 6);
    new_el_in_back(head, 78);

    print(head);

    new_el_in_middle(head, 56, 2);

    print(head);

    sort_buble(head);

    print(head);
    
    delete_list(head);

    Dnode* d_head = nullptr;

    new_in_back(d_head, 44);
    new_in_back(d_head, 52);
    new_in_back(d_head, 25);
    new_in_back(d_head, 1488);

    print_dnode(d_head);

    sort_dnode_buble(d_head);

    print_dnode(d_head);

    delete_dnode(d_head);
    return 0;
}