#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//використовую простір імен для обчислень ряду
namespace SeriesCalculations {
    //використовую перевантажену функцію для обчислень ряду для фіксованого n
    double calculateSeries(double x, int n) {
        double sum = 1.0;
        double cos_x = cos(x);//використала вбудовану ф-ю cos

        for (int i = 1; i <= n; ++i) {
            double term = 1.0;
            for (int j = 1; j <= i; ++j) { //використовую вкладений цикл
                term *= cos_x / j;
            }
            sum += term;
        }

        return sum * cos(sin(x));
    }

    //використовую перевантажену функцію для обчислення ряду з точностю epsilon
    double calculateSeries(double x, double epsilon) {
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
}

int main() {
    double a = 0.1, b = 1.0;
    int k = 10;        
    int n = 20;           
    double epsilon = 0.0001;
    double step = (b - a) / k;

    cout << "x\tSeries (fixed n)\tSeries (epsilon)\tExact" << endl;
    cout << fixed << setprecision(6);

    for (double x = a; x <= b; x += step) {
        //викликаю перевантажені функції
        double seriesFixedN = SeriesCalculations::calculateSeries(x, n);
        double seriesEpsilon = SeriesCalculations::calculateSeries(x, epsilon);
        double exactValue = exp(cos(x)) * cos(sin(x));

        cout << x << "\t" << seriesFixedN << "\t\t" << seriesEpsilon << "\t\t" << exactValue << endl;

        if (fabs(seriesFixedN - exactValue) < epsilon) {
            cout << "Досягнута точність для x = " << x << "." << endl;
        }
    }

    return 0;
}
