#include <iostream>
#include <vector>
#include <string>

using namespace std;

void listBooks(const vector<string>& books, const vector<bool>& availability);

void borrowBook(vector<bool>& availability);

void returnBook(vector<bool>& availability);

int main() {
    vector<string> books = {"The Great Gatsby", "1984", "To Kill a Mockingbird", "Moby-Dick", "Pride and Prejudice"};
    vector<bool> availability(books.size(), true);
    int choice;
    
    do {
    mainMenu:
        cout << "\nLibrary Management System" << endl;
        cout << "1. List all books" << endl;
        cout << "2. Borrow a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listBooks(books, availability);
                break;
            case 2:
                borrowBook(availability);
                break;
            case 3:
                returnBook(availability);
                break;
            case 4:
                cout << "Exiting the system..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                goto mainMenu;
        }

        char userCase;
        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> userCase;
        if (userCase == 'n' || userCase == 'N') break;
        
    } while (true);

    return 0;
}

void returnBook(vector<bool>& availability) {
    int index;
    cout << "\nEnter the number of the book you want to return: ";
    cin >> index;
    if (index > 0 && index <= availability.size()) {
        if (!availability[index - 1]) {
            availability[index - 1] = true;
            cout << "Book successfully returned!\n";
        } else {
            cout << "This book was not borrowed.\n";
        }
    } else {
        cout << "Invalid book number." << endl;
    }
}

void borrowBook(vector<bool>& availability) {
    int index;
    cout << "\nEnter the number of the book you want to borrow: ";
    cin >> index;
    if (index > 0 && index <= availability.size()) {
        if (availability[index - 1]) {
            availability[index - 1] = false;
            cout << "Book successfully borrowed!" << endl;
        } else {
            cout << "This book is already borrowed." << endl;
        }
    } else {
        cout << "Invalid book number." << endl;
    }
}

void listBooks(const vector<string>& books, const vector<bool>& availability) {
    cout << "\nList of books in the library:" << endl;
    for (size_t i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i] << " - " 
             << (availability[i] ? "available" : "borrowed") << endl;
    }
}
