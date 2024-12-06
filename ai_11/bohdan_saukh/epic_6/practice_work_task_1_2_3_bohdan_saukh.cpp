#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* nextNode;

    ListNode(int val) : value(val), nextNode(nullptr) {}
};

class LinkedList {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->nextNode;
            current->nextNode = previous;
            previous = current;           
            current = nextNode;
        }
        return previous;
    }

    bool areListsEqual(ListNode* list1, ListNode* list2) {
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->value != list2->value) {
                return false;
            }
            list1 = list1->nextNode;
            list2 = list2->nextNode;
        }
        return list1 == nullptr && list2 == nullptr;
    }

    void appendToList(ListNode*& head, int value) {
        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->nextNode != nullptr) {
                current = current->nextNode;
            }
            current->nextNode = newNode;
        }
    }

    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        ListNode* resultHead = nullptr;
        int carryOver = 0;

        while (num1 != nullptr || num2 != nullptr || carryOver != 0) {
            int sum = carryOver;

            if (num1 != nullptr) {
                sum += num1->value;
                num1 = num1->nextNode;
            }

            if (num2 != nullptr) {
                sum += num2->value;
                num2 = num2->nextNode;
            }

            carryOver = sum / 10;
            appendToList(resultHead, sum % 10);
        }
        return resultHead;
    }

    void printList(ListNode* head) const {
        while (head != nullptr) {
            cout << head->value << " ";
            head = head->nextNode;
        }
        cout << endl;
    }

    void printReversed(ListNode* head) {
        head = reverseList(head);
        while (head != nullptr) {
            cout << head->value;
            head = head->nextNode;
        }
        cout << endl;
    }
};

int main() {
    LinkedList listOperations;

    ListNode* list1 = nullptr;
    listOperations.appendToList(list1, 1);
    listOperations.appendToList(list1, 2);
    listOperations.appendToList(list1, 3);
    listOperations.appendToList(list1, 4);

    // Task 1: Reverse the list
    cout << "Task 1" << endl;
    cout << "Original list: ";
    listOperations.printList(list1);

    list1 = listOperations.reverseList(list1);

    cout << "Reversed list: ";
    listOperations.printList(list1);

    // Task 2: Compare two linked lists
    ListNode* list2 = nullptr;
    listOperations.appendToList(list2, 1);
    listOperations.appendToList(list2, 6);
    listOperations.appendToList(list2, 7);
    listOperations.appendToList(list2, 9);

    ListNode* list3 = nullptr;
    listOperations.appendToList(list3, 2);
    listOperations.appendToList(list3, 5);
    listOperations.appendToList(list3, 7);

    cout << endl << "Task 2" << endl;
    cout << "First list: ";
    listOperations.printList(list2);
    cout << "Second list: ";
    listOperations.printList(list3);

    if (listOperations.areListsEqual(list2, list3)) {
        cout << "The lists are equal" << endl;
    } else {
        cout << "The lists are not equal" << endl;
    }

    // Task 3: Add two numbers
    cout << endl << "Task 3" << endl;
    ListNode* sumResult = listOperations.addTwoNumbers(list2, list3);

    cout << "First number: ";
    listOperations.printReversed(list2);
    cout << "Second number: ";
    listOperations.printReversed(list3);
    cout << "Sum: ";
    listOperations.printReversed(sumResult);

    return 0;
}
