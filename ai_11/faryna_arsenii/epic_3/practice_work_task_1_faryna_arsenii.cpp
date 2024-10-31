#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> book_list ({ 
    "1. 1984",
    "2. Harry Potter and the Goblet of Fire",
    "3. Footprints on the road",
    "4. The Catcher in the Rye",
    "5. Wuthering Heights",
    "6. Fight Club",
    "7. Fahrenheit 451", 
});

vector<bool> available_books({ false, true, false, true, false, true, false });

int main() {
    int option;
    char choice;
    int choosen_book;

    do {
        while (true) {
        MainMenu:
            cout << "1. Enumerate all books\n";
            cout << "2. Allow to take book if it is available\n";
            cout << "3. Allow to return the book\n";
            cout << "4. Leave the library\n";
            cout << "Choose an option: ";
            cin >> option;
            
            switch (option) {
                case 1:
                    cout << "Here is your list of books:" << endl;
                    for (const auto& book : book_list) {
                        cout << book << endl;
                    }
                    cout << "----------------------------------------------------" << endl;
                    break;
                
                case 2:
                cout << "Available books:" << endl;
                for (int i = 0; i < book_list.size(); i++) {
                    if (available_books[i]) {
                        cout << book_list[i] << endl;
                    }
                }
                
                while (true) {
                    cout << "Enter the number of the book you want to take: ";
                    cin >> choosen_book;
                    
                    // Check index validity
                    if (choosen_book < 1 || choosen_book > book_list.size()) {
                        cout << "Invalid number. Please choose a valid book number." << endl;
                        continue;
                    }

                    if (available_books[choosen_book - 1]) {
                        available_books[choosen_book - 1] = false; 
                        cout << "Thank you for choosing our library!" << endl;
                        break;
                    } else {
                        cout << "This book is currently borrowed. Please choose another book." << endl;
                    }
                }
                cout << "----------------------------------------------------" << endl;
                break;

                case 3:
                    int index;
                    cout << "Enter the number of the book you want to return: ";
                    cin >> index;

                    // Check index validity
                    if (index < 1 || index > book_list.size()) {
                        cout << "We don't have this book, please enter a correct number." << endl;
                    } else if (available_books[index - 1]) {
                        cout << "This book is already in the library!" << endl;
                    } else {
                        available_books[index - 1] = true;
                        cout << "Thank you for returning the book!" << endl;
                    }
                    cout << "----------------------------------------------------" << endl;
                    break;

                case 4:
                    cout << "See you next time in our library!" << endl;
                    return 0;

                default:
                    cout << "You chose the wrong option, please try again." << endl;
                    goto MainMenu;
            }
            break;
        }

        cout << "Would you like to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}
