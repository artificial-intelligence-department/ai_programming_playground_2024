#include <iostream>
#include <string>

using namespace std;

const int NUM_BOOKS = 4;

void listBooks(const string books[], const bool availability[]) {
    cout << "\nСписок усіх книг:\n";
    for (int i = 0; i < NUM_BOOKS; ++i) {
        cout << i + 1 << ". " << books[i] << " - " 
             << (availability[i] ? "Доступна" : "Зайнята") << "\n";
    }
}

void borrowBook(bool availability[]) {
    int bookNumber;
    cout << "\nВведіть номер книги, яку хочете взяти: ";
    cin >> bookNumber;
    --bookNumber;  // Зменшуємо, щоб привести до індексу масиву

    if (bookNumber >= 0 && bookNumber < NUM_BOOKS) {
        if (availability[bookNumber]) {
            availability[bookNumber] = false;
            cout << "Ви взяли книгу.\n";
        } else {
            cout << "Книга недоступна для позичання.\n";
        }
    } else {
        cout << "Невірний номер книги.\n";
    }
}

void returnBook(bool availability[]) {
    int bookNumber;
    cout << "\nВведіть номер книги, яку хочете повернути: ";
    cin >> bookNumber;
    --bookNumber;

    if (bookNumber >= 0 && bookNumber < NUM_BOOKS) {
        if (!availability[bookNumber]) {
            availability[bookNumber] = true;
            cout << "Ви повернули книгу.\n";
        } else {
            cout << "Книга вже доступна в бібліотеці.\n";
        }
    } else {
        cout << "Невірний номер книги.\n";
    }
}

int main() {
    string books[NUM_BOOKS] = {"Із крові й попелу", "Гаррі Поттер", "Панк 57", "Самотність простих чисел"};
    bool availability[NUM_BOOKS] = {true, true, true, true};  // Ініціалізуємо всі книги як доступні

    int choice;
    bool exit = false;

    while (!exit) {
    mainMenu:  // Мітка для повернення до головного меню за допомогою goto
        cout << "\nГоловне меню:\n";
        cout << "1. Переглянути всі книги\n";
        cout << "2. Взяти книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listBooks(books, availability);
                break;
            case 2:
                borrowBook(availability);
                break;
            case 3:
                returnBook(availability);
                break;
            case 4:
                exit = true;
                continue;  // Переходимо до завершення циклу while
            default:
                cout << "Неправильний вибір. Спробуйте ще раз.\n";
                goto mainMenu;  // Використання goto для повернення до меню
        }

        char anotherOperation;
        do {
            cout << "\nВи хочете виконати іншу операцію? (y/n): ";
            cin >> anotherOperation;
            if (anotherOperation == 'y') {
                goto mainMenu;
            } else if (anotherOperation == 'n') {
                exit = true;
            } else {
                cout << "Невірний вибір. ";
            }
        } while (anotherOperation != 'y' && anotherOperation != 'n');
    }

    cout << "Дякуємо за користування програмою керування бібліотекою!\n";
    return 0;
}
