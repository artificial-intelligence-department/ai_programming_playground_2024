#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

struct films
{
    char name[50];
    char director[50];
    char country[50];
    long long profit;
};

void addData(const char *file)
{

    films film[]{
        {"Reservoir Dogs", "Quentin Tarantino", "USA", 2800000},
        {"Shawshank Redemption", "Frank Darabont", "USA", 73000000},
        {"12 Angry Men", "Sidney Arthur Lumet", "USA", 2000000},
        {"Goodfellas", "Martin Scorsese", "USA", 47000000},
        {"Seven", "David Andrew Leo Fincher", "USA", 327333559}};

    FILE *filmFile = fopen(file, "wb");
    if (filmFile == NULL)
    {
        cerr << "Fail to open a file";
    }

    for (int i = 0; i < 5; i++)
    {
        if (fwrite(&film[i], sizeof(films), 1, filmFile) != 1)
        {
            cerr << "An error occured";
            exit(0);
        }
    }
    fclose(filmFile);
}

void printData(const char *file)
{
    films film;
    FILE *filmFile;

    filmFile = fopen(file, "rb");

    if (filmFile == NULL)
    {
        cerr << "Fail to open a file";
        exit(0);
    }

    while (fread(&film, sizeof(films), 1, filmFile) == 1)
    {
        cout << "Name: " << film.name << endl;
        cout << "Director: " << film.director << endl;
        cout << "Country: " << film.country << endl;
        cout << "Profit: " << film.profit << "$" << endl;
        cout << endl;
    }
    fclose(filmFile);
}

void deleteData(const char *file)
{

    FILE *filmFile;

    filmFile = fopen(file, "rb+");

    if (filmFile == NULL)
    {
        cerr << "Fail to open a file";
        exit(0);
    }

    fseek(filmFile, 0, SEEK_END);    // Переміщуємо вказівник на початкок файлу
    long fileSize = ftell(filmFile); // Отримуємо розмір файлу
    if (fileSize == 0)
    {
        cerr << "File is empty";
        exit(0);
    }
    size_t filmSize = sizeof(films) * 2; // Розмір двох фільмів

    long newSize = fileSize - filmSize;
    if (ftruncate(fileno(filmFile), newSize) != 0) // Функція для обрізання файлу
    {
        cerr << "Error occured" << endl;
    }
    else
    {
        cerr << "2 last elements were deleted" << endl;
        cout << endl;
    }
    fclose(filmFile);

    printData(file);
}

void addElement(const char *file, const char *filmName)
{
    FILE *filmFile;
    filmFile = fopen(file, "rb+");
    FILE *newFilmFile;
    newFilmFile = fopen("newFilmFile.dat", "wb");
    if (filmFile == NULL)
    {
        cerr << "Fail to open a file";
        exit(0);
    }
    if (newFilmFile == NULL)
    {
        cerr << "Fail to open a file";
        exit(0);
    }

    films film;
    films newFilm[]{
        {"The Silence of the Lambs", "Jonathan Demme", "USA", 272742922}};

    bool targetFound = false;
    while (fread(&film, sizeof(films), 1, filmFile))
    {
        if (!targetFound && strcmp(film.name, filmName) == 0)
        {
            targetFound = true;
            fwrite(&film, sizeof(films), 1, newFilmFile);    // Записуємо поточний елемент
            fwrite(&newFilm, sizeof(films), 1, newFilmFile); // Додаємо новий елемент
        }
        else
        {
            fwrite(&film, sizeof(films), 1, newFilmFile); // Продовжуємо копіювати інші елементи
        }
    }

    fclose(filmFile);
    fclose(newFilmFile);
    cout << "With added film: " << endl;
    cout << endl;
    printData("newFilmFile.dat");
}

int main()
{
    const char *fileName = "films.dat";
    addData(fileName);
    printData(fileName);
    deleteData(fileName);
    addElement(fileName, "Reservoir Dogs");
    return 0;
}