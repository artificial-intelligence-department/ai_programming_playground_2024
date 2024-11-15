#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//обчислюємо розклад в ряд для заданого n
double calculateSeriesFixedN(double x, int n) {
    double sum = 1.0;
    double term = 1.0;
    double cos_x = cos(x);
    
    for (int i = 1; i <= n; ++i) {
        term *= cos_x / i;
        sum += term;
    }
    
    return sum * cos(sin(x));
}

//обчислюємо розклад в ряд для точності епсілон
double calculateSeriesEpsilon(double x, double epsilon) {
    double sum = 1.0;
    double term = 1.0;
    double cos_x = cos(x);
    int i = 1;
    
    while (fabs(term) > epsilon) { 
        term *= cos_x / i;
        sum += term;
        ++i;
    }
    
    return sum * cos(sin(x)); 
}

int main() {
    double a = 0.1, b = 1.0; // Діапазон значень x
    int k = 10;
    int n = 20;
    double epsilon = 0.0001;

    double step = (b - a) / k;

    cout << "x\tSeries (fixed n)\tSeries (epsilon)\tExact" << endl;
    cout << fixed << setprecision(6);

    for (double x = a; x <= b; x += step) {
        double seriesFixedN = calculateSeriesFixedN(x, n);
        double seriesEpsilon = calculateSeriesEpsilon(x, epsilon);
        double exactValue = exp(cos(x)) * cos(sin(x));
        
        cout << x << "\t" << seriesFixedN << "\t\t" << seriesEpsilon << "\t\t" << exactValue << endl;
    }
    
    return 0;
}
