#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Структура для збереження інформації про студента
struct Student {
    string name;
    int age;
    string group;

    // Запис у файл
    void writeToFile(ofstream &outFile) const {
        outFile << name << "\n" << age << "\n" << group << "\n";
    }

    // Читання з файлу
    static Student readFromFile(ifstream &inFile) {
        Student student;
        getline(inFile, student.name);
        string ageStr;
        getline(inFile, ageStr);
        student.age = stoi(ageStr); // Перетворення рядка на число
        getline(inFile, student.group);
        return student;
    }

    // Вивід з файлу
    void print() const {
        cout << "Ім'я: " << name << ", Вік: " << age << ", Група: " << group << endl;
    }
};

int main() {

    string fileName = "students.txt"; 

    // Список студентів для запису у файл
    vector<Student> students = {
                        {"Олександр", 20, " ШІ-21 "},
                        {"Марія", 19, " ШІ-22 "},
                        {"Іван", 21, " ШІ-23 "}
    };
// 1. Відкриття файлу для запису 
    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Помилка: Не вдалося відкрити файл для запису!" << endl;
        return 1;
    }
// Запис студентів у файл
    for (const auto &student : students) {
        student.writeToFile(outFile);
        outFile << "---\n"; 
    }
    outFile.close();
    cout << "Дані студентів записані у файл: " << fileName << endl;

// 2. Відкриття файлу для читання 
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Помилка: Не вдалося відкрити файл для читання!" << endl;
        return 1;
    }
// Читання студентів із файлу та збереження їх у список
    vector<Student> loadedStudents;
    while (inFile.peek() != EOF) {      // чи не досягнуто кінця файлу
        Student student = Student::readFromFile(inFile);
        loadedStudents.push_back(student);
        string delimiter;
        getline(inFile, delimiter);
    }
    inFile.close();

// Виведення списку студентів
    cout << "\n Список студентів, завантажених із файлу:" << endl;
    for (const auto &student : loadedStudents) {
        student.print();
    }
    return 0;
}