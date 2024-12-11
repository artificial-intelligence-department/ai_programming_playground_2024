#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Параметри
    double x_start = 0.3;
    double x_end = 5.0;
    double step = 0.1;
    int count_negative = 0; // Лічильник негативних значень

    // Цикл для перебору значень x у заданому діапазоні
    for (double x = x_start; x <= x_end; x += step) {
        double y = cos(x * x) * exp(-x); // Обчислення функції
        
        // Перевірка на негативне значення
        if (y < 0) {
            count_negative++;
        }
    }

    // Виведення результату
    cout << "Кількість негативних значень функції: " << count_negative << endl;

    return 0;
}
