#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 5 * x * x - 2 * x + 2;
}

double integrate(double a, double b, int n) {
    double delta_x = (b - a) / n; 
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double x_i = a + i * delta_x; 
        sum += f(x_i) * delta_x;  
    }

    return sum;
}

int main() {
    double a, b;
    int n;

    cout << "Введіть ліву межу інтегралу (a): ";
    cin >> a;
    cout << "Введіть праву межу інтегралу (b): ";
    cin >> b;
    cout << "Введіть кількість підінтервалів (n): ";
    cin >> n;

    double result = integrate(a, b, n);

    cout << "Наближене значення інтегралу: " << result << endl;

    return 0;
}

