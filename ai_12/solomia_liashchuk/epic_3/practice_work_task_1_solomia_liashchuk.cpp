#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    vector<string> books = {"Гаррі Поттер", "1984", "Інферно", "Сяйво", "Біблія", "Кобзар", "Колонія", "Зазирни в мої сни"};
    vector<bool> availability(books.size(), true);
    int choice;

    do 
    {
    main_menu:
        cout << "\n--- Бібліотека ---\n";
        cout << "1. Перерахувати всі книги\n";
        cout << "2. Взяти книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) 
        {
            cout << "Список книг в бібліотеці:\n";
            for (size_t i = 0; i < books.size(); ++i) 
            {
                cout << i + 1 << ". " << books[i] << " - ";
                if (availability[i]) 
                {
                    cout << "доступна\n";
                }
                else 
                {
                    cout << "взята\n";
                }
            }

        } 
        else if (choice == 2) 
        {
            string title;
            bool found = false;
            cout << "Введіть назву книги (без пробілів), яку хочете взяти: ";
            cin >> title;

            for (size_t i = 0; i < books.size(); ++i) 
            {
                if (books[i] == title) 
                {
                    found = true;
                    if (availability[i]) 
                    {
                        availability[i] = false;
                        cout << "Ви взяли книгу: " << title << endl;
                    } 
                    else 
                    {
                        cout << "На жаль, книга вже зайнята.\n";
                    }
                    break;
                }
            }
            if (!found) 
            {
                cout << "Книга не знайдена.\n";
            }

        } 
        else if (choice == 3) 
        {
            string title;
            bool found = false;
            cout << "Введіть назву книги (без пробілів), яку хочете повернути: ";
            cin >> title;

            for (size_t i = 0; i < books.size(); ++i) 
            {
                if (books[i] == title) 
                {
                    found = true;
                    availability[i] = true;
                    cout << "Ви повернули книгу: " << title << endl;
                    break;
                }
            }
            if (!found) 
            {
                cout << "Книга не знайдена.\n";
            }

        } 
        else if (choice == 4) 
        {
            cout << "Дякую за використання програми!\n";
            break;
        } 
        else 
        {
            cout << "Неправильний вибір! Спробуйте ще раз.\n";
            goto main_menu;
        }

        char continueChoice;
        cout << "Виконати іншу операцію? (y/n): ";
        cin >> continueChoice;
        if (continueChoice != 'y') break;

    } 
    
    while (true);

    return 0;
}