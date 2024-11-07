#include <iostream>
#include <vector>
using namespace std;

void listAllofEm(vector<string> &books, vector<bool> &bookavailability);
void borrowAbook(vector<string> &books, vector<bool> &bookavailability);
void returnAbook(vector<string> &books, vector<bool> &bookavailability);

int main()
{
    int option;
    int continuee;
    vector<string> books={"booknum1", "booknum2", "booknum3", "booknum4", "booknum5"};
    vector<bool> bookavailability(books.size());
    for (int i=0; i<books.size(); i++)
    {
        bookavailability[i]=true;
    }
    while (true)
    {
        options:
            cout << "\nYou are currently in a library. What would you like to do?" << endl;
            cout << "1 - list all books." << endl;
            cout << "2 - borrow a book." << endl;
            cout << "3 - return a book." << endl;
            cout << "4 - leave." << endl;
            cin >> option;
            switch (option)
            {   
                case 1:
                listAllofEm (books, bookavailability);
                break;
                case 2:
                borrowAbook (books, bookavailability);
                break;
                case 3:
                returnAbook (books, bookavailability);
                break;
                case 4:
                cout << "Thank you for visiting the library!" << endl;
                return 0;
                default:
                cout << "You chose an option that doesn't exist, try again!" << endl;
                goto options;
            }
            do
            {
                cout << "Anything else? (1 - y, 0 - n)" << endl;
                cin >> continuee;
                if (continuee==0)
                {
                    cout << "Thank you for visiting the library!" << endl;
                    return 0;
                }
            } while (continuee!=1);
    }
}

void listAllofEm(vector<string> &books, vector<bool> &bookavailability)
{
    int j = 0;
    cout << "Available books: " << endl;
    for (bool i : bookavailability)
    {
        if (i)
        {
            cout << books[j] << endl;
        }
        j++;
    }
    j = 0;
    cout << "Unavailable books: " << endl;
    for (bool i : bookavailability)
    {
        if (!i)
        {
            cout << books[j] << endl;
        }
        j++;
    }
}

void borrowAbook(vector<string> &books, vector<bool> &bookavailability)
{
    int num;
    int j = 0;
    cout << "Available books: " << endl;
    for (bool i : bookavailability)
    {
        if (i)
        {
            cout << j+1 << ". " << books[j] << endl;
        }
        j++;
    }
    borrowing:
        cout << "Which book would you like to borrow?" << endl;
        cin >> num;
        if (bookavailability[num-1])
        {
            cout << "You got the " << books[num-1] << " book!" << endl;
            bookavailability[num-1]=false;
        }
        else
        {
            cout << "That book isn't available." << endl;
            goto borrowing;
        }
}

void returnAbook(vector<string> &books, vector<bool> &bookavailability)
{
    int num;
    int j = 0;
    cout << "Borrowed books: " << endl;
    for (bool i : bookavailability)
    {
        if (!i)
        {
            cout << j+1 << ". " << books[j] << endl;
        }
        j++;
    }
    returning:
        cout << "Which book would you like to return?" << endl;
        cin >> num;
        if (!bookavailability[num-1])
        {
            cout << "You returned the " << books[num-1] << " book!" << endl;
            bookavailability[num-1]=true;
        }
        else
        {
            cout << "You aren't borrowing that book or it doesn't exist." << endl;
            goto returning;
        }
}
