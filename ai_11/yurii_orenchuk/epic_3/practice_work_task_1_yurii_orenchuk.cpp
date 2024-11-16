#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main(){
    vector<string> books = {"C++ for dummies", "Hatchet", "Dune", "The Alchemist", "Fahrenheit 451"};
    vector<bool> available(books.size(), true);
    bool exit;
    int choose;

    while(!exit){   
    menu:
        cout << "-----Library-----\n";
        cout << "1. List all books\n";
        cout << "2. List book availability\n";
        cout << "3. Borrow a book\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choose;


        switch (choose) {
            case 1:
                for(int i = 0; i < books.size(); i++){
                    cout << i+1 << ". " << books[i] << endl;
                }
                break;

            case 2:
                for(bool i : available){
                    if(i == 0) cout << "NO\n";
                    else cout << "YES\n";
                }
                break;

            case 3:
                int borrow;
                cout << "Choose the book you want to borrow: ";
                cin >> borrow;
                if(borrow > 0 && borrow <= available.size()){
                    if(available[borrow-1]){
                        available[borrow-1] = false;
                        cout << "You have borrowed this book\n";
                    } else 
                    cout << "Sorry, this book isnt available\n";
                } else 
                cout << "Please choose a valid number\n";
                break;

            case 4:
                int returns;
                cout << "Choose the book you want to return: ";
                cin >> returns;
                if(returns > 0 && returns <= available.size()){
                    if(!available[returns-1]){
                        available[returns-1] = true;
                        cout << "You have returned this book\n";
                    } else 
                    cout << "This book wasn't even borrowed!\n";
                } else 
                cout << "Please choose a valid number\n";
                break;

            case 5:
                cout << "We hope you enjoyed your stay!";
                exit = true;
                break;

            default:
                cout << "Please enter a valid number (1, 2, 3, 4 or 5)" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                goto menu;
        }

    }

    return 0;
}