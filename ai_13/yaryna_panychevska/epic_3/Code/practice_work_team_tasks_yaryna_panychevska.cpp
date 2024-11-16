#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string Book;
    int operation;
    char UsrInp;
    string operations[4] = {
        "Exit",
        "Check the list",
        "Return a book",
        "Borrow a book"
    };
    vector <string> Library = { "1984 - George Orwell", "Pride and Prejudice - Jane Austen", "The Great Gatsby - F. Scott Fitzgerald" };
main_menu:
    while (true)
    {
        cout << "\nWelcome to the library! What would you like to do?\n";
        for (int i = 0; i < 4; ++i)
        {
            cout << i << ". " << operations[i] << endl;
        }
        cout << "Please, enter operation: ";
        cin >> operation;
        if (operation == 0)
        {
            cout << "Exiting..." << endl;
            break;
        }
        do {
            if (operation == 1)
            {
                cout << "The current list of books: " << endl;
                for (int i = 0; i < Library.size(); ++i)
                {
                    cout << i + 1 << ". " << Library[i] << endl;
                }
            }
            else if (operation == 2)
            {
                cout << "Type the name of book you want to return (example: 1984 - George Orwell): " << endl;
                cin.ignore();
                getline(cin, Book);
                Library.push_back(Book);
                cout << "You returned book to the library.\n";
            }
            else if (operation == 3) {
                cout << "Type the book you want to borrow (example: 1984 - George Orwell): " << endl;
                cin.ignore();
                getline(cin, Book);

                bool existence = false;
                for (const auto& book : Library)
                {
                    if (book == Book)
                    {
                        existence = true;
                        break;
                    }
                }
                if (existence) {
                    auto it = find(Library.begin(), Library.end(), Book);
                    if (it != Library.end()) {
                        Library.erase(it);
                        cout << "You took the book: " << Book << endl;
                    }
                }
                else {
                    cout << "The book [ " << Book << " ] was not found in the library." << endl;
                }
            }
            else {
                cout << "Invalid input. Returning no main menu.";
                goto main_menu;
            }

            cout << "\nWould you like to perform another operation? (Y/N)";
            cin >> UsrInp;
            if (UsrInp == 'N' || UsrInp == 'n')
            {
                cout << "Thanks for visiting!" << endl;
                return 0;
            }
            else
            {
                goto main_menu;
            }
        } while (UsrInp == 'Y' || UsrInp == 'y');
    }
    return 0;
}