#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <vector>
#include <iomanip>

using namespace std;

struct Car 
{
    char brand[50]; 
    int serialNumber; 
    char regNumber[30]; 
    int year; 
};

void process_file(const string& filename, vector<Car>& cars)
{
    ofstream outfile(filename, ios::binary);
    if(!outfile.is_open())
    {
    cout << "Error: Unable to creat a file";
    return;
    }

    for (const Car& car : cars) 
    {
        outfile.write(car.brand, sizeof(car.brand));
        outfile.write(reinterpret_cast<const char*>(&car.serialNumber), sizeof(car.serialNumber));
        outfile.write(car.regNumber, sizeof(car.regNumber));
        outfile.write(reinterpret_cast<const char*>(&car.year), sizeof(car.year));
    }

    outfile.close();

    ifstream infile(filename, ios::binary);
    if(!infile.is_open())
    {
        cout << "Error: Unable to read the file :(";
        return;
    }

    cout << left << setw(50) << "Brand" << setw(15) << "Serial Number" << setw(15) << "Reg Number" << setw(15) << "Year" << endl;
    cout << "_____________________________________________________________________________" << endl;
    Car carR;
    while(infile.read(reinterpret_cast<char*>(&carR), sizeof(Car)))
    {
        cout << setw(50) << carR.brand << setw(15) << carR.serialNumber << setw(15) << carR.regNumber << setw(15) << carR.year << endl;
    }

    infile.close();

    if(cars.size() >= 3) 
    {
        cars.erase(cars.begin(), cars.begin() + 3); 
    }
        
    Car newCar = {"NewBrand", 12345, "ABC123", 2023};
    cars.push_back(newCar);

    outfile.open(filename, ios::binary | ios::trunc); 
    if(!outfile.is_open()) 
    {
        cout << "Error: Unable to create the file" << endl;
        return;
    }

    for(const Car& car : cars) 
    {
        outfile.write(car.brand, sizeof(car.brand));
        outfile.write(reinterpret_cast<const char*>(&car.serialNumber), sizeof(car.serialNumber));
        outfile.write(car.regNumber, sizeof(car.regNumber));
        outfile.write(reinterpret_cast<const char*>(&car.year), sizeof(car.year));
    }

    outfile.close();

    infile.open(filename, ios::binary);
    if(!infile.is_open()) 
    {
        cout << "Error: Unable to read the file :(" << endl;
        return;
    }

    cout << "\nUpdated file content:" << endl;
    cout << left << setw(50) << "Brand" << setw(15) << "Serial Number" << setw(15) << "Reg Number" << setw(15) << "Year" << endl;
    cout << "__________________________________________________________________________________" << endl;

    while(infile.read(reinterpret_cast<char*>(&carR), sizeof(Car))) 
    {
        cout << setw(50) << carR.brand << setw(15) << carR.serialNumber << setw(15) << carR.regNumber << setw(15) << carR.year << endl;
    }

    infile.close();
}

int main()
{
    vector<Car> cars = 
    {
    {"Toyota", 12345, "AB1234AA", 2010},   
    { "Honda", 67890, "KH5678KH", 2015},    
    {  "Ford", 11223, "KS9101KS", 2012},     
    {   "BMW", 33445, "DP1122DP", 2020}
    };

    string filename = "cars.dat.bin";
    process_file(filename, cars);

    cout << "File updated successfully!" << endl;

    return 0;
}
