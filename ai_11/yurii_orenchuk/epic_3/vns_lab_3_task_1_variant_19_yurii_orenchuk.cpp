#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

namespace FacSpace{
    int Factorial(int n) {
        if (n <= 1)
            return 1;
        else
            return n * Factorial(n - 1);
    }
}
using namespace FacSpace;
int main(){
    double a = 0.1, b = 1.0, eps = 0.0001;
    int k = 10, n = 20;
    double step = (b-a)/k;

    double x;
    double sum = 1;
    double term1, term2;
    
    for(float x = a; x <= b; x += step){
        double exact = pow(M_E, (2 * x));

        term2 = pow((2*x), n) / Factorial(n);

        n = 1;
        do {
            term1 = pow((2*x), n) / Factorial(n);
            if (term1 < eps)
            {
                break;
            }
            sum += term1;
            n++;
        } while (term1 >= eps);

        
        cout << x << '\t' << "Exact: " << exact << '\t' << "To precision: " << term1 << '\t' << "For n = 20: " << term2 << endl;
    }

    return 0;
}