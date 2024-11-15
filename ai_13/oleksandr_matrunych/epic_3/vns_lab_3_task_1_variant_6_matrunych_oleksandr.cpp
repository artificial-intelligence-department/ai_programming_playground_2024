#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double EPSILON = 0.0001;
const int n = 25;

double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
double seriesSum(double x) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += (cos(i * M_PI / 4) / factorial(i)) * pow(x, i);
    }
    return sum;
}
double seriesApprox(double x) {
    double sum = 1.0;
    double term;
    int i = 1;
    do {
        term = (cos(i * M_PI / 4) / factorial(i)) * pow(x, i);
        sum += term;
        i++;
    } while (term > EPSILON);
    return sum;
}

double exactValue(double x) {
    return exp(cos(M_PI / 4) * x) * cos(x * M_PI / 4);
}

int main() {
    double a = 0.1, b = 1.0;
    int n = 10;
    double step = (b - a) / n;
    cout << fixed << setprecision(9);

    for (double x = a; x <= b; x += step) {
        cout << "X = " << x 
             << "; Series Sum = " << seriesSum(x) 
             << "; Approx = " << seriesApprox(x) 
             << "; Exact = " << exactValue(x) << endl;
    }

    return 0;
}
