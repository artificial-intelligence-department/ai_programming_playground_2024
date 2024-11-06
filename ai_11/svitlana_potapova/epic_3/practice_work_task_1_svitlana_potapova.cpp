#include <iostream>
#include <vector>
using namespace std;

void show_books(vector<string>& books, vector<bool>& available, int amount){
    for (int i=0; i<amount; i++){
        if(available[i] == 1){
            cout << books[i] << endl;
        }
    }
}
void take_book(vector<string>& books, vector<bool>& available, int book_choice, int amount){
    cout << "which book do you want to take?" << endl;
    input:
    cin >> book_choice;
    if(book_choice<1 || book_choice>amount){
        cout << "Wrong input. Try again.";
        goto input;
    }
    else if(available[book_choice-1]!= 1){
        cout << "Sorry, we don`t have this book at the moment.";
    }
    else{
        available[book_choice-1] = 0;
        cout << "You`ve taken the book";
    }
}

void return_book(vector<string>& books, vector<bool>& available, int bookToReturn, int amount){
    cout << "which book do you want to return?" << endl;
    inp:
    cin >> bookToReturn;
    if(bookToReturn<1 || bookToReturn>amount){
        cout << "Wrong input. Try again." << endl;
        goto inp;
    }
    else if(available[bookToReturn-1] == 1){
        cout << "We already have this book.";
    }
    else{
        available[bookToReturn-1] = 1;
        cout << "Thank you for returning the book!";
    }
}

int main(){
    vector<string> books{
    "№1 'Gone with the Wind'",
    "№2 'The Thorn Birds'",
    "№3 'The Secret History'",
    "№4 'Pride and Prejudice'",
    "№5 'Fire and Blood'"
    };
    vector<bool> available{1,1,1,1,1};
    int amount = books.size();
    int option, book_choice, bookToReturn;
    char yn;

    while(true){
            Menu:
            cout << "Choose an option: " << endl;
            cout << "1. List all books" << endl;
            cout << "2. Take a book" << endl;
            cout << "3. Return a book" << endl;
            cout << "4. Exit" << endl;

            cin >> option;
            switch(option){
                case 1:
                show_books(books, available, amount);
                break;

                case 2:
                take_book(books, available, book_choice, amount);
                break;

                case 3:
                return_book(books, available, bookToReturn, amount); 
                break;

                case 4:
                return 0;

                default:
                cout << "Wrong input. Choose another option" << endl;
                goto Menu;
            }
            do{
                cout << "\nDo you want choose another option? (y/n): ";
                cin >> yn;
                if (yn == 'n'){
                    return 0;
                }
                else if(yn == 'y'){
                    goto Menu;
                }
                else{
                    cout << "Please write an valid answer" << endl;
                }
            }
            while(yn != 'y');
    }
}
