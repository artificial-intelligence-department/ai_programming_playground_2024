#include <iostream>

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

int main()
{
    
}