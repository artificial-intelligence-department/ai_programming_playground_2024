#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        Node* temp = top;
        int value = temp->value;
        top = top->next;
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->value;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        Node* current = top;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.print();

    cout << "Top Element: " << stack.peek() << endl;

    stack.pop();
    stack.print();

    return 0;
}
