#include<bits/stdc++.h>

using namespace std;

struct Book {
    string name;
    bool available;
};

int main() {
    vector<Book> books = {{"Book1", true},
                          {"Book2", true},
                          {"Book3", true},
                          {"Book4", true}};
    int choice;
    MENU:
    cout << endl << "Меню:" << endl;
    cout << "1. Список всіх книг" << endl;
    cout << "2. Взяти книгу" << endl;
    cout << "3. Повернути книгу" << endl;
    cout << "4. Вийти" << endl;
    cout << "Оберіть дію: ";
    cin >> choice;
    switch (choice) {
        case 1: {
            for (Book book: books) {
                cout << book.name << " ";
                if (book.available) cout << "Доступна" << endl;
                else cout << "Недоступна" << endl;
            }
            break;
        }
        case 2: {
            int book_num;
            cout << "Введіть номер книги ";
            cin >> book_num;
            if ((book_num < 1) || (book_num > books.size())) {
                cout << "Книги з таким номером не існує" << endl;
                goto MENU;
            } else if (!books[book_num - 1].available) {
                cout << "Ця книга недоступна" << endl;
                goto MENU;
            } else {
                cout << "Ви взяли книгу №" << book_num << " " << books[book_num - 1].name << endl;
                books[book_num - 1].available = false;
            }
            break;
        }
        case 3: {
            int book_num;
            cout << "Введіть номер книги ";
            cin >> book_num;
            if ((book_num < 1) || (book_num > books.size())) {
                cout << "Книги з таким номером не існує" << endl;
                goto MENU;
            } else if (books[book_num - 1].available) {
                cout << "Ця книга не була позичена" << endl;
                goto MENU;
            } else {
                cout << "Ви повернули книгу №" << book_num << " " << books[book_num - 1].name << endl;
                books[book_num - 1].available = true;
            }
            break;
        }
        case 4: {
            cout << "Гарного дня!" << endl;
            exit(0);
        }
        default: {
            cout << "Невідома дія, спробуйте ще раз";
        }
    }
    cout << "Бажаєте виконати іншу операцію? (1 -> так, 0 -> ні)" << endl;
    cin >> choice;
    if (choice) goto MENU;
    else cout << "Гарного дня!" << endl;
}