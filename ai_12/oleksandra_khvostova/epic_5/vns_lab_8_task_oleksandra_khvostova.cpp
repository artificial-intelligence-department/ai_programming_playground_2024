#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct {
    char name[50];
    char address[50];
    char group[50];
    int rate;
} Student;

void addInitialData(const char* filename);
void Delete(const char* filename, int rate);
void printFile(const char* filename);
void addNew(const char* filename, const Student& newStudent); // Fixed function declaration

int main() {
    const char* filename = "students.dat";
    addInitialData(filename);
    printFile(filename);

    int rate;
    cout << "Enter the minimum rate to keep students: ";
    cin >> rate;

    Delete(filename, rate);
    printFile(filename);

    Student newStudent = {"NewName", "NewAddress", "NewGroup", 88}; 
    addNew(filename, newStudent);
    printFile(filename);
    
    return 0;
}

void addInitialData(const char* filename) {
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        cerr << "Can't open the file." << endl;
        exit(1);
    }

    Student listOfStudents[] = {
        {"Name1", "Address1", "Group1", 21},
        {"Name2", "Address2", "Group2", 56},
        {"Name3", "Address3", "Group3", 43},
        {"Name4", "Address4", "Group4", 20},
        {"Name5", "Address5", "Group5", 28},
        {"Name6", "Address6", "Group6", 93}
    };

    for (int i = 0; i < 6; i++) {
        if (fwrite(&listOfStudents[i], sizeof(Student), 1, f) != 1) {
            cerr << "Error writing to file." << endl;
            exit(2);
        }
    }
    fclose(f);
    cout << "All students are added successfully." << endl;
}

void Delete(const char* filename, int rate) {
    FILE* fPtr = fopen(filename, "rb");
    if (fPtr == NULL) {
        cout << "Error opening file." << endl;
        return;
    }

    Student* fEmps = new Student[6];
    fread(fEmps, sizeof(Student), 6, fPtr);
    fclose(fPtr);

    // Count students with rating >= rate
    size_t cNewEms = 0;
    for (size_t i = 0; i < 6; i++) {
        if (fEmps[i].rate >= rate) {
            cNewEms++;
        }
    }

    Student* dEmps = new Student[cNewEms];
    size_t dEmpsI = 0;
    for (size_t i = 0; i < 6; i++) {
        if (fEmps[i].rate >= rate) {
            dEmps[dEmpsI++] = fEmps[i];
        }
    }

    FILE* fnPtr = fopen(filename, "wb");
    if (fnPtr == NULL) {
        cout << "Error opening file." << endl;
        delete[] fEmps;
        delete[] dEmps;
        return;
    }
    fwrite(dEmps, sizeof(Student), cNewEms, fnPtr);
    fclose(fnPtr);

    delete[] fEmps;
    delete[] dEmps;
}

void printFile(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        cerr << "Error opening file." << endl;
        exit(5);
    }

    Student person;
    cout << "Current list of students:" << endl;
    cout << "---------------------------------" << endl;

    while (fread(&person, sizeof(Student), 1, f) == 1) {
        cout << "Name: " << person.name << endl;
        cout << "Address: " << person.address << endl;
        cout << "Group: " << person.group << endl;
        cout << "Rate: " << person.rate << endl;
        cout << "---------------------------------" << endl;
    }

    fclose(f);
}

void addNew(const char* filename, const Student& newStudent) {
    // Open the file for reading
    FILE* fPtr = fopen(filename, "rb");
    if (fPtr == NULL) {
        cout << "Error opening file." << endl;
        return;
    }

    // Determine the number of existing records
    fseek(fPtr, 0, SEEK_END);
    long fileSize = ftell(fPtr);
    size_t numRecords = fileSize / sizeof(Student);
    fseek(fPtr, 0, SEEK_SET);

    // Read the existing students
    Student* emps = new Student[numRecords];
    fread(emps, sizeof(Student), numRecords, fPtr);
    fclose(fPtr);

    // Create a new array with one additional slot
    Student* newStudents = new Student[numRecords + 1];
    for (size_t i = 0; i < numRecords; i++) {
        newStudents[i] = emps[i];
    }
    newStudents[numRecords] = newStudent;

    // Write the new array back to the file
    FILE* fCptr = fopen(filename, "wb");
    if (fCptr == NULL) {
        cout << "Error opening file." << endl;
        delete[] emps;
        delete[] newStudents;
        return;
    }
    fwrite(newStudents, sizeof(Student), numRecords + 1, fCptr);
    fclose(fCptr);

    delete[] emps;
    delete[] newStudents;
}