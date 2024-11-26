#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

struct Node 
{
    char* value;
    Node* prev = NULL;
    Node* next = NULL;
};

struct LinkedList
{
    size_t size;
    Node* head;
    Node* tail;
};

LinkedList create_list(size_t size)
{
    Node* n = new Node { new char[6], NULL, NULL };
    strcpy(n->value, "abcde");
    Node* prev_n = n;
    LinkedList l { size, n, NULL };
    for (int i = 1; i < size; i++)
    {
        std::stringstream ss("");
        ss << "abcde" << i;
        char* val = new char[ss.str().size()]; 
        strcpy(val, ss.str().c_str());
        n = new Node { val, prev_n, NULL };
        prev_n->next = n;
        prev_n = n;
    }
    l.tail = n;
    return l;
}

void print_list(LinkedList l)
{
    if (!l.head)
    {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    Node* n = l.head;
    while (n)
    {
        std::cout << n->value << std::endl;
        n = n->next;
    }
}

void write_to_file(LinkedList& l, std::string path)
{
    std::fstream fs(path, std::fstream::out | std::fstream::binary);
    Node* n = l.head;
    fs << l.size << std::endl;
    while (n)
    {
        fs << n->value << std::endl;
        n = n->next;
    }
    fs.close();
}

void delete_list(LinkedList& l)
{
    if (!l.head)
    {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    Node* n = l.head->next;
    Node* prev_n = l.head;
    while (n)
    {
        delete prev_n;
        prev_n = n;
        n = n->next;
    }
    delete n;
    l.head = l.tail = NULL;
}

LinkedList restore_list_from_file(std::string path)
{
    LinkedList l;
    std::fstream fs(path, std::fstream::in | std::fstream::binary);
    std::string buf;
    std::getline(fs, buf);
    l.size = std::stoull(buf);
    bool head_written = false;
    Node* n, * prev_n;
    while (std::getline(fs, buf))
    {
        n = new Node;
        n->value = new char[BUFSIZ];
        strcpy(n->value, buf.c_str());
        if(!head_written)
        {
            l.head = n;
            head_written = true;
        }
        else
        {
            prev_n->next = n;
        }
        prev_n = n;
    }
    l.tail = n;
    return l;
}

void delete_element_by_value(LinkedList& l, const char* val)
{
    Node* n = l.head;
    while (n)
    {
        if (!strcmp(n->value, val)) break;
        n = n->next;
    }
    if (n->prev) n->prev->next = n->next;
    else l.head = n->next;
    if (n->next) n->next->prev = n->prev;
    else l.tail = n->prev;
    delete n;
    l.size--;
}

bool add_before_and_after_index(LinkedList& l, size_t index, const char* new_val)
{
    Node* n = l.head;
    int i = 0;
    while (n)
    {
        if (i++ >= index) break;
        n = n->next;
    }
    if (!n)
    {
        std::cout << "Element with index " << index << " not found!" << std::endl;
        return false;
    }
    Node* prev = n->prev; 
    Node* next = n->next;
    n->prev = new Node { new char[strlen(new_val)], prev, n };
    strcpy(n->prev->value, new_val);
    if (prev)
    {
        prev->next = n->prev;
    }
    else
    {
        l.head = n->prev;
    }
    n->next = new Node { new char[strlen(new_val)], n, next };
    strcpy(n->next->value, new_val);
    if (next)
    {
        next->prev = n->next;
    }
    else
    {
        l.tail = n->next;
    }
    l.size += 2;
    return true;
}

void add_before_and_after_index(LinkedList& l, size_t index, const char* new_val, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (!add_before_and_after_index(l, index + i, new_val)) break;
    }
}

int main()
{
    LinkedList l = create_list(5);
    print_list(l);
    delete_element_by_value(l, "abcde");
    std::cout << std::endl;
    print_list(l);
    add_before_and_after_index(l, 2, "aaa", 3);
    std::cout << std::endl;
    print_list(l);
    add_before_and_after_index(l, -1, "bbb", 3);
    std::cout << std::endl;
    print_list(l);
    write_to_file(l, "lab10.dat");
    delete_list(l);
    print_list(l);
    l = restore_list_from_file("lab10.dat");
    print_list(l);
    delete_list(l);
}