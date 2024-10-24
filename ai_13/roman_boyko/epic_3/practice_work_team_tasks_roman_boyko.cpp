#include <iostream>
#include <string>
#include "stdio.h"
using namespace std;
const int maxSize = 100;
string books[maxSize] = {"Harry Potter",
                         "To Kill a Mockingbird",
                         "Pride and Prejudice",
                         "1984",
                         "Jane Eyre",
                         "The Catcher in the Rye",
                         "The Lord of the Rings"};

bool avail[] = {true, true, true, true, true, true, true};
void listBooks();
void borrowBooks();
void returnBooks();
int main()
{

    int ch;
    do
    {
        char a;
        cout << "Library Menu\n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "Enter your choice: ";
        cin >> ch;
        if (ch == 1)
        {
            listBooks();
        }
        else if (ch == 2)
        {
            borrowBooks();
        }
        else if (ch == 3)
        {
            returnBooks();
        }
        else
        {
            cout << "Invalid choice!" << endl;
            goto menu;
        }

        cout << "Do you want to choose another operation? (y/n): ";
        cin >> a;
        if (a != 'y')
        {
            break;
        }
    menu:
    } while (true);
}

void listBooks()
{
    for (int i = 0; i < maxSize; i++)
    {
        if (!books[i].empty())
        {
            cout << "Book " << i + 1 << ": " << books[i] << " -- ";
            if (avail[i])
            {
                cout << " is available!" << endl;
                continue;
            }
            else
            {
                cout << " is not available" << endl;
                continue;
            }
        }
    }
}

void borrowBooks()
{
    int k;
    cout << "Enter book number you want to borrow: ";
    cin >> k;
    if (avail[k - 1])
    {
        cout << "You borrowed the book: " << books[k - 1] << endl;
        avail[k - 1] = false;
    }
    else
    {
        cout << "The book is already borrowed!" << endl;
    }
}

void returnBooks()
{
    int k;
    cout << "Enter book number you want to return: ";
    cin >> k;
    if (!avail[k - 1])
    {
        cout << "You returned the book: " << books[k - 1] << endl;
        avail[k - 1] = true;
    }
    else
    {
        cout << "The book is already in the library!" << endl;
    }
}