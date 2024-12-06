#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

// "Власник автомобіля"
struct CarOwner {
    char priz[50];  // Прізвище
    char name[50];     // Ім'я
    char batok[50];  // По батькові
    char carN[15];   // Номер автомобіля
    char phone[15];       // Телефон
    char techP[15]; 
};

// Функції - Створити
void createFile(const char* filename) {
    FILE* f = fopen(filename, "wb");
    if (f == nullptr) {
        cerr << "Помилка відкриття файлу." << endl;
        exit(0);
    }

    CarOwner owners[] = {
        {"Грушевський", "Михайло", "Сергійович", "A1", "1", "TP1"},
        {"Zuckerberg", "Mark", "Elliot", "B1", "2", "TP2"},
        {"Стефанович", "Євгеній", "Володимирович", "B2", "0938256177", "TP3"}
    };

    for (const auto& owner : owners) {
        fwrite(&owner, sizeof(CarOwner), 1, f);
    }

    fclose(f);
    cout << "Файл успішно створено з початковими даними." << endl;
}
// зчитати
void printFile(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (f == nullptr) {
        cerr << "Помилка відкриття файлу." << endl;
        exit(0);
    }

    CarOwner owner;
    cout << "Вміст файлу:" << endl;
    cout << "----------------------------------------------------------" << endl;
    while (fread(&owner, sizeof(CarOwner), 1, f) == 1) {
        cout << "Прізвище: " << owner.priz << ", Ім'я: " << owner.name
             << ", По батькові: " << owner.batok << endl;
        cout << "Номер авто: " << owner.carN << ", Телефон: " << owner.phone
             << ", Номер техпаспорта: " << owner.techP << endl;
        cout << "----------------------------------------------------------" << endl;
    }

    fclose(f);
}

//видалити
void deleteByCarNumber(const char* filename, const char* carNumber) {
    FILE* f = fopen(filename, "rb");
    FILE* bezN = fopen("bezN.dat", "wb");
    if (f == nullptr || bezN == nullptr) {
        cerr << "Помилка відкриття файлу." << endl;
        exit(0);
    }

    CarOwner owner;
    bool shuk = false;

    while (fread(&owner, sizeof(CarOwner), 1, f) == 1) {
        if (strcmp(owner.carN, carNumber) != 0) {
            fwrite(&owner, sizeof(CarOwner), 1, bezN);
        } else {
            shuk = true;
        }
    }

    fclose(f);
    fclose(bezN);

    remove(filename);
    rename("bezN.dat", filename);

    if (shuk) {
        cout << "Власник з номером авто " << carNumber << "успішно видалено." << endl;
    } else {
        cout << "Власник з номером авто " << carNumber << " не знайдено." << endl;
    }
}

//додати
void addBeforeSurname(const char* filename, const CarOwner& owner1, const CarOwner& owner2, const char* surname) {
    FILE* f = fopen(filename, "rb");
    FILE* dot = fopen("dot.dat", "wb");
    if (f == nullptr || dot == nullptr) {
        cerr << "Помилка відкриття файлу." << endl;
        exit(0);
    }

    CarOwner owner;
    bool dodav = false;

    while (fread(&owner, sizeof(CarOwner), 1, f) == 1) {
        if (strcmp(owner.batok, surname) == 0 && !dodav) {
            fwrite(&owner1, sizeof(CarOwner), 1, dot);
            fwrite(&owner2, sizeof(CarOwner), 1, dot);
            dodav = true;
        }
        fwrite(&owner, sizeof(CarOwner), 1, dot);
    }

    fclose(f);
    fclose(dot);

    remove(filename);
    rename("dot.dat", filename);

    if (dodav) {
        cout << "Два власники додані перед власником з прізвищем " << surname << "." << endl;
    } else {
        cout << "Власник з  прізвищем " << surname << " не знайдено. Нові власники додані до кінця." << endl;
    }
}

int main() {
    const char* filename = "carowners.dat";

    // Створти
    createFile(filename);

    // Друк
    printFile(filename);

    // видалити
    deleteByCarNumber(filename, "B2");
    printFile(filename);

    // Додати
    CarOwner owner1 = {"Байден", "Джозеф", "Робінетт", "AB1", "123", "TP12"};
    CarOwner owner2 = {"Іванов", "Іван", "Іванович", "AB2", "456", "TP21"};
    addBeforeSurname(filename, owner1, owner2, "Elliot");
    printFile(filename);

    return 0;
}


