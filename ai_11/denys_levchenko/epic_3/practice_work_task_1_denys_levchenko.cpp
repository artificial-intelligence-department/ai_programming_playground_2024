#include <iostream>
#include <string>

using namespace std;

int main() {
    const int num_books = 5;
    string books[num_books] = {"Harry Potter", "Lord of the Rings", "The Little Prince", "One Hundred Years of Solitude", "Kobzar"};
    bool availability[num_books] = {true, true, true, true, true};
    int choice;
    string user_choice;

main_menu:
    while (true) {
        cout << "\nГоловне меню:\n";
        cout << "1. Переглянути всі книги\n";
        cout << "2. Взяти книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Введіть свій вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nСписок книг:\n";
                for (int i = 0; i < num_books; i++) {
                    cout << i + 1 << ". " << books[i] << (availability[i] ? " (Доступна)" : " (Позичена)") << "\n";
                }
                break;
            }
            case 2: {
                cout << "\nВведіть номер книги, яку хочете взяти: ";
                int book_number;
                cin >> book_number;

                if (book_number < 1 || book_number > num_books) {
                    cout << "Невірний номер книги. Спробуйте ще раз.\n";
                    goto main_menu;
                }

                if (availability[book_number - 1]) {
                    availability[book_number - 1] = false;
                    cout << "Ви успішно взяли книгу: " << books[book_number - 1] << "\n";
                } else {
                    cout << "Ця книга вже позичена.\n";
                }
                break;
            }
            case 3: {
                cout << "\nВведіть номер книги, яку хочете повернути: ";
                int book_number;
                cin >> book_number;

                if (book_number < 1 || book_number > num_books) {
                    cout << "Невірний номер книги. Спробуйте ще раз.\n";
                    goto main_menu;
                }

                if (!availability[book_number - 1]) {
                    availability[book_number - 1] = true;
                    cout << "Ви успішно повернули книгу: " << books[book_number - 1] << "\n";
                } else {
                    cout << "Ця книга вже доступна.\n";
                }
                break;
            }
            case 4: {
                cout << "Вихід з програми...\n";
                return 0;
            }
            default: {
                cout << "Невірний вибір. Спробуйте ще раз.\n";
                goto main_menu;
            }
        }

        do {
            cout << "\nБажаєте виконати іншу операцію? (y/n): ";
            cin >> user_choice;
            if (user_choice == "n" || user_choice == "n") {
                cout << "Вихід з програми...\n";
                return 0;
            } else if (user_choice == "y" || user_choice == "y") {
                goto main_menu;
            } else {
                cout << "Невірний вибір. Спробуйте ще раз.\n";
            }
        } while (user_choice != "y" && user_choice != "n" && user_choice != "y" && user_choice != "n");
    }

    return 0;
}
