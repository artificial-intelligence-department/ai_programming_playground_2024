#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 5; 

void listBooks(string books[], bool availability[], int size) {
    cout << "Список книг в  бібліотеці:\n";
    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ". " << books[i] 
             << (availability[i] ? " (Доступно)" : " (Взято)") << endl;
    }
}

void borrowBook(string books[], bool availability[], int size) {
    int bookNum;
    cout << "Введіть номер книги, яку хочете взяти: ";
    cin >> bookNum;

    if (bookNum < 1 || bookNum > size) {
        cout << "Невірний номер книги.\n";
        return;
    }

    if (availability[bookNum - 1]) {
        availability[bookNum - 1] = false;
        cout << "Ви успішно взяли книгу: " << books[bookNum - 1] << endl;
    } else {
        cout << "Ця книга вже взята.\n";
    }
}

void returnBook(string books[], bool availability[], int size) {
    int bookNum;
    cout << "Введіть номер книги, яку хочете повернути: ";
    cin >> bookNum;

    if (bookNum < 1 || bookNum > size) {
        cout << "Невірний номер книги.\n";
        return;
    }

    if (!availability[bookNum - 1]) {
        availability[bookNum - 1] = true;
        cout << "Ви успішно повернули книгу: " << books[bookNum - 1] << endl;
    } else {
        cout << "Ця книга вже є в бібліотеці.\n";
    }
}

int main() {
  
    string books[MAX_BOOKS] = {"Книга 1", "Книга 2", "Книга 3", "Книга 4", "Книга 5"};
    bool availability[MAX_BOOKS] = {true, true, true, true, true}; 

    int choice;
    bool continueProgram = true;

  
    while (continueProgram) {
        
        cout << "\nМеню:\n";
        cout << "1. Перерахувати всі книги\n";
        cout << "2. Взяти книгу\n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listBooks(books, availability, MAX_BOOKS); 
                break;
            case 2:
                borrowBook(books, availability, MAX_BOOKS); 
                break;
            case 3:
                returnBook(books, availability, MAX_BOOKS); 
                break;
            case 4:
                continueProgram = false; 
                break;
            default:
            
                cout << "Невірний вибір! Спробуйте ще раз.\n";
                goto menu; 
        }

        char continueChoice;
        cout << "Хочете виконати іншу операцію? (y/n): ";
        cin >> continueChoice;
        if (continueChoice == 'n' || continueChoice == 'N') {
            continueProgram = false;
        }

        menu: ; 
    }

    cout << "До побачення!\n";
    return 0;
}
