#include <iostream>
#include <string>

using namespace std;

const int numBooks = 4;
string books[numBooks] = {"1984", "Бідний тато, багатий тато", "Код да Вінчі", "Біблія"};
bool Borrowed[numBooks] = {false, false, false, false};

void listBooks() {
    cout << "\nСписок книг:\n";
    for (int i = 0; i < numBooks; i++) {
        cout << (i + 1) << ". " << books[i] << (Borrowed[i] ? " (зайнята)" : " (доступна)") << endl;
    }
}

bool isBookAvailable(int index) {
    if (index < 1 || index > numBooks) {
        cout << "Помилка: Неправильний номер книги.\n";
        return false;
    }
    return true;
}

bool borrowBook() {
    int bookIndex;
    cout << "Введіть номер книги, яку хочете взяти: ";
    cin >> bookIndex;

    if (!isBookAvailable(bookIndex)) {
        return true;
    }

    if (Borrowed[bookIndex - 1]) {
        cout << "На жаль, книга \"" << books[bookIndex - 1] << "\" вже зайнята.\n";
    } else {
        Borrowed[bookIndex - 1] = true;
        cout << "Ви успішно взяли книгу \"" << books[bookIndex - 1] << "\".\n";
    }
    return false;
}

bool returnBook() {
    int bookIndex;
    cout << "Введіть номер книги, яку хочете повернути: ";
    cin >> bookIndex;

    if (!isBookAvailable(bookIndex)) {
        return true;
    }

    if (!Borrowed[bookIndex - 1]) {
        cout << "Ця книга вже є в бібліотеці.\n";
    } else {
        Borrowed[bookIndex - 1] = false;
        cout << "Ви успішно повернули книгу \"" << books[bookIndex - 1] << "\".\n";
    }
    return false;
}

int main() {
    int choice;
    bool Uexit = false;

    do {
    main_menu:
        cout << "\nГоловне меню:\n";
        cout << "1. Переглянути всі книги\n";
        cout << "2. Взяти книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Виберіть дію: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listBooks();
                break;
            case 2:
                if (borrowBook()) {
                    goto main_menu;
                }
                break;
            case 3:
                if (returnBook()) {
                    goto main_menu;
                }
                break;
            case 4:
                Uexit = true;
                cout << "Дякуємо за користування бібліотекою!\n";
                break;
            default:
                cout << "Неправильний вибір! Спробуйте знову.\n";
                goto main_menu;
        }

        if (!Uexit) {
            string usercin;
            cout << "Бажаєте перейти до головного меню? (Yes/Exit): ";
            cin >> usercin;
            if (usercin == "exit" || usercin =="Exit") {
                Uexit = true;
                cout << "Дякуємо за користування бібліотекою!\n";
            } else if (usercin == "yes" || usercin == "Yes") {
                goto main_menu;
            } else{
                cout << "Неправильний вибір, спробуйте ще раз\n";
            }
        }
    } while (!Uexit);

    return 0;
}
