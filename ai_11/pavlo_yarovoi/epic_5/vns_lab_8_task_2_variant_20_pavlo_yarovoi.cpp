#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Country {
    char name[50];
    char language[50];
    char currency[50];
    double exchangeRate;
};

void createFile(const char* filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Cannot create file." << endl;
        return;
    }

    Country countries[] = {
        {"USA", "English", "Dollar", 1.0},
        {"Japan", "Japanese", "Yen", 0.007},
        {"Germany", "German", "Euro", 1.1}
    };

    for (auto& country : countries) {
        file.write(reinterpret_cast<char*>(&country), sizeof(Country));
    }

    file.close();
}

void printFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Cannot open file for reading." << endl;
        return;
    }

    Country country;
    while (file.read(reinterpret_cast<char*>(&country), sizeof(Country))) {
        cout << "Name: " << country.name
             << ", Language: " << country.language
             << ", Currency: " << country.currency
             << ", Exchange Rate: " << country.exchangeRate << endl;
    }

    file.close();
}

bool searchAndDelete(const char* filename, const char* targetName) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Cannot open file for reading." << endl;
        return false;
    }

    ofstream tempFile("temp.bin", ios::binary);
    if (!tempFile) {
        cerr << "Error: Cannot create temporary file." << endl;
        return false;
    }

    Country country;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&country), sizeof(Country))) {
        if (strcmp(country.name, targetName) == 0) {
            found = true;
        } else {
            tempFile.write(reinterpret_cast<char*>(&country), sizeof(Country));
        }
    }

    file.close();
    tempFile.close();

    remove(filename);
    rename("temp.bin", filename);

    return found;
}

void addCountry(const char* filename, const Country& newCountry) {
    ofstream file(filename, ios::binary | ios::app);
    if (!file) {
        cerr << "Error: Cannot open file for appending." << endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&newCountry), sizeof(Country));
    file.close();
}

int main() {
    const char* filename = "countries.bin";
    createFile(filename);

    cout << "Initial file contents:" << endl;
    printFile(filename);

    if (searchAndDelete(filename, "Germany")) {
        cout << "Country deleted successfully." << endl;
    } else {
        cout << "Country not found." << endl;
    }

    cout << "File contents after deletion:" << endl;
    printFile(filename);

    Country newCountry = {"India", "Hindi", "Rupee", 0.012};
    addCountry(filename, newCountry);

    cout << "File contents after addition:" << endl;
    printFile(filename);

    return 0;
}
