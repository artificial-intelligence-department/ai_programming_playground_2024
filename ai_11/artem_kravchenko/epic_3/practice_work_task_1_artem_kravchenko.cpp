#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display_menu(){
    cout << "\nМеню бібліотеки:\n";
    cout << "1. Переглянути всі книги\n";
    cout << "2. Взяти книгу\n";
    cout << "3. Повернути книгу\n";
    cout << "4. Вийти\n";
    cout << "Оберіть опцію: ";
}

int main(){

    vector<string> book = {"Бушкрафт", "У дикій глушині", "У розрядженому повітрі", "Приборкати страх"};
    vector<bool> avail(book.size(), true);

    int choice;
    do{
    display_menu();
    cin >> choice;
    int number;
    switch (choice)
    {
    case 1:
        cout << "\nСписок книг:\n";
        for (size_t i = 0; i < book.size(); i++)
        {
            cout << i+1 << ". " << book[i] << " - " <<(avail[i] ? "Доступна" : "Зайнята") << "\n";
        }
        
        break;
    case 2:
        cout << "\nВведіть номер книги, яку хочете взяти: ";
        cin >> number;
        if (number >= 1 && number <= book.size() && avail[number - 1])
        {
            avail[number - 1] = false;
            cout << "Ви успішно взяли книгу: " << book[number - 1] << "\n";
        }else{
            cout << "Книга недоступна або невірний номер\n";
        }
        break;
    case 3:
        cout << "\nВведіть номер книги, яку хочете повернути: ";
        cin >> number;
        if (number >= 1 && number <= book.size() && !avail[number - 1])
        {
            avail[number - 1] = true;
            cout << "Ви успішно повернули книгу: " << book[number - 1] << "\n";
        }else{
            cout << "Книга вже доступна або невірний номер\n";
        }
        break;
    case 4:
        cout << "\nВи вийшли з бібліотеки\n";
        break;
    default:
        cout << "\nНеправильний вибір. Будь ласка, спробуйте ще раз\n";
        break;
    }
    } while (choice != 4);

    return 0;
}