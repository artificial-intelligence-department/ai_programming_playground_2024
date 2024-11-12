#include <iostream>
#include <vector>
#include <string>

using namespace std;

//displaymenu
void d() {

    cout << "=== Library menu ===" << endl;

    cout << " Show all books" << endl;

    cout << " Take a book" << endl;

    cout << " Return the book" << endl;

    cout << " Exit" << endl;

    cout << "Select an option: " << endl;
}

int main() {

    vector<string> b = { "book 1", "book 2" "book 3", "book 4" };  //books
    vector<bool> a = { true, true, true, true }; //availeble

    int c;//choice
    bool e = false; //exit

    while (!e) {
        d();

        cin >> c;

        switch (c) {

        case 1: {  

            cout << "List of all books:" << endl;
            for (size_t i = 0; i < b.size(); ++i) {
                cout << i + 1 << ". " << b[i] << (a[i] ? " (available)" : " (not available)");
            }
            break;
        } case 2: {  

            int bn; //books number

            cout << "Enter the number of the book you want to take: " <<  endl;
            cin >> bn;


            if (bn > 0 && bn <= b.size()) {
                if (a[bn - 1]) {
                    a[bn - 1] = false;
                    cout << "You took the book: " << b[bn - 1] << endl;
                }
                else {
                    cout << "This book is already taken!" << endl;
                }
            }
            else {
                cout << "Invalid book number!" << endl;
            }
            break;
        } case 3: {  

            int nb; //number of book

            cout <<"Select the book you want to return : ";
            cin >> nb;

            if (nb > 0 && nb <= b.size()) {
                if (!a[nb - 1]) {
                    a[nb - 1] = true;
                    cout << "You returned the book: " << b[nb - 1] << endl;
                }
                else {
                    cout << "This book is now available!" << endl;
                }
            }
            else {
                cout << "Invalid book number!"<<endl;
            }
            break;
        } case 4: {  

            e = true;

            cout << "Thank you for using the library!" << endl;
            break;
        } default:  

            cout << "Wrong choice. Try again." << endl;
            goto start;  
        }

       
        char cc; //continue

        do {

            cout << "Do you want to perform another operation?? (y/n): ";
            cin >> cc;

            if (cc == 'y' || cc == 'Y') {
                goto start;
            }
            else if (cc == 'n' || cc == 'N') {
                e = true;
            } else cout << "Wrong choice. ";

        } while (cc != 'y' && cc != 'Y' && cc != 'n' && cc != 'N');

    start:

        continue;  
    }



    return 0;
}
