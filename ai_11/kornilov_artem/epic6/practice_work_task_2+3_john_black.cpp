#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* add(Node* n1, Node* n2) {
    Node* dummyHead = new Node(0);
    Node* current = dummyHead;
    int carry = 0;

    while (n1 || n2 || carry) {
        int sum = carry; 

        if (n1) {
            sum += n1->data; 
            n1 = n1->next;
        }
        if (n2) {
            sum += n2->data; 
            n2 = n2->next;
        }

        carry = sum / 10; 
        sum %= 10;        

        current->next = new Node(sum); 
        current = current->next;
    }

    Node* result = dummyHead->next; 
    delete dummyHead;              
    return result;
}


void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node* createList(initializer_list<int> digits) {
    Node* head = nullptr;
    Node* current = nullptr;
    for (int digit : digits) {
        Node* newNode = new Node(digit);
        if (!head) {
            head = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;
    }
    return head;
}

bool compare(Node* h1, Node* h2) {
    while (h1 && h2) { 
        if (h1->data != h2->data) {
            return false; 
        }
        h1 = h1->next; 
        h2 = h2->next;
    }

    
    if (h1 || h2) {
        return false; 
    }

    return true; 
}



int main() {
    Node* list1 = createList({1, 2, 3, 4, 5}); 
    Node* list2 = createList({1, 2, 3, 4, 5}); 
    Node* list3 = createList({1, 2, 3});       

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    cout << "List 3: ";
    printList(list3);

    cout << "Compare List 1 and List 2: " << (compare(list1, list2) ? "Equal" : "Not Equal") << endl;
    cout << "Compare List 1 and List 3: " << (compare(list1, list3) ? "Equal" : "Not Equal") << endl;
    
    Node* num1 = createList({9, 7, 3}); // Число: 973
    Node* num2 = createList({6, 5, 4}); // Число: 654

    cout << "First number: ";
    printList(num1);

    cout << "Second number: ";
    printList(num2);

    Node* sum = add(num1, num2);

    cout << "Sum: ";
    printList(sum);

    return 0;
}
