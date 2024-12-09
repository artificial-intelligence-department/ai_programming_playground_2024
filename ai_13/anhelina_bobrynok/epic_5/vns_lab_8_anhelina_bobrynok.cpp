#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Структура для країни
struct Country {
    char name[50];
    char capital[50];
    int population;
    double area;
};

// Функція для запису елементів в двійковий файл
void writeToFile(const char* filename, Country countries[], int count) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Помилка при відкритті файлу для запису!" << endl;
        return;
    }

    outFile.write(reinterpret_cast<char*>(&count), sizeof(count)); 
    outFile.write(reinterpret_cast<char*>(countries), sizeof(Country) * count); 

    outFile.close();
    cout << "Дані успішно записано у файл." << endl;
}

// Функція для виведення вмісту файлу
void printFileContents(const char* filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    int count;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(count)); 

    Country country;
    cout << "Вміст файлу:\n";
    for (int i = 0; i < count; ++i) {
        inFile.read(reinterpret_cast<char*>(&country), sizeof(Country));
        cout << "Назва: " << country.name << ", Столиця: " << country.capital
             << ", Населення: " << country.population << ", Площа: " << country.area << endl;
    }

    inFile.close();
}

// Функція для знищення елементів, де чисельність населення менша за задану
void deleteElementsByPopulation(const char* filename, int minPopulation) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    int count;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(count)); 

    Country* countries = new Country[count];
    for (int i = 0; i < count; ++i) {
        inFile.read(reinterpret_cast<char*>(&countries[i]), sizeof(Country));
    }
    inFile.close();

    // Визначення нового розміру
    int newCount = 0;
    for (int i = 0; i < count; ++i) {
        if (countries[i].population >= minPopulation) {
            countries[newCount++] = countries[i];
        }
    }

    // Перезаписування файлу з новими даними
    writeToFile(filename, countries, newCount);

    delete[] countries;
    cout << "Елементи з чисельністю населення менше " << minPopulation << " були видалені." << endl;
}

// Функція для додавання нового елемента після заданого індексу
void addElementAfterIndex(const char* filename, int index, Country newCountry) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    int count;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(count)); 

    Country* countries = new Country[count + 1]; 

    // Читання всіх елементів файлу
    for (int i = 0; i < count; ++i) {
        inFile.read(reinterpret_cast<char*>(&countries[i]), sizeof(Country));
    }
    inFile.close();

    // Додавання нового елемента після вказаного індексу
    for (int i = count; i > index; --i) {
        countries[i] = countries[i - 1]; 
    }
    countries[index + 1] = newCountry; 

    // Перезаписування файлу з новими даними
    writeToFile(filename, countries, count + 1);

    delete[] countries;
    cout << "Елемент успішно додано після індексу " << index << "." << endl;
}

int main() {
    const char* filename = "countries.dat";

    // Приклад країн
    Country countries[] = {
        {"Ukraine", "Kyiv", 4105267, 603550},
        {"Poland", "Warsaw", 38386000, 312696},
        {"Germany", "Berlin", 83019200, 357022},
        {"USA", "Washington", 331002651, 9833517}
    };


    writeToFile(filename, countries, 4);

    printFileContents(filename);

    deleteElementsByPopulation(filename, 40000000);

    Country newCountry = {"France", "Paris", 67081000, 551695};
    addElementAfterIndex(filename, 1, newCountry);

    printFileContents(filename);

    return 0;
}
