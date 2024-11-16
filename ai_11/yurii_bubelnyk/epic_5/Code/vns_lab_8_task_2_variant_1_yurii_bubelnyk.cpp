#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct Abiturient {
    string firstName;
    string lastName;
    string patronymic;
    int birthYear;
    vector<int> examScores;
    double averageGrade;
};

double calculateAverage(const vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}
void addStudent(const char* filename) {
    Abiturient student;
    cout << "Enter student's first name: ";
    cin >> student.firstName;
    cout << "Enter student's last name: ";
    cin >> student.lastName;
    cout << "Enter student patronymic: ";
    cin >> student.patronymic;
    cout << "Enter birthYear: ";
    cin >> student.birthYear;
    cout << "Enter grades (separated by space, end with -1): ";
    int grade;
    while (std::cin >> grade && grade != -1) {
        student.examScores.push_back(grade);
    }

    FILE* file = fopen(filename, "a");
    if (file) {
        fprintf(file, "%s %s %s %d", student.firstName.c_str(), student.lastName.c_str(),
                student.patronymic.c_str(), student.birthYear);
        for (int g : student.examScores) {
            fprintf(file, " %d", g);
        }
        fprintf(file, "\n");
        fclose(file);
        cout << "Student added successfully!\n";
    } else {
        cerr << "Error opening file for writing!\n";
    }
}

void searchStudent(const char* filename, const string& lastName) {
    FILE* file = fopen(filename, "r");
    if (file) {
        char firstName[50], lastNameFromFile[50], patronymic[50];
        int birthYear;
        bool found = false;

        while (fscanf(file, "%s %s %s %d", firstName, lastNameFromFile, patronymic, &birthYear) == 4) {
            Abiturient student;
            student.firstName = firstName;
            student.lastName = lastNameFromFile;
            student.patronymic = patronymic;
            student.birthYear = birthYear;

            int grade;
            while (fscanf(file, "%d", &grade) == 1) {
                student.examScores.push_back(grade);
            }
            

            if (student.lastName == lastName) {
                cout << "Found student: " << student.firstName << " " << student.lastName << endl;
                cout << "Average grade: " << fixed << setprecision(2) << calculateAverage(student.examScores) << endl;
                found = true;
                break;
            }
        }
        fclose(file);
        if (!found) {
            cout << "No student found with the last name: " << lastName << endl;
        }
    } else {
        cerr << "Error opening file for reading!\n";
    }
}

void deleteStudentByLastName(const char* filename, const string& lastName) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        cerr << "Error opening file for reading!\n";
        return;
    }

    FILE* tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        cerr << "Error opening temporary file for writing!\n";
        fclose(file);
        return;
    }

    char firstName[50], lastNameFromFile[50], patronymic[50];
    int birthYear;
    vector<int> grades;
    bool found = false;

    while (fscanf(file, "%s %s %s %d", firstName, lastNameFromFile, patronymic, &birthYear) == 4) {
        grades.clear();
        int grade;
        while (fscanf(file, "%d", &grade) == 1) {
            grades.push_back(grade);
        }

        if (lastName == lastNameFromFile) {
            found = true;
            continue; 
        }

        fprintf(tempFile, "%s %s %s %d", firstName, lastNameFromFile, patronymic, birthYear);
        for (int g : grades) {
            fprintf(tempFile, " %d", g);
        }
        fprintf(tempFile, "\n");
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(filename);         
        rename("temp.txt", filename);   
        cout << "Student with last name \"" << lastName << "\" has been deleted.\n";
    } else {
        remove("temp.txt"); 
        cout << "No student found with the last name \"" << lastName << "\".\n";
    }
}

int main(){

    const char* filename = "Data.txt";
    int choice;
    string lastName;


    do {
        cout << "1. Add student\n2. Search student by last name\n3. Delete Student\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                cout << "Enter last name to search: ";
                cin >> lastName;
                searchStudent(filename, lastName);
                break;
            case 3:
                cout << "Enter last name to delete: ";
                cin >> lastName;
                deleteStudentByLastName(filename, lastName);
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cerr << "Invalid choice!\n";
        }
    } while (choice != 4);


    return 0;
}