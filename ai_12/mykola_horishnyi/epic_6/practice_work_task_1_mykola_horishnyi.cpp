#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* reverse(Node* head)
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    return prev;
}

bool compare(Node* h1, Node* h2) 
{
    while (h1 && h2) {
        if (h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

Node* add(Node* n1, Node* n2) 
{
    Node* dummyHead = new Node(0);
    Node* current = dummyHead;
    int carry = 0; 

    while (n1 || n2 || carry) {
        int sum = carry;
        if (n1) sum += n1->data;
        if (n2) sum += n2->data;

        carry = sum / 10;
        sum %= 10;

        current->next = new Node(sum);
        current = current->next;

        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    return dummyHead->next;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    //Taks 1
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head1);

    Node* reversed = reverse(head1);
    cout << "Reversed list: ";
    printList(reversed);

    //Task 2 
    Node* num1 = new Node(5);
    num1->next = new Node(3);
    num1->next->next = new Node(1);

    Node* num2 = new Node(5);
    num2->next = new Node(6);
    num2->next->next = new Node(3);

    cout << "Comparing two lists: ";
    cout << (compare(num1, num2) ? "True" : "False") << endl;

    // Task 3 
    Node* bigNum1 = new Node(2);
    bigNum1->next = new Node(9);
    bigNum1->next->next = new Node(1);

    Node* bigNum2 = new Node(1);

    Node* sumList = add(bigNum1, bigNum2);

    cout << "Sum of two large numbers: ";
    printList(sumList);

    return 0;
}


