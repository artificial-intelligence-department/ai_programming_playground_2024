#include <iostream>
using namespace std;

struct Node {
    int data;       
    Node* next;      

    Node(int value) : data(value), next(nullptr) {} // Конструктор
};

// Функція для перевертання списку
Node* reverse(Node* head) {
    Node* prev = nullptr;  
    Node* current = head;  

    while (current != nullptr) {
        Node* nextNode = current->next; 
        current->next = prev;           
        prev = current;                 
        current = nextNode;             
    }
    return prev; // новий head списку
}

// Функція для порівняння двох списків
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) { 
            return false;
        }
        h1 = h1->next; 
        h2 = h2->next; 
    }

    // Якщо один з списків закінчився раніше 
    return h1 == nullptr && h2 == nullptr;
}

// Функція для додавання двох чисел(у вигляді списків)
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr; 
    Node* tail = nullptr;    
    int carry = 0;           

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry;

        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        Node* newNode = new Node(digit);
        if (result == nullptr) {
            result = newNode;
            tail = result;  
        } else {
            tail->next = newNode;
            tail = tail->next;  
        }
    }

    return result;  
}

// Функція для додавання елемента в кінець списку
Node* addInEndNode(Node* head, int value) {
    Node* newNode = new Node(value); 
    if (head == nullptr) {
        return newNode; 
    }

    Node* temp = head; 
    while (temp->next != nullptr) {
        temp = temp->next; 
    }
    temp->next = newNode;

    return head;
}

// Функція для створення списку з масиву
Node* createList(const int arr[], int size) {
    Node* head = nullptr;
    for (int i = 0; i < size; ++i) {
        head = addInEndNode(head, arr[i]); 
    }
    return head;
}

// Функція для виведення списку
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {2, 7, 3, 4, 5};  
    int arr2[] = {2, 7, 3, 4, 5};  
    int arr3[] = {1, 5, 9};
    int arr4[] = {4, 5, 1};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);

    Node* head1 = createList(arr1, size1);
    Node* head2 = createList(arr2, size2);
    Node* head3 = createList(arr3, size3);
    Node* head4 = createList(arr4, size4);

    cout << "Source list 1: ";
    printList(head1);
    cout << "Source list 2: ";
    printList(head2);

    // Порівнюємо список 1 і 2
    if (compare(head1, head2)) {
        cout << "Lists are the same!" << endl;
    } else {
        cout << "Lists are different!" << endl;
    }

    // Перевертаємо список 1
    head1 = reverse(head1);
    cout << "Reversed list 1: ";
    printList(head1);

    // Додаємо список 3 і 4
    Node* sumHead = add(head3, head4);
    cout << "Adding list 3 and list 4: ";
    printList(sumHead);

    return 0;
}
