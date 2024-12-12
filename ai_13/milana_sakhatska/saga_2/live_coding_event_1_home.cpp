#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

const int VARIANT = 77; // Номер варіанту (константа)

// Допоміжна функція для пошуку 3-х найбільших і 3-х найменших чисел
void findTopAndBottom(double arr[], int size, double top[], double bottom[]) {
    sort(arr, arr + size);
    for (int i = 0; i < 3; ++i) {
        bottom[i] = arr[i];
        top[i] = arr[size - 1 - i];
    }
}

// Завдання 1: function_1
double function_1() {
    double a, b, f;
    int c, d, e;
    cout << "Enter two real numbers (a, b): ";
    cin >> a >> b;
    cout << "Enter three integers (c, d, e): ";
    cin >> c >> d >> e;
    cout << "Enter one double precision real number (f): ";
    cin >> f;

    double nums[] = {a, b, c, d, e, f};
    double top[3], bottom[3];
    findTopAndBottom(nums, 6, top, bottom);

    double sumTop = top[0] + top[1] + top[2];
    double sumBottom = bottom[0] + bottom[1] + bottom[2];
    double result;

    if (sumTop > sumBottom * 4) {
        result = sumTop + sumBottom;
    } else if (sumTop > sumBottom * 3) {
        result = sumTop / sumBottom;
    } else if (sumTop > sumBottom * 2) {
        result = sumTop * sumBottom;
    } else {
        result = sumTop - sumBottom;
    }

    result /= VARIANT;
    cout << "Result from function_1: " << result << endl;
    return result;
}

// Завдання 2: function_2
void function_2(double &x, double matrix[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = x;
        }
    }

    srand(time(nullptr));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
    }

    cout << "Updated matrix: " << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Завдання 3: function_3
void function_3(double matrix[5][5], double result[5]) {
    for (int j = 0; j < 5; ++j) {
        double minValue1 = matrix[0][j];
        double minValue2 = matrix[0][j];

        for (int i = 1; i < 5; ++i) {
            minValue1 = min(minValue1, matrix[i][j]);
            if (matrix[i][j] < minValue2) {
                minValue2 = matrix[i][j];
            }
        }

        if (minValue1 == minValue2) {
            cout << "Column " << j << ": Match found." << endl;
        } else {
            cout << "Column " << j << ": No match." << endl;
        }

        result[j] = minValue1;
    }
}

// Завдання 4: function_4
struct Student {
    string name;
    string surname;
    double money;
    Student* prev;
    Student* next;
};

Student* function_4(double result[5]) {
    Student* students[7];
    for (int i = 0; i < 7; ++i) {
        students[i] = new Student();
    }

    string names[] = {"Ivan", "Petro", "Oleg", "Anna", "Maria", "Dmytro", "Sofia"};
    string surnames[] = {"Ivanov", "Petrenko", "Shevchenko", "Koval", "Boyko", "Tkachenko", "Bondarenko"};

    for (int i = 0; i < 7; ++i) {
        students[i]->name = names[rand() % 7];
        students[i]->surname = surnames[rand() % 7];
    }

    students[0]->money = *max_element(result, result + 5);
    students[6]->money = *min_element(result, result + 5);

    for (int i = 1; i <= 5; ++i) {
        students[i]->money = result[i - 1];
    }

    for (int i = 0; i < 6; ++i) {
        students[i]->next = students[i + 1];
        students[i + 1]->prev = students[i];
    }
    students[0]->prev = nullptr;
    students[6]->next = nullptr;

    cout << "Student list: " << endl;
    for (int i = 0; i < 7; ++i) {
        cout << students[i]->name << " " << students[i]->surname << " $" << students[i]->money << endl;
    }

    return students[0];
}

// Завдання 5: function_5
void help_for_function_5(Student* student, ofstream& file) {
    if (student == nullptr) return;
    file << student->name << " " << student->surname << " $" << student->money << endl;
    help_for_function_5(student->prev, file);
}

void function_5(Student* head) {
    ofstream file("students.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    if (VARIANT % 2 == 0) {
        Student* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        help_for_function_5(tail, file);
    } else {
        Student* current = head;
        while (current != nullptr) {
            file << current->name << " " << current->surname << " $" << current->money << endl;
            current = current->next;
        }
    }

    file.close();
}

void function_6() {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "File not found!" << endl;
        return;
    }

    string line;
    cout << "Contents of the file:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

// Головна функція
int main() {
    double x = function_1();

    double matrix[5][5];
    function_2(x, matrix);

    double result[5];
    function_3(matrix, result);

    Student* head = function_4(result);

    function_5(head);
    function_6();

    return 0;
}