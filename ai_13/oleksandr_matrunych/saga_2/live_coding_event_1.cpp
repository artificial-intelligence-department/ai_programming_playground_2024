#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <list>
#include <fstream>

using namespace std;

const int VARIANT = 71; // Цілочисельна константа

double function_1() {
    double a, b, f; // Дійсні змінні
    int c, d, e; // Цілочисельні змінні

    cout << "Enter two real numbers a, b: ";
    cin >> a >> b;

    cout << "Enter three integers c, d, e: ";
    cin >> c >> d >> e;

    cout << "Enter a double-precision real number f: ";
    cin >> f;

    double* arr = new double[6]{a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f}; // Одновимірний масив

    sort(arr, arr + 6); // Використання математичної функції

    double sum_min = arr[0] + arr[1] + arr[2];
    double sum_max = arr[3] + arr[4] + arr[5];

    double result;

    if (sum_max > sum_min * 4) { // Умовний оператор
        result = sum_max + sum_min;
    } else if (sum_max > sum_min * 3) {
        result = sum_max / sum_min;
    } else if (sum_max > sum_min * 2) {
        result = sum_max * sum_min;
    } else {
        result = 0;
    }

    double x = result / VARIANT; // Оператор ділення

    cout << "Result: " << x << endl;

    delete[] arr; // Вказівник

    return x;
}

void function_2(double& x, double matrix[5][5]) { // Двовимірний масив
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < 5; ++i) { // For цикл
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; ++i) { // For цикл
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
    }

    cout << "Updated matrix:" << endl;
    for (int i = 0; i < 5; ++i) { // For цикл
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void function_3(double matrix[5][5], double min_elements[5]) {
    for (int j = 0; j < 5; ++j) { // For цикл
        double min_value_1 = numeric_limits<double>::max();
        double min_value_2 = numeric_limits<double>::max();

        for (int i = 0; i < 5; ++i) { // For цикл
            if (matrix[i][j] < min_value_1) {
                min_value_1 = matrix[i][j];
            }
        }

        min_value_2 = *min_element(&matrix[0][j], &matrix[5][j]); // Математична функція

        min_elements[j] = min_value_1;
    }

    cout << "Smallest elements in each column:" << endl;
    for (int j = 0; j < 5; ++j) { // For цикл
        cout << min_elements[j] << " ";
    }
    cout << endl;
}

struct Student { // Cтруктура даних
    string first_name;
    string last_name;
    double balance;
};

list<Student> function_4(double min_elements[5]) { 
    string first_names[] = {"John", "Alice", "Bob", "Eva", "Tom", "Lucy", "Mike"}; // Одновимірний масив
    string last_names[] = {"Smith", "Johnson", "Williams", "Brown", "Davis", "Miller", "Wilson"};

    list<Student> students;

    for (int i = 0; i < 7; ++i) { // For цикл
        Student student;
        student.first_name = first_names[i];
        student.last_name = last_names[i];

        if (i == 0) {
            student.balance = *max_element(min_elements, min_elements + 5); // Математична функція
        } else if (i == 6) {
            student.balance = *min_element(min_elements, min_elements + 5); 
        } else {
            student.balance = min_elements[i - 1] + min_elements[i];
        }

        students.push_back(student);
    }

    cout << "Student List:" << endl;
    for (const auto& student : students) { // For цикл
        cout << student.first_name << " " << student.last_name
             << " | Balance: " << student.balance << endl;
    }

    return students;
}

void help_for_function_5_recursive(list<Student>& students, ofstream& file) { // Рекурсивна функція
    if (students.empty()) {
        return;
    }
    Student student = students.back();
    students.pop_back();

    help_for_function_5_recursive(students, file);

    file << student.first_name << " " << student.last_name
         << " | Balance: " << student.balance << endl;
}

void help_for_function_5_non_recursive(list<Student>& students, ofstream& file) {
    for (const auto& student : students) { // For цикл
        file << student.first_name << " " << student.last_name
             << " | Balance: " << student.balance << endl;
    }
}

void function_5(list<Student>& students) {
    ofstream file("students.txt");

    if (file.is_open()) { // Умовний оператор
        if (VARIANT % 2 == 0) {
            help_for_function_5_recursive(students, file);
        } else {
            help_for_function_5_non_recursive(students, file);
        }
        file.close();
    } else {
        cout << "Error opening the file." << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
}

void function_6() {
    ifstream file("students.txt"); // Функція роботи з файлами для зчитування

    if (!file.is_open()) {
        cout << "Error: File 'students.txt' not found!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) { // While цикл
        cout << line << endl;
    }

    file.close();
}

int main() {
    double x = function_1(); // Функція з параметрами

    double matrix[5][5]; // Двовимірний масив
    function_2(x, matrix);

    double min_elements[5]; // Одновимірний масив
    function_3(matrix, min_elements);

    list<Student> students = function_4(min_elements);

    function_5(students);

    function_6();

    return 0;
}
