#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ListBooks(const vector<string>& books, const vector<bool>& availability)
 {
    cout << "Books in the library:\n";
    for (int i = 0; i < books.size(); ++i) 
    {
        cout << i + 1 << ". " << books[i] << " - " << (availability[i] ? "Available" : "Not Available") << endl;
    }
}

void BorrowBook(vector<bool>& availability)
 {
    int bookNumber;
    cout << "Enter the book number to borrow: ";
    cin >> bookNumber;
    if (bookNumber > 0 && bookNumber <= availability.size() && availability[bookNumber - 1])
     {
        availability[bookNumber - 1] = false;
        cout << "You have borrowed the book.\n";
    }
    else
    {
        cout << "Invalid book number or the book is not available.\n";
    }
}

void ReturnBook(vector<bool>& availability) {
    int bookNumber;
    cout << "Enter the book number to return: ";
    cin >> bookNumber;
    if (bookNumber > 0 && bookNumber <= availability.size() && !availability[bookNumber - 1]) 
    {
        availability[bookNumber - 1] = true;
        cout << "You have returned the book.\n";
    } 
    else
    {
        cout << "Invalid book number or the book was not borrowed.\n";
    }
}

int main()
{
    vector<string> books = {"Book1", "Book2", "Book3", "Book4", "Book5"};
    vector<bool> availability(books.size(), true);
    char choice;

    do {
        menu:
        cout << "Library Management System\n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case '1':
                ListBooks(books, availability);
                break;
            case '2':
                BorrowBook(availability);
                break;
            case '3':
                ReturnBook(availability);
                break;
            case '4':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                goto menu;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}