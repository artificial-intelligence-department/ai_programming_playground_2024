#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int val) 
    {
        data = val;
        next = nullptr;
    }
};

Node* add(Node* n1, Node* n2) 
{
    Node* result = nullptr; 
    Node* tail = nullptr;   
    int carry = 0;          

    while (n1 != nullptr || n2 != nullptr || carry > 0) 
    {
        int sum = carry; 

        if (n1 != nullptr) 
        {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr) 
        {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10; 
        int digit = sum % 10;

        Node* newNode = new Node(digit);

        if (result == nullptr) 
        {
            result = newNode; 
            tail = newNode;   
        } 
        else 
        {
            tail->next = newNode; 
            tail = newNode;
        }
    }

    return result;
}

Node* reverse(Node* head) 
{
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) 
    {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* append(Node* head, int value) 
{
    if (head == nullptr) 
    {
        return new Node(value);
    }
    Node* temp = head;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = new Node(value);
    return head;
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{
    Node* num1 = nullptr;
    num1 = append(num1, 9);
    num1 = append(num1, 7);
    num1 = append(num1, 3);
    num1 = append(num1, 1);

    Node* num2 = nullptr;
    num2 = append(num2, 9);
    num2 = append(num2, 4);
    num2 = append(num2, 8);
    num2 = append(num2, 5);

    cout << "Number 1: ";
    printList(num1);
    cout << "Number 2: ";
    printList(num2);

    num1 = reverse(num1);
    num2 = reverse(num2);

    Node* sum = add(num1, num2);

    sum = reverse(sum);

    cout << "Sum: ";
    printList(sum);

    return 0;
}
