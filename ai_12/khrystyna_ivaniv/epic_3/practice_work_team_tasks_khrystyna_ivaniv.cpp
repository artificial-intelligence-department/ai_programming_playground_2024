#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> list_of_books({
    "1. From blood and ash",
    "2. Fourth wing",
    "3. Stalking Jack the Ripper",
    "4. A court of thorns and roses",
    "5. Invisible life of addie larue",
    "6. Shadow of the fox",
    "7. Powerless",
    "8. A five-minute life",
    "9. The cruel prince",
    "10. Kingdom of the cursed",
});

vector<bool> available_books({
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
});

int main()
{

    for (int i = 0; i < 10; i++)
    {
        cout << list_of_books[i] << endl;
    }

    bool next_choice = true;
    int choice;
    int number = 0;
    bool inside = 0;
    int keep_exploring = 0;
    int output_list = 0;
try_again:
    cout << "Would you like to enter the library? " << endl
         << "enter 1 if you want to;" << endl
         << "enter 0 if you do not;" << endl;
    cin >> keep_exploring;
    cout << endl;

    switch (keep_exploring)
    {
    case 1:
        inside = true;
        break;
    case 0:
        inside = false;
        break;
    default:
        cout << "Try choosing an option again!" << endl;
        goto try_again;
        break;
    }

    while (inside)
    {
    try_again_2:
        cout << "Would you like to see the list?" << endl
             << "enter 1 if yes" << endl
             << "enter 2 if no" << endl
             << "enter 0 if you want to exit a library" << endl;
        cin >> output_list;
        cout << endl;
        switch (output_list)
        {
        case 1:
            for (string list : list_of_books)
            {
                cout << list << endl;
            }
            cout << endl;
            break;
        case 2:
            break;
        case 0:
            inside = false;
            break;
        default:
            cout << "Try another choice!" << endl;
            goto try_again_2;
        }
        if (!inside)
        {
            break;
        }

        do
        {
            cout << "If you want to take the book - enter 1," << endl
                 << "If you want to return the book - enter 2," << endl
                 << "if you want to stop - enter 0" << endl;
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                cout << "enter the number of the book you would like to take: " << endl;
                cin >> number;
                if (available_books[number - 1])
                {
                    available_books[number - 1] = false;
                    cout << "You've taken the book: " << list_of_books[number - 1] << endl;
                    cout << endl;
                }
                else
                {
                    cout << "this book has already been taken!" << endl;
                    cout << endl;
                }
                break;
            case 2:
                cout << "enter the number of the book you would like to return:" << endl;
                cin >> number;
                cout << endl;
                if (!available_books[number - 1])
                {
                    available_books[number - 1] = true;
                    cout << "You've returned the book: " << list_of_books[number - 1] << endl;
                    cout << endl;
                }
                else
                {
                    cout << "this book has not been taken!" << endl;
                    cout << endl;
                }
                break;
            case 0:
                next_choice = false;
                break;
            default:
                cout << "Looks like you typed something wrong(" << endl;
            }
        } while (next_choice);
    }
    cout << "Thank you for visiting my library!" << endl;
    return 0;
}