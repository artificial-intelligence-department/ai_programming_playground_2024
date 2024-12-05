#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) {
    stack<int> stack1, stack2;

    while (n1) {
        stack1.push(n1->data);
        n1 = n1->next;
    }

    while (n2) {
        stack2.push(n2->data);
        n2 = n2->next;
    }

    int carry = 0;
    Node* result = nullptr;

    while (!stack1.empty() || !stack2.empty() || carry) {
        int sum = carry;
        if (!stack1.empty()) {
            sum += stack1.top();
            stack1.pop();
        }
        if (!stack2.empty()) {
            sum += stack2.top();
            stack2.pop();
        }

        carry = sum / 10;
        Node* newNode = new Node(sum % 10);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* n1 = new Node(9);
    n1->next = new Node(7);
    n1->next->next = new Node(3);

    Node* n2 = new Node(6);
    n2->next = new Node(4);
    n2->next->next = new Node(5);

    Node* result = add(n1, n2);

    cout << "Сума: ";
    printList(result);

    return 0;
}