#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double exactFunction(double x);
double seriesSumN(double x, int n);
double seriesSumEpsilon(double x, double epsilon);

int main() {
    double a = 0.1;
    double b = 1.0;
    int n = 15;
    int k = 10;
    double epsilon = 0.0001;
    double step = (b - a) / k;
    cout << fixed << setprecision(6);
    
    for (double x = a; x <= b; x += step) {
        double exact = exactFunction(x);
        double seriesN = seriesSumN(x, n);
        double seriesE = seriesSumEpsilon(x, epsilon);

        cout << "X= " << x << "\tSN= " << seriesN << "\tSE= " << seriesE << "\tY= " << exact << endl;
    }

    return 0;
}

double exactFunction(double x) {
    return 2 * (pow(cos(x), 2) - 1); 
}

double seriesSumN(double x, int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        double temp = pow(-1, i) * pow(2 * x, 2 * i) / tgamma(2 * i + 1);
        sum += temp;
    }
    return sum;
}

double seriesSumEpsilon(double x, double epsilon) {
    double sum = 0.0;
    double temp;
    int i = 1;
    do {
        temp = pow(-1, i) * pow(2 * x, 2 * i) / tgamma(2 * i + 1);
        sum += temp;
        i++;
    } while (fabs(temp) >= epsilon);
    return sum;
}
