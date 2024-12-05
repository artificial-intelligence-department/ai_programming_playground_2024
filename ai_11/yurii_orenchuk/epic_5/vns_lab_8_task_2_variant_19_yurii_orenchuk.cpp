#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

struct films {
    char name[50];
    char director[50];
    char country[50];
    int profit;
};

void add_info(char *filename) {
    FILE *filmFile = fopen(filename, "wb");
    if (filmFile == NULL) {
        cout << "Failed to open file while adding info";
    }

    int n;
    cout << "Enter number of films: ";
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        films film;
        cout << "Film title: ";
        cin.ignore();
        cin.getline(film.name, 100);
        cout << "Director: ";
        cin.getline(film.director, 50);
        cout << "Country of origin: ";
        cin >> film.country;
        cout << "Profit: ";
        cin >> film.profit;

        fwrite(&film, sizeof(film), 1, filmFile);
    }
    fclose(filmFile);
}

void print_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        cout << "Failed to open file while printing file\n";
        return;
    }

    films film;
    bool isEmpty = true;

    while (fread(&film, sizeof(film), 1, file)) {
        isEmpty = false;
        cout << "Title: " << film.name << endl;
        cout << "Director: " << film.director << endl;
        cout << "Country of origin: " << film.country << endl;
        cout << "Profits: " << film.profit << endl;
    }

    if (isEmpty) {
        cout << "File is empty\n";
    }

    fclose(file);
}

void delete_last_2(char *file) {

    FILE *filmFile;

    filmFile = fopen(file, "rb+");

    fseek(filmFile, 0, SEEK_END);
    long fileSize = ftell(filmFile);
    if (fileSize == 0) {
        cout << "File is empty\n";
        exit(0);
    }
    size_t filmSize = sizeof(films) * 2;

    long newSize = fileSize - filmSize;
    if (ftruncate(fileno(filmFile), newSize) != 0) {
        cout << "Failed to delete last 2 elements\n";
    }
    else cout << "2 last elements deleted successfully\n\n";

    fclose(filmFile);

    print_file(file);
}

void add_after_name(const char *file, const char *filmName)
{
    FILE *filmFile;
    filmFile = fopen(file, "rb+");
    FILE *newFilmFile;
    newFilmFile = fopen("newFilmFile.bin", "wb");
    if (filmFile == NULL) {
        cout << "Failed to open a file";
        exit(0);
    }
    if (newFilmFile == NULL) {
        cout << "Failed to open new file";
        exit(0);
    }

    films film;
    films newFilm[]{
        {"New Film", "Biden", "USA", 950000000}};

    bool targetFound = false;
    while (fread(&film, sizeof(films), 1, filmFile)) {
        if (!targetFound && strcmp(film.name, filmName) == 0) {
            targetFound = true;
            fwrite(&film, sizeof(films), 1, newFilmFile);
            fwrite(&newFilm, sizeof(films), 1, newFilmFile);
        } else {
            fwrite(&film, sizeof(films), 1, newFilmFile);
        }
    }

    fclose(filmFile);
    fclose(newFilmFile);
    cout << "\nWith added film: \n\n";
    print_file("newFilmFile.bin");
}

int main(){
    char *fileName = "films.bin";
    add_info(fileName);

    cout << "\nFile contents:\n";
    print_file(fileName);

    delete_last_2(fileName);

    add_after_name(fileName, "Interstellar");

    return 0;
}