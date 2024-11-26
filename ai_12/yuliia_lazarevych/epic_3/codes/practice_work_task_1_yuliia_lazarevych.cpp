#include <iostream>
#include <vector>
#include <string>

using namespace std;

void listBooks(const vector<string>& books, const vector<bool>& available) {
    cout << "Список книг:" << endl;
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i] << " - " << (available[i] ? "доступна" : "позичена") << endl;
    }
}

void borrowBook(vector<bool>& available) {
    int index;
    cout << "Введіть номер книги, яку хочете позичити: ";
    cin >> index;
    if (index < 1 || index > available.size() || !available[index - 1]) {
        cout << "Книга недоступна для позичення" << endl;
    } else {
        available[index - 1] = false;
        cout << "Ви позичили книгу" << endl;
    }
}

void returnBook(vector<bool>& available) {
    int index;
    cout << "Введіть номер книги, яку хочете повернути: ";
    cin >> index;
    if (index < 1 || index > available.size() || available[index - 1]) {
        cout << "Ця книга вже є в бібліотеці" << endl;
    } else {
        available[index - 1] = true;
        cout << "Ви повернули книгу" << endl;
    }
}

int main() {
    vector<string> books = {"Книга 1", "Книга 2", "Книга 3"};
    vector<bool> available(books.size(), true);
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
                listBooks(books, available);
                break;
            case 2:
                borrowBook(available);
                break;
            case 3:
                returnBook(available);
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
