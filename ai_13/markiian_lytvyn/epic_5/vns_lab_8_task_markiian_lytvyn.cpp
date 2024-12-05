#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Film {
    char name[100];
    char director[100];
    int year;
    int cost;
};

const char* filename = "film.dat";

void create_file() {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        cerr << "Error." << endl;
        return;
    }
    while (true) {
        Film film;
        cout << "Enter film name (or press Enter to stop): ";
        cin.ignore();  
        cin.getline(film.name, 100);

        if (strlen(film.name) == 0) {  
            break;
        }
        cout << "Director: ";
        cin.getline(film.director, 100);
        cout << "Year: ";
        cin >> film.year;
        cout << "Cost in millions: ";
        cin >> film.cost;
        fwrite(&film, sizeof(Film), 1, file);
    }
    fclose(file);
}

void create_file(const vector<Film>& films) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        cerr << "Error." << endl;
        return;
    }
    for (const auto& film : films) {
        fwrite(&film, sizeof(Film), 1, file);
    }
    fclose(file);
}

void print_file() {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Error." << endl;
        return;
    }
    Film film;
    while (fread(&film, sizeof(Film), 1, file)) 
    {
        cout << "Name: " << film.name
             << ", Director: " << film.director
             << ", Year: " << film.year
             << ", Cost in millions: " << film.cost << "\n";
    }
    fclose(file);
}

void delete_expensive(double max_price) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Error." << endl;
        return;
    }

    vector<Film> films;
    Film film;

    while (fread(&film, sizeof(Film), 1, file)) {
        if (film.cost <= max_price) {
            films.push_back(film);
        }
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) {
        cerr << "Error." << endl;
        return;
    }

    for (const auto& m : films) {
        fwrite(&m, sizeof(Film), 1, file);
    }

    fclose(file);
}

void add_film() {
Film new_Film;
    cout << "Enter film name (or press Enter to stop): " << endl;
    cout << "Name: "; cin.ignore(); cin.getline(new_Film.name, 100);
    if (strlen(new_Film.name) == 0) {
        return;  
    }
    cout << "Director: "; cin.getline(new_Film.director, 100);
    cout << "Year: "; cin >> new_Film.year;
    cout << "Cost: "; cin >> new_Film.cost;
    FILE* file = fopen(filename, "rb");
    vector<Film> films;
    Film film;
    while (fread(&film, sizeof(Film), 1, file)) {
        films.push_back(film);
    }

    fclose(file);

    file = fopen(filename, "wb");
    fwrite(&new_Film, sizeof(Film), 1, file);
    for (const auto& m : films) {
        fwrite(&m, sizeof(Film), 1, file);
    }
    fclose(file);
}

int main() {
    vector<Film> primary_films = {
        {"One piece", "Eiichiro Oda", 1999, 150},
        {"Home Alone", "Chris Columbus", 1990, 120},
        {"Interstellar", "Christoper Nolan", 2009, 310},
        {"Spider Man: No Way Home", "John Watts", 1999, 350},
        {"Fight Club", "David Fincer", 1999, 170},
        {"Titanic", "James Cameron", 1997, 190},
        {"Harry Potter and the Half-Blood Prince", "David Ets", 2009, 240}
    };
    create_file(primary_films);

    cout << "File`s content:" << endl;
    print_file();
    int max_price;
    cout << "\nMax cost: ";
    cin >> max_price;
    delete_expensive(max_price);
    cout << "\nFile after removing films:" << endl;
    print_file();
    add_film();
    cout << "\nFile after new films added:" << endl;
    print_file();

    return 0;
}
