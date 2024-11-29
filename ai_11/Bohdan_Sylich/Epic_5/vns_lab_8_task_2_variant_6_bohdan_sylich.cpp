#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Schoolboy {
    string surname;
    string name;
    string patronymic;
    int classNumber;
    string phoneNumber;
    int grades[4]; // 0 - математика, 1 - фізика, 2 - українська мова, 3 - література
};

// Function to create a binary file
void createBinaryFile(const string& filename, const vector<Schoolboy>& schoolboys) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error: Failed to open the file for writing!" << endl;
        return;
    }

    for (const auto& schoolboy : schoolboys) {
        outFile.write(reinterpret_cast<const char*>(&schoolboy), sizeof(Schoolboy));
    }

    outFile.close();
}

// Function to print the binary file content
void printBinaryFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error: Failed to open the file for reading!" << endl;
        return;
    }

    Schoolboy schoolboy;
    while (inFile.read(reinterpret_cast<char*>(&schoolboy), sizeof(Schoolboy))) {
        cout << "Прізвище: " << schoolboy.surname << ", Ім'я: " << schoolboy.name
             << ", По батькові: " << schoolboy.patronymic << ", Клас: " << schoolboy.classNumber
             << ", Телефон: " << schoolboy.phoneNumber << ", Оцінки: "
             << schoolboy.grades[0] << ", " << schoolboy.grades[1] << ", "
             << schoolboy.grades[2] << ", " << schoolboy.grades[3] << endl;
    }

    inFile.close();
}

// Function to add a new schoolboy to the binary file
void addSchoolboy(const string& filename, const Schoolboy& newSchoolboy) {
    ofstream outFile(filename, ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error: Failed to open the file for appending!" << endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&newSchoolboy), sizeof(Schoolboy));
    outFile.close();
}

// Function to delete a schoolboy from the binary file
void deleteSchoolboy(const string& filename, const string& surname) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error: Failed to open the file for reading!" << endl;
        return;
    }

    vector<Schoolboy> schoolboys;
    Schoolboy schoolboy;

    while (inFile.read(reinterpret_cast<char*>(&schoolboy), sizeof(Schoolboy))) {
        schoolboys.push_back(schoolboy);
    }

    inFile.close();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error: Failed to open the file for writing!" << endl;
        return;
    }

    for (const auto& sb : schoolboys) {
        if (sb.surname != surname) {
            outFile.write(reinterpret_cast<const char*>(&sb), sizeof(Schoolboy));
        }
    }

    outFile.close();
}

int main() {
    string filename = "schoolboys.dat";

    // Create the binary file
    vector<Schoolboy> schoolboys = {
        {"Іваненко", "Іван", "Іванович", 10, "123456789", {5, 4, 5, 5 }},
        {"Петренко", "Петро", "Петрович", 9, "987654321", {4, 4, 3, 5}},
        {"Сидоренко", "Сидір", "Сидорович", 11, "456789123", {5, 5, 5, 5}}
    };

    createBinaryFile(filename, schoolboys);

    cout << "Вміст файлу:" << endl;
    printBinaryFile(filename);

    // Adding a new schoolboy
    Schoolboy newSchoolboy = {"Коваленко", "Олег", "Олегович", 8, "111222333", {3, 4, 4, 3}};
    addSchoolboy(filename, newSchoolboy);

    cout << "Вміст файлу після додавання нового школяра:" << endl;
    printBinaryFile(filename);

    // Deleting a schoolboy
    deleteSchoolboy(filename, "Петренко");

    cout << "Вміст файлу після видалення школяра Петренка:" << endl;
    printBinaryFile(filename);

    return 0;
}