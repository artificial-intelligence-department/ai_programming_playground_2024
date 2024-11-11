#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    for (double x = 1.0; x <= 2.0; x += 0.1) {
        // Перший метод
        double s1 = 1.0;     
        double term1 = 1.0;  
        for (int i = 1; i <= 15; i++) {
            term1 *= x / i; 
            s1 += term1;
        }

        // Другий метод
        double s2 = 1.0;    
        double term2 = 1.0;  
        int j = 1;
        while (fabs(term2) > 0.0001) {
            term2 *= x / j; 
            s2 += term2;
            j++;
        }

        double exactValue = exp(x);

        printf("%.1f", x);
        printf("     %.4f", s1);
        printf("     %.4f", s2);
        printf("     %.4f\n", exactValue);

    }

    return 0;
}


