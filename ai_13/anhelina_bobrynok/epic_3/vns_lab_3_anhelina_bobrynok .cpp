#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція для обчислення ряду при заданій кількості членів n
double calculateSeriesFixedN(double x, int n) {
    double sumSeries = 0.0;
    for (int i = 0; i < n; ++i) {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / tgamma(2 * i + 2); 
        sumSeries += term;
    }
    return sumSeries;
}

// Функція для обчислення ряду з точністю epsilon
double calculateSeriesPrecision(double x, double epsilon) {
    double sumSeries = 0.0;
    int i = 0;
    double term = x; 
    while (fabs(term) >= epsilon) {
        term = pow(-1, i) * pow(x, 2 * i + 1) / tgamma(2 * i + 2); // (-1)^i * x^(2i+1) / (2i+1)!
        sumSeries += term;
        ++i;
    }
    return sumSeries;
}

int main() {

    double a = 0.1;
    double b = 1.0;
    int k = 10;
    double epsilon = 0.0001;
    int n = 10;
    
    double step = (b - a) / k;

    cout << fixed << setprecision(6);
    cout << " x\t   S(x) для n    S(x) для ε    Точне значення\n";
    cout << "----------------------------------------------\n";
    
    for (double x = a; x <= b; x += step) {
  
        double seriesFixedN = calculateSeriesFixedN(x, n);
        
        double seriesPrecision = calculateSeriesPrecision(x, epsilon);

        double exactValue = sin(x);

        cout << x << "\t" << seriesFixedN << "\t" << seriesPrecision << "\t" << exactValue << "\n";
    }
    
    return 0;
}

