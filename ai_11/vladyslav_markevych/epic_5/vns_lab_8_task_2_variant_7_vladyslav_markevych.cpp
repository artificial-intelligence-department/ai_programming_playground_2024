#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    char surname[50];
    char name[50];
    char patronymic[50];
    char address[100];
    char group[20];
    float rating;
};

void createFile(const char* filename) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Помилка при відкритті файлу для запису!" << endl;
        return;
    }

    Student students[] = {
        {"Petliura", "Olexander", "Ivanovich", "Lviv, Yevgena Lazarenko St. 42", "A1", 75.5},
        {"Khvyliovyi", "Anton", "Petrovich", "Lviv, Levandivska St. 2", "B1", 60.2},
        {"Hrushevskyi", "Zakhar", "Zakharovich", "Lviv, Lysenytska St. 3", "C1", 85.0},
        {"Dovzhenko", "Serhiy", "Petrovich", "Lviv, Listova St. 4", "B1", 90.3}
    };

    file.write(reinterpret_cast<char*>(students), sizeof(students));
    file.close();

    cout << "Файл успішно створений." << endl;
}

void printFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    Student student;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        cout << "Прізвище: " << student.surname << ", "
             << "Ім'я: " << student.name << ", "
             << "По батькові: " << student.patronymic << ", "
             << "Адреса: " << student.address << ", "
             << "Група: " << student.group << ", "
             << "Рейтинг: " << student.rating << endl;
    }

    file.close();
}

void addStudent(const char* filename, const Student& newStudent) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "Помилка при відкритті файлу для додавання!" << endl;
        return;
    }

    file.seekg(0, ios::end); 
    file.write(reinterpret_cast<const char*>(&newStudent), sizeof(newStudent));
    file.close();

    cout << "Студент доданий в кінець файлу." << endl;
}

void removeStudentsByRating(const char* filename, float minRating) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    file.seekg(0, ios::end);
    long fileSize = file.tellg();
    int numStudents = fileSize / sizeof(Student);

    file.seekg(0, ios::beg);
    Student* students = new Student[numStudents];
    file.read(reinterpret_cast<char*>(students), fileSize);
    file.close();

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile.is_open()) {
        cerr << "Не вдалось відкрити файо" << endl;
        delete[] students;
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rating >= minRating) {
            tempFile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
        }
    }

    tempFile.close();
    delete[] students;

    remove(filename);
    rename("temp.dat", filename);

    cout << "Студенти з рейтингом менше " << minRating << " були видалені." << endl;
}

int main() {
    const char* filename = "students.dat";

    createFile(filename);

    cout << "\nВміст файлу до змін:" << endl;
    printFile(filename);

    removeStudentsByRating(filename, 70.0);

    Student newStudent = {"Kovalenko", "Oleh", "Ivanovich", "Lviv, Luhansk St. 5", "B2", 80.0};
    addStudent(filename, newStudent);

    cout << "\nВміст файлу після змін:" << endl;
    printFile(filename);

    return 0;
}
