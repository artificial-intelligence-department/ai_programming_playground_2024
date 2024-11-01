#include <iostream>
#include <cmath>

using namespace std;

double exactValue(double x) {
    return 0.5 - (M_PI / 4) * fabs(sin(x));
}

double sumWithFixedN(double x, int n) {
    double sum = 0.0;
    for (int k = 1; k <= n; k++) {
        sum += cos(2 * k * x) / (4 * k * k - 1); 
    }
    return sum;
}

double sumWithPrecision(double x, double epsilon) {
    double sum = 0.0;
    double a = 0.0;
    int k = 1;
    
    do {
        a = cos(2 * k * x) / (4 * k * k - 1);
        sum += a;
        k++;
    } while (fabs(a) > epsilon);
    
    return sum;
}

int main() {
    double a = 0.1;
    double b = 0.8;
    int k = 10;
    int n = 50;
    double epsilon = 0.0001;

    double step = (b - a) / k;
    
    cout << "X\t\tsumWithN\t\tsumWithEpsilon\t\tfuncValue" << endl;
    
    for (double x = a; x <= b; x += step) {
        double sumWithN = sumWithFixedN(x, n);
        double sumWithEpsilon = sumWithPrecision(x, epsilon);
        double funcValue = exactValue(x);
        cout << x << "\t\t" << sumWithN << "\t\t" << sumWithEpsilon << "\t\t" << funcValue << endl;
    }
}
