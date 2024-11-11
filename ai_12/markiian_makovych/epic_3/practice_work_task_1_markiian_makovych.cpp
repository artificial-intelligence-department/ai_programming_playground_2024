#include <iostream>
#include <string>
using namespace std;

int main()
{
    string books[] = {"Book1", "Book2", "Book3"};

    string status;
    string bookTake, bookGive;
    string choice;
    for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++)
    {
        cout << books[i] << endl;
    }
    do
    {
    start:
        cout << "Do you want to take or return?" << endl;
        cin >> choice;
        if (choice == "take")
        {
            cout << "Pick a book" << endl;
            for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++)
            {
                cout << books[i] << endl;
            }
            cin >> bookTake;
            for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++)
            {
                if (bookTake == books[i])
                {
                    books[i] = "Empty";
                };
            };
        };
        if (choice == "return")
        {
            cout << "Which book are you returning?" << endl;
            cin >> bookGive;
            for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++)
            {
                if (books[i] == "Empty")
                {
                    books[i] = bookGive;
                    break;
                }
            }
        }

        for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++)
        {
            cout << books[i] << endl;
        }

        cout << "If you want to exit type (end), If you want to go to menu type (start)" << endl;

        cin >> status;
        if (status == "start")
            goto start;
    } while (status != "end");

    return 0;
}