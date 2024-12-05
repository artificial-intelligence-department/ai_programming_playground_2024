#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Film {
    char title[50];
    char director[50];
    char country[30];
    double profit;
};

void createFile(const string& filename, const vector<Film>& films) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для запису.\n";
        return;
    }
    for (const auto& film : films) {
        file.write(reinterpret_cast<const char*>(&film), sizeof(Film));
    }
    file.close();
}

void printFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для читання.\n";
        return;
    }
    Film film;
    cout << "Вміст файлу:\n";
    while (file.read(reinterpret_cast<char*>(&film), sizeof(Film))) {
        cout << "Назва: " << film.title << "\n"
             << "Режисер: " << film.director << "\n"
             << "Країна: " << film.country << "\n"
             << "Прибуток: " << film.profit << "\n\n";
    }
    file.close();
}

void deleteLastTwo(const string& filename) {
    vector<Film> films;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для читання.\n";
        return;
    }
    Film film;
    while (file.read(reinterpret_cast<char*>(&film), sizeof(Film))) {
        films.push_back(film);
    }
    file.close();
    if (films.size() < 2) {
        cerr << "Недостатньо елементів для видалення.\n";
        return;
    }
    films.pop_back();
    films.pop_back();
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису.\n";
        return;
    }
    for (const auto& f : films) {
        outFile.write(reinterpret_cast<const char*>(&f), sizeof(Film));
    }
    outFile.close();
}

void addAfterTitle(const string& filename, const string& targetTitle, const Film& newFilm) {
    vector<Film> films;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для читання.\n";
        return;
    }
    Film film;
    while (file.read(reinterpret_cast<char*>(&film), sizeof(Film))) {
        films.push_back(film);
    }
    file.close();
    bool found = false;
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису.\n";
        return;
    }
    for (size_t i = 0; i < films.size(); ++i) {
        outFile.write(reinterpret_cast<const char*>(&films[i]), sizeof(Film));
        if (string(films[i].title) == targetTitle) {
            outFile.write(reinterpret_cast<const char*>(&newFilm), sizeof(Film));
            found = true;
        }
    }
    outFile.close(); 
    if (!found) {
        cerr << "Елемент із заданою назвою не знайдено.\n";
    }
}

int main() {
    const string filename = "films.bin";
    vector<Film> films = {
        {"Inception", "Christopher Nolan", "USA", 829.89},
        {"Parasite", "Bong Joon-ho", "South Korea", 258.4},
        {"Lobster", "Yorgos Lantimos", "UK", 123.6},
        {"Moonrise Kingdom", "Wes Anderson", "USA", 68.3}
    };
    createFile(filename, films);
    cout << "Початковий файл:\n";
    printFile(filename);
    deleteLastTwo(filename);
    cout << "\nПісля видалення останніх двох елементів:\n";
    printFile(filename);
    Film newFilm = {"Avatar", "James Cameron", "USA", 2847.24};
    addAfterTitle(filename, "Inception", newFilm);
    cout << "\nПісля додавання нового елемента після 'Inception':\n";
    printFile(filename);
    return 0;
}