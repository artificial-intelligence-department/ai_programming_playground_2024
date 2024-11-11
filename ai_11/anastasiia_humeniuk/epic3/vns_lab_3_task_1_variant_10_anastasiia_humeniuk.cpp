#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x) {
    return pow(M_E, cos(x)) * cos(sin(x));
}

double fact(int n) {
    return (n == 0 || n == 1) ? 1 : n * fact(n - 1);
}

int main() {
    double k = 10;         
    double e = 0.0001;    
    int N = 20;             
    double a = 1, b = 0.1;  
    double step = (b - a) / k; 

   cout << fixed << setprecision(6);
   cout << setiosflags(ios::left);
    

    for (int i = 0; i < k; i++) {
        double x = a + (i * step);
        double func_value = func(x);

        double sumN = 0.0;
        for (int j = 1; j <= N; j++) {
            double termN = cos(j * x) / fact(j);
            sumN += termN;
        }

        double sumE = 0.0;
        double termE;
        int m = 1;
        do {
            termE = cos(m * x) / fact(m);
            sumE += termE;
            m++;
        } while (abs(termE) >= e);

        // Виведення результатів
        cout << "X=" << setw(10) << x
             << " SN=" << setw(10) << sumN
             << " SE=" << setw(10) << sumE
             << " Y=" << setw(10) << func_value << "\n";
    }
    
    return 0;
}
