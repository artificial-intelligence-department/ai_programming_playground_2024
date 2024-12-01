
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Student
{
    std::string fullName;
    std::string phoneNumber;
    std::string group;
    int grades[3];

    double getAverageGrade() const
    {
        return (grades[0] + grades[1] + grades[2]) / 3.0;
    }
};

void saveToFile(const std::vector<Student> &students, const std::string &filename)
{
    std::ofstream outFile(filename);
    for (const auto &student : students)
    {
        outFile << student.fullName << ";" << student.phoneNumber << ";" << student.group << ";" << student.grades[0]
                << "," << student.grades[1] << "," << student.grades[2] << "\n";
    }
}

std::vector<Student> loadFromFile(const std::string &filename)
{
    std::vector<Student> students;
    std::ifstream inFile(filename);
    std::string line;

    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        Student student;
        std::string gradesStr;

        std::getline(ss, student.fullName, ';');
        std::getline(ss, student.phoneNumber, ';');
        std::getline(ss, student.group, ';');
        std::getline(ss, gradesStr, ';');

        std::stringstream gradesStream(gradesStr);
        for (int i = 0; i < 3; ++i)
        {
            std::string grade;
            std::getline(gradesStream, grade, ',');
            student.grades[i] = std::stoi(grade);
        }
        students.push_back(student);
    }
    return students;
}

void removeStudentsByGroup(std::vector<Student> &students, const std::string &group, double minAverage)
{
    students.erase(std::remove_if(students.begin(), students.end(),
                                  [&](const Student &student) {
                                      return student.group == group && student.getAverageGrade() < minAverage;
                                  }),
                   students.end());
}

void addStudentAfterSurname(std::vector<Student> &students, const std::string &surname, const Student &newStudent)
{
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->fullName.find(surname) != std::string::npos)
        {
            students.insert(it + 1, newStudent);
            return;
        }
    }
}

int main()
{
    std::string filename = "students.txt";
    std::vector<Student> students;

    int choice;
    do
    {
        std::cout << "1. Додати студентів\n";
        std::cout << "2. Вивести студентів\n";
        std::cout << "3. Видалити студентів за групою та середнім балом\n";
        std::cout << "4. Додати студента після прізвища\n";
        std::cout << "0. Вийти\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            int n;
            std::cout << "Скільки студентів додати? ";
            std::cin >> n;
            for (int i = 0; i < n; ++i)
            {
                Student student;
                std::cout << "Введіть ПІБ: ";
                std::cin.ignore();
                std::getline(std::cin, student.fullName);
                std::cout << "Введіть номер телефону: ";
                std::cin >> student.phoneNumber;
                std::cout << "Введіть групу: ";
                std::cin >> student.group;
                std::cout << "Введіть оцінки (3 шт): ";
                for (int &grade : student.grades)
                {
                    std::cin >> grade;
                }
                students.push_back(student);
            }
            saveToFile(students, filename);
            break;
        }
        case 2: {
            students = loadFromFile(filename);
            for (const auto &student : students)
            {
                std::cout << "ПІБ: " << student.fullName << "\n";
                std::cout << "Телефон: " << student.phoneNumber << "\n";
                std::cout << "Група: " << student.group << "\n";
                std::cout << "Оцінки: " << student.grades[0] << ", " << student.grades[1] << ", " << student.grades[2]
                          << "\n";
                std::cout << "--------------------------\n";
            }
            break;
        }
        case 3: {
            std::string group;
            double minAverage;
            std::cout << "Введіть номер групи: ";
            std::cin >> group;
            std::cout << "Введіть мінімальний середній бал: ";
            std::cin >> minAverage;
            students = loadFromFile(filename);
            removeStudentsByGroup(students, group, minAverage);
            saveToFile(students, filename);
            break;
        }
        case 4: {
            std::string surname;
            Student newStudent;
            std::cout << "Введіть прізвище: ";
            std::cin >> surname;
            std::cout << "Введіть нового студента\n";
            std::cout << "ПІБ: ";
            std::cin.ignore();
            std::getline(std::cin, newStudent.fullName);
            std::cout << "Телефон: ";
            std::cin >> newStudent.phoneNumber;
            std::cout << "Група: ";
            std::cin >> newStudent.group;
            std::cout << "Оцінки (3 шт): ";
            for (int &grade : newStudent.grades)
            {
                std::cin >> grade;
            }
            students = loadFromFile(filename);
            addStudentAfterSurname(students, surname, newStudent);
            saveToFile(students, filename);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
