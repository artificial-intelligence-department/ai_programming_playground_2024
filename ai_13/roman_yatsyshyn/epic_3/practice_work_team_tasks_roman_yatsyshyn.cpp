#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string books[5] = {"To Kill a Mockingbird",
                    "1984",
                    "Harry Potter and the Philosopher\'s Stone",
                    "Pride and Prejudice",
                    "The Great Gatsby"};

int status[5] = {1, 1, 1, 1, 1};

int _SIZE = sizeof(books) / sizeof(books[0]);

void recount(){
    // for each loop
    int a = 0;

    for (int i : status)
    {
        if (i == 1)
        {
            cout << a+1 << ") " << books[a] << " – доступна\n"; a--;
        }
        else
        {
            cout << a+1 << ") " << books[a] << " – НЕдоступна\n"; a--;
        }

        a++;
    }
}

void listofbooks(){
    cout << "\n";
    for (int i = 0; i < _SIZE; i++)
    {
        cout << i+1 << ") " << books[i] << "\n";
    }
    cout << "\n";
}

void borrowbook(){
    int idx_b = 0;
    listofbooks();
    cout << "What book (from 1 to " << _SIZE << ") you want to borrow?\n";
    cin >> idx_b;
    if (status[idx_b-1] == 1)
    {
        status[idx_b-1] = 0;
        cout << "The book is yours!\n\n";
    }
    else{
        cout << "Sorry, the book is taken!\n\n";
    }
}

void returnbook(){
    int idx_r = 0;
    // int borrowed = 0;
    for (int i = 0; i < _SIZE; i++)
    {
        if (status[i] == 0){
            cout << i+1 << ") " << books[i] << "\n";
        }
    }
    cout << "What book you want to return?\n";
    cin >> idx_r;
    status[idx_r-1] = 1;
    cout << "Thank you for your return\n";
}

int main(){
main_menu:
    char new_option = 'a'; // (y/n) of new command
    bool yes_new = 1; // boolean of new command
    char exit_option = 'a'; // (y/n) of exit
    bool no_exit = 1; // boolean of while(exit)

    // while
    while (no_exit)
    {
        int option_status = 0; // switch expression

        // do while
        do{
            cout << "What do you want me to do? (option 1-3)\n";
            cout << "1) List of books.\n2) Take a book.\n3) Return a book.\n";
            cin >> option_status;

            switch (option_status)
            {
            case 1:
                listofbooks();
                break;
            case 2:
                borrowbook();
                break;
            case 3:
                returnbook();
                break;
            default:
                cout << "Wrong input!\n";
                goto main_menu;
                break;
            }

        new_command_label:
            cout << "Any other commands? (y/n)\n";
            cin >> new_option;

            if (new_option == 'y'){yes_new = 1;}
            else if (new_option == 'n'){yes_new = 0;}
            else{cout << "Wrong option\n"; goto new_command_label;}
            
            
        }
        while(yes_new);

    exit_label:
        cout << "Want to exit? (y/n)\n";
        cin >> exit_option;

        if (exit_option == 'y'){no_exit = 0;}
        else if (exit_option == 'n'){no_exit = 1;}
        else{cout << "Wrong option\n"; goto exit_label;}      
    }
    cout << "Bye for now!";
}
