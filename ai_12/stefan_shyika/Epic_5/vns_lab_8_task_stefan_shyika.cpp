#include <iostream>
#include <cstring>

using namespace std;

typedef struct{
    char title[50];
    char author[50];
    int year;
    int numberOfPages;
}Book;

void addInitialData(const char* filename);
void deleteThreeFirstBooks(const char* filename);
void addBeforeTheBook(const char* filename, const Book& newBook, const char* title);
void printFile(const char* filename);

int main(){
    const char* filename = "books.dat";
    addInitialData(filename);
    deleteThreeFirstBooks(filename);
    
    Book newBook = {"newBook", "Stefan", 2024, 999};

    addBeforeTheBook(filename, newBook, "Book6");

}


void addInitialData(const char* filename) {
    FILE* f = fopen(filename, "wb");
    if ((f == NULL)){
        cerr << "Can't opent the file." << endl;
        exit(1); 
    }

    Book initialBooks[] = {
        {"Book1", "Author1", 1925, 218},
        {"Book2", "Author2", 1960, 281},
        {"Book3", "Author3", 1949, 328},
        {"Book4", "Author4", 1813, 279},
        {"Book5", "Author5", 1951, 277},
        {"Book6", "Author6", 1851, 635}
    };

    for (int i = 0; i < 6; i++) {
        if (fwrite(&initialBooks[i], sizeof(Book), 1, f) != 1) {
            cerr << "Error writing to file." << endl;
            exit(2);
        }
    }
    fclose(f);
    cout << "Initial books added successfully." << endl;
    printFile(filename);
}

void deleteThreeFirstBooks(const char* filename){
    FILE* f = fopen(filename, "rb");
    FILE* tmp = fopen("tmp.dat", "wb");

    if(f == NULL || tmp == NULL){
        cerr << "Can't open the file." << endl;
        exit(3);
    }

    Book book;
    int counter = 0;

    while(fread(&book, sizeof(Book), 1, f) == 1){
        if(counter >= 3){
            fwrite(&book, sizeof(Book), 1, tmp);
        }
        counter++;
    }

    fclose(tmp);
    fclose(f);

    remove(filename);
    rename("tmp.dat", filename);
    cout << "Deleted the first 3 books from " << filename << "." << endl;
    printFile(filename);
}

void addBeforeTheBook(const char* filename, const Book& newBook, const char* title){
    FILE* f = fopen(filename, "rb");
    FILE* tmp = fopen("tmp.dat", "wb");

    if (f == NULL || tmp == NULL) {
        cerr << "Error opening file." << endl;
        exit(4);
    }

    bool inserted = false;
    Book book;

    while(fread(&book, sizeof(Book), 1, f)){
        if(strcmp(book.title, title) == 0 && !inserted){
            fwrite(&newBook, sizeof(Book), 1, tmp);
            inserted = true;
        }
        fwrite(&book, sizeof(Book), 1, tmp);
    }

    if (!inserted) {
        cout << "No such title in the file :( Book inserted in the end." << endl;
        fwrite(&newBook, sizeof(Book), 1, tmp);
    }


    fclose(f);
    fclose(tmp);

    remove(filename);
    rename("tmp.dat", filename);
    if (inserted){
    cout << "Book added successfully before title: " << title << endl;
    }
    printFile(filename);
}

void printFile(const char* filename){
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        cerr << "Error opening file." << endl;
        exit(5);
    }

    Book book;
    cout << "Contents of " << filename << ":" << endl;
    cout << "---------------------------------" << endl;

    while (fread(&book, sizeof(Book), 1, f) == 1) {
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Year: " << book.year << endl;
        cout << "Number of Pages: " << book.numberOfPages << endl;
        cout << "---------------------------------" << endl;
    }

    fclose(f); 
}