#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

struct Dergava {
    char naming[50];
    char capital[50];
    long long naselennia;
    long long ploshcha;
};

void adder(const char* filename) {
    FILE* file = fopen(filename, "wb");

    if (file == NULL) {
        cerr << "Error opening file for writing." << endl;
        exit(1);
    }

    Dergava countries[] = {
        {"Argentina", "Buenos Aires", 45195774, 2780400},
        {"Ukraine", "Kyiv", 41902416, 603628},
        {"Germany", "Berlin", 83166711, 357022},
        {"Canada", "Ottawa", 38005238, 9984670}
    };

    fwrite(countries, sizeof(Dergava), 4, file);
    fclose(file);
}

void deleteByPopulation(const char* filename, long long population) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "Error opening file for reading." << endl;
        exit(2);
    }

    vector<Dergava> validCountries;
    Dergava country;

    while (fread(&country, sizeof(Dergava), 1, file) == 1) {
        if (country.naselennia >= population) {
            validCountries.push_back(country);
        }
    }
    fclose(file);

    file = fopen(filename, "wb");
    if (file == NULL) {
        cerr << "Error opening file for writing." << endl;
        exit(3);
    }

    for (const auto& c : validCountries) {
        fwrite(&c, sizeof(Dergava), 1, file);
    }
    fclose(file);

    cout << "Countries with population less than " << population << " have been deleted." << endl;
}

void addAfterCountry(const char* filename, const Dergava& newCountry, const char* tempName) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "Error opening file for reading." << endl;
        exit(4);
    }

    vector<Dergava> countries;
    Dergava country;
    bool found = false;

    while (fread(&country, sizeof(Dergava), 1, file) == 1) {
        countries.push_back(country);
        if (strcmp(country.naming, tempName) == 0) {
            countries.push_back(newCountry);
            found = true;
        }
    }

    if (!found) {
        cout << "Country with name '" << tempName << "' not found, try again " << endl;
        
    }

    fclose(file);

    

    file = fopen(filename, "wb");
    if (file == NULL) {
        cerr << "Error opening file for writing." << endl;
        exit(5);
    }

    for (const auto& c : countries) {
        fwrite(&c, sizeof(Dergava), 1, file);
    }
    fclose(file);

}

void displayCountries(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "Error opening file for reading." << endl;
        exit(6);
    }

    Dergava country;
    cout << "List of countries:" << endl;
    cout << "------------------------" << endl;
    while (fread(&country, sizeof(Dergava), 1, file) == 1) {
        cout << "Country: " << country.naming << endl;
        cout << "Capital: " << country.capital << endl;
        cout << "Population: " << country.naselennia << endl;
        cout << "Area: " << country.ploshcha << endl;
        cout << "------------------------" << endl;
    }
    fclose(file);
}

int main() {
    const char* fileTitle = "countries.bin";
    adder(fileTitle);

    int choice;
    while ( choice != 4) {
        cout << "\nChoose an option:\n";
        cout << "1 - Delete countries with population less than specified\n";
        cout << "2 - Add a new country after a specified country\n";
        cout << "3 - Display all countries\n";
        cout << "4 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            long long population;
            cout << "Enter minimum population to keep: ";
            cin >> population;
            deleteByPopulation(fileTitle, population);
        } 
        else if (choice == 2) {
            Dergava newCountry;
            cout << "Enter new country details:\n";
            cout << "Name: ";
            cin >> ws; 
            cin.getline(newCountry.naming, 50);
            cout << "Capital: ";
            cin.getline(newCountry.capital, 50);
            cout << "Population: ";
            cin >> newCountry.naselennia;
            cout << "Area: ";
            cin >> newCountry.ploshcha;

            char targetName[50];
            cout << "Enter the name of the country to add after: ";
            cin >> ws;
            cin.getline(targetName, 50);

            addAfterCountry(fileTitle, newCountry, targetName);
        } 
        else if (choice == 3) {
            displayCountries(fileTitle);
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
