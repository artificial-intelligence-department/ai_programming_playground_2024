#include <iostream>
using namespace std;

//Структура Node
struct Node
{
    int Value;
    Node* Next;
};

//Створення вузлів
Node* createNode(int v) {
    Node* New_Node = new Node;
    New_Node->Value = v;
    New_Node->Next = NULL;
    return New_Node;
}

//Виведення списку в нормальному вигляді
void printList(Node* head) {
    while (head != NULL) {
        cout << "" << head->Value << " -> ";
        head = head->Next;
        if (head == NULL) {
            cout << "NULL";
        }
    }
}

//Функція, яка перепризначує вказівник кожного вузла на попередній
Node* reverseList(Node* head) {
    Node* Curr_Node = head;
    Node* Prev_Node = NULL;
    Node* Next_Node;

    while (Curr_Node != NULL) {
        Next_Node = Curr_Node->Next;
        Curr_Node->Next = Prev_Node;

        Prev_Node = Curr_Node;
        Curr_Node = Next_Node;
    }
    return Prev_Node;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* New_Node = createNode(value);

        if (head == NULL) {
            head = New_Node;
            tail = New_Node;
        }
        else {
            tail->Next = New_Node;
            tail = New_Node;
        }
    }
    cout << "Linked list: ";
    printList(head);

    head = reverseList(head);
    cout << "\n" << "Reversed linked list: ";
    printList(head);
    
    return 0;
}
