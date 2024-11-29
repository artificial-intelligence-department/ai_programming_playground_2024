#include <iostream>

using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;

    bool isEmpty() const {
        return frontNode == nullptr;
    }

    int size() const {
        int count = 0;
        Node* current = frontNode;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    void enqueue(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;

            if (frontNode == nullptr) {
                rearNode = nullptr;
            }
        } else {
            cout << "Черга порожня. Неможливо видалити елемент." << endl;
        }
    }

    int getSize() const {
        return size();
    }

    void printQueue() const {
        if (isEmpty()) {
            cout << "Черга порожня." << endl;
            return;
        }
        
        Node* current = frontNode;
        cout << "Елементи черги: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Розмір черги після додавання елементів: " << myQueue.getSize() << endl;
    myQueue.printQueue();

    myQueue.dequeue();
    cout << "Розмір черги після видалення елементу: " << myQueue.getSize() << endl;
    myQueue.printQueue();

    return 0;
}
