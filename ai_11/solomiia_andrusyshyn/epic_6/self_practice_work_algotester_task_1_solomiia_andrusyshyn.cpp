#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    Book(string t = "", string a = "", int y = 0) : title(t), author(a), year(y) {}
};

class Library {
private:
    Book* books; 
    int size;    
    int capacity; 

    void resize() {
        int new_capacity = capacity * 2;
        Book* new_books = new Book[new_capacity];

        for (int i = 0; i < size; i++) {
            new_books[i] = books[i];
        }

        delete[] books;
        books = new_books;
        capacity = new_capacity;
    }

public:
    Library() : size(0), capacity(2) {
        books = new Book[capacity];
    }

    ~Library() {
        delete[] books;
    }

    void addBook(const Book& book) {
        if (size == capacity) {
            resize();
        }
        books[size++] = book;
    }

    void removeBook(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            books[i] = books[i + 1];
        }
        size--;
    }

    void displayBooks() const {
        for (int i = 0; i < size; i++) {
            cout << "Title: " << books[i].title
                 << ", Author: " << books[i].author
                 << ", Year: " << books[i].year << endl;
        }
    }

    void findBooksByAuthor(const string& author) const {
        for (int i = 0; i < size; i++) {
            if (books[i].author == author) {
                cout << "Title: " << books[i].title
                     << ", Year: " << books[i].year << endl;
            }
        }
    }
};

int main() {
    Library library;

    library.addBook(Book("Pride and Prejudice", "Jane Austen", 1813));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("1984", "George Orwell", 1949));
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951));

    cout << "All books in the library:" << endl;
    library.displayBooks();

    cout << "\nBooks by 'George Orwell':" << endl;
    library.findBooksByAuthor("George Orwell");

    cout << "\nRemoving the second book..." << endl;
    library.removeBook(1);

    cout << "\nUpdated list of books:" << endl;
    library.displayBooks();

    return 0;
}
