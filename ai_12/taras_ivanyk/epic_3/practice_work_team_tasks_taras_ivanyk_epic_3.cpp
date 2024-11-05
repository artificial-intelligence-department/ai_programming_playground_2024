#include <iostream>
#include <vector>
#include <string>

using namespace std;

void showMenu() {
    cout << "***** MENU *****" << endl;
    cout << "1. Enumerate all books" << endl;
    cout << "2. Borrow a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. EXIT" << endl;
}

void listBooks(const vector<string>& books, const vector<bool>& available) {
    cout << "List of books: " << endl;
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i] << (available[i] ? " (available)" : " (not available)") << endl;
    }
}

void borrowBook(vector<bool>& available) {
    cout << "Enter a number of the book you want to borrow: " << endl; 
    int bookNumber;
    cin >> bookNumber;

    if (bookNumber < 1 || bookNumber > available.size() || !available[bookNumber - 1]) {
        cout << "Book is not available or you entered the wrong number." << endl;
        return;
    }

    available[bookNumber - 1] = false; 
    cout << "You borrowed a book." << endl;
}

void returnBook(vector<bool>& available) {
    cout << "Enter a number of the book you want to return: " << endl;
    int bookNumber;
    cin >> bookNumber;

    if (bookNumber < 1 || bookNumber > available.size() || available[bookNumber - 1]) {
        cout << "Book wasn't borrowed or you entered a wrong number." << endl;
        return;
    }

    available[bookNumber - 1] = true; 
    cout << "You returned a book." << endl;
}

int main() {
    vector<bool> available = {true, true, true, true, true};
    vector<string> books = {"Harry Potter", "Sword of King Arthur", "Gentlemen", "El Camino", "Bad Boys"};

    int choice;
    
    while (true) { 
        showMenu();
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listBooks(books, available);
                break;
            case 2:
                borrowBook(available);
                break;
            case 3:
                returnBook(available);
                break;
            case 4:
                cout << "Thank you, for using our library, see you)" << endl;
                return 0; 
            default:
                cout << "Incorrect choice, try again!" << endl;
                continue; 
        }
        cout << "Do you want to do another operation? (1 - yes, 0 - no): ";
        int continueChoice;
        cin >> continueChoice;

        if (continueChoice != 1) { 
            break;
        }
    }
    return 0;
}
