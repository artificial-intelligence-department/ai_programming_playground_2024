#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Створення масивів для зберігання назв книг і їх доступності
    vector<string> books = {"C++ Programming", "Data Structures", "Algorithms", "Computer Networks"};
    vector<bool> availability = {true, true, true, true};  // true - книга доступна, false - книга позичена
    
    int choice;  // Змінна для збереження вибору користувача
    bool continue_program = true;  // Флаг для продовження роботи програми

    while (continue_program) {
        // Головне меню
        cout << "\nБібліотека\n";
        cout << "1. Перерахувати всі книги\n";
        cout << "2. Позичити книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Виберіть опцію (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Перерахування всіх книг
                cout << "\nСписок книг:\n";
                for (int i = 0; i < books.size(); i++) {
                    cout << i + 1 << ". " << books[i];
                    if (availability[i]) {
                        cout << " - доступна\n";
                    } else {
                        cout << " - позичена\n";
                    }
                }
                break;
            }
            case 2: {
                // Позичити книгу
                int book_number;
                cout << "\nВведіть номер книги, яку хочете позичити (1-" << books.size() << "): ";
                cin >> book_number;

                if (book_number < 1 || book_number > books.size()) {
                    cout << "Невірний номер книги. Спробуйте ще раз.\n";
                    goto main_menu;  // Перехід до головного меню, якщо номер книги некоректний
                }

                // Перевірка на доступність книги
                if (availability[book_number - 1]) {
                    availability[book_number - 1] = false;
                    cout << "Ви успішно позичили книгу: " << books[book_number - 1] << endl;
                } else {
                    cout << "Ця книга вже позичена.\n";
                }
                break;
            }
            case 3: {
                // Повернути книгу
                int book_number;
                cout << "\nВведіть номер книги, яку хочете повернути (1-" << books.size() << "): ";
                cin >> book_number;

                if (book_number < 1 || book_number > books.size()) {
                    cout << "Невірний номер книги. Спробуйте ще раз.\n";
                    goto main_menu;  // Перехід до головного меню, якщо номер книги некоректний
                }

                // Повернення книги
                if (!availability[book_number - 1]) {
                    availability[book_number - 1] = true;
                    cout << "Ви успішно повернули книгу: " << books[book_number - 1] << endl;
                } else {
                    cout << "Ця книга не була позичена.\n";
                }
                break;
            }
            case 4:
                // Вихід з програми
                cout << "Дякуємо за використання бібліотеки! До побачення.\n";
                continue_program = false;  // Завершуємо програму
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз.\n";
                goto main_menu;  // Перехід до головного меню в разі неправильного вибору
        }

        // Запит користувача, чи хоче він виконати ще одну операцію
        char again;
        cout << "\nБажаєте виконати іншу операцію? (y/n): ";
        cin >> again;

        if (again == 'n' || again == 'N') {
            continue_program = false;  // Завершуємо програму, якщо користувач вибрав "n"
        }

    main_menu:
        continue_program;
    }

    return 0;
}
