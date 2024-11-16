#include <iostream>
#include <string>

using namespace std;

void List_of_books(string Books[10])
{
    cout << "List of books: " << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ". " << Books[i] << endl;
    }
}

bool Operations_with_books(bool availability[10], string Books[10], int choice, int num, int continuation)
{
    operations:
    cout << "What operation would you like to perform?" << endl << "1 - take a book" << endl;
    cout << "2 - return a book" << endl << "Your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "What book would you like to take?" << endl;
            cin >> num;

            num = num - 1;

            if (availability[num] == 1)
            {
                cout << "You took a book " << Books[num] << endl;
                availability[num] = 0;
            }
            else
            {
                cout << "We don't have book " << Books[num] << " at the moment" << endl;
            }
            break;
        
        case 2:
            cout << "What book would you like to return?" << endl;
            cin >> num;

            num = num - 1;

            if (availability[num] == 0)
            {
                cout << "You returned book " << Books[num] << endl;
                availability[num] = 1;
            }
            else
            {
                cout << "We have book " << Books[num] << " already" << endl;
            }
            break;
        
        defaulf:
            break;
    }

    cout << "Would you like to perform any other operation?" << endl << "1 - yes" << endl << "2 - no" << endl << "Your choice: " << endl;
    cin >> continuation;

    switch (continuation)
    {
        case 1:
            goto operations;
            break;
        default:
            return availability;
    }
}

int main()
{
    string books[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    bool avail[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int choice;
    int op_choice;
    int number;
    int cont;

    do
    {
    menu:
        cout << "menu:" << endl << "1) main menu" << endl << "2) list of books" << endl;
        cout << "3) operations with books" << endl << "0) exit" << endl << "Your choice: " << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
                goto menu;
                break;
            case 2:
                List_of_books(books);
                break;
            case 3:
                Operations_with_books(avail, books, op_choice, number, cont);
                break;
            default:
                return 0;
        }
    }
    while (choice != 0);
    
}