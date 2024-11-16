#include <iostream>
const int capacity = 8;
int arr[capacity];
int front = 0;
int rear = -1;
int size = 0;
void add(int n);
void remove();
void print();
int main()
{
    print();
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    add(6);
    add(7);
    add(8);
    add(9);
    remove();
    remove();
    add(10);
    add(11);    
}
void add(int n)
{   
    if(size==capacity)
    {
        std::cout << "The queue is full, cannot add elements." << std::endl;
    }
    else
    {
        rear = (rear+1) % capacity;
        arr[rear]=n;
        size++;
        print();
    }
}
void remove()
{
    if(size==0)
    {
        std::cout << "The queue is empty, no elements to remove." << std::endl;
    }
    else
    {
        front = (front+1) % capacity;
        size--;
        print();
    }
}
void print()
{
    if(size==0)
    {
        std::cout << "The queue is empty, no elements to print." << std::endl;
    }
    else
    {
        std::cout << "Current queue: ";
        for(int i=0; i<size; i++)
        {
            std::cout << arr[(front+i)%capacity] << " ";
        }
        std::cout << std::endl;
    }
}
