#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Car {
    char brand[50];
    int serial_number;
    char reg_number[20];
    int year;
};

void addCarToFile(const string& filename, const Car& car) {
    ofstream file(filename, ios::binary | ios::app);
    if (file) {
        file.write(reinterpret_cast<const char*>(&car), sizeof(Car));
        cout << "Added car to file: " << car.brand << " " << car.serial_number << " " << car.reg_number << " " << car.year << endl;
    }
}

void printCarsFromFile(const string& filename) {
    ifstream file(filename, ios::binary);
    Car car;
    cout << "Current cars in file:\n";
    while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
        cout << car.brand << " " << car.serial_number << " " << car.reg_number << " " << car.year << endl;
    }
    cout << endl;
}

void deleteFirstThreeCars(const string& filename) {
    ifstream file(filename, ios::binary);
    vector<Car> cars;
    Car car;
    while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
        cars.push_back(car);
    }
    file.close();

    ofstream outFile(filename, ios::binary | ios::trunc);
    if (cars.size() <= 3) {
        cout << "Deleted all cars from the file since there are 3 or fewer cars." << endl;
    } else {
        for (size_t i = 3; i < cars.size(); ++i) {
            outFile.write(reinterpret_cast<const char*>(&cars[i]), sizeof(Car));
        }
        cout << "Deleted the first three cars from the file." << endl;
    }
}

void addCarAfterRegNumber(const string& filename, const string& targetRegNumber, const Car& newCar) {
    ifstream file(filename, ios::binary);
    vector<Car> cars;
    Car car;
    while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
        cars.push_back(car);
    }
    file.close();

    ofstream outFile(filename, ios::binary | ios::trunc);
    bool carAdded = false;
    for (size_t i = 0; i < cars.size(); ++i) {
        outFile.write(reinterpret_cast<const char*>(&cars[i]), sizeof(Car));
        if (targetRegNumber == cars[i].reg_number && !carAdded) {
            outFile.write(reinterpret_cast<const char*>(&newCar), sizeof(Car));
            cout << "Added new car after registration number " << targetRegNumber << ": "
                 << newCar.brand << " " << newCar.serial_number << " " << newCar.reg_number << " " << newCar.year << endl;
            carAdded = true;
        }
    }

    if (!carAdded) {
        cout << "Registration number " << targetRegNumber << " not found. New car not added." << endl;
    }
}

Car createCar() {
    Car car;
    cout << "Enter car details (brand, serial_number, reg_number, year):\n";
    cin.ignore();
    cin.getline(car.brand, 50);
    cin >> car.serial_number;
    cin.ignore();
    cin.getline(car.reg_number, 20);
    cin >> car.year;
    return car;
}

int main() {
    const string filename = "cars.dat";

    int n;
    cout << "Enter number of cars to add: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        addCarToFile(filename, createCar());
    }

    printCarsFromFile(filename);

    cout << "Deleting the first three cars from the file...\n";
    deleteFirstThreeCars(filename);
    printCarsFromFile(filename);

    string regNum;
    cout << "Enter registration number after which to add a new car: ";
    cin >> regNum;
    addCarAfterRegNumber(filename, regNum, createCar());
    printCarsFromFile(filename);

    return 0;
}
