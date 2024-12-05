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

//Конвертація числа в зв'язний список
Node* NumToLinkedList(int num) {
    Node* head = NULL;
    Node* tail = NULL;
    while (num != 0) {
        int digit = num % 10;
        num = num / 10;
        Node* New_Node = createNode(digit);
        if (head == NULL) {
            head = New_Node;
            tail = New_Node;
        }
        else {
            tail->Next = New_Node;
            tail = New_Node;
        }
    }
    return head;
}
//Реверс зв'язного списку
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
//Додаємо два зв'язних списки
Node* add(Node* num1, Node* num2) {
    Node* head_result = NULL;
    Node* tail_result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->Value;
            num1 = num1->Next;
        }
        if (num2 != NULL) {
            sum += num2->Value;
            num2 = num2->Next;
        }

        carry = sum / 10;
        int digit = sum % 10;
        Node* New_Node = createNode(digit);
        carry = sum / 10;

        if (head_result == NULL) {
            head_result = New_Node;
            tail_result = New_Node;
        }
        else {
            tail_result->Next = New_Node;
            tail_result = tail_result->Next;
        }
    }
    return head_result;
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
    cout << "Enter num1: ";
    cin >> n;
    head1 = NumToLinkedList(n);

    cout << "Enter num2: ";
    cin >> m;
    head2 = NumToLinkedList(m);

    cout << "\n" << "Linked list for num1: ";
    printList(head1);

    cout << "\n" << "Linked list for num2: ";
    printList(head2);

    Node* result = add(head1, head2);

    cout << "\n" << "Sum of LL1 and LL2 is: ";
    printList(result);

    return 0;
}