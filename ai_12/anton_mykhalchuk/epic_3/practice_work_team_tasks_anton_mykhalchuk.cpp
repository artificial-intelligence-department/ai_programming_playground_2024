#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main()
{
    char choice;
    string books[10] = {"1984", "To Kill a Mockingbird", "The Great Gatsby", "Moby-Dick", "Pride and Prejudice",
                        "The Catcher in the Rye", "Brave New World", "Kobzar", "Taras Bulba", "The Hobbit"};
    bool bookAvailability[10] = {true, true, true, true, true, true, true, true, true, true};
    int borr, ret;
    bool continueOperation;

    mainMenu:

    while (choice != 'q')
    {
        continueOperation = true;
        cout << "Choose what you want to do in library ('b' for borrowing, 'r' for returning, 'e' for enumerating, 'q' for quitting): ";
        cin >> choice;
        switch (choice)
        {
        case 'b':
        {
            do
            {
                cout << "Write index number of book that you want to borrow, or '100' for returning to menu: ";
                cin >> borr;
                if (borr >= 0 && borr < 10)
                {
                    if (bookAvailability[borr])
                    {
                        bookAvailability[borr] = false;
                        cout << "You have borrowed \"" << books[borr] << "\"." << endl;
                    }
                    else
                    {
                        cout << "The book \"" << books[borr] << "\" is already borrowed." << endl;
                    }
                }
                else if (borr == 100)
                {
                    continueOperation = false;
                }
                else
                {
                    cout << "Invalid book index!" << endl;
                }
            } while (continueOperation);
            break;
        }

        case 'r':
        {
            do
            {
                cout << "Write index number of book that you want to return or '100' for returning to menu: ";
                cin >> ret;
                if (ret >= 0 && ret < 10)
                {
                    if (!bookAvailability[ret])
                    {
                        bookAvailability[ret] = true;
                        cout << "You have returned \"" << books[ret] << "\"." << endl;
                    }
                    else
                    {
                        cout << "The book \"" << books[ret] << "\" was not borrowed." << endl;
                    }
                }
                else if (ret == 100)
                {
                    continueOperation = false;
                }
                else
                {
                    cout << "Invalid book index!" << endl;
                }
                break;
            } while (continueOperation);
            break;
        }

        case 'e':
            for (int i = 0; i < 10; i++)
            {
                cout << "Book \"" << books[i] << "\" with index " << i << " is ";
                if (bookAvailability[i])
                    cout << "available" << endl;
                else
                    cout << "not available!" << endl;
            }

        case 'q':
            cout << "See you later!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
            goto mainMenu;
            break;
        }
    }
}
