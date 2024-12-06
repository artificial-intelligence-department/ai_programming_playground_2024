#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
    Node* head;
public:
    DoubleLinkedList() : head(nullptr) {}

    void addAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1 && current != nullptr; ++i) {
                current = current->next;
            }

            if (current == nullptr) {
                cout << "Position out of range." << endl;
                delete newNode;
            } else {
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
            }
        }
    }

    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    DoubleLinkedList reverse() const {
        DoubleLinkedList reversedList;
        Node* current = head;

        while (current != nullptr) {
            reversedList.addAtPosition(current->value, 1);
            current = current->next;
        }

        return reversedList;
    }

    bool isEqual(const DoubleLinkedList& other) const {
        Node* node1 = head;
        Node* node2 = other.head;

        while (node1 != nullptr && node2 != nullptr) {
            if (node1->value != node2->value) {
                return false;
            }
            node1 = node1->next;
            node2 = node2->next;
        }

        return node1 == nullptr && node2 == nullptr;
    }

    DoubleLinkedList sumWith(const DoubleLinkedList& other) const {
        DoubleLinkedList result;
        Node* ptr1 = head;
        Node* ptr2 = other.head;
        int carry = 0;

        while (ptr1 != nullptr || ptr2 != nullptr || carry != 0) {
            int total = carry;
            if (ptr1 != nullptr) {
                total += ptr1->value;
                ptr1 = ptr1->next;
            }
            if (ptr2 != nullptr) {
                total += ptr2->value;
                ptr2 = ptr2->next;
            }

            result.addAtPosition(total % 10, 1);
            carry = total / 10;
        }

        return result.reverse();
    }
};

int main() {
    DoubleLinkedList listA, listB;

    listA.addAtPosition(1, 1);
    listA.addAtPosition(2, 2);
    listA.addAtPosition(3, 3);
    listA.addAtPosition(7, 4);

    cout << "Original list: ";
    listA.display();

    listB = listA.reverse();
    cout << "Reversed list: ";
    listB.display();

    if (listA.isEqual(listB)) {
        cout << "Lists are identical." << endl;
    } else {
        cout << "Lists differ." << endl;
    }

    DoubleLinkedList listC = listA.sumWith(listA);
    cout << "Sum of the list with itself: ";
    listC.display();

    return 0;
}
