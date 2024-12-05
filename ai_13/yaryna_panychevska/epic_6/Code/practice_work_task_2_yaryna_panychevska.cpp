#include <iostream>
using namespace std;

struct Node
{
    int Value;
    Node* Next;
};

Node* createNode(int v) {
    Node* New_Node = new Node;
    New_Node->Value = v;
    New_Node->Next = NULL;
    return New_Node;
}

//Порівняння списків
bool compare(Node* head1, Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        //Перевірка на співпадіння елементів
        if (head1->Value != head2->Value) {
            return false;
        }
        else {
            head1 = head1->Next;
            head2 = head2->Next;
        }
        //Перевірка на довжину
        if (head1 != NULL || head2 != NULL) {
            return false;
        }
    }
    return true;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << "" << head->Value << " -> ";
        head = head->Next;
        if (head == NULL) {
            cout << "NULL";
        }
    }
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    int n, m;
    cout << "Enter the number of elements for linked list 1: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* New_Node = createNode(value);

        if (head1 == NULL) {
            head1 = New_Node;
            tail1 = New_Node;
        }
        else {
            tail1->Next = New_Node;
            tail1 = New_Node;
        }
    }
    //--------------------------------------------------------------------------//
    cout << "Enter the number of elements for linked list 2: ";
    cin >> m;
    cout << "Enter " << m << " elements: ";
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        Node* New_Node = createNode(value);


        if (head2 == NULL) {
            head2 = New_Node;
            tail2 = New_Node;
        }
        else {
            tail2->Next = New_Node;
            tail2 = New_Node;
        }
    }

    cout << "Linked list 1: ";
    printList(head1);
    cout << "\n" << "Linked list 2: ";
    printList(head2);

    if (compare(head1, head2)) {
        cout << "\nLinled list 1 and Linked list 2 are identical";
    }
    else {
        cout << "\nLinked list 1 and Linked list 2 are not identical";
    }
    return 0;
}