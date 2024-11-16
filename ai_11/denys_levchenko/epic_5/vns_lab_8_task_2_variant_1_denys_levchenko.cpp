#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
struct Owner {
    char name[50];
    char car_number[20];
    char phone[20];
    char passport_number[20];
};

void addRecord(ofstream &file) {
    Owner owner;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(owner.name, 50);
    cout << "Enter Car Number: ";
    cin.getline(owner.car_number, 20);
    cout << "Enter Phone: ";
    cin.getline(owner.phone, 20);
    cout << "Enter Passport Number: ";
    cin.getline(owner.passport_number, 20);
    file.write(reinterpret_cast<char*>(&owner), sizeof(Owner));
}


void printRecords(ifstream &file) {
    Owner owner;
    while (file.read(reinterpret_cast<char*>(&owner), sizeof(Owner))) {
        cout << "Name: " << owner.name << "\n";
        cout << "Car Number: " << owner.car_number << "\n";
        cout << "Phone: " << owner.phone << "\n";
        cout << "Passport Number: " << owner.passport_number << "\n";
        cout << "-----------------------\n";
    }
}

void deleteRecord(const char* filename, const char* passportToDelete) {
    ifstream file(filename, ios::binary);
    ofstream temp("temp.dat", ios::binary);
    Owner owner;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&owner), sizeof(Owner))) {
        if (strcmp(owner.passport_number, passportToDelete) != 0) {
            temp.write(reinterpret_cast<char*>(&owner), sizeof(Owner));
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();
    remove(filename);
    rename("temp.dat", filename);

    if (found) {
        cout << "Record deleted.\n";
    } else {
        cout << "Record not found.\n";
    }
}

void insertRecordBeforeName(const char* filename, const char* nameToFind) {
    ifstream file(filename, ios::binary);
    ofstream temp("temp.dat", ios::binary);
    Owner owner;
    bool inserted = false;

    while (file.read(reinterpret_cast<char*>(&owner), sizeof(Owner))) {
        if (!inserted && strcmp(owner.name, nameToFind) == 0) {
            cout << "Insert new record:\n";
            addRecord(temp);
            inserted = true;
        }
        temp.write(reinterpret_cast<char*>(&owner), sizeof(Owner));
    }

    if (!inserted) {
        cout << "Name not found. Adding record at the end.\n";
        addRecord(temp);
    }

    file.close();
    temp.close();
    remove(filename);
    rename("temp.dat", filename);
}

int main() {
    const char* filename = "owners.dat";
    int choice;
    char searchValue[50];

    while (true) {
        cout << "1. Add Record\n2. Print Records\n3. Delete Record by Passport Number\n4. Insert Record Before Name\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream file(filename, ios::binary | ios::app);
            addRecord(file);
            file.close();
        } else if (choice == 2) {
            ifstream file(filename, ios::binary);
            printRecords(file);
            file.close();
        } else if (choice == 3) {
            cout << "Enter Passport Number to delete: ";
            cin >> searchValue;
            deleteRecord(filename, searchValue);
        } else if (choice == 4) {
            cout << "Enter Name to insert record before: ";
            cin.ignore();
            cin.getline(searchValue, 50);
            insertRecordBeforeName(filename, searchValue);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
