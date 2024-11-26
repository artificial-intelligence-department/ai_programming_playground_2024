#include <iostream>
#include <vector>
#include <string>

using namespace std;

string displayBooks(const vector<string>& books, const vector<bool>& availability) {
    string result = "\nList of Books:\n";
    for (size_t i = 0; i < books.size(); ++i) {
        result += to_string(i + 1) + ". " + books[i] + " - " +
                  (availability[i] ? "Available" : "Not Available") + "\n";
    }
    return result;
}

string borrowBook(vector<bool>& availability, int bookNumber) {
    if (bookNumber < 1 || bookNumber > static_cast<int>(availability.size())) {
        return "Invalid book number.\n";
    }
    if (availability[bookNumber - 1]) {
        availability[bookNumber - 1] = false;
        return "You borrowed the book successfully.\n";
    }
    return "Sorry, the book is already borrowed.\n";
}

string returnBook(vector<bool>& availability, int bookNumber) {
    if (bookNumber < 1 || bookNumber > static_cast<int>(availability.size())) {
        return "Invalid book number.\n";
    }
    if (!availability[bookNumber - 1]) {
        availability[bookNumber - 1] = true;
        return "You returned the book successfully.\n";
    }
    return "The book was not borrowed.\n";
}

int main() {
    vector<string> books = {
        "1984",
        "The Great Gatsby",
        "Neuromancer",
        "Brave New World",
        "Faust",
        "The Master and Margarita"
    };
    vector<bool> availability(books.size(), true);

    int choice;
    string continueChoice;

start:
    cout << "\nLibrary Management System\n";
    cout << "1. List all books\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << displayBooks(books, availability);
            break;
        case 2: {
            cout << displayBooks(books, availability);
            cout << "\nEnter the number of the book you want to borrow: ";
            int bookNumber;
            cin >> bookNumber;
            cout << borrowBook(availability, bookNumber);
            break;
        }
        case 3: {
            cout << displayBooks(books, availability);
            cout << "\nEnter the number of the book you want to return: ";
            int bookNumber;
            cin >> bookNumber;
            cout << returnBook(availability, bookNumber);
            break;
        }
        case 4:
            cout << "Exiting the system. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            goto start;
    }

    do {
        cout << "\nDo you want to perform another operation? (yes/no): ";
        cin >> continueChoice;

        if (continueChoice == "yes" || continueChoice == "Yes") {
            goto start;
        } else if (continueChoice == "no" || continueChoice == "No") {
            cout << "Exiting the system. Goodbye!\n";
            return 0;
        } else {
            cout << "Invalid input. Please enter 'yes' or 'no'.\n";
        }
    } while (true);

    return 0;
} 