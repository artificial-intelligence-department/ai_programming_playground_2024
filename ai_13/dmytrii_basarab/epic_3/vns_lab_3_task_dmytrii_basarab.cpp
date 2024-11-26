#include <iostream>
#include <cmath>

using namespace std;

double Function(double x) {
    return (((x * x) / 4.0) + (x / 2.0) + 1) * exp(x / 2.0);
}



int factorial(int n) {
    if (n <= 1) {
        return 1; 
    }
    return n * factorial(n - 1); 
}

int main() {
    double a = 0.1, b = 1.0;
    int k = 10;
    int n = 30;
    const double epsilon = 0.0001;

    double step = (b - a) / k;

    cout << "Calculation results: " << endl;

    for (int i = 0; i <= 10; ++i) {
        double x = a + i * step;

        
        double just = Function(x);

        
        double sumn = 0.0;
        for (int j = 1; j <= n; ++j) { 
            double currentElementn = ((pow(j, 2) + 1) * pow(x / 2, j)) / factorial(j);
            sumn += currentElementn;
        }

        
        double sume = 0.0;
        double currentElemente = 1.0; 
        int j = 1;                   
        while (abs(currentElemente) >= epsilon) {
            currentElemente = ((pow(j, 2) + 1) * pow(x / 2, j)) / factorial(j);
            sume += currentElemente;
            ++j;
        }

        
        cout << "X = " << x << " | SN = " << sumn << " | SE = " << sume << " | Y = " << just << endl;
    }

    return 0;
}
