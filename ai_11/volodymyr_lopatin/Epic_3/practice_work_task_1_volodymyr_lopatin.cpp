#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> booknames = {"1984", "The A.B.C. Murders", "Invisible Monsters", "Six of Crows", "Norwegian Wood"};
    vector<int> avail = {1, 0, 1, 0, 1};
    string com;
    vector<int> indexes;
    vector<string> availbooks;
    vector<string> takenBooks;

    menu:
    while (true) {
        cout << "Hello, what would you like to do? (view/take/return/exit) - ";
        cin >> com;

        if (com == "view") {
            for (int i = 0; i < booknames.size(); ++i) {
            cout << i + 1 << ". " << booknames[i] << endl;
            }

        } else if (com == "take") {
            vector<int> indexes;
            vector<string> availbooks;
            int index = 0;
            cout << "Available books:" << endl;
            for (int stat : avail) {
                if (stat == 1) {
                    cout << indexes.size() + 1 << ". " << booknames[index] << endl;
                    availbooks.push_back(booknames[index]);
                    indexes.push_back(index);
                }
                ++index;
            }

            if (availbooks.empty()) {
                cout << "Sorry, there's no book to take at the point." << endl;
            } else {
                int take;
                cout << "Which one do you want to take (from 1 to " << availbooks.size() << "): ";
                cin >> take;
                if (take >= 1 && take <= availbooks.size()) {
                    cout << "Great, you just took the book: " << availbooks[take-1] << endl;
                    avail[indexes[take-1]] = 0;
                    takenBooks.push_back(availbooks[take-1]);
                } else {
                    cout << "This book is not available." << endl;
                }
            }
        } else if (com == "exit") {
            break;
        } else if (com == "return") {
            if (takenBooks.empty()) {
                cout << "You didn't take anything to return" << endl;
            } else {
                cout << "You took these books: " << endl;
                for (int i = 0; i < takenBooks.size(); i++) {
                    cout << i + 1 << ". " << takenBooks[i] << endl;
                }

                int ret;
                cout << "Which one do you want to return? ";
                cin >> ret;

                if (ret >= 1 && ret <= takenBooks.size()) {
                    cout << "You just returned a book" << endl;
                    int bookIndex = -1;
                    for (int i = 0; i < takenBooks.size(); i++) {
                        if (takenBooks[ret-1] == booknames[i]) {
                            bookIndex = i;
                            avail[i] = 1;
                            break;
                        }
                    }
                    takenBooks.erase(takenBooks.begin() + bookIndex);
                } else {
                    cout << "Invalid input" << endl;
                    goto menu;
                }
            }
        } else {
            cout << "Invalid input" << endl;
            goto menu;
        }
        do {
            cout << "Do you want to do something else?(yes/no):" << endl;
            string cont;
            cin >> cont;
            if (cont == "yes" || cont == "y") {
                goto menu;
            } else if(cont == "no" || cont == "n") {
                break;
            } else {
                cout << "Invalid input" << endl;
            
            }
        } while (true);
        break;
    }

    return 0;
}

