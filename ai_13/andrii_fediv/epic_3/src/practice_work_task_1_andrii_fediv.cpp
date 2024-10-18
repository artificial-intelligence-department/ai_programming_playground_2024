#include <iostream>
#include <vector>
#include <string>

using namespace std;

void listB(vector<string> B, vector<bool> av)
{
    cout << "Book List:\n";
    for (size_t i = 0; i < B.size(); ++i)
    {
        cout << i + 1 << ". " << B[i] << " - " << (av[i] ? "avaible" : "Borrowed") << endl;
    }
}

void useB(vector<string> B, vector<bool> av, bool action)
{
    int i;
    cout << "Enter the book number you want to " << action? "borrow: " : "return: ";
    cin >> i;
    if (i < 1 || i > B.size() || !av[i - 1])
    {
        cout << "Invalid choice or book not " << action? "avaible.\n" : "borrowed.\n";
    }
    else
    {
        av[i - 1] = !action;
        cout << "You " << (action? "borrowed" : "returned") << " the book: " << B[i - 1] << endl;
    }
}

int main()
{
    vector<string> B = {"The Great Gatsby", "1984", "To Kill a Mockingbird", "The Catcher in the Rye"};
    vector<bool> av = {true, true, true, true};

    int choice;
main_menu:
    do
    {
        cout << "\nMenu(enter number):\n1. List all books\n2. Borrow a book\n3. Return a book\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            listB(B, av);
            break;
        case 2:
            useB(B, av, 1);
            break;
        case 3:
            useB(B, av, 0);
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            goto main_menu; // Використання goto
        }

    } while (choice != 4);

    return 0;
}
