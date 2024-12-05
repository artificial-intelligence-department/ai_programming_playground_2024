#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Student {
    char surname[50];
    char name[50];
    char patronymic[50];
    int grade;  
    char phone[15];
    int math, physics, ukrainian, literature; 
};

void printStudent(const Student& s) {
    cout << setw(15) << s.surname << " "
         << setw(15) << s.name << " "
         << setw(15) << s.patronymic << " "
         << "Grade: " << s.grade << ", Phone: " << s.phone
         << ", Scores [Math: " << s.math << ", Phys: " << s.physics
         << ", Ukr: " << s.ukrainian << ", Lit: " << s.literature << "]\n";
}

void printFile(const char* filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Failed to open the file for reading!\n";
        return;
    }
    Student s;
    while (inFile.read((char*)&s, sizeof(Student))) {
        printStudent(s);
    }
    inFile.close();
}

void writeToFile(const char* filename, Student* students, int count) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Failed to open the file for writing!\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        outFile.write((char*)&students[i], sizeof(Student));
    }
    outFile.close();
}

int readFromFile(const char* filename, Student*& students) {
    ifstream inFile(filename, ios::binary | ios::ate);
    if (!inFile) {
        cerr << "Failed to open the file for reading!\n";
        return 0;
    }
    streamsize size = inFile.tellg();
    int count = size / sizeof(Student);
    students = new Student[count];
    inFile.seekg(0, ios::beg);
    inFile.read((char*)students, size);
    inFile.close();
    return count;
}

void deleteLowScores(const char* filename) {
    Student* students = nullptr;
    int count = readFromFile(filename, students);

    if (count == 0) return;

    Student* filteredStudents = new Student[count];
    int newCount = 0;

    for (int i = 0; i < count; ++i) {
        if (students[i].math != 2 && students[i].physics != 2 &&
            students[i].ukrainian != 2 && students[i].literature != 2) {
            filteredStudents[newCount++] = students[i];
        }
    }

    writeToFile(filename, filteredStudents, newCount);

    delete[] students;
    delete[] filteredStudents;
}

void addToStart(const char* filename, const Student& newStudent) {
    Student* students = nullptr;
    int count = readFromFile(filename, students);

    Student* updatedStudents = new Student[count + 1];
    updatedStudents[0] = newStudent;
    for (int i = 0; i < count; ++i) {
        updatedStudents[i + 1] = students[i];
    }

    writeToFile(filename, updatedStudents, count + 1);

    delete[] students;
    delete[] updatedStudents;
}

int main() {
    const char* filename = "students.dat";

    Student students[] = {
        {"Ivanov", "Ivan", "Ivanovich", 10, "097-456...", 5, 4, 3, 2},
        {"Petrov", "Petr", "Petrovich", 9, "097-567...", 2, 5, 4, 5},
        {"Sidorov", "Sidr", "Sidorovich", 8, "097-678...", 4, 4, 4, 4}
    };
    int count = sizeof(students) / sizeof(students[0]);

    writeToFile(filename, students, count);

    cout << "Initial file content:\n";
    printFile(filename);

    deleteLowScores(filename);

    cout << "\nAfter deleting students with low scores:\n";
    printFile(filename);

    Student newStudent = {"Alex", "Alex", "Alexandrovich", 11, "456-789", 5, 5, 5, 5};
    addToStart(filename, newStudent);

    cout << "\nAfter adding a new student:\n";
    printFile(filename);

    return 0;
}
