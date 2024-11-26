#include <iostream>
using namespace std;

const int SIZE = 100; // Максимальний розмір масиву

// Функція для виводу елементів масиву
void printStack(int stack[], int length) {
    if (length == 0) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i < length; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

// Додавання елемента в стек
void push(int stack[], int& length, int value) {
    if (length >= SIZE) {
        cout << "Stack overflow. Cannot add more elements." << endl;
        return;
    }
    stack[length] = value;
    length++;
    cout << "Added element: " << value << endl;
    printStack(stack, length);
}

// Видалення елемента зі стека
void pop(int stack[], int& length) {
    if (length <= 0) {
        cout << "Stack underflow. No elements to remove." << endl;
        return;
    }
    cout << "Removed element: " << stack[length - 1] << endl;
    length--;
    printStack(stack, length);
}

int main() {
    int stack[SIZE];  // Масив для зберігання елементів стека
    int length = 0;   // Поточна кількість елементів у стеку
    int choice;

    cout << "Enter initial stack size (<= " << SIZE << "): ";
    cin >> length;

    if (length > SIZE || length < 0) {
        cout << "Invalid stack size." << endl;
        return 1;
    }

    // Заповнення початкового стека
    cout << "Enter " << length << " elements: ";
    for (int i = 0; i < length; i++) {
        cin >> stack[i];
    }

    printStack(stack, length);

    // Меню для роботи зі стеком
    while (true) {
        cout << "\nChoose operation:\n1. Push (add element)\n2. Pop (remove element)\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            push(stack, length, value);
        }
        else if (choice == 2) {
            pop(stack, length);
        }
        else if (choice == 3) {
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
