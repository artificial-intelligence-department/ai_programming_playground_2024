#include <iostream>

#define SIZE 5

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
    Node* head = new Node { "abcde", NULL, NULL };
    Node* n = head;
    LinkedList l { SIZE, head, NULL };
    for (int i = 1; i < SIZE; i++)
    {
        
    }
}