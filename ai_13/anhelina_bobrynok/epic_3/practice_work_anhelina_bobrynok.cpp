#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ListBooks(string books[], bool available[]) {
    for (int i = 0; i < 5; i++) {
        cout << books[i] << " - " << (available[i] ? "Available" : "Not available") << endl;
    }
}

void TakeBook(string books[], bool available[], vector<string>& users_books) {
    cout << "Enter the book you would like to take:" << endl;
    string choose_book;
    cin.ignore();
    getline(cin, choose_book);
    bool found = false;

    for (int i = 0; i < 5; i++) {
        if (choose_book == books[i] && available[i]) {
            cout << "You took: " << choose_book << endl;
            users_books.push_back(choose_book);
            available[i] = false;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, we don't have this book in stock or it's already taken." << endl;
    }
}

void ReturnBook(string books[], bool availability[], vector<string>& users_books) {
    cout << "Enter the book you would like to return:" << endl;
    string choose_book;
    cin.ignore();
    getline(cin, choose_book);

    auto it = find(users_books.begin(), users_books.end(), choose_book);
    if (it != users_books.end()) {
        for (int i = 0; i < 5; i++) {
            if (books[i] == choose_book) {
                availability[i] = true;
                cout << "You returned: " << choose_book << endl;
                break;
            }
        }
        users_books.erase(it);
    } else {
        cout << "This book is not in your borrowed list." << endl;
    }
}

int main() {
    string action;
    string books[5] = {
        "Harry Potter and the Philosopher's Stone",
        "The Little Prince",
        "Alice's Adventures in Wonderland",
        "The Hobbit",
        "Lolita"
    };
    bool available[5] = {true, true, true, true, true};
    vector<string> users_books;

    while (action != "exit") {
    begin:
        cout << "\nLibrary Menu\n";
        cout << "Please enter an action (list, take, return, exit): ";
        cin >> action;

        if (action == "list") {
            string continuation;
            do {
                ListBooks(books, available);
                cout << "Go to menu?(yes,no): ";
                cin >> continuation;
            } while (continuation == "no");

        } else if (action == "take") {
            string continuation;
            do {
                TakeBook(books, available, users_books);
                cout << "Go to menu?(yes,no): ";
                cin >> continuation;
            } while (continuation == "no");  

        } else if (action == "return") {
            string continuation;
            do {
                ReturnBook(books, available, users_books);
                cout << "Go to menu?(yes,no): ";
                cin >> continuation;
            } while (continuation == "no");

        } else if (action != "exit") {
            cout << "Invalid action. Try again." << endl;
            goto begin;
        }
    }
    return 0;
}



