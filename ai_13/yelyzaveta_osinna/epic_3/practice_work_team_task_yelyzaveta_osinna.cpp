#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Ініціалізація книг та їх доступності
vector<string> books = {"Старий і море", "Гаррі Поттер", "Тіні забутих предків", "1984", "Кобзар"};
vector<bool> available = {true, true, true, true, true};

// Функція для перерахунку всіх книг
void listBooks() {
    cout << "\nСписок всіх книг:\n";
    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i] << " - " << (available[i] ? "Доступна" : "Недоступна") << endl;
    }
}

// Функція для перевірки наявності книги та взяття її користувачем
void borrowBook() {
    int bookNumber;
    listBooks();
    cout << "\nВведіть номер книги, яку бажаєте взяти: ";
    cin >> bookNumber;

    // Перевірка коректності номера
    if (bookNumber < 1 || bookNumber > books.size()) {
        cout << "Неправильний номер книги!\n";
        goto menu; // Використання goto для повернення до меню
    }

    // Вибір книги
    if (available[bookNumber - 1]) {
        available[bookNumber - 1] = false;
        cout << "Ви взяли книгу \"" << books[bookNumber - 1] << "\".\n";
    } else {
        cout << "Ця книга вже недоступна!\n";
    }

menu: // Мітка для повернення до меню
    return;
}

// Функція для повернення книги
void returnBook() {
    int bookNumber;
    listBooks();
    cout << "\nВведіть номер книги, яку бажаєте повернути: ";
    cin >> bookNumber;

    // Перевірка коректності номера
    if (bookNumber < 1 || bookNumber > books.size()) {
        cout << "Неправильний номер книги!\n";
        goto menu; // Використання goto для повернення до меню
    }

    // Повернення книги
    if (!available[bookNumber - 1]) {
        available[bookNumber - 1] = true;
        cout << "Ви повернули книгу \"" << books[bookNumber - 1] << "\".\n";
    } else {
        cout << "Ця книга вже була доступна!\n";
    }

menu: // Мітка для повернення до меню
    return;
}

// Основна функція з меню
int main() {
    int choice;
    bool continueProgram = true;

    while (continueProgram) { // Продовжувати працювати, поки користувач не вирішить вийти
        cout << "\nМеню:\n";
        cout << "1. Перерахувати всі книги\n";
        cout << "2. Взяти книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listBooks();
                break;
            case 2:
                borrowBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                continueProgram = false;
                cout << "Вихід з програми.\n";
                break;
            default:
                cout << "Неправильний вибір. Спробуйте ще раз.\n";
                goto menu;
        }

        // Запит на продовження після кожної операції
        char continueChoice;
        do {
            cout << "\nБажаєте виконати іншу операцію? (y/n): ";
            cin >> continueChoice;
            if (continueChoice == 'n' || continueChoice == 'N') {
                continueProgram = false;
            } else if (continueChoice != 'y' && continueChoice != 'Y') {
                cout << "Неправильний вибір. ";
            }
        } while (continueChoice != 'y' && continueChoice != 'Y' && continueChoice != 'n' && continueChoice != 'N');

menu: // Мітка для повернення до меню при неправильному виборі
        continue;
    }

    return 0;
}
