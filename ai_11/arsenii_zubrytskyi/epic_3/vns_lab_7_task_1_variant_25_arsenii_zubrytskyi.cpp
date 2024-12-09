#include <iostream>
#include <cmath>
#include <cstdarg>

using namespace std;

// Функція для обчислення довжини сторони за координатами її кінцевих точок
double sideLength(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Функція для обчислення площі трикутника за координатами його вершин
double square(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

// Функція для обчислення площі трикутника, що містить найдовшу діагональ в опуклому багатокутнику
// зі змінною кількістю вершин (потрібно передати щонайменше 6 параметрів для 3 вершин)
double square1(int numPoints, ...) {
    if (numPoints < 6 || numPoints % 2 != 0) {
        cerr << "Невірна кількість координат." << endl;
        return -1;
    }

    va_list args;
    va_start(args, numPoints);

    // Збереження координат
    double* coords = new double[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        coords[i] = va_arg(args, double);
    }
    va_end(args);

    // Знаходимо найдовшу діагональ
    double maxDiagonal = 0;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < numPoints / 2; ++i) {
        for (int j = i + 1; j < numPoints / 2; ++j) {
            double length = sideLength(coords[2 * i], coords[2 * i + 1], coords[2 * j], coords[2 * j + 1]);
            if (length > maxDiagonal) {
                maxDiagonal = length;
                p1 = i;
                p2 = j;
            }
        }
    }

    // Обчислення площі трикутника, що містить найдовшу діагональ
    double area = 0;
    for (int i = 0; i < numPoints / 2; ++i) {
        if (i != p1 && i != p2) {
            area = square(
                coords[2 * p1], coords[2 * p1 + 1],
                coords[2 * p2], coords[2 * p2 + 1],
                coords[2 * i], coords[2 * i + 1]
            );
            break;
        }
    }

    delete[] coords;
    return area;
}

int main() {
    // Приклад використання
    double x1 = 0, y1 = 0, x2 = 4, y2 = 0, x3 = 2, y3 = 3;
    cout << "Довжина сторони: " << sideLength(x1, y1, x2, y2) << endl;
    cout << "Площа трикутника: " << square(x1, y1, x2, y2, x3, y3) << endl;

    cout << "Площа трикутника з найдовшою діагоналлю: "
         << square1(8, 0.0, 0.0, 4.0, 0.0, 4.0, 3.0, 0.0, 3.0) << endl;

    return 0;
}
