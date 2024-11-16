#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 5;
string books[MAX_BOOKS] = {"Book1", "Book2", "Book3", "Book4", "Book5"};
bool available[MAX_BOOKS] = {true, true, true, true, true};

void showBooks() {
    cout << "Список книг:" << endl;
    for (int i = 0; i < MAX_BOOKS; i++) {
        cout << i + 1 << ". " << books[i] << " - " << (available[i] ? "доступна" : "уже взята") << endl;
    }
}

void updateBookStatus(bool borrowing) {
    int bookNum;
    cout << "Введіть номер книги, яку хочете " << (borrowing ? "взяти: " : "повернути: ");
    cin >> bookNum;

    if (bookNum < 1 || bookNum > MAX_BOOKS) {
        cout << "Неправильний номер книги. Спробуйте ще раз" << endl;
        return;
    }

    if (available[bookNum - 1] == borrowing) {
        available[bookNum - 1] = !borrowing;
        cout << "Ви успішно " << (borrowing ? "взяли" : "повернули") << " книгу: " << books[bookNum - 1] << endl;
    } else {
        cout << "Ця книга вже " << (borrowing ? "зайнята" : "доступна") << endl;
    }
}

int main() {
    int choice;
    do {
        cout << endl << "Меню:" << endl;
        cout << "1. Показати всі книги" << endl;
        cout << "2. Взяти книгу" << endl;
        cout << "3. Повернути книгу" << endl;
        cout << "4. Вийти" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
            case 1: showBooks(); break;
            case 2: updateBookStatus(true); break;
            case 3: updateBookStatus(false); break;
            case 4: cout << "Вихід з програми" << endl; break;
            default: cout << "Неправильний вибір. Спробуйте ще раз" << endl;
        }
    } while (choice != 4);

    return 0;
}
