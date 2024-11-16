#include <iostream>

using namespace std;

const int MAX_BOOKS = 4; 


void listBooks(const int available[])
 {
    cout << "\nList of books in the library::\n";
    for (int i = 0; i < MAX_BOOKS; i++) {
        cout << i + 1 << ". Book " << i + 1 << " - ";
        
        if (available[i] == 1)
        {
            cout << "Available";
        } 
        else
        {
            cout << "Not available";
        }
        cout << endl;
    }
}


void borrowBook(int available[])
 {
    int choice;
    cout << "Enter number of book , that you want take: ";
    cin >> choice;


    if (choice > 0 && choice <= MAX_BOOKS) 
    {
        if (available[choice - 1] == 1) {
            available[choice - 1] = 0;
            cout << "You take this book:\n";
        } 
        else
        {
            cout << "This book is already taken :\n";
        }
    } 
    else 
    {
        cout << "Unknowing number of book.\n";
    }
}


void returnBook(int available[]) 
{
    int choice;
    cout << "Enter number of book, that you want return: ";
    cin >> choice;

    
    if (choice > 0 && choice <= MAX_BOOKS) {
        if (available[choice - 1] == 0) 
        {
            available[choice - 1] = 1;
            cout << "You return this bool.\n";
        } 
        else 
        {
            cout << "This book is in library.\n";
        }
    } 
    else 
    {
        cout << "Unknowing number of book.\n";
    }
}

int main() {

    int available[MAX_BOOKS] = { 1, 1, 1, 1 };

    int choice; 

    do {
        main_menu: 
        cout << "\nMenu:\n";
        cout << "1. Look all books\n";
        cout << "2. Take a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Choose operation: ";
        cin >> choice;

        
        if (choice == 1) 
        {
            listBooks(available); 
        }
        else if (choice == 2) 
        {
            borrowBook(available); 
        }
        else if (choice == 3) 
        {
            returnBook(available); 
        }
        else if (choice == 4) 
        {
            cout << "Goodbye!\n";
        }
        else 
        {
            
            cout << "Wrong choice. Try again.\n";
            goto main_menu;
        }

        
        if (choice != 4) {
            char continueChoice;
            cout << "\nDo another operation? (y/n): ";
            cin >> continueChoice;
            
            
            if (continueChoice != 'y' && continueChoice != 'Y') break;
        }
    } while (choice != 4); 

    return 0;
}
