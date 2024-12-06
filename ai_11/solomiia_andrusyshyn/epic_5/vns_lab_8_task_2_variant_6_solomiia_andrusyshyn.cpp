#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct SchoolStudent {
    string surname;
    string name;
    string patronymic;
    int grade;
    string phoneNumber;
    int mathGrade;
    int physicsGrade;
    int ukraineGrade;
    int literatureGrade;
};

void createFile(const string& filename, const vector<SchoolStudent>& students) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    for (const auto& student : students) {
        file.write((char*)&student, sizeof(SchoolStudent));
    }
    file.close();
}

void printFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка відкриття файлу для читання!" << endl;
        return;
    }
    SchoolStudent student;
    while (file.read((char*)&student, sizeof(SchoolStudent))) {
        cout << "Прізвище: " << student.surname << ", Ім'я: " << student.name
             << ", По батькові: " << student.patronymic << ", Клас: " << student.grade
             << ", Телефон: " << student.phoneNumber
             << ", Оцінки: [Математика: " << student.mathGrade
             << ", Фізика: " << student.physicsGrade
             << ", Українська мова: " << student.ukraineGrade
             << ", Література: " << student.literatureGrade << "]" << endl;
    }
    file.close();
}

void deleteStudentsWithTwos(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка відкриття файлу для читання!" << endl;
        return;
    }
    vector<SchoolStudent> students;
    SchoolStudent student;
    while (file.read((char*)&student, sizeof(SchoolStudent))) {
        if (student.mathGrade != 2 && student.physicsGrade != 2 &&
            student.ukraineGrade != 2 && student.literatureGrade != 2) {
            students.push_back(student);
        }
    }
    file.close();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    for (const auto& s : students) {
        outFile.write((char*)&s, sizeof(SchoolStudent));
    }
    outFile.close();
}

void addStudentToFile(const string& filename, const SchoolStudent& newStudent) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка відкриття файлу для читання!" << endl;
        return;
    }
    vector<SchoolStudent> students;
    SchoolStudent student;
    while (file.read((char*)&student, sizeof(SchoolStudent))) {
        students.push_back(student);
    }
    file.close();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    outFile.write((char*)&newStudent, sizeof(SchoolStudent));
    for (const auto& s : students) {
        outFile.write((char*)&s, sizeof(SchoolStudent));
    }
    outFile.close();
}

int main() {
    string filename = "students.bin";

    vector<SchoolStudent> initialStudents = {
        {"Іваненко", "Іван", "Іванович", 10, "1234567890", 5, 4, 3, 2},
        {"Петренко", "Петро", "Петрович", 11, "0987654321", 2, 3, 4, 5}
    };

    createFile(filename, initialStudents);
    cout << "Початковий вміст файлу:" << endl;
    printFile(filename);

    deleteStudentsWithTwos(filename);
    cout << "\nПісля видалення учнів з двійками:" << endl;
    printFile(filename);

    SchoolStudent newStudent = {"Новий", "Учень", "Олексійович", 9, "1122334455", 4, 4, 5, 5};
    addStudentToFile(filename, newStudent);
    cout << "\nПісля додавання нового учня на початок:" << endl;
    printFile(filename);

    return 0;
}
