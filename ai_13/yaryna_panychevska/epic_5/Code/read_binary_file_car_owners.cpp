#include <iostream>
#include <fstream>
using namespace std;

struct CarOwner {
    char Surname[30];
    char Name[30];
    char Patronymic[30];
    char CarNumber[20];
    char TechPass[20];
    char RegistrationOffice[50];
};

int main() {
    
    ifstream file("car_owners.bin", ios::binary);
    if (!file) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    CarOwner owner; 

    cout << "Data from the file:" << endl;
    int i = 1; 
    while (file.read((char*)&owner, sizeof(CarOwner))) {
        cout << "Record " << i++ << ":\n";
        cout << "Surname: " << owner.Surname << endl;
        cout << "Name: " << owner.Name << endl;
        cout << "Patronymic: " << owner.Patronymic << endl;
        cout << "Car Number: " << owner.CarNumber << endl;
        cout << "Technical Passport Number: " << owner.TechPass << endl;
        cout << "Registration Office: " << owner.RegistrationOffice << endl;
        cout << "---------------------------" << endl;
    }

    file.close(); 
    return 0;
}
