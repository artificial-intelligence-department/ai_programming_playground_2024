#include <iostream>
#include <vector>
#include <string>
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

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void append(vector<int>& arr) {
        for (int i = arr.size() - 1; i >= 0; i--) {
            Node* newNode = new Node(arr[i]);
            newNode->next = head;
            head = newNode;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    Node* getHead() {
        return head;
    }
};

void add(Node* n1, Node* n2) {
    vector<int> tmp;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry > 0) {
        int sum = carry;

        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10;               // Знаходимо переніс
        tmp.insert(tmp.begin(), sum % 10); // Зберігаємо залишок від ділення
    }

    LinkedList list;
    list.append(tmp);

    // Формуємо суму як рядок для відображення
    string forsum = "";
    for (int digit : tmp) {
        forsum += to_string(digit);
    }

    cout << "Number of sum is: " << forsum << endl;
    list.print();
}

bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

int main() {
    LinkedList list1;
    LinkedList list2;

    vector<int> arr1 = {6, 4, 1, 2, 3, 11};
    vector<int> arr2 = {9, 0, 7, 8, 4, 1};

    list1.append(arr1);
    list2.append(arr2);

    cout << "Original lists: " << endl;
    list1.print();
    list2.print();

    // Task 1: Reverse lists
    list1.reverse();
    list2.reverse();
    cout << "Reversed lists: " << endl;
    list1.print();
    list2.print();

    // Task 2: Compare lists
    cout << "Comparing lists: ";
    if (compare(list1.getHead(), list2.getHead())) {
        cout << "Lists are equal." << endl;
    } else {
        cout << "Lists are different." << endl;
    }

    // Task 3: Add lists
    cout << "Adding lists: " << endl;
    add(list1.getHead(), list2.getHead());

    return 0;
}