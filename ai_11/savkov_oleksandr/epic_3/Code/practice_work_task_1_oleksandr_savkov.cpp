#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> books = {
        "To Kill a Mockingbird",
        "1984",
        "Pride and Prejudice",
        "The Great Gatsby",
        "The Catcher in the Rye",
        "The Hobbit",
        "Harry Potter and the Philosopher's Stone",
        "Moby-Dick",
        "Brave New World"
    };

    vector<bool> booksStatus = {
        true,
        true,
        false,
        true,
        true,
        true,
        true,
        false,
        true
    };

    int caseValue = 0;
    bool whileStopper = true;
    int temp = 0;
    int booksIncomon;
    string takenBook = "";
    string givenBook = "";

    while (whileStopper) {
        do {
        start:
            cout << " Write:\n 1 - if you wanna count all available books\n 2 - take book from library\n 3 - give book to library\n 4 - exit\n";
            cin >> caseValue;
            cin.clear();
            cin.ignore(100, '\n');

            if (caseValue == 1) {
                cout << "number of available books" << endl;
                booksIncomon = 0;
                for (const auto& bookStatus : booksStatus) {
                    booksIncomon += bookStatus;
                }
                cout << booksIncomon << endl;

            } else if (caseValue == 2) {
                cout << "List of available books" << endl;
                for (int i = 0; i < books.size(); i++) {
                    if (booksStatus[i]) {
                        cout << books[i] << endl;
                    }
                }
                bool validInput = false;
                while (!validInput) {
                    cout << "Write the name of book you wanna take" << endl;
                    getline(cin, takenBook);
                    auto takenBookNumber = find(books.begin(), books.end(), takenBook);
                    
                    if (takenBookNumber != books.end()) {
                        int takenBookIndex = distance(books.begin(), takenBookNumber);
                        if (booksStatus[takenBookIndex]) {
                            booksStatus[takenBookIndex] = false;
                            cout << "Now book is unavailable" << endl;
                            validInput = true;
                        } else {
                            cout << "Book is already unavailable" << endl;
                        }
                    } else {
                        cout << "You entered an invalid book name" << endl;
                    }
                }

            } else if (caseValue == 3) {
                cout << "List of unavailable books" << endl;
                for (int i = 0; i < books.size(); i++) {
                    if (!booksStatus[i]) {
                        cout << books[i] << endl;
                    }
                }
                bool validGaveInput = false;
                while (!validGaveInput) {
                    cout << "Write the name of book you wanna give back" << endl;
                    getline(cin, givenBook);
                    auto givenBookNumber = find(books.begin(), books.end(), givenBook);
                    
                    if (givenBookNumber != books.end()) {
                        int givenBookIndex = distance(books.begin(), givenBookNumber);
                        if (!booksStatus[givenBookIndex]) {
                            booksStatus[givenBookIndex] = true;
                            cout << "Now book is available" << endl;
                            validGaveInput = true;
                        } else {
                            cout << "Book is already available" << endl;
                        }
                    } else {
                        cout << "You entered an invalid book name" << endl;
                    }
                }

            } else if (caseValue == 4) {
                cout << "Exiting the program\n";
                whileStopper = false;
            } else {
                cout << "Invalid number, try again" << endl;
                goto start;
            }
            if(caseValue != 4) {
                cout << "Would you like to chose another option?\n type 1 if yes, or 0 if no \n";
                perev:
                cin >> temp;

                if (temp == 0) {
                    whileStopper = false;
                } else if (temp == 1) {
                    
                } else {
                    cout << "incorrect number,try again\n";
                    goto perev;
                }
            } 

        } while (whileStopper);
    }

    return 0;
}
