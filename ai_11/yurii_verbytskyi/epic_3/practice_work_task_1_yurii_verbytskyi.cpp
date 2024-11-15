#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> Books = {"Charly", "Fedko", "Physics", "George", "Cats"};
vector<bool> IsAvailable = {true, true, true, true, true};

// Функція для підрахунку кількості доступних книг
int QuantityOfBooks() {
    int quantity = 0;
    for (bool isAvailable : IsAvailable) { // Для кожного елемента масиву IsAvailable
        if (isAvailable) {
            ++quantity;
        }
    }
    return quantity;
}

int main() {
    int size = Books.size();
    int firstanswer;
    char secondanswer;
    char finalanswer;
    int l; // Індекс книги
    int quantity;
    quantity = QuantityOfBooks();

    do{
    main: // Мітка для повернення до початку меню
    cout << "What would you like to do?\n";
    cout << "1. Count books\n2. Borrow book\n3. Return book\n4. Quit program\n";
    cin >> firstanswer;

    switch (firstanswer) {
        case 1:
            cout << quantity << " book(s) available" << endl;
            break;

        case 2:
            for(int i = 0; i < size; i++){
                cout << i+1 << ". " << Books[i] << endl;
            }
            cout << "Enter the number of the book you want to borrow: ";
            cin >> l;
            if (l < 1 || l > size) {
                cout << "Invalid book number. Try again." << endl;
                goto main;
            }

            if (IsAvailable[l - 1] == true) {
                cout << "Book \"" << Books[l - 1] << "\" is available. Would you like to take it now (y/n)? ";
                cin >> secondanswer;
                if (secondanswer == 'y') {
                    IsAvailable[l - 1] = false;
                    cout << "You have borrowed the book \"" << Books[l - 1] << "\"." << endl;
                } else if (secondanswer == 'n') {
                    goto main;
                } else {
                    cout << "Invalid input. Try again." << endl;
                    goto main;
                }
            } else {
                cout << "Book \"" << Books[l - 1] << "\" is not available." << endl;
            }
            break;

        case 3:
            for(int i = 0; i < size; i++){
                cout << i+1 << ". " << Books[i] << endl;
            }
            cout << "Enter the number of the book you want to return: ";
            cin >> l;
            if (l < 1 || l > size) {
                cout << "Invalid book number. Try again." << endl;
                goto main;
            }

            if (IsAvailable[l - 1] == false) {
                IsAvailable[l - 1] = true;
                cout << "Thank you for returning the book \"" << Books[l - 1] << "\"." << endl;
            } else {
                cout << "This book is already here, maybe you mean another book?" << endl;
                goto main;
            }
            break;

        case 4:
                cout << "Are you sure you want to quit? (y/n)\n";
                cin >> finalanswer;
            if(finalanswer == 'n'){
                goto main;
            } else return 0;

        default:
            cout << "Invalid option. Try again." << endl;
            goto main;
    }
    cout << "Would you like to continue (y/n)?" << endl;
    cin >> finalanswer;
    if (finalanswer == 'y'){
        goto main;
    }
    } while(finalanswer != 'n');
    return 0;
}
