#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Рекурсивна функція для обчислення факторіала
double Factorial(int n) {
    if (n <= 1) return 1;
    return n * Factorial(n - 1);
}

// Функція для обчислення членів ряду Тейлора
double Taylor(double x, int i) {
    return pow(-1, i) * pow(x, 2 * i) * (2 * i * i + 1) / Factorial(2 * i);
}


double Approximate_N(double x, int n) {
    double sum = 1.0;
    for (int i = 1; i <= n; i++) {
        double n_result = Taylor(x, i);
        sum += n_result;
    }
    return sum;
}

// Функція для обчислення суми SE (з точністю до epsilon)
double Approximate_Epsilon(double x, double epsilon) {
    double sum = 1.0;
    double previous_sum = 0.0;
    int i = 1;

    while (true) {
        double n_result = Taylor(x, i);
        previous_sum = sum; // Sn
        sum += n_result; // Sn+1

        if (abs(sum - previous_sum) < epsilon) {
            break;
        }

        i++;
    }

    return sum;
}

int main() {
    double a = 0.1;
    double b = 1.0;
    int n = 35;
    int k = 10;
    double epsilon = 0.0001;
    double step = (b - a) / k;

    cout << fixed << setprecision(6);
    cout << setw(10) << "X" << setw(15) << "SN" << setw(15) << "SE" << setw(15) << "Y" << endl;

    for (double x = a; x <= b; x += step) {
        double approximate_Value_N = Approximate_N(x, n);
        double approximate_Value_Epsilon = Approximate_Epsilon(x, epsilon);
        double y = (1 - pow(x, 2) / 2) * cos(x) - (x / 2) * sin(x);

        cout << setw(10) << x << setw(15) << approximate_Value_N << setw(15) << approximate_Value_Epsilon << setw(15) << y << endl;
    }

    return 0;
}
