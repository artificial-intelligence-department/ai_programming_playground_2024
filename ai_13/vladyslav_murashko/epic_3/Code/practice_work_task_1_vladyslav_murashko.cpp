#include <iostream>
#include <vector>

using namespace std;

void showBooksList(const vector<string> &books)
{
    cout << "\n\n___Books list___\n";
    for (size_t i = 0; i < books.size(); i++)
    {
        cout << "| " << books[i] << " | ";
        if ((i + 1) % 4 == 0)
        {
            cout << endl;
        }
    }
}

bool showBooksAvailability(const vector<string> &books, const vector<bool> &booksAvailability, bool isAvaliable)
{
    cout << "\n\n___" << (isAvaliable ? "Available" : "Borrowed") << " books list___\n";
    int count = 0;
    int i = 0;
    for (auto &book : books)
    {
        if (booksAvailability[i] == isAvaliable)
        {
            cout << i + 1 << ": " << book << endl;
            count++;
        }
        i++;
    }
    if (count == 0)
    {
        return false;
    }
    return true;
}

void borrowBook(const vector<string> &books, vector<bool> &booksAvailability)
{
    if (!showBooksAvailability(books, booksAvailability, true))
    {
        cout << "\nWe currently don`t have any available books for you :(\n";
        return;
    }
    int answ;
borrow_input:
    try
    {
        cout << "\nSelect the number of the available book: ";
        cin >> answ;
        if (!booksAvailability[answ - 1])
        {
            throw answ;
        }
        booksAvailability[answ - 1] = false;
    }
    catch (...)
    {
        cout << "\nWrong input! Try again\n";
        goto borrow_input;
    }
    return;
}

void returnBook(const vector<string> &books, vector<bool> &booksAvailability)
{
    if (!showBooksAvailability(books, booksAvailability, false))
    {
        cout << "\nYou don`t have any borrowed books!\n";
        return;
    }
    int answ;
return_input:
    try
    {
        cout << "\nSelect the number of the borrowed book: ";
        cin >> answ;
        if (booksAvailability[answ - 1])
        {
            throw answ;
        }
        booksAvailability[answ - 1] = true;
    }
    catch (...)
    {
        cout << "\nWrong input! Try again\n";
        goto return_input;
    }
    return;
}

int main()
{
    vector<string> books{"book1", "book2", "book3", "book4"};
    vector<bool> booksAvailability(books.size());
    for (int i = 0; i < books.size(); i++)
    {
        booksAvailability[i] = true;
    }

    int answ;

    while (true)
    {

    input:
        cout << "\nSelect one of the given options by entering the corresponding number:";
        cout << "\n1 - borrow a book";
        cout << "\n2 - return a book";
        cout << "\n3 - list the books\n";
        cin >> answ;
        switch (answ)
        {
        case 1:
            borrowBook(books, booksAvailability);
            break;
        case 2:
            returnBook(books, booksAvailability);
            break;
        case 3:
            showBooksList(books);
            break;
        default:
            cout << "\nWrong input! Try again\n";
            goto input;
        }
        do
        {
            cout << "\nDo you want to do something else? (1 - yes, 0 - no)\n";
            cin >> answ;
            if (answ == 0)
            {
                return 0;
            }
        } while (answ != 1);
    }

    return 0;
}
