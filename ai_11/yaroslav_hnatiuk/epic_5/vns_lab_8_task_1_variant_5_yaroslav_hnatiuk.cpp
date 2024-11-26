#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Human {
    string fullName;
    int birthYear;
    int growthSm;
    int weightKg;
};

Human formElement();
void showElement();
void appendElement();
void deleteElement();

int main() {
    int choice;

    cout << "Available operations:\n";
    cout << "1. View all records\n";
    cout << "2. Add a record after the person with the specified surname\n";
    cout << "3. Delete records with the specified height and weight\n\n";
    cout << "What would you like to do?: ";
    cin >> choice;

    switch (choice) {
        case 1:
            showElement();
            break;
        case 2:
            appendElement();
            break;
        case 3:
            deleteElement();
            break;
        default:
            cout << "Invalid choice";
    }

    return 0;
}

Human formElement() {
    Human createHuman;

    cout << "Enter full name (Last Name, First Name, Patronymic): ";
    cin.ignore();
    getline(cin, createHuman.fullName);

    cout << "Enter year of birth: ";
    cin >> createHuman.birthYear;
    cout << "Enter height (cm): ";
    cin >> createHuman.growthSm;
    cout << "Enter weight (kg): ";
    cin >> createHuman.weightKg;

    return createHuman;
}

void showElement() {
    ifstream file("Humans.txt");
    if (!file) {
        cout << "File not found" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void appendElement() {
    string surname;
    cout << "Enter the last name of the person after whom a new record will be added: ";
    cin >> surname;

    ifstream file("Humans.txt");
    if (!file) {
        cout << "File not found" << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.clear();
    file.close();

    Human newHuman = formElement();

    for (int i = 0; i < lines.size(); i += 5) {
        if (lines[i].find(surname) != string::npos) {
            lines.insert(lines.begin() + i + 4, "");
            lines.insert(lines.begin() + i + 5, newHuman.fullName);
            lines.insert(lines.begin() + i + 6, to_string(newHuman.birthYear));
            lines.insert(lines.begin() + i + 7, to_string(newHuman.growthSm));
            lines.insert(lines.begin() + i + 8, to_string(newHuman.weightKg));
            break;
        }
    }

    ofstream file1("Humans.txt");

    if (!file1) {
        cout << "File not found" << endl;
        return;
    }

    for (int i = 0; i < lines.size(); i++) file1 << lines[i] << endl;

    file.close();
}

void deleteElement() {  
    string height, weight;
    cout << "Enter height of the person to delete: ";
    cin >> height;
    cout << "Enter weight of the person to delete: ";
    cin >> weight;

    ifstream file("Humans.txt");
    if (!file) {
        cout << "File not found" << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.clear();
    file.close();

    for (int i = 0; i < lines.size(); i += 1) cout << lines[i] << " ";

    for (int i = 3; i < lines.size(); i += 5) {
        if (lines[i] == weight && lines[i - 1] == height) {
            lines.erase(lines.begin() + i + 1);
            lines.erase(lines.begin() + i);
            lines.erase(lines.begin() + i - 1);
            lines.erase(lines.begin() + i - 2);
            lines.erase(lines.begin() + i - 3);

        }
    }

    ofstream file1("Humans.txt");

    if (!file1) {
        cout << "File not found" << endl;
        return;
    }

    for (int i = 0; i < lines.size(); i++) file1 << lines[i] << endl;

    file.close();
}
