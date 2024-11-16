#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> list_of_books = {
    "Book 1", "Book 2", "Book 3", "Book 4", "Book 5",
    "Book 6", "Book 7", "Book 8", "Book 9", "Book 10"
};

vector<bool> available_books(10, true); // All books initially available

int main() {
    bool next_choice = true;
    int choice;
    int number;
    bool inside = false;
    int keep_exploring = 0;
    int output_list = 0;

try_again:
    cout << "Would you like to enter the library? " << endl
         << "Enter 1 if yes, 0 if no: ";
    cin >> keep_exploring;
    cout << endl;

    if (keep_exploring == 1) {
        inside = true;
    } else if (keep_exploring == 0) {
        inside = false;
    } else {
        cout << "Invalid option. Try again!" << endl;
        goto try_again;
    }

    while (inside) {
    try_again_2:
        cout << "Would you like to see the list?" << endl
             << "Enter 1 for yes, 2 for no, 0 to exit library: ";
        cin >> output_list;
        cout << endl;

        if (output_list == 1) {
            for (size_t i = 0; i < list_of_books.size(); i++) {
                cout << (i + 1) << ". " << list_of_books[i] 
                     << (available_books[i] ? " (Available)" : " (Not Available)") << endl;
            }
            cout << endl;
        } else if (output_list == 0) {
            inside = false;
            break;
        } else if (output_list != 2) {
            cout << "Invalid choice. Try again!" << endl;
            goto try_again_2;
        }

        do {
            cout << "Choose an action:\n"
                 << "1. Take a book\n"
                 << "2. Return a book\n"
                 << "0. Stop\n";
            cin >> choice;
            cout << endl;

            if (choice == 1) {
                cout << "Enter the number of the book to take: ";
                cin >> number;
                if (number >= 1 && number <= list_of_books.size()) {
                    if (available_books[number - 1]) {
                        available_books[number - 1] = false;
                        cout << "You've taken: " << list_of_books[number - 1] << endl;
                    } else {
                        cout << "This book has already been taken!" << endl;
                    }
                } else {
                    cout << "Invalid book number!" << endl;
                }
            } else if (choice == 2) {
                cout << "Enter the number of the book to return: ";
                cin >> number;
                if (number >= 1 && number <= list_of_books.size()) {
                    if (!available_books[number - 1]) {
                        available_books[number - 1] = true;
                        cout << "You've returned: " << list_of_books[number - 1] << endl;
                    } else {
                        cout << "This book was not taken!" << endl;
                    }
                } else {
                    cout << "Invalid book number!" << endl;
                }
            } else if (choice != 0) {
                cout << "Invalid choice. Try again!" << endl;
            }
            next_choice = (choice != 0);

        } while (next_choice);
    }

    return 0;
}
