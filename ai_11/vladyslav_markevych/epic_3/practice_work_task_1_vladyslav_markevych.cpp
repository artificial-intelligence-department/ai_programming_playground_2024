#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Startmenu(){
    cout << "Ось, які функції ми можемо Вам запропонувати:" << endl;
    cout << "1. Які книги в наявності" << endl;
    cout << "2. Взяти книгу" << endl;
    cout << "3. Повернути книгу" << endl;
    cout << "4. Закінчити" << endl;
    cout << "Виберіть, те що вам потрібно: ";
}

int main(){
    int choice;
    vector<string> allbooks = {"1984", "Колгосп тварин", "Володар перснів", "Зелена миля", "Воно"};
    vector<bool> avail = {true, true, true, true, true};

    while (true) {
        Startmenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Список книг:" << endl;
                for (int i = 0; i < allbooks.size(); i++) {
                    cout << i + 1 << ". " << allbooks[i] << " - " 
                         << (avail[i] ? "Є в наявності" : "Нажаль немає") << endl;
                }
                cout << endl; 
                break;

            case 2: {
                int bookNumber;
                cout << "Введіть номер книги, яку хочете взяти: ";
                cin >> bookNumber;
                if (bookNumber > 0 && bookNumber <= allbooks.size()) {
                    if (avail[bookNumber - 1]) {
                        avail[bookNumber - 1] = false;
                        cout << "Ви взяли книгу: " << allbooks[bookNumber - 1] << endl;
                    } else {
                        cout << "Нажаль, ця книга вже недоступна." << endl;
                    }
                } else {
                    cout << "Некоректний номер книги." << endl;
                }
                cout << endl;
                break;
            }

            case 3: {
                int bookNumber;
                cout << "Введіть номер книги, яку хочете повернути: ";
                cin >> bookNumber;
                if (bookNumber > 0 && bookNumber <= allbooks.size()) {
                    if (!avail[bookNumber - 1]) {
                        avail[bookNumber - 1] = true;
                        cout << "Ви повернули книгу: " << allbooks[bookNumber - 1] << endl;
                    } else {
                        cout << "Ця книга вже є в наявності." << endl;
                    }
                } else {
                    cout << "Некоректний номер книги." << endl;
                }
                cout << endl;
                break;
            }

            case 4:
                cout << "Дякуємо за користування! До побачення!" << endl;
                return 0;

            default:
                cout << "Неіснуюча команда, спробуйте ще раз." << endl;
                cout << endl;
                break;
        }
    }

    return 0;
}
