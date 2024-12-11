#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int number) : value(number), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;
        int size;

        void deleteList(Node* current) {
            if (current == nullptr) return; 
            deleteList(current->next); 
            delete current;
        }

    public:
        LinkedList() : head(nullptr), size(0){}
        ~LinkedList() {deleteList(head);}

        void appendFrontNode(int number) {
            if (head == nullptr) {
                head = new Node(number);
                return;
            }

            Node* temp = head;
            head = new Node(number);
            head->next = temp;
            size++;
        }

        void appendIntoNode(int number, int index) {
            if (index > size || index < 0) {
                cout << "Wrong index";

            } else if (index == 0) {
                appendFrontNode(number);

            } else if (index == size) {
                appendBackNode(number);

            } else {
                Node* current = head;

                for (int i = 0; i < index - 1; i++) {
                    current = current->next;
                }

                Node* temp = current->next;
                current->next = new Node(number);
                current->next->next = temp;
                size++;
            }
        }

        void appendBackNode(int number) {
            if (head == nullptr) {
                head = new Node(number);
                return;
            }

            Node* current = head;
            while (current->next != nullptr) current = current->next;
            current->next = new Node(number);
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