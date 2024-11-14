#include <iostream>
#include <cmath>
#include <iomanip>

double exactFunction(double x) {
    return (1.0 / 4.0) * ((x * x) - (M_PI * M_PI) / 3.0);
}
double seriesFunction(double x, int n) {
    double sum = -cos(x);
    for (int k = 2; k <= n; ++k) {
        sum += pow(-1, k) * cos(k * x) / (k * k);
    }
    return sum;
}
double seriesFunctionWithAccuracy(double x, double epsilon) {
    double sum = -cos(x);
    int k = 2;
    double term;
    do {
        term = pow(-1, k) * cos(k * x) / (k * k);
        sum += term;
        k++;
    } while (fabs(term) >= epsilon);
    return sum;
}

int main() {
    double a = M_PI / 5;
    double b = M_PI;
    int k = 10;
    int n = 20; 
    double epsilon = 0.0001;
    double step = (b - a) / k;
    std::cout << std::fixed << std::setprecision(6);
    
    for(; a<=b; a += step){
        double x;
        x = a;
        double exact = exactFunction(x);
        double seriesN = seriesFunction(x, n);
        double seriesEpsilon = seriesFunctionWithAccuracy(x, epsilon);
        std::cout << "X= "<< x << "\tY= " << exact << "\tSN= " << seriesN << "\tSE= " << seriesEpsilon << "\n";
    }
    return 0;
}
