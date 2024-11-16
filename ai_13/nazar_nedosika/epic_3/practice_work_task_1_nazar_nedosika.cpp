#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> books = {"Кобзар", "Одіссея", "Іліада", "Перевтілення", "По той бік добра і зла"};
vector<bool> available = {true, true, true, true, true};

void listBooks() {
    cout << "\nСписок книг:\n";
    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i] << (available[i] ? " (доступна)\n" : " (взята)\n");
    }
    cout << endl;
}

void borrowBook() {
    int choice;

    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i] << (available[i] ? " (доступна)\n" : " (взята)\n");
    }

    cout << "\nВведіть номер книги, яку бажаєте взяти: ";
    cin >> choice;

    if (choice < 1 || choice > books.size()) {
        cout << "Неправильний вибір. Спробуйте ще раз.\n";
        goto end;
    }

    if (available[choice - 1]) {
        available[choice - 1] = false;
        cout << "Ви успішно взяли книгу: " << books[choice - 1] << endl;
    } else {
        cout << "Цю книгу вже взяли.\n";
    }

end:;
}

void returnBook() {
    int choice;

    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i] << (available[i] ? " (доступна)\n" : " (взята)\n");
    }

    cout << "\nВведіть номер книги, яку бажаєте повернути: ";
    cin >> choice;

    if (choice < 1 || choice > books.size()) {
        cout << "Неправильний вибір. Спробуйте ще раз.\n";
        goto end;
    }

    if (!available[choice - 1]) {
        available[choice - 1] = true;
        cout << "Ви успішно повернули книгу: " << books[choice - 1] << endl;
    } else {
        cout << "Ця книга вже доступна.\n";
    }

end:;
}

int main() {
    int choice;

    do {
        cout << "\nМеню бібліотеки:\n";
        cout << "1. Переглянути всі книги\n";
        cout << "2. Взяти книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Виберіть опцію: ";
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
                return 0;
            default:
                cout << "Неправильний вибір \n";
                goto menu;
        }

    menu:
        cout << "1. Головне меню\n";;
        cout << "2 .Вихід з програми\n";
        cin >> choice;

    } while (choice == 1);


    return 0;
}