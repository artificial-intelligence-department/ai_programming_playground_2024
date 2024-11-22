#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Movie 
{
    char title[100];
    char director[50];
    int year;
    double price;
};

const char *filename = "movies.bin";

void createFile() 
{
    FILE *file = fopen(filename, "wb");
    if (!file) 
    {
        cerr << "Помилка відкриття файлу для запису." << "\n";
        return;
    }

    int n;
    cout << "Введіть кількість фільмів: ";
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        Movie movie;
        cout << "Назва фільму: ";
        cin.ignore();
        cin.getline(movie.title, 100);
        cout << "Режисер: ";
        cin.getline(movie.director, 50);
        cout << "Рік випуску: ";
        cin >> movie.year;
        cout << "Ціна: ";
        cin >> movie.price;

        fwrite(&movie, sizeof(Movie), 1, file);
    }

    fclose(file);
}

void printFile() 
{
    FILE *file = fopen(filename, "rb");
    if (!file) 
    {
        cerr << "Помилка відкриття файлу для читання!" << "\n";
        return;
    }

    Movie movie;
    bool isEmpty = true;

    while (fread(&movie, sizeof(Movie), 1, file)) 
    {
        isEmpty = false;
        cout << "Назва: " << movie.title
             << ", Режисер: " << movie.director
             << ", Рік випуску: " << movie.year
             << ", Ціна: " << movie.price << "\n";
    }

    if (isEmpty) 
    {
        cout << "Файл порожній." << "\n";
    }

    fclose(file);
}

void deleteExpensiveMovies(double maxPrice) 
{
    FILE *file = fopen(filename, "rb");
    if (!file) 
    {
        cerr << "Помилка відкриття файлу для читання." << "\n";
        return;
    }

    vector<Movie> movies;
    Movie movie;

    while (fread(&movie, sizeof(Movie), 1, file)) 
    {
        if (movie.price <= maxPrice) 
        {
            movies.push_back(movie);
        }
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) 
    {
        cerr << "Помилка відкриття файлу для запису." << "\n";
        return;
    }

    for (const auto &m : movies) 
    {
        fwrite(&m, sizeof(Movie), 1, file);
    }

    fclose(file);
}

void addMovieToStart() 
{
    Movie newMovie;
    cout << "Додавання нового фільму:" << "\n";
    cout << "Назва: ";
    cin.ignore();
    cin.getline(newMovie.title, 100);
    cout << "Режисер: ";
    cin.getline(newMovie.director, 50);
    cout << "Рік випуску: ";
    cin >> newMovie.year;
    cout << "Ціна: ";
    cin >> newMovie.price;

    FILE *file = fopen(filename, "rb");
    if (!file) 
    {
        cerr << "Помилка відкриття файлу для читання!" << "\n";
        return;
    }

    vector<Movie> movies;
    Movie movie;

    while (fread(&movie, sizeof(Movie), 1, file)) 
    {
        movies.push_back(movie);
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) 
    {
        cerr << "Помилка відкриття файлу для запису." << "\n";
        return;
    }

    fwrite(&newMovie, sizeof(Movie), 1, file);

    for (const auto &m : movies) 
    {
        fwrite(&m, sizeof(Movie), 1, file);
    }

    fclose(file);
}

int main() 
{
    createFile();

    cout << "\n" << "Вміст файлу після створення:" << "\n";
    printFile();

    double maxPrice;
    cout << "\n" << "Максимальна ціна для збереження фільмів: ";
    cin >> maxPrice;
    deleteExpensiveMovies(maxPrice);

    cout << "\n" << "Вміст файлу після видалення дорогих фільмів:" << "\n";
    printFile();

    addMovieToStart();

    cout << "\n" << "Вміст файлу після додавання нового фільму:" << "\n";
    printFile();

    return 0;
}