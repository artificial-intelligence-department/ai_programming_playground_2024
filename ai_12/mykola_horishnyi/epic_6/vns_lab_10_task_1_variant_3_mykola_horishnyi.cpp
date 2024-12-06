#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Node 
{
    int data;
    unique_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) 
    {
    }
};
class LinkedList 
{
private:
    unique_ptr<Node> head; 

public:
    LinkedList() : head(nullptr) 
    {
    }

    void addElement(int value)
    {
        unique_ptr<Node> newNode = make_unique<Node>(value);
        if (!head || value < head->data) 
        {
            newNode->next = move(head);
            head = move(newNode);
            return;
        }

        Node* current = head.get();
        while (current->next && current->next->data < value) 
        {
            current = current->next.get();
        }
        newNode->next = move(current->next);
        current->next = move(newNode);
    }

    void deleteElementsLessThan(int threshold) 
    {
        while (head && head->data < threshold) 
        {
            head = move(head->next);
        }

        Node* current = head.get();
        while (current && current->next) 
        {
            if (current->next->data < threshold) 
            {
                current->next = move(current->next->next);
            }
            else {
                current = current->next.get();
            }
        }
    }

    void printList() const 
    {
        Node* current = head.get();
        while (current) {
            cout << current->data << " ";
            current = current->next.get();
        }
        cout << endl;
    }
};

int main() 
{
    LinkedList list;

    list.addElement(10);
    list.addElement(5);
    list.addElement(70);
    list.addElement(20);


    cout << "Your first list : ";
    list.printList();

    list.deleteElementsLessThan(10);
    cout << "Last list with numbers < 10 : ";
    list.printList();

    return 0;
}










