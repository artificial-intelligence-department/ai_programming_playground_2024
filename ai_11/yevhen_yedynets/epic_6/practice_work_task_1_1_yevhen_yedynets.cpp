#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* prev = nullptr;
    Node* temp = nullptr;
    int carry = 0, sum;
    while (n1 != nullptr || n2 != nullptr || carry) {
        sum = carry;
        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }
        carry = sum / 10;
        sum %= 10;
        temp = new Node(sum);
        if (result == nullptr) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }
    return result;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    cout << "=== Робота з пов'язаними списками ===\n";

    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    cout << "Вхідний список: ";
    printList(list1);
    list1 = reverse(list1);
    cout << "Обернений список: ";
    printList(list1);

    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);
    cout << "Списки рівні: " << (compare(list1, list2) ? "Так" : "Ні") << endl;

    Node* num1 = new Node(9);
    num1->next = new Node(9);
    Node* num2 = new Node(1);
    Node* sum = add(num1, num2);
    cout << "Сума чисел: ";
    printList(sum);

    return 0;
}