#include <iostream>
using namespace std;

int main() {
    string action, book, answer, 
        booksNames[5] = {"Booook", "Kobzar", "Goldfinch", "Foundation", "1984"};
    bool correctBookName, stillWorking, 
        booksAvailability[5] = {true, false, true, true, false};

    do {
        Menu:
            cout << "Available actions: \n1. View books \n2. Borrow a book \n3. Return a book \n\nWhat would you like to do?: ";
            cin >> action;
            
            if (action == "1" || action == "View books") {
                cout << "Available books: " << booksNames[0];
                for (int i = 1; i < 5; i++) cout << ", " << booksNames[i];

                cout << "\nCorresponding availability of books: ";
                for (bool i: booksAvailability) {
                    if (i == true ) cout << "available ";
                    else cout << "not available ";
                }

            } else if (action == "2" || action == "Borrow a book") {
                cout << "Which book are you interested in?: ";
                cin >> book;

                correctBookName = false;
                for (int i = 0; i < 5; i++) {
                    if (book == booksNames[i]) {
                        correctBookName = true;

                        if (booksAvailability[i] == true) {
                            cout << "*You have borrowed the book*";
                            booksAvailability[i] = false;
                        } else cout << "Unfortunately, this book is currently unavailable";
                        
                        break;
                    }
                }   

                if (!correctBookName) cout << "Invalid input";

            } else if (action == "3" || action == "Return a book") {
                cout << "Which book are you returning?: ";
                cin >> book;

                correctBookName = false;
                for (int i = 0; i < 5; i++) {
                    if (book == booksNames[i]) {
                        correctBookName = true;

                        if (booksAvailability[i] == false) {
                            cout << "*You have returned the book*";
                            booksAvailability[i] = true;
                        } else cout << "This book was not borrowed from us";

                        break;
                    }
                }  

                if (!correctBookName) cout << "Invalid input";

            } else {
                cout << "Invalid input\n\n";
                goto Menu;
            } 

            do {
                cout << "\n\nWould you like to continue operations?: ";
                cin >> answer;

                if (answer == "Yes") {
                    stillWorking = true;
                    break;

                } else if (answer == "No") {
                    stillWorking = false;
                    break;

                } else cout << "I don't understand you, try 'Yes' or 'No'";

            } while (true);

    } while (stillWorking);

    return 0;
}

