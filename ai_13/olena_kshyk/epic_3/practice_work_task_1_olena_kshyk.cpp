#include <iostream>
#include <vector>
using namespace std;

void list_books(vector<string> &books, vector<string> &availability)
{
    cout << "\nAvailable Books:\n";
    for (int i = 0; i < books.size(); i++)
    {
        cout << "- " << books[i] << " (" << availability[i] << ")\n";
    }
    cout << endl;
}

void borrow_book(vector<string> &books, vector<string> &availability)
{
    string book;
    cout << "Enter the name of the book you want to borrow: ";
    cin >> book;
    bool found = false;
    for (int i = 0; i < books.size(); i++)
    {
        if (book == books[i])
        {
            if (availability[i] == "available")
            {
                cout << "You have successfully borrowed \"" << book << "\".\n";
                availability[i] = "borrowed";
            }
            else
            {
                cout << "Sorry, \"" << book << "\" is already borrowed.\n";
            }
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Sorry, we do not have this book.\n";
    }
}

void return_book(vector<string> &books, vector<string> &availability)
{
    string book;
    cout << "Enter the name of the book you want to return: ";
    cin >> book;
    bool found = false;
    for (int i = 0; i < books.size(); i++)
    {
        if (book == books[i])
        {
            if (availability[i] == "borrowed")
            {
                cout << "Thank you! You have returned \"" << book << "\".\n";
                availability[i] = "available";
            }
            else
            {
                cout << "\"" << book << "\" was not borrowed.\n";
            }
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "You cannot return a book that we do not have.\n";
    }
}

int main()
{
    vector<string> books = {
        "The Great Gatsby",
        "1984",
        "Pride and Prejudice",
        "Moby Dick",
        "The Hobbit",
        "A Song of Ice and Fire",
        "The Name of the Wind",
    };
    vector<string> availability(books.size(), "available");

    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1 - List all books\n";
        cout << "2 - Borrow a book\n";
        cout << "3 - Return a book\n";
        cout << "4 - Exit\n";
        cout << "Choose an option: ";
menu:
        cin >> choice;
        switch (choice)
        {
        case 1:
            list_books(books, availability);
            break;
        case 2:
            borrow_book(books, availability);
            break;
        case 3:
            return_book(books, availability);
            break;
        case 4:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            goto menu;
            break;
        }
    } while (choice != 4);

    return 0;
}
