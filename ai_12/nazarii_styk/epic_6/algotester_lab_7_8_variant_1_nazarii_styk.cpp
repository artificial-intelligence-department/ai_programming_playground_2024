#include <iostream>
#include <vector>
#include <string>

struct Node 
{
    int data;    
    Node* prev;  
    Node* next;  

    // Конструктор вузла
    Node(int val) 
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

struct DoublyLinkedList 
{
    Node* head;   
    Node* tail;   
    int size;     
    DoublyLinkedList() 
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }


    void insert(int index, const std::vector<int>& values) 
    {
        if (index < 0 || index > size) 
        {
            return;
        }

        Node* current = head;
        for (int i = 0; i < index && current; ++i) 
        {
            current = current->next;
        }

        for (int value : values) 
        {
            Node* new_node = new Node(value);

            if (!head) 
            { 
                head = tail = new_node;
            } 
            else if (current == head) 
            { // початок
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            } 
            else if (!current) 
            { // кінець
                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
            } 
            else 
            { // середина
                new_node->prev = current->prev;
                new_node->next = current;
                current->prev->next = new_node;
                current->prev = new_node;
            }

            size++;
        }
    }


    void erase(int index, int n) 
    {
        if (index < 0 || index >= size) return;

        Node* current = head;
        for (int i = 0; i < index; ++i) 
        {
            current = current->next;
        }

        for (int i = 0; i < n && current; ++i) 
        {
            Node* to_delete = current;
            current = current->next;

            if (to_delete->prev) to_delete->prev->next = to_delete->next;
            if (to_delete->next) to_delete->next->prev = to_delete->prev;
            if (to_delete == head) head = to_delete->next;
            if (to_delete == tail) tail = to_delete->prev;

            delete to_delete;
            size--;
        }
    }

    int get(int index) 
    {
        if (index < 0 || index >= size) return -1;

        Node* current = head;
        for (int i = 0; i < index; ++i) 
        {
            current = current->next;
        }
        return current->data;
    }

    // Змінити значення за індексом
    void set(int index, int value) 
    {
        if (index < 0 || index >= size) return;

        Node* current = head;
        for (int i = 0; i < index; ++i) 
        {
            current = current->next;
        }
        current->data = value;
    }

    int getSize() 
    {
        return size;
    }

    void print() 
    {
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() 
{
    DoublyLinkedList list;
    int Q;
    std::cin >> Q;

    while (Q--) 
    {
        std::string command;
        std::cin >> command;

        if (command == "insert") 
        {
            int index, n;
            std::cin >> index >> n;
            std::vector<int> values(n);
            for (int i = 0; i < n; ++i) 
            {
                std::cin >> values[i];
            }
            list.insert(index, values);
        } 
        else if (command == "erase") 
        {
            int index, n;
            std::cin >> index >> n;
            list.erase(index, n);
        }
        else if (command == "size") 
        {
            std::cout << list.getSize() << std::endl;
        }
        else if (command == "get") 
        {
            int index;
            std::cin >> index;
            std::cout << list.get(index) << std::endl;
        } 
        else if (command == "set") 
        {
            int index, value;
            std::cin >> index >> value;
            list.set(index, value);
        } 
        else if (command == "print") 
        {
            list.print();
        }
    }

    return 0;
}
