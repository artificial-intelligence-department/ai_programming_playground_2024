#include <bits/stdc++.h>

using namespace std;

struct Car {
    char brand[50];
    int year;
    double price;
    char color[30];
};

const char *filename = "cars.bin";

void createFile() {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return;
    }

    int n;
    cout << "Введіть кількість автомобілів: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Car car;
        cout << "Марка: ";
        if(i==0)
            cin.ignore();
        cin.getline(car.brand, 50);
        cout << "Рік випуску: ";
        cin >> car.year;
        cout << "Ціна: ";
        cin >> car.price;
        cout << "Колір: ";
        cin.ignore();
        cin.getline(car.color, 30);
        fwrite(&car, sizeof(Car), 1, file);
    }

    fclose(file);
}

void printFile() {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return;
    }

    Car car;
    bool isEmpty = true;

    while (fread(&car, sizeof(Car), 1, file)) {
        isEmpty = false;
        cout << "Марка: " << car.brand
             << ", Рік випуску: " << car.year
             << ", Ціна: " << car.price
             << ", Колір: " << car.color << endl;
    }

    if (isEmpty) {
        cout << "Файл порожній." << endl;
    }

    fclose(file);
}

void deleteOldCars(int minYear) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return;
    }

    vector<Car> cars;
    Car car;

    while (fread(&car, sizeof(Car), 1, file)) {
        if (car.year >= minYear) {
            cars.push_back(car);
        }
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return;
    }

    for (auto car: cars) {
        fwrite(&car, sizeof(Car), 1, file);
    }

    fclose(file);
}

void addCarToStart() {
    Car newCar;
    cout << "Додавання нового автомобіля:" << endl;
    cout << "Марка: ";
    cin.ignore();
    cin.getline(newCar.brand, 50);
    cout << "Рік випуску: ";
    cin >> newCar.year;
    cout << "Ціна: ";
    cin >> newCar.price;
    cout << "Колір: ";
    cin.ignore();
    cin.getline(newCar.color, 30);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return;
    }

    vector<Car> cars;
    Car car;

    while (fread(&car, sizeof(Car), 1, file)) {
        cars.push_back(car);
    }

    fclose(file);

    file = fopen(filename, "wb");
    if (!file) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return;
    }

    fwrite(&newCar, sizeof(Car), 1, file);


    for (auto car: cars) {
        fwrite(&car, sizeof(Car), 1, file);
    }

    fclose(file);
}

int main() {
    createFile();

    cout << endl << "Вміст файлу після створення:" << endl;
    printFile();

    int minYear;
    cout << endl << "Мінімальний рік випуску для збереження: ";
    cin >> minYear;
    deleteOldCars(minYear);

    cout << endl << "Вміст файлу після видалення старих автомобілів:" << endl;
    printFile();

    addCarToStart();

    cout << endl << "Вміст файлу після додавання нового автомобіля:" << endl;
    printFile();

    return 0;
}
