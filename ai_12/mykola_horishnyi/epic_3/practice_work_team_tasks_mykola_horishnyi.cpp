#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> books = { "First", "Second", "Third", "Fourth", "Fifth" };
    vector<bool> availability = { true, true, true, true, true }; 

    int option;

    while (true) {
        cout << "\nMenu:\n";
        cout << " 1 - Count all books \n";
        cout << " 2 - Rent a book \n";
        cout << " 3 - Give back a book \n";
        cout << " 4 - Exit \n";
        cout << "Choose your option: ";
        cin >> option;

        switch (option) {
        case 1: {
            cout << "Book list: \n";
            for (size_t i = 0; i < books.size(); i++) {
                cout << (i + 1) << ". " << books[i] << (availability[i] ? " (Yes)" : " (No)") << endl;
            }
            break;
        }
        case 2: {
            int choice;
            cout << "Enter the number of the book you want to rent: ";
            cin >> choice;
            if (choice < 1 || choice > books.size() || !availability[choice - 1]) {
                cout << "This book is not available.\n";
                break;
            }

            availability[choice - 1] = false;
            cout << "You rented: " << books[choice - 1] << "\n";
            break;
        }
        case 3: {
            int choice;
            cout << "Enter the number of the book you want to give back: ";
            cin >> choice;
            if (choice < 1 || choice > books.size() || availability[choice - 1]) {
                cout << "Wrong number or this book wasn't rented.\n";
                break;
            }

            availability[choice - 1] = true;
            cout << "You gave back: " << books[choice - 1] << "\n";
            break;
        }
        case 4: {
            cout << "Exit conplete \n";
            return 0;
        }
        default:
            cout << "Invalid option, please try again.\n";
        }

        cout << "Do you want to try another option? (1 - Yes, 0 - No): ";
        int anotherOperation;
        cin >> anotherOperation;

        if (anotherOperation == 0) {
            break; 
        }
    }

    return 0;
}
