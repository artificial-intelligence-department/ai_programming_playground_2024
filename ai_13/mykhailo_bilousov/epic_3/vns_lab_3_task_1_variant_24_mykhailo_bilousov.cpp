#include <iostream>
#include <cmath>
using namespace std;

#define N 40
#define EPSILON 0.0001
#define L -2
#define R -0.1

double f_setn(double x) {
    double sum = 0;
    for(int n = 1; n <= N; n++) sum += (pow(-1, n)*pow(1+x, 2*n)/n);
    return sum;
}

double f_setepsilon(double x) {
    double sum = 0, part = 0, prevpart = -1;
    int n = 1;
    do {
        sum += part;
        prevpart = part;
        part = (pow(-1, n)*pow(1+x, 2*n)/n);
        n++;
    } while(abs(part-prevpart) > EPSILON);
    return sum;
}

int main() {
    for(double x = L; x <= R; x += (R-L)/10) {
        cout << "x = " << x << endl;
        cout << "Function for set n (" << N << "): " << f_setn(x) << endl;
        cout << "Function for set epsilon (" << EPSILON << "): " << f_setepsilon(x) << endl;
    }
}