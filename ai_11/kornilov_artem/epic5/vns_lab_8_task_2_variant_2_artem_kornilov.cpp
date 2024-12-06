#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

struct Coworker {
    char name[15];
    char surname[15];
    char middleName[15];
    char position[25];
    int wage;
    int birhDay;
    int birthMonth;
    int birthYear;

};

void deleteSurname(Coworker& a) {
    strcpy(a.surname, "\0");

    ofstream outFileTemp("coworker_data_temp.txt", ios::binary);
    if (!outFileTemp) {
        cerr << "Error: File could not be opened." << endl;
    }

    outFileTemp.write(reinterpret_cast<char*>(&a), sizeof(Coworker));

    outFileTemp.close();

    remove("coworker_data.txt");
    rename("coworker_data_temp.txt", "coworker_data.txt");
}

void addNumber(fstream* out) {
    int n;
    cin >> n;

    out->seekp(0, ios::end);
    out->write(reinterpret_cast<char*>(&n), sizeof(int));
}

int main () {

    fstream outFile("coworker_data.txt", ios::out | ios::binary);
    if (!outFile) {
        cerr << "Error: File could not be opened." << endl;
    return 1;
    }

    Coworker a = {"Name", "Surenamenko", "Middlenamovich", "Toilet cleaner", 1000000, 1, 1, 1999};

    outFile.write(reinterpret_cast<char*>(&a), sizeof(Coworker));
    
    outFile.close();
    

    deleteSurname(a);
    
    outFile.open("coworker_data.txt", ios::in |  ios::out | ios::binary);
    if (!outFile) {
        cerr << "Error: File could not be opened." << endl;
    return 1;
    }

    addNumber(&outFile);

    Coworker b;
    int n;

    outFile.seekg(0, ios::beg);
    outFile.read(reinterpret_cast<char*>(&b), sizeof(Coworker));

    outFile.read(reinterpret_cast<char*>(&n), sizeof(int));

    cout << b.name << " " << b.surname << " " << b.middleName << " " << b.position << " " << b.wage << " ";
    cout << b.birhDay << "/" << b.birthMonth << "/" << b.birthYear << " " << n;
    
    outFile.close();

    return 0;
}