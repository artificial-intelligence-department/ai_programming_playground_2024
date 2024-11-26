#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <random>
#include <vector>

using namespace std;

struct book {
    string name;
    string author;
    int year_of_publication;
    int pages;
};

bool is_file_empty(const string& filename);
void deletion(const string& filename);
void add_some_books(const string& filename);
void add_book_before_given(const string& filename, const string& given, const string& book_name, const string& new_author, int year_of_publication, int pages);
void print(const string& filename);

int main() {
    const string filename = "books.txt";
    int choice;

    do {
        cout << "\n1. Delete 3 books from start\n"
             << "2. Add book before a given book\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (is_file_empty(filename)) {
            cout << "The file is empty. Adding default books...\n";
            add_some_books(filename);
        }

        switch (choice) {
            case 1:
                deletion(filename);
                break;
            case 2: {
                string given_book, book_name, new_author;
                int year_of_publication, pages;

                cout << "Enter the name of the book before which to add: ";
                cin >> given_book;
                cout << "Enter new book name: ";
                cin >> book_name;
                cout << "Enter new author: ";
                cin >> new_author;
                cout << "Enter year of publication: ";
                cin >> year_of_publication;
                cout << "Enter number of pages: ";
                cin >> pages;

                add_book_before_given(filename, given_book, book_name, new_author, year_of_publication, pages);
                break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cerr << "Invalid choice!\n";
        }
        print(filename);
    } while (choice != 3);

    return 0;
}

void deletion(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading!\n";
        return;
    }

    vector<string> lines;
    string line;
    int current_line = 0;
    while (getline(inFile, line)) {
        if (current_line >= 3) { 
            lines.push_back(line);
        }
        current_line++;
    }
    inFile.close();

    ofstream outFile(filename, ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& line : lines) {
        outFile << line << endl;
    }
    outFile.close();
}

void add_some_books(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing!\n";
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 500);

    book books[10];
    for (int i = 0; i < 10; ++i) {
        books[i].name = "name" + to_string(i + 1);
        books[i].author = "author" + to_string(i + 1);
        books[i].pages = dis(gen);
        books[i].year_of_publication = 1500 + dis(gen);

        outFile << books[i].name << " " << books[i].author << " "
                << books[i].year_of_publication << " " << books[i].pages << endl;
    }
    outFile.close();
}

void add_book_before_given(const string& filename, const string& given, const string& book_name, const string& new_author, int year_of_publication, int pages) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading!\n";
        return;
    }

    vector<book> books;
    book temp;
    book new_book = {book_name, new_author, year_of_publication, pages};
    bool inserted = false;

    while (inFile >> temp.name >> temp.author >> temp.year_of_publication >> temp.pages) {
        if (!inserted && temp.name == given) {
            books.push_back(new_book);
            inserted = true;
        }
        books.push_back(temp);
    }
    inFile.close();

    ofstream outFile(filename, ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& b : books) {
        outFile << b.name << " " << b.author << " " << b.year_of_publication
                << " " << b.pages << endl;
    }
    outFile.close();
}

void print(const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cerr << "Error opening file for reading!\n";
    }
}

bool is_file_empty(const string& filename) {
    ifstream inFile(filename, ios::ate | ios::binary); 
    if (!inFile.is_open()) {
        return true; 
    }
    return inFile.tellg() == 0;
}
