#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

const string fileName = "students.csv";

struct Student {
    string name;
    int age;
    double grade;
    string faculty;
};

void write(Student *arr, int size) {
    ofstream file(fileName);
    if(!file.is_open()) {
        cerr << "Error: file in not opened\n";
        return;
    }
    for(int i = 0; i < size; i++) {
        file << arr[i].name << "," << arr[i].age << "," << arr[i].grade << "," << arr[i].faculty << "\n";
    }
    file.close();
}

void print(Student *arr, int size) {
    ifstream file(fileName);
    if(!file.is_open()) {
        cerr << "Error: file in not opened\n";
        return;
    }
    cout << "File contains:\n";
    cout << setw(13) << "Name" << setw(13) << "Age" << setw(13) << "Grade" << setw(13) << "Faculty\n";
    string buffer;
    string word = "";
    while(getline(file, buffer)) {
        for(int i = 0; i < buffer.size(); i++) {
            if(buffer[i] == ',') {
                cout << setw(13) << word;
                word = "";
            } else if(i == buffer.size()-1) {
                word += buffer[i];
                cout << setw(13) << word << "\n";
                word = "";
            }
            else word += buffer[i];
        }
        cout << "\n";
    }
    file.close();
}

Student* addNewStudent(Student *arr, int size) {
    cout << "Enter data about new student:\n";
    Student student;
    cout << "Name: ";
    cin >> student.name;
    cout << "Age: ";
    cin >> student.age;
    cout << "Grade: ";
    cin >> student.grade;
    cout << "Faculty: ";
    cin >> student.faculty;
    Student *array = new Student[size+1];
    for(int i = 0; i < size; i++) 
        array[i] = arr[i];
    array[size] = student;

    ofstream file(fileName, ios::app);
    if(!file.is_open()) {
        cerr << "Error: file in not opened\n";
        return 0;
    }
    file << student.name << "," << student.age << "," << student.grade << "," << student.faculty << "\n";
    return array;
}

void getMiddleGradesFac(Student *arr, int size) {
    map<string, int> dict;
    for(int i = 0; i < size; i++) {
        int counter = count_if(arr, arr + size, [arr, i](Student &student){
            return student.faculty == arr[i].faculty;
        });
        dict.emplace(arr[i].faculty, counter);
    }
    int len = dict.size();
    for(const auto el : dict) {
        double grades = 0;
        for(int j = 0; j < size; j++) {
            if(arr[j].faculty == el.first)
                grades += arr[j].grade;
        }
        cout << "Average grade in " << el.first << " = " << grades/el.second << "\n";
    }
}

void findBestStudents(Student* arr, int size) {
    set<string> faculties;
    for(int i = 0; i < size; i++)
        faculties.insert(arr[i].faculty);
    for(const auto el : faculties) {
        double grade = -1.0;
        int index = -1;
        for(int i = 0; i < size; i++) {
            if(arr[i].faculty == el) {
                if(arr[i].grade > grade)
                    index = i;
            }
        }
        cout << "The best student on " << el << " is " << arr[index].name << " with " << arr[index].grade << " total\n";
    }
}

int main() {
    Student *arr = new Student[5]{
        {"Kolya", 23, 47.32, "CS"},
        {"Marichka", 19, 24.21, "Sports"},
        {"Anatoliy", 18, 78.23, "Engeneering"},
        {"Vasyl", 22, 98, "Chemistry"},
        {"Lev", 20, 63, "CS"}
    };
    write(arr, 5);
    print(arr, 5);
    Student *array = addNewStudent(arr, 5);
    delete[] arr;
    arr = array;
    cout << "After adding a new student ";
    print(arr, 6);
    getMiddleGradesFac(arr, 6);
    findBestStudents(arr, 6);
    return 0;
}