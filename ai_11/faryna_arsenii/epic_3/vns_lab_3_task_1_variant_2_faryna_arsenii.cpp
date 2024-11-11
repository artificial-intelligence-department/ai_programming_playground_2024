#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double N = 40;
const double PI = 3.141592;
const double A = PI / 5, B = (9 * PI) / 5, K = 10.0, E = 0.0001;

double f(double x) {
    return -log(abs(2 * (sin(x / 2))));
}

double SN(double x) {
    double sum = 1;
    for (double i = 1; i <= N; i++) {
        sum += cos(i * x) / i;
    }
    return sum;
}

double SE(double x) {
    double sum = 1;
    double prev;
    double i = 1;
    do {
        prev = sum;
        sum += cos(i * x) / i;
        i++;
    } while (abs(prev - sum) > E);
    return sum;
}

int main() {
    double step = (B - A) / K;
    cout << fixed << setprecision(10);
    for (double x = A; x <= B; x += step) {
        cout << "X = " << x << "; SN = " << SN(x) << "; SE = " << SE(x) << "; Y = " << f(x) << endl;
    }
    return 0;
}