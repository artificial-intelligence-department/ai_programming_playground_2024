#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct CarOwner {
    char Surname[30];
    char Name[30];
    char Patronymic[30];
    char CarNumber[20];
    char TechPass[20];
    char RegistrationOffice[50];
};

// Функція для створення файлу
void createFile(const char* filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Error: Unable to create file." << endl;
        return;
    }

    int n;
    cout << "How many car owners do you want to add? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        CarOwner owner;
        cout << "Owner " << i + 1 << ":\n";
        cout << "Surname: "; cin.getline(owner.Surname, 30);
        cout << "Name: "; cin.getline(owner.Name, 30);
        cout << "Patronymic: "; cin.getline(owner.Patronymic, 30);
        cout << "Car Number: "; cin.getline(owner.CarNumber, 20);
        cout << "Technical Passport Number: "; cin.getline(owner.TechPass, 20);
        cout << "Registration Office: "; cin.getline(owner.RegistrationOffice, 50);

        file.write((char*)&owner, sizeof(CarOwner));
    }
    file.close();
}

// Функція для друку файлу
void printFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    CarOwner owner;
    while (file.read((char*)&owner, sizeof(CarOwner))) {
        cout << "Surname: " << owner.Surname
            << ", Name: " << owner.Name
            << ", Car Number: " << owner.CarNumber << endl;
    }
    file.close();
}

// Видалення запису за номером автомобіля
void deleteByCarNumber(const char* filename, const char* carNumber) {
    ifstream file(filename, ios::binary);
    ofstream temp("temp.bin", ios::binary);

    if (!file || !temp) {
        cout << "Error: Unable to open file for deletion." << endl;
        return;
    }

    CarOwner owner;
    bool found = false;
    while (file.read((char*)&owner, sizeof(CarOwner))) {
        if (strcmp(owner.CarNumber, carNumber) != 0) {
            temp.write((char*)&owner, sizeof(CarOwner));
        }
        else {
            found = true;
        }
    }

    if (!found) {
        cout << "Error: Car number not found." << endl;
    }

    file.close();
    temp.close();
    remove(filename);
    rename("temp.bin", filename);
}

// Додавання двох записів перед заданим прізвищем
void addBeforeSurname(const char* filename, const char* surname) {
    ifstream file(filename, ios::binary);
    ofstream temp("temp.bin", ios::binary);

    if (!file || !temp) {
        cout << "Error: Unable to open file for addition." << endl;
        return;
    }

    CarOwner owner;
    bool added = false;

    while (file.read((char*)&owner, sizeof(CarOwner))) {
        if (!added && strcmp(owner.Surname, surname) == 0) {
            for (int i = 0; i < 2; i++) {
                CarOwner newOwner;
                cout << "Enter data for new owner " << i + 1 << ":\n";
                cout << "Surname: "; cin.getline(newOwner.Surname, 30);
                cout << "Name: "; cin.getline(newOwner.Name, 30);
                cout << "Patronymic: "; cin.getline(newOwner.Patronymic, 30);
                cout << "Car Number: "; cin.getline(newOwner.CarNumber, 20);
                cout << "Technical Passport Number: "; cin.getline(newOwner.TechPass, 20);
                cout << "Registration Office: "; cin.getline(newOwner.RegistrationOffice, 50);

                temp.write((char*)&newOwner, sizeof(CarOwner));
            }
            added = true;
        }
        temp.write((char*)&owner, sizeof(CarOwner));
    }

    if (!added) {
        cout << "Error: Surname not found." << endl;
    }

    file.close();
    temp.close();
    remove(filename);
    rename("temp.bin", filename);
}

int main() {
    const char* filename = "car_owners.bin";

    int choice;
    do {
        cout << "\nMenu:\n"
            << "1. Create file\n"
            << "2. Print file\n"
            << "3. Delete by car number\n"
            << "4. Add 2 elements before surname\n"
            << "0. Exit\n"
            << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            createFile(filename);
            break;
        case 2:
            printFile(filename);
            break;
        case 3: {
            char carNumber[20];
            cout << "Enter car number to delete: ";
            cin.getline(carNumber, 20);
            deleteByCarNumber(filename, carNumber);
            break;
        }
        case 4: {
            char surname[30];
            cout << "Enter surname to add before: ";
            cin.getline(surname, 30);
            addBeforeSurname(filename, surname);
            break;
        }
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
