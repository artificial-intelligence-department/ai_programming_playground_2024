#include <iostream>
#include <vector>

using namespace std;

int main(){
vector<string> bookNames = {"Book1", "Book2", "Book3", "Book4"};
vector<bool> isAvaliable(bookNames.size(), true);

bool exit = false;
int takeChoice = 0;
int returnChoice = 0;

while (!exit){

int option = 0;

MainMenu:
cout << "Main menu.\n" << "1) list all books\n" << "2) take a book\n" << "3) return a book\n" << "4) exit\n";


cin >> option;

switch (option){

    case 1:
        
        for (int i = 0; i < 4; i++){
            
            cout << i+1 << ") \"" << bookNames[i] << "\"" << " ";

            if (isAvaliable[i]){
                cout << "avaliable\n" << endl;
            }
            
            else{
                cout << "unavaliable\n" << endl;
            }
        }

        break;

    case 2:

        TakeBook:

        cout << "Enter the number of book you would like to take:\n(from 1 to 4)\n";

        cin >> takeChoice;

        if (takeChoice > 0 && takeChoice < 5){
            if (isAvaliable[takeChoice-1]) {
                cout << "You have successfuly borrowed the book \"" << bookNames[takeChoice-1] << "\"!\n\n";
                isAvaliable[takeChoice-1] = 0;
            }

            else {
                cout << "You have already borrowed the book \"" << bookNames[takeChoice-1] << "\"!\n\n";
            }
        }

        else {
            cout << "Incorrect input!\n\n";

            goto TakeBook;
        }

        break;

    case 3:

        ReturnBook:

        cout << "Enter the number of book you would like to return:\n(from 1 to 4)\n";

        cin >> returnChoice;

        if (returnChoice > 0 && returnChoice < 5){
            if (!isAvaliable[returnChoice-1]) {
                cout << "You have successfuly returned the book \"" << bookNames[returnChoice-1] << "\"!\n\n";
                isAvaliable[returnChoice-1] = 1;
            }

            else {
                cout << "The library already contains the book \"" << bookNames[returnChoice-1] << "\"!\n\n";
            }

        }

         else {
            cout << "Incorrect input!\n\n";

            goto ReturnBook;
        }

        break;
    case 4:

        cout << "exiting the program!\n";

        exit = true;

        break;

    default:
        
        cout << "Incorrect input!\n";

        goto MainMenu;
        
        break;
}

if (exit) {
    break;
}

char otherOps;

do {

    cout << "Do you want to perform any other operations? (y/n)\n";

    cin >> otherOps;

    if (otherOps == 'n' || otherOps == 'N'){
        exit = true;
    }

    break;

} while (otherOps != 'n' && otherOps != 'N' && otherOps != 'y' && otherOps != 'Y');

}
    
return 0;
}