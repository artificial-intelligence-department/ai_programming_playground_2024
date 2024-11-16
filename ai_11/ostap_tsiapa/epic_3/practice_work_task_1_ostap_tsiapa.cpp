#include <iostream>
#include <vector>
#include <string>

using namespace std;

void listBooks(const vector<string>& books, const vector<bool>& availability) {
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i] << " - " << (availability[i] ? "Available" : "Checked out") << endl;
    }
}

void borrowBook(vector<bool>& availability) {
    int bookIndex;
    cout << "Enter the number of the book you want to borrow: ";
    cin >> bookIndex;
    if (bookIndex < 1 || bookIndex > static_cast<int>(availability.size()) || !availability[bookIndex - 1]) {
        cout << "Invalid choice or book not available." << endl;
        goto mainMenu;
    } else {
        availability[bookIndex - 1] = false;
        cout << "Book borrowed successfully!" << endl;
    }
    return;

    mainMenu:
    cout << "Returning to main menu." << endl;
}

void returnBook(vector<bool>& availability) {
    int bookIndex;
    cout << "Enter the number of the book you want to return: ";
    cin >> bookIndex;
    if (bookIndex < 1 || bookIndex > static_cast<int>(availability.size()) || availability[bookIndex - 1]) {
        cout << "Invalid choice or book already returned." << endl;
        goto mainMenu;
    } else {
        availability[bookIndex - 1] = true;
        cout << "Book returned successfully!" << endl;
    }
    return;

    mainMenu:
    cout << "Returning to main menu." << endl;
}

int main() {
    vector<string> books = {"The Great Gatsby", "1984", "To Kill a Mockingbird", "Pride and Prejudice", "The Hobbit", "Surgeon"};
    vector<bool> availability(books.size(), true);

    char choice;
    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. List all books" << endl;
        cout << "2. Borrow a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                listBooks(books, availability);
                break;
            case '2':
                borrowBook(availability);
                break;
            case '3':
                returnBook(availability);
                break;
            case '4':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                goto mainMenu;
        }

        do {
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> choice;
        } while (choice != 'y' && choice != 'n');

    } while (choice == 'y');

    return 0;

    mainMenu:
    cout << "Returning to main menu." << endl;
    return main();
}
