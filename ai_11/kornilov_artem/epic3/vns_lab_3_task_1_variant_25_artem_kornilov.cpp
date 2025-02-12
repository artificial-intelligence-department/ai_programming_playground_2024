#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double exactFunction(double x) {
    return (exp(x) - exp(-x)) / 2;
}


double seriesWithFixedNRecursive(double x, int n, int i = 0) {

    if (i > n) {
        return 0.0;
    }

    double term = pow(x, 2 * i + 1) / tgamma(2 * i + 2);

    return term + seriesWithFixedNRecursive(x, n, i + 1);
}


double seriesWithEpsilon(double x, double epsilon) {
    double sum = 0.0;
    double term = x;
    int i = 0;
    
    while (fabs(term) > epsilon) {
        sum += term;
        i++;
        term = pow(x, 2 * i + 1) / tgamma(2 * i + 2);
    }
    return sum;
}

int main() {
    double a = 0.1;
    double b = 1.0;
    int k = 10;
    int n = 20; 
    double epsilon = 0.0001; 

    double step = (b - a) / k;
    
    cout << fixed << setprecision(6);
    cout << " x\t\tSeries (n = " << n << ")\t\tSeries (Eps = " << epsilon << ")\tExact Value\n";
    cout << "--------------------------------------------------------------------------\n";

    for (double x = a; x <= b; x += step) {
        double valueWithN = seriesWithFixedNRecursive(x, n);
        double valueWithEpsilon = seriesWithEpsilon(x, epsilon);
        double exactValue = exactFunction(x);

        cout << x << "\t" << valueWithN << "\t\t" << valueWithEpsilon << "\t\t" << exactValue << "\n";
    }

    return 0;
}

