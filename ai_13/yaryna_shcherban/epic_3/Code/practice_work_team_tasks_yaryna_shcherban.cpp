#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<string> books = {
                            "Divine Rivals", 
                            "Once upon a broken heart", 
                            "Powerless", 
                            "Shatter me", 
                            "Fourth wing", 
                            "The Atlas Six", 
                            "King of wrath", 
                            "Endgame", 
                            "Twisted games", 
                            "The Silent Patient" };

    
    vector<bool> available(books.size(), true);
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. View books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "List of books:\n";
            for (size_t i = 0; i < books.size(); ++i) {
                cout << i + 1 << ". " << books[i];
                if (available[i]) {
                    cout << " (Available) ";
                } else {
                    cout << " (Unavailable) ";
                }
                cout << "\n";
            }

        } else if (choice == 2 || choice == 3) {

            int bookNumber;
            cout << "Enter the book number: ";
            cin >> bookNumber;

            if (bookNumber < 1 || bookNumber > books.size()) {
                cout << "Incorrect book number. Try again.\n";
                continue;
            }

            bool isAvailable = available[bookNumber - 1];

            if (choice == 2 && isAvailable) {

                available[bookNumber - 1] = false;
                cout << "You took the book: " << books[bookNumber - 1] << "\n";
            } 
            else if (choice == 3 && !isAvailable) {

                available[bookNumber - 1] = true;
                cout << "You returned the book: " << books[bookNumber - 1] << "\n";
            } 
            else {
                if (choice == 2) {
                    cout << "The book is unavailable.\n";
                } else {
                    cout << "The book is already in the library.\n";
                }
            }

        } else if (choice != 4) {
            cout << "Wrong choice. Try again.\n";
        }
        
    } while (choice != 4);

    cout << "The program is complete.\n";
    return 0;
}