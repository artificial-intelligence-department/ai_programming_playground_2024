#include <iostream>

class DoubleLinkedList
{
private:
    struct Node
    {
        int data;
        Node* previous;
        Node* next;

        Node(): data(0), previous(nullptr), next(nullptr) {}
        Node(int val, Node* prev = nullptr, Node* nxt = nullptr): data(val), previous(prev), next(nxt) {} 
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    
public:
    void push_back(int value);
    void push_forward(int value);
    void push_middle(int value);
    void bubble_sort();

    void print();
};

void DoubleLinkedList::push_back(int value)
{
    Node* new_node = new Node(value);
    if (head == nullptr)
    {
        head = new_node;
        size++;
        return;
    }
    Node* current = head;
    while (current->next != nullptr)
        current = current->next;
    current->next = new_node;
    new_node->previous = current;
    size++;
}

void DoubleLinkedList::push_forward(int value)
{
    Node* new_node = new Node(value);
    new_node->next = head;
    head->previous = new_node;
    head = new_node;
    new_node->previous = nullptr;
    size++;
}

void DoubleLinkedList::push_middle(int value)
{
    Node* current = head;
    int counter = 0;
    while (counter != size/2)
    {
        current = current->next;
        counter++;
    }
    
    Node* new_node = new Node(value);
    new_node->next = current->next;
    current->next = new_node;
    new_node->previous = current;
    size++;
}

void DoubleLinkedList::bubble_sort()
{
    for (int i = size - 1; i > 0; i--)
    {
        Node* current = head;
        Node* next_node = current->next;
        for (int j = 0; j < i; j++)
        {
            if (current->data > next_node->data)
            {
                int temp = current->data;
                current->data = next_node->data;
                next_node->data = temp;
            }
            current = next_node;
            next_node = next_node->next;
        }
    }

}

void DoubleLinkedList::print()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}



int main()
{
    DoubleLinkedList lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_forward(9);
    lst.push_middle(0);
    lst.print();
    lst.bubble_sort();
    lst.print();
    
    return 0;

}