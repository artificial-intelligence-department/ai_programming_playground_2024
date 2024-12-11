#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int number, Node* nextNode, Node* prevNode) : value(number), next(nextNode), prev(nextNode) {}
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int size;

        void deleteList(Node* current) {
            if (current == nullptr) return; 
            deleteList(current->next); 
            delete current;
        }

    public:
        LinkedList() : head(nullptr), tail(nullptr), size(0) {}
        ~LinkedList() {deleteList(head);}

        void appendFrontNode(int number) {
            if (size == 0) {
                head = new Node(number, nullptr, nullptr);
                tail = head;

            } else {
                head->prev = new Node(number, head, nullptr);
                head = head->prev;
            }
            
            size++;
        }

        void appendIntoNode(int number, int index) {
            if (index > size || index < 0) {
                cout << "Не корректний індекс";

            } else if (index == 0) {
                appendFrontNode(number);

            } else if (index == size) {
                appendBackNode(number);

            } else {
                Node* current = head;

                for (int i = 0; i < index; i++) {
                    current = current->next;
                }

                Node* newNode = new Node(number, current, current->prev);
                current->prev->next = newNode;
                current->prev = newNode;
            }

            size++;
        }

        void appendBackNode(int number) {
            if (size == 0) {
                head = new Node(number, nullptr, nullptr);
                tail = head;

            } else {
                tail->next = new Node(number, nullptr, tail);
                tail = tail->next;
            }

            size++;
        }

        void printListCaller() {
            printList(head);
        }

        void printList(Node* current) {
            if (current == nullptr) return;
            cout << current->value << " ";
            printList(current->next);
        }
};

int main() {
    LinkedList list;

    int Q;
    cout << "Кількість операцій: ";
    cin >> Q;

    while (Q--) {
        string choise;
        cout << "Операція: ";
        cin >> choise;

        if (choise == "1") {
            int number;
            cout << "Новий елемент: ";
            cin >> number;
            list.appendFrontNode(number);

        } else if (choise == "2") {
            int number, index;
            cout << "Новий елемент: ";
            cin >> number;
            cout << "Позиція: ";
            cin >> index;
            list.appendIntoNode(number, index);

        } else if (choise == "3") {
            int number;
            cout << "Новий елемент: ";
            cin >> number;
            list.appendBackNode(number);

        } else if (choise == "4") {
            cout << "Список: ";
            list.printListCaller();
            cout << endl;
        }
    }

    return 0;
}