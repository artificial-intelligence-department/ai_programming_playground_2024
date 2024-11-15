#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ShowBooks(const vector<string>& library, const vector<bool>& status)
{
    cout << "Available Books:\n";
    for (int i = 0; i < library.size(); ++i) 
    {
        cout << i + 1 << ". " << library[i] << " - " << (status[i] ? "Available" : "Not available") << endl;
    }
}

void TakeBook(vector<bool>& status)
{
    int bookID;
    cout << "Enter the book number you want to borrow: ";
    cin >> bookID;
    if (bookID > 0 && bookID <= status.size() && status[bookID - 1])
    {
        status[bookID - 1] = false;
        cout << "You have successfully borrowed the book.\n";
    }
    else
    {
        cout << "Invalid number or the book is unavailable.\n";
    }
}

void GiveBackBook(vector<bool>& status)
{
    int bookID;
    cout << "Enter the book number you want to return: ";
    cin >> bookID;
    if (bookID > 0 && bookID <= status.size() && !status[bookID - 1])
    {
        status[bookID - 1] = true;
        cout << "Thank you for returning the book.\n";
    }
    else
    {
        cout << "Invalid number or the book was not borrowed.\n";
    }
}

int main()
{
    vector<string> library = {"Book 1", "Book 2", "Book 3", "Book 4", "Book 5"};
    vector<bool> status(library.size(), true);
    char selection;

    do
    {
        mainMenu:
        cout << "Welcome to the Library System\n";
        cout << "1. Display all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> selection;

        switch (selection)
        {
            case '1':
                ShowBooks(library, status);
                break;
            case '2':
                TakeBook(status);
                break;
            case '3':
                GiveBackBook(status);
                break;
            case '4':
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid selection, try again.\n";
                goto mainMenu;
        }

    bool validInput = false;
        while (!validInput) {
            cout << "Would you like to perform another action? (y/n): ";
            cin >> selection;

            if (selection == 'y' || selection == 'Y') {
                validInput = true;
            } else if (selection == 'n' || selection == 'N') {
                validInput = true;
                cout << "Exiting the system.\n";
            } else {
                cout << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";
            }
        }
    } while (selection == 'y' || selection == 'Y');

    return 0;
}

