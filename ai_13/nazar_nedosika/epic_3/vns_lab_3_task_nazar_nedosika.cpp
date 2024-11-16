#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double y(double x) {
    return 0.25 * (x * x - M_PI * M_PI / 3);
}

double S_fixed_n(double x, int n) {
    double sum = 0;
    for (int j = 1; j <= n; ++j) {
        sum = sum + pow(-1, j) * cos(j * x) / (j * j);
    }
    return sum;
}

double S_epsilon(double x, double epsilon) {
    double sum = 0;
    int j = 1;
    double current_element;

    do {
        current_element = pow(-1, j) * cos(j * x) / (j * j);
        sum = sum + current_element;
        j = j + 1;
    } while (fabs(current_element) >= epsilon);

    return sum;
}

int main() {
    double a = M_PI / 5;
    double b = M_PI;
    int k = 10;
    int n = 20;
    double epsilon = 0.0001;

    double step = (b - a) / k;

    cout << "x \t\t y_exact \t S_fixed_n \t S_epsilon \n";

    for (int i = 0; i <= k; i = i + 1) {
        double x = a + i * step;

        double y_val = y(x);
        double S_fixed_n_val = S_fixed_n(x, n);
        double S_epsilon_val = S_epsilon(x, epsilon);

        cout << fixed << setprecision(6) << x << "\t " << y_val << "\t " << S_fixed_n_val << "\t " << S_epsilon_val << "\n";
    }

    return 0;
}
