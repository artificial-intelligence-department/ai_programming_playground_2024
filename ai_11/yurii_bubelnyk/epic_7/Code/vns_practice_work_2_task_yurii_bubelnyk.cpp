#include <iostream>
#include <cmath> // для cos() і sin()

using namespace std;

// Рекурсивна функція
void calculate(double x, double x_end, double hx, double a, double b, double c);

int main() {
    double a = 0.75;
    double b = 1.19;
    double c = -2.5;
    // Значення для X
    double x_start = 0.0;
    double x_end = 2.0;
    double hx = 0.1;

    // Виклик рекурсивної функції
    calculate(x_start, x_end, hx, a, b, c);

    return 0;
}

void calculate(double x, double x_end, double hx, double a, double b, double c) {
    if (x > x_end) { // коли X вийде за межі тоді закінчиться функція
        return;
    }

    double y; // Змінна для збереження обрахунків
    //Перевірка меж
    if (x < 0.5) {
        y = a * x + b; // Випадок для x < 0.5
    } else if (x >= 0.5 && x < 1.0) {
        y = cos(b * x) + c; // Випадок для 0.5 <= x < 1.0
    } else {
        y = sin(2 * x) + b * c; // Випадок для 1.0 <= x <= 2.0
    }

    // Вивід результатів
    cout << "x = " << x << ", y = " << y << endl;

    // Рекурся, функція викликається з наступним кроком X
    calculate(x + hx, x_end, hx, a, b, c);
}