#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

const int VARIANT = 43; //цілочисельна константа

struct Student {
    string first_name;
    string last_name;
    double balance;
};

double function_1() {
    double a, b, f;
    int c, d, e;
    cout << "Введіть два дійсних числа a, b: ";
    cin >> a >> b;
    cout << "Введіть три цілі числа c, d, e: ";
    cin >> c >> d >> e;
    cout << "Введіть одне дійсне число з подвійною точністю f: ";
    cin >> f;

    double numbers[] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};

    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            if (numbers [i] > numbers [j]) swap (numbers [i], numbers [j]);
        }
    }
    double sum_max = numbers[3] + numbers[4] + numbers[5];
    double sum_min = numbers[0] + numbers[1] + numbers[2];

    double result;
    if (sum_max > sum_min * 4) result = sum_max + sum_min;
    else if (sum_max > sum_min * 3) result = sum_max / sum_min;
    else if (sum_max > sum_min * 2) result = sum_max * sum_min;

    return result / VARIANT;
}

double ** function_2(double& x) {
    const int SIZE = 5;
    double** matrix = new double*[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; ++i) {
        matrix[i] = new double[SIZE];
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = (x + VARIANT +j - i) * (rand() % 100+1);
        }
    }

    cout << "Елементи матриці:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << " " << endl;
        }
    }
    
    return matrix;
};

void function_3(double** matrix) {
    const int SIZE = 5;
    double min_elements[SIZE] = {0}; //одновимірний масив

    for (int j = 0; j < SIZE; ++j) {
        double min_value = matrix[0][j];
        for (int i = 1; i < SIZE; ++i) {
            if (matrix[i][j] < min_value) min_value = matrix[i][j];
        }
        min_elements[j] = min_value;
    }

    for(int i = 0; i < SIZE; ++i) {
        cout << "Мінімум в стовпці " << i + 1 << ": " << min_elements[i] << endl;
    }
}

void function_4(double* array) {
    Student students[7];
    string first_names[] = {"Юля", "Софія", "Саша", "Леся", "Іван", "Оксана", "Роман"};
    string last_names[] = {"Лазаревич", "Куць", "Хвостова", "Ляшко", "Загородній", "Кохач", "Хмельницький"};

    students[0].balance = array[0];
    students[6].balance = array[4];

    for (int i = 1; i < 6; ++i) {
        students[i].balance = array[i - 1];
    };

    for (int i = 0; i < 7; ++i) {
        students[i].first_name = first_names[i];
        students[i].last_name = last_names[i];
        cout << students[i].first_name << " " << students[i].last_name << ": $"<< students[i].balance << endl;
    };
};

void help_for_function_5(Student* students, int size, ofstream& file, bool reverse) {
    if (reverse) {
        for (int i = size - 1; i >=0; --i) {
            file << students[i].first_name << " " << students[i].last_name << " " << students[i].balance << endl;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            file << students[i].first_name << " " << students[i].last_name << " " << students[i].balance << endl;
        }
    }
};

void function_5(Student* students) {
    ofstream file("students.txt");
    if (!file) {
        cerr << "Помилка створення файлу!" << endl;
        return;
    }

    if (VARIANT % 2 == 0) {
        help_for_function_5(students, 7, file, true);
    }
    else {
        help_for_function_5(students, 7, file, false);
    }

    file.close();
    ifstream infile("students.txt");
    if (!infile) {
        cerr << "Помилка читання файлу!" << endl;
        return;
    }

    cout << "Вмість файлу:\n";
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();
};

int main() {
    double x = function_1();
    //cout << "Результат першої функції: " << x << endl;
    double** matrix = function_2(x);
    function_3(matrix);
    for (int i = 0; i < 5; ++i) delete [] matrix[i];
    delete[] matrix;

    double array [5] = {10, 20, 30, 40, 50};
    function_4(array);

    Student students[7] = {
        {"Юля", "Лазаревич", 50},
        {"Софія", "Куць", 40}, 
        {"Саша", "Хвостова", 30}, 
        {"Леся", "Ляшко", 20}, 
        {"Іван", "Загородній", 15}, 
        {"Оксана", "Кохач", 10}, 
        {"Роман", "Хмельницький", 5}, 
    };

    function_5(students);
}