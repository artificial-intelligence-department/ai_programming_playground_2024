#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Patient {
    char surname[50];
    char name[50];
    char patronymic[50];
    char address[100];
    int medicalCardNumber;
    int insurancePolicyNumber;
};


void createFile(const string& filename, const vector<Patient>& patients) {
    ofstream file(filename, ios::binary);
    
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& patient : patients) {
        file.write(reinterpret_cast<const char*>(&patient), sizeof(Patient));
    }
    file.close();
}

void printFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    Patient patient;
    while (file.read(reinterpret_cast<char*>(&patient), sizeof(Patient))) {
        cout << "Patient: " << patient.surname << " " << patient.name << " " << patient.patronymic << endl;
        cout << "Adress: " << patient.address << endl;
        cout << "Medical card number: " << patient.medicalCardNumber << endl;
        cout << "Insurance policy number: " << patient.insurancePolicyNumber << endl;
        cout << "---------------------------" << endl;
    }
    file.close();
}

void addPatientsAtStart(const string& filename, const vector<Patient>& newPatients) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    vector<Patient> patients(newPatients);
    Patient patient;
    while (file.read(reinterpret_cast<char*>(&patient), sizeof(Patient))) {
        patients.push_back(patient);
    }
    file.close();

    ofstream outFile(filename, ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& p : patients) {
        outFile.write(reinterpret_cast<const char*>(&p), sizeof(Patient));
    }
    outFile.close();
}

void deletePatientByCardNumber(const string& filename, int cardNumber) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    vector<Patient> patients;
    Patient patient;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&patient), sizeof(Patient))) {
        if (patient.medicalCardNumber != cardNumber) {
            patients.push_back(patient);
        } else {
            found = true;
        }
    }
    file.close();

    if (!found) {
        cerr << "Patient with medical record number " << cardNumber << " not found!" << endl;
        return;
    }

    ofstream outFile(filename, ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& p : patients) {
        outFile.write(reinterpret_cast<const char*>(&p), sizeof(Patient));
    }
    outFile.close();
}

int main() {
    string filename = "patients.bin";

    vector<Patient> initialPatients = {
        {"Shevchenko", "Taras", "Hryhorovych", "Poltava", 12345, 67890},
        {"Kovalenko", "Oleksandr", "Petrovych", "Rivne", 12346, 67891}
    };
    
    createFile(filename, initialPatients);
    cout << "The initial contents of the file:" << endl;
    printFile(filename);


    int cardNumberToDelete = 12345;
    deletePatientByCardNumber(filename, cardNumberToDelete);
    cout << "File contents after deleting a patient with a medical record number " << cardNumberToDelete << ":" << endl;
    printFile(filename);

    vector<Patient> newPatients = {
        {"Doroshenko", "Mykola", "Ivanovych", "Kryvyi Rih", 12347, 67892},
        {"Lytvynenko", "Vasyl", "Anatoliyovych", "Lviv", 12348, 67893}
    };
    addPatientsAtStart(filename, newPatients);
    cout << "File contents after adding patients:" << endl;
    printFile(filename);

    return 0;
}