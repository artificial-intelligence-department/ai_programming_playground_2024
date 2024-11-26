#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Car {
    char brand[50];
    char serialNumber[20];
    char registrationNumber[20];
    int year;
};

void createFile(const char* filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    Car car;
    int numberOfCars;

    cout << "Enter the number of cars to add: ";
    cin >> numberOfCars;
    cin.ignore(); 

    for (int i = 0; i < numberOfCars; ++i) {
        cout << "Enter brand: ";
        cin.getline(car.brand, 50);
        cout << "Enter serial number: ";
        cin.getline(car.serialNumber, 20);
        cout << "Enter registration number: ";
        cin.getline(car.registrationNumber, 20);
        cout << "Enter year of manufacture: ";
        cin >> car.year;
        cin.ignore(); 

        outFile.write(reinterpret_cast<char*>(&car), sizeof(Car));
    }

    outFile.close();
    cout << "File created successfully." << endl;
}


void printFile(const char* filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    Car car;
    cout << "Car records in the file:" << endl;
    while (inFile.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
        cout << "Brand: " << car.brand << 
                ", Serial Number: " << car.serialNumber << 
                ", Registration Number: " << car.registrationNumber << 
                ", Year: " << car.year << endl;
    }
    inFile.close();
}


void addCar(const char* filename) {
    ofstream outFile(filename, ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error opening file for appending." << endl;
        return;
    }

    Car car;
    cout << "Enter brand: ";
    cin.ignore(); 
    cin.getline(car.brand, 50);
    cout << "Enter serial number: ";
    cin.getline(car.serialNumber, 20);
    cout << "Enter registration number: ";
    cin.getline(car.registrationNumber, 20);
    cout << "Enter year of manufacture: ";
    cin >> car.year;

    outFile.write(reinterpret_cast<char*>(&car), sizeof(Car));
    outFile.close();
    cout << "Car added successfully." << endl;
}


void deleteCar(const char* filename, const char* serialNumber) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        return;
    }

    Car car;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
        if (strcmp(car.serialNumber, serialNumber) != 0) {
            tempFile.write(reinterpret_cast<char*>(&car), sizeof(Car));
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove(filename); 
    rename("temp.txt", filename); 

    if (found) {
        cout << "Car with serial number " << serialNumber << " deleted successfully." << endl;
    } else {
        cout << "Car with serial number " << serialNumber << " not found." << endl;
    }
}


int main() {
    const char* filename = "cars.txt";
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create file\n";
        cout << "2. Print file contents\n";
        cout << "3. Add car\n";
        cout << "4. Delete car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                printFile(filename);
                break;
            case 3:
                addCar(filename);
                break;
            case 4: {
                char serialNumber[20];
                cout << "Enter the serial number of the car to delete: ";
                cin.ignore(); 
                cin.getline(serialNumber, 20);
                deleteCar(filename, serialNumber);
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}