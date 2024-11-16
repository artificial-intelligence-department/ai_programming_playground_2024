#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Функція з n
double SN(double x, int n) {
    double sum = 0;
    double term = (x - 1) / (x + 1);
    for (int i = 1; i <= n; i++) {
        sum += term / (2 * i - 1);
        term *= ((x - 1) * (x - 1)) / ((x + 1) * (x + 1));
    }
    return sum;
}

// Функція з e
double SE(double x, double e) {
    double sum = 0;
    double term = (x - 1) / (x + 1);
    int i = 1;
    while (fabs(term) > e) {
        sum += term / (2 * i - 1);
        term *= ((x - 1) * (x - 1)) / ((x + 1) * (x + 1));
        i++;
    }
    return sum;
}

int main() {
    double a = 0.2, b = 1;
    int k = 10;
    int n = 10;
    double e = 0.0001;
    double step = (b - a) / k;

    cout << "Обчислення функції\n";
    cout << fixed << setprecision(4);  // встановлюємо точність для чисел
    for (double x = a; x <= b; x += step) {
        double N = SN(x, n);
        double E = SE(x, e);
        double exactValue = 0.5 * log(x);

        cout << "X=" << setw(6) << x << "\t"
             << "SN=" << setw(8) << N << "\t"
             << "SE=" << setw(8) << E << "\t"
             << "Y=" << setw(8) << exactValue << endl;
    }
    
    return 0;
}
