#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Structure "Book"
struct Book {
    string title;
    string author;
    int year;
    int pages;
};

void writeToFile(const string& filename, const vector<Book>& books) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (const auto& book : books) {
        outFile.write(reinterpret_cast<const char*>(&book), sizeof(Book));
    }
    outFile.close();
}

void printFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    Book book;
    while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        cout << "Title: " << book.title << ", Author: " << book.author
             << ", Year: " << book.year << ", Pages: " << book.pages << endl;
    }
    inFile.close();
}

void deleteFirstThree(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    vector<Book> books;
    Book book;
    int index = 0;
    while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (index++ >= 3) {
            books.push_back(book);
        }
    }
    inFile.close();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (const auto& b : books) {
        outFile.write(reinterpret_cast<const char*>(&b), sizeof(Book));
    }
    outFile.close();
}

void addBeforeTitle(const string& filename, const string& targetTitle, const Book& newBook) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    vector<Book> books;
    Book book;
    bool inserted = false;
    while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (!inserted && book.title == targetTitle) {
            books.push_back(newBook);
            inserted = true;
        }
        books.push_back(book);
    }
    inFile.close();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (const auto& b : books) {
        outFile.write(reinterpret_cast<const char*>(&b), sizeof(Book));
    }
    outFile.close();
}

int main() {
    string filename = "books.bin";
    vector<Book> books = {
        {"Book1", "Author1", 2001, 100},
        {"Book2", "Author2", 2002, 200},
        {"Book3", "Author3", 2003, 300},
        {"Book4", "Author4", 2004, 400}
    };

    writeToFile(filename, books);

    cout << "Initial file content:" << endl;
    printFile(filename);

    deleteFirstThree(filename);
    cout << "\nAfter deleting first 3 elements:" << endl;
    printFile(filename);

    Book newBook = {"NewBook", "NewAuthor", 2024, 150};
    addBeforeTitle(filename, "Book4", newBook);
    cout << "\nAfter adding a new element before 'Book4':" << endl;
    printFile(filename);

    return 0;
}
