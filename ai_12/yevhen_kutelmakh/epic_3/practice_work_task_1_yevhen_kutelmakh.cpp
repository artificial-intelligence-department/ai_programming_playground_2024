#include <iostream>
#include <string>
using namespace std;

string books[10] {
    "To Kill a Mockingbird",
    "Harry Potter and the Sorcerer`s Stone",
    "Pride and Prejudice",
    "The Diary of a Young Girl",
    "Animal Farm",
    "The Little Prince",
    "1984",
    "The Great Gatsby",
    "The Catcher in the Rye",
    "The Lord of the Rings"
};

int available[10] {1, 1, 0, 0, 1, 1, 1, 0, 1, 0};

int checkName(string bookName) {
    int index = 0;
    for(auto i : books) {
        if(bookName==i) 
            return index;
        index++;
    }
    return -1;
}

int checkIfAvailible(string bookName) {
    int index = checkName(bookName);
    if(index != -1) 
        return available[index];
    return -1;
}

void setAvailibility(string bookName, int array[]) {
    int index = checkName(bookName);
    if(index != -1) {
        array[index] = !array[index];  // Інвертує доступність
    }
}

int main() {
    cout << "Hello, dear customer! What do you want to do?\n";
    while(1) {
        char c;
        Here:
        do {
            cout << "Enter s for showing the list of books, t for taking the book, r for returning the book or e for exit: ";
            cin >> c;
            cin.ignore(32767, '\n');
            if(c!='e') {
                switch(c) {
                    case 's':{
                        cout << "This is the list of books in our library:\n";
                        for(int i = 0; i < 10; i++) {
                            cout << books[i] << "\n";
                        }
                        cout << "Anything else?\n";
                    } break;
                    case 't': {
                        cout << "Which one you want to take? ";
                        string book;
                        getline(cin, book);
                        int index = checkName(book);
                        if(index != -1) {
                            if(checkIfAvailible(book)) {
                                cout << "There is your book, but don`t forget to return it!\n";
                                setAvailibility(book, available);
                            }
                            else 
                                cout << "Sorry, someone has already taken it!\n";
                        }
                        else 
                            cout << "Sorry, we don`t have this book!\n";
                        
                    } break;
                    case 'r': {
                        cout << "Which one you want to return? ";
                        string book;
                        getline(cin, book);
                        int index = checkName(book);
                        if(index != -1) {
                            if(checkIfAvailible(book)) 
                                cout << "We have this one here, so you must have taken it from somewhere else\n";
                            else {
                                cout << "Thanks for bringing it back!\n";
                                setAvailibility(book, available);
                            }
                        }
                        else 
                            cout << "Sorry we don`t have this book!\n";
                    } break;
                    default: cout << "Invalid input, try again!\n"; goto Here;
                };
            }
        } while(c!='e');
        break;
    }
    cout << "Thanks for your visit! We are waiting for you";
    return 0;
}