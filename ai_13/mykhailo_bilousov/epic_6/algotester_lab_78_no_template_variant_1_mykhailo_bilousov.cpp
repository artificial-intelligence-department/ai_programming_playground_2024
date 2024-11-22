#include <iostream>

struct Node 
{
    int value;
    Node* prev = NULL;
    Node* next = NULL;
};

class LinkedList
{
    size_t size;
    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void insert(size_t index, size_t size, int* elems)
    {
        Node* n = head, * new_n = NULL, * n_next = NULL;
        if (index > 0)
        {
            for (int i = 0; i < index-1; i++)
            {
                n = n->next;
            }
            if (n != NULL) n_next = n->next;
            for (int i = 0; i < size; i++)
            {
                new_n = new Node { elems[i], NULL, NULL };
                if (n != NULL) 
                {
                    n->next = new_n;
                    new_n->prev = n;
                }
                else head = new_n;
                n = new_n;
            }
        }
        else
        {
            Node* old_head = head;
            bool head_set = false;
            for (int i = 0; i < size; i++)
            {
                new_n = new Node { elems[i], NULL, NULL };
                if (n != NULL && head_set) 
                {
                    n->next = new_n;
                    new_n->prev = n;
                }
                else 
                {
                    head = new_n;
                    head_set = true;
                }
                n = new_n;
            }
            n->next = old_head;
            if (old_head != NULL) old_head->prev = n;
        }
        if (n_next != NULL)
        {
            n_next->prev = n;
            n->next = n_next;
        }
        else tail = n;
        this->size += size;
    }

    void erase(size_t index, size_t size)
    {
        Node* n = head, * n_at_index = NULL, * n_prev = NULL;
        for (int i = 0; i < index; i++) n = n->next;
        n_at_index = n->prev;
        for (int i = 0; i < size; i++)
        {
            n_prev = n;
            n = n_prev->next;
            delete n_prev;
        }
        if (n_at_index) n_at_index->next = n;
        else head = n;
        if (n) n->prev = n_at_index;
        else tail = n_at_index;
        this->size -= size;
    }

    size_t get_size() 
    {
        return size;
    }

    int& operator[](size_t index)
    {
        Node* n = head;
        for (size_t i = 0; i < index; i++) n = n->next;
        return n->value;
    }

    const int& operator[](size_t index) const
    {
        Node* n = head;
        for (size_t i = 0; i < index; i++) n = n->next;
        return n->value;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& ll)
    {
        Node* n = ll.head;
        while(n != NULL)
        {
            os << n->value << " ";
            n = n->next;
        }
        return os;
    }
};

int main()
{
    LinkedList l;
    std::string input;
    int q, index, count, value;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        std::cin >> input;
        if (input == "insert")
        {
            std::cin >> index;
            std::cin >> count;
            int* arr = new int[count];
            for (int j = 0; j < count; j++) std::cin >> arr[j];
            l.insert(index, count, arr);
            delete[] arr;
        }
        else if (input == "erase")
        {
            std::cin >> index; 
            std::cin >> count; 
            l.erase(index, count);
        }
        else if (input == "get")
        {
            std::cin >> index;
            std::cout << l[index] << std::endl;
        }
        else if (input == "set")
        {
            std::cin >> index;
            std::cin >> value;
            l[index] = value;
        }
        else if (input == "print")
        {
            std::cout << l << std::endl;
        }
        else if (input == "size")
        {
            std::cout << l.get_size() << std::endl;
        }
    }
}