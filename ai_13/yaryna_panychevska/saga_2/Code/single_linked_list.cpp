#include <iostream>
using namespace std;

//Однонаправлений список
struct Node
{
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

struct LinkedList
{
    Node* head;//Завжди вказуватиме на оновлену вершину 
    LinkedList() : head(NULL) {}//Створюється початково порожній список

    void addToList(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        head->next = newNode;
    }


    void insertAtTheBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    void insertAtTheEnd(int value) {
        Node* newNode = new Node(value);
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertInTheMiddle(int value) {
        Node* newNode = new Node(value);
        Node* temp = head;
        int length = 0;

        while (temp->next != NULL) {
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
        while (middle > 1) {
            temp = temp->next;
            middle--;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }


    void BubbleSort() {
        if (head == NULL || head->next == NULL) {
            return;
        }
        for (Node* i = head; i != NULL; i = i->next) {
            // Внутрішній цикл - для проходу по елементах до останнього
            for (Node* j = head; j->next != NULL; j = j->next) {
                if (j->data > j->next->data) {
                    // Обмін значеннями між вузлами
                    int temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                }
            }
        }
    }

    void printList(Node* head) {
        while (head != NULL) {
            cout << "" << head->data << " -> ";
            head = head->next;
            if (head == NULL) {
                cout << "NULL";
            }
        }
    }
};

int main() {
    LinkedList myList;

    myList.addToList(54);
    myList.addToList(20);
    cout << "Original Linked list: ";
    myList.printList(myList.head);

    myList.insertAtTheBeginning(10);
    myList.insertAtTheBeginning(30);
    myList.insertAtTheBeginning(35);
    myList.insertAtTheBeginning(67);

    cout << "\nLinked list after adding elements before head node: ";
    myList.printList(myList.head);

    myList.insertAtTheEnd(90);
    cout << "\nLinked list after adding elements at the end: ";
    myList.printList(myList.head);

    myList.insertInTheMiddle(105);
    cout << "\nLinked list after adding elements in the middle: ";
    myList.printList(myList.head);

    myList.BubbleSort();
    cout << "\nLinked list after bubble sort: ";
    myList.printList(myList.head);

    return 0;
}