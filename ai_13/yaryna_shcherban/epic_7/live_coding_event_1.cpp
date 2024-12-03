#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Цілочисельна константа
const int Variant = 84;

// Функція для роботи з одновимірним масивом
double function_1() {
// Дійсна змінна
    float a, b;   
// Цілочисельні змінні         
    int c, d, e;           
// Змінна з подвійною точністю
    double f;              

    cout << "Enter a, b (float): ";
    cin >> a >> b;
    cout << "Enter c, d, e (int): ";
    cin >> c >> d >> e;
    cout << "Enter f (double): ";
    cin >> f;
//Математичні обчислення
    double array_1[6] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    int n = sizeof(array_1) / sizeof(array_1[0]);
    sort(array_1, array_1 + n);

    cout << "Smallest 3 elements: ";
    for (int i = 0; i < 3; i++) {
        cout << array_1[i] << " ";
    }
    cout << endl;

    cout << "Largest 3 elements: ";
    for (int i = n - 3; i < n; i++) {
        cout << array_1[i] << " ";
    }
    cout << endl;

    double sum_max = array_1[5] + array_1[4] + array_1[3];
    double sum_min = array_1[0] + array_1[1] + array_1[2];
    double sum = 0;
//Оператор if та розгалуження
    if (sum_max > sum_min * 2) {
        sum = sum_max * sum_min;
    } else if (sum_max > sum_min * 3) {
        sum = sum_max / sum_min;
    } else if (sum_max > sum_min * 4) {
        sum = sum_max + sum_min;
    } else {
        sum = sum_max - sum_min;
    }

    double x = sum / Variant;
    cout << "Result of function_1: " << x << endl;
    return x;
}

// Функція з аргументами
void function_2(double x_1, double matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x_1;
        }
    }

    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (matrix[i][j] + Variant + (j - i)) * (rand() % 100 + 1);
        }
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Функція для роботи з матрицею
void function_3(double matrix[5][5], int n, int m) {
    cout << "Minimum elements in each row: ";
    for (int i = 0; i < n; i++) {
        double minm = matrix[i][0];
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] < minm) {
                minm = matrix[i][j];
            }
        }
        cout << minm << " ";
    }
    cout << endl;
}

// Знаходження мінімальних елементів у колонках
void smallestInCol(double matrix[5][5], int n, int m) {
    cout << "Minimum elements in each column: ";
    for (int i = 0; i < m; i++) {
        double minm = matrix[0][i];
        for (int j = 1; j < n; j++) {
            if (matrix[j][i] < minm) {
                minm = matrix[j][i];
            }
        }
        cout << minm << " ";
    }
    cout << endl;
}

void smallestInRow(double matrix[5][5], int n, int m) {
    cout << "Minimum elements in each row: ";
    for (int i = 0; i < n; i++) {
        double minm = matrix[i][0];
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] < minm) {
                minm = matrix[i][j];
            }
        }
        cout << minm << " ";
    }
    cout << endl;
}

int main() {
    double x = function_1();
    double matrix[5][5];
    function_2(x, matrix);

    int n = 5, m = 5;
    function_3(matrix, n, m);
    smallestInCol(matrix, n, m);
    smallestInRow(matrix, n, m);

    return 0;
}