#include <iostream>
#include <string>
using namespace std;

void listBooks(const string books[], const bool available[], int size) {
    cout << "Список книг:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << books[i] << " - " << (available[i] ? "доступна" : "позичена") << endl;
    }
}

void borrowBook(bool available[], int size) {
    int index;
    cout << "Введіть номер книги, яку хочете позичити: ";
    cin >> index;
    if (index < 1 || index > size || !available[index - 1]) {
        cout << "Книга недоступна для позичення" << endl;
    } else {
        available[index - 1] = false;
        cout << "Ви позичили книгу" << endl;
    }
}

void returnBook(bool available[], int size) {
    int index;
    cout << "Введіть номер книги, яку хочете повернути: ";
    cin >> index;
    if (index < 1 || index > size || available[index - 1]) {
        cout << "Ця книга вже є в бібліотеці" << endl;
    } else {
        available[index - 1] = true;
        cout << "Ви повернули книгу" << endl;
    }
}

int main() {
    const int size = 3;
    string books[size] = {"Книга 1", "Книга 2", "Книга 3"};
    bool available[size] = {true, true, true};
    int choice;

    do {
    menu:
        cout << "\nМеню:\n";
        cout << "1. Показати всі книги\n";
        cout << "2. Позичити книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listBooks(books, available, size);
                break;
            case 2:
                borrowBook(available, size);
                break;
            case 3:
                returnBook(available, size);
                break;
            case 4:
                cout << "Вихід з програми" << endl;
                break;
            default:
                cout << "Неправильний вибір." << endl;
                goto menu;
        }

        char again;
        cout << "Хочете виконати іншу операцію? (y/n): ";
        cin >> again;
        if (again == 'n' || again == 'N') break;

    } while (true);

    return 0;
}
