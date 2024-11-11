#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double N = 40;
const double PI = 3.141592653589793;
const double A = PI / 5, B = PI; 
const double K = 10.0;
const double E = 0.0001; 

double f(double x) {
    return (PI * PI) / 8 - (PI / 4) * abs(x);
}

double SN(double x) {
    double sum = 0;
    for (double i = 1; i <= N; i++) {
        int term_index = 2 * i - 1;
        sum += cos(term_index * x) / pow(term_index,2);
    }
    return sum;
}

double SE(double x) {
    double sum = 0;
    double term;
    double i = 1;
    do {
        int term_index = 2 * i - 1;
        term = cos(term_index * x) / (term_index * term_index);
        sum += term;
        i++;
    } while (abs(term) > E);
    return sum;
}

int main() {
    double step = (B - A) / K;
    cout << fixed << setprecision(10);
    for (double x = A; x <= B; x += step) {
        cout << "X = " << x 
             << "; SN = " << SN(x) 
             << "; SE = " << SE(x) 
             << "; Y = " << f(x) << endl;
    }
    return 0;
}
