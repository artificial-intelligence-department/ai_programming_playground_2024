#include <iostream>
using namespace std;

//Двонаправлений список
struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

struct LinkedList
{
    Node* head;
    Node* tail;
    LinkedList() : head(NULL), tail(NULL) {}

    void AddToList(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

    }

    void insertAtTheBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTheEnd(int value) {
        Node* newNode = new Node(value);
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertInTheMiddle(int value) {
        Node* newNode = new Node(value);
        Node* temp = head;
        int length = 0;

        // Обчислюємо довжину списку
        while (temp != NULL) {
            temp = temp->next;
            length++;
        }

        int middle;
        if (length % 2 == 0) {
            middle = length / 2;
        }
        else {
            middle = (length + 1) / 2;
        }

        temp = head;
        // Переходимо до вузла перед серединою
        for (int i = 0; i < middle - 1; i++) {
            temp = temp->next;
        }

        // Оновлюємо посилання
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void reverseList() {
        if (head == NULL) return;

        Node* current = head;
        Node* temp = NULL;

        while (current != NULL) {

            temp = current->next;
            current->next = current->prev;
            current->prev = temp;

            if (temp == NULL) {
                head = current;
                break;
            }
            current = temp;
        }
    }

    void BubbleSort() {
        if (head == NULL || head->next == NULL) {
            return; // Список порожній або має лише один елемент
        }

        bool swapped; // Змінна для перевірки, чи були обміни
        Node* current;
        Node* last = NULL; // Вказує на вже відсортовану частину списку

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    // Обмін значеннями між вузлами
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;

                    swapped = true; // Фіксуємо, що був обмін
                }
                current = current->next; // Переходимо до наступного вузла
            }
            last = current; // Оновлюємо останній відсортований елемент
        } while (swapped); // Повторюємо, поки були обміни
    }

    void printList(Node* head) {
        while (head != NULL) {
            cout << "" << head->data << " <-> ";
            head = head->next;
            if (head == NULL) {
                cout << "NULL";
            }
        }
    }

};
int main() {

    LinkedList myList;
    myList.AddToList(10);
    myList.AddToList(20);
    myList.AddToList(30);

    cout << "Original Double Linked list: ";
    myList.printList(myList.head);

    myList.insertAtTheBeginning(40);
    cout << "\nDouble Linked list after adding elements at the beginning: ";
    myList.printList(myList.head);

    myList.insertAtTheEnd(50);
    myList.insertAtTheEnd(60);
    cout << "\nDouble Linked list after adding elements at the end: ";
    myList.printList(myList.head);

    myList.insertInTheMiddle(90);
    myList.insertInTheMiddle(80);
    cout << "\nDouble Linked list after adding elements int the middle: ";
    myList.printList(myList.head);

    myList.reverseList();
    cout << "\nDouble Linked list after reversing: ";
    myList.printList(myList.head);

    myList.BubbleSort();
    cout << "\nDouble Linked list after bubble sort: ";
    myList.printList(myList.head);

    return 0;
}