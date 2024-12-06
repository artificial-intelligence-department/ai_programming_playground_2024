#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Patient {
    char lastName[40];
    char firstName[40];
    char middleName[40];
    char address[100];
    int medicalCardNumber;
    int insurancePolicyNumber;
};

// Функція для введення даних пацієнта з клавіатури
Patient inputPatient() {
    Patient patient;
    cout << "Введіть прізвище: ";
    cin >> patient.lastName;
    cout << "Введіть ім'я: ";
    cin >> patient.firstName;
    cout << "Введіть по батькові: ";
    cin >> patient.middleName;
    cout << "Введіть адресу: ";
    cin.ignore();
    cin.getline(patient.address, 100);
    cout << "Введіть номер медичної карти: ";
    cin >> patient.medicalCardNumber;
    cout << "Введіть номер страхового поліса: ";
    cin >> patient.insurancePolicyNumber;
    return patient;
}

// Функція для збереження пацієнтів у файл
void savePatientsToFile(const char* filename, const vector<Patient>& patients) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        cerr << "Помилка при відкритті файлу для запису!" << endl;
        exit(1);
    }
    fwrite(&patients[0], sizeof(Patient), patients.size(), file);
    if (ferror(file)) {
        cerr << "Помилка при записі у файл." << endl;
        exit(2);
    }
    fclose(file);
}

// Функція для читання пацієнтів із файлу
vector<Patient> readPatientsFromFile(const char* filename) {
    vector<Patient> patients;
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        exit(3);
    }
    Patient temp;
    while (fread(&temp, sizeof(Patient), 1, file)) {
        patients.push_back(temp);
    }
    fclose(file);
    return patients;
}

// Функція для друку пацієнтів
void printPatients(const vector<Patient>& patients) {
    cout << "Вміст файлу:" << endl;
    for (const auto& patient : patients) {
        cout << patient.lastName << " " << patient.firstName << " " << patient.middleName << " "
             << patient.address << " " << patient.medicalCardNumber << " " << patient.insurancePolicyNumber << endl;
    }
}

// Функція для знищення пацієнта із заданим номером медичної карти
void deletePatientByMedicalCardNumber(vector<Patient>& patients, int cardNumber) {
    auto it = remove_if(patients.begin(), patients.end(),
        [cardNumber](const Patient& patient) { return patient.medicalCardNumber == cardNumber; });
    if (it != patients.end()) {
        patients.erase(it, patients.end());
    } else {
        cerr << "Пацієнта з номером медичної карти " << cardNumber << " не знайдено." << endl;
    }
}

// Функція для додавання пацієнтів до файлу
void addPatientsToBeginning(const char* filename, const vector<Patient>& newPatients) {
    vector<Patient> existingPatients = readPatientsFromFile(filename);
    existingPatients.insert(existingPatients.begin(), newPatients.begin(), newPatients.end());
    savePatientsToFile(filename, existingPatients);
}

int main() {
    const char* filename = "patients.dat";
    vector<Patient> patients;

    // Введення пацієнтів
    int choice;
    do {
        patients.push_back(inputPatient());
        cout << "Бажаєте додати ще одного пацієнта? (1 - Так, 0 - Ні): ";
        cin >> choice;
    } while (choice != 0);

    // Зберігаємо початкових пацієнтів у файл
    savePatientsToFile(filename, patients);

    // Зчитуємо та друкуємо пацієнтів з файлу
    patients = readPatientsFromFile(filename);
    cout << "Початковий список пацієнтів:" << endl;
    printPatients(patients);

    // Знищуємо пацієнта з номером медичної карти 23456
    deletePatientByMedicalCardNumber(patients, 23456);

    // Зберігаємо оновлений список пацієнтів у файл
    savePatientsToFile(filename, patients);

    // Додаємо нових пацієнтів на початок файлу
    vector<Patient> newPatients = {
        {"Ostap", "Tsiapa", "Andriyovych", "Ternopil, 83", 23456, 90123},
        {"Lionel", "Messi", "Andres", "Barcelona, 10", 56789, 12345}
    };
    addPatientsToBeginning(filename, newPatients);

    // Знову зчитуємо та друкуємо пацієнтів з файлу
    patients = readPatientsFromFile(filename);
    cout << "Оновлений список пацієнтів:" << endl;
    printPatients(patients);

    return 0;
}
