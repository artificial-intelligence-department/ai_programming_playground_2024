#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct StudentInfo {
    string full_name;
    string group_name;
    string phone_number;
    int subject_marks[3];
};

void addNewStudent(vector<StudentInfo>& student_list) {
    StudentInfo new_student;
    cout << "Введіть ім'я студента: ";
    getline(cin, new_student.full_name);
    cout << "Введіть номер телефону: ";
    getline(cin, new_student.phone_number);
    cout << "Введіть групу: ";
    getline(cin, new_student.group_name);
    cout << "Введіть оцінки по 3 предметах: ";
    cin >> new_student.subject_marks[0] >> new_student.subject_marks[1] >> new_student.subject_marks[2];
    cin.ignore(); // очищаємо буфер вводу
    student_list.push_back(new_student);
}

void deleteStudentIfLowGrades(vector<StudentInfo>& student_list, const string& group, float min_average) {
    auto it = student_list.begin();
    while (it != student_list.end()) {
        float avg_marks = (it->subject_marks[0] + it->subject_marks[1] + it->subject_marks[2]) / 3.0f;
        if (it->group_name == group && avg_marks < min_average) {
            it = student_list.erase(it);
        } else {
            ++it;
        }
    }
}

void printStudents(const vector<StudentInfo>& student_list) {
    for (const auto& student : student_list) {
        cout << "Ім'я: " << student.full_name << endl;
        cout << "Телефон: " << student.phone_number << endl;
        cout << "Група: " << student.group_name << endl;
        cout << "Оцінки: " << student.subject_marks[0] << ", "
             << student.subject_marks[1] << ", "
             << student.subject_marks[2] << endl;
        cout << "----------------------------" << endl;
    }
}

void saveToBinaryFile(const vector<StudentInfo>& student_list, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }
    for (const auto& student : student_list) {
        file.write(student.full_name.c_str(), student.full_name.size() + 1);
        file.write(student.phone_number.c_str(), student.phone_number.size() + 1);
        file.write(student.group_name.c_str(), student.group_name.size() + 1);
        file.write(reinterpret_cast<const char*>(student.subject_marks), sizeof(student.subject_marks));
    }
    file.close();
}

void loadFromFile(vector<StudentInfo>& student_list, const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    StudentInfo student;
    while (getline(file, student.full_name, '\0')) {
        getline(file, student.phone_number, '\0');
        getline(file, student.group_name, '\0');
        file.read(reinterpret_cast<char*>(student.subject_marks), sizeof(student.subject_marks));
        student_list.push_back(student);
    }

    file.close();
}

int main() {
    vector<StudentInfo> students;
    string filename = "students.dat";
    int action;

    while (true) {
        cout << "1. Додати студента\n"
             << "2. Видалити студентів за середнім балом\n"
             << "3. Показати список студентів\n"
             << "4. Зберегти дані у файл\n"
             << "5. Завантажити дані з файлу\n"
             << "6. Вийти\n"
             << "Ваш вибір: ";
        cin >> action;
        cin.ignore(); // Очищаємо буфер

        switch (action) {
            case 1: {
                addNewStudent(students);
                break;
            }
            case 2: {
                string group;
                float minAvg;
                cout << "Введіть групу: ";
                getline(cin, group);
                cout << "Введіть мінімальний середній бал: ";
                cin >> minAvg;
                cin.ignore();
                deleteStudentIfLowGrades(students, group, minAvg);
                break;
            }
            case 3:
                printStudents(students);
                break;
            case 4:
                saveToBinaryFile(students, filename);
                break;
            case 5:
                loadFromFile(students, filename);
                break;
            case 6:
                cout << "Вихід з програми." << endl;
                return 0;
            default:
                cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
        }
    }

    return 0;
}
