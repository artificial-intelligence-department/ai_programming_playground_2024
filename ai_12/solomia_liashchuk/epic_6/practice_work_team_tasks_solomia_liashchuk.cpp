#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

Node* head = nullptr;
Node* head2 = nullptr;
void Show(Node* head)
{
    if(head == nullptr)
    {
            cout << "list is emty" << endl;
    }

    Node* current = head;
    while(current != nullptr)
    {
        cout << current->value << " " << endl;
        current = current->next;
    }
    
};

Node* reverse(Node* head)
{
    Node* next = nullptr;
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr)
    {
        next = current->next;   
        current->next = prev;  
        prev = current;         
        current = next;         
    }

    return prev;
}

bool compare(Node *h1, Node *h2)
{
    while(h1 != nullptr && h2 != nullptr)
    {
        if(h1->value != h2->value)
        {
            cout << "Not compare" << endl;
            return false;
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    return h1 == nullptr && h2 == nullptr;
}

Node* add(Node *n1, Node *n2)
{
    Node* resultHead = nullptr;
    Node* resultTail = nullptr;
    int carry = 0;        

    while(n1 != nullptr || n2 != nullptr || carry != 0)
    {
        int digit1 = (n1 != nullptr) ? n1->value : 0;
        int digit2 = (n2 != nullptr) ? n2->value : 0;

        int sum = digit1 + digit2 + carry; 
        carry = sum / 10;                
        int currentDigit = sum % 10;     

        Node* newNode = new Node{currentDigit, nullptr}; 
        if(resultHead == nullptr)
        {
            resultHead = newNode; 
            resultTail = resultHead;
        }
        else
        {
            resultTail->next = newNode; 
            resultTail = newNode;
        }

        if(n1) n1 = n1->next; 
        if(n2) n2 = n2->next;
    }
    return resultHead;
}


int main()
{
    Node* head = new Node{3, nullptr}; 
    head->next = new Node{8, nullptr};
    head->next->next = new Node{1, nullptr};

    cout << "List one: " << endl;
    Show(head);


    Node* head2 = new Node{4, nullptr}; 
    head2->next = new Node{6, nullptr};
    head2->next->next = new Node{9, nullptr};

    cout << "List two: " << endl;
    Show(head2);

    head = reverse(head);
    cout << "Reversede list" << endl;
    Show(head);

    if(compare(head, head2))
    {
        cout << "Lists are equal" << endl;
    }
    else
    {
        cout << "Lists are not equal" << endl;
    }

    Node* result = add(head, head2);

    cout << "Result of addition: ";
    Show(result);

    while(head != nullptr)
    {
        Node* current = head;
        head = head->next;
        delete current;
    }

    while(head2 != nullptr)
    {
        Node* temp2 = head2;
        head2 = head2->next;
        delete temp2;
    }

    while(result != nullptr)
    {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
    
}

