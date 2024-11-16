#include <iostream>
using namespace std;

const int N = 100; 

class Queue {
private:
    int a[N];
    int front, rear, size;

public:
    Queue() : front(0), rear(0), size(0) {} 

    void enqueue(int value) {
        if (size == N) {
            cout << "Черга переповнена!" << endl;
            return;
        }
        a[rear] = value;
        rear = (rear + 1) % N;
        size++;
        printQueue();
    }

    void dequeue() {
        if (size == 0) {
            cout << "Черга порожня!" << endl;
            return;
        }
        front = (front + 1) % N; 
        size--;
        printQueue();
    }

    void printQueue() {
        if (size == 0) {
            cout << "Черга порожня!" << endl;
            return;
        }
        cout << "Черга: ";
        for (int i = 0; i < size; i++) {
            cout << a[(front + i) % N] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int n;
    cout << "Введіть кількість елементів у черзі (не більше " << N << "): ";
    cin >> n;

    if (n > N || n < 0) {
        cout << "Некоректна кількість елементів!" << endl;
        return 1;
    }


    for (int i = 0; i < n; i++) {
        int value;
        cout << "Введіть елемент " << i + 1 << ": ";
        cin >> value;
        queue.enqueue(value);
    }

    int choice;
    do {
        cout << "\nОберіть операцію:\n";
        cout << "1. Додати елемент\n";
        cout << "2. Видалити елемент\n";
        cout << "3. Вихід\n";
        cout << "Введіть номер операції: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Введіть значення для додавання: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << "Вихід з програми." << endl;
                break;
            default:
                cout << "Неправильний вибір!" << endl;
        }
    } while (choice != 3);

    return 0;
}
