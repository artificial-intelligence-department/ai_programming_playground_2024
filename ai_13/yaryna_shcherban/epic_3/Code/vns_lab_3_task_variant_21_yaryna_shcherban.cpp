#include <iostream>
#include <cmath>

using namespace std;

double function_N (double x, int n);
double function_E (double x, double epsilon);

double function_N(double x, int n) {
    double sum = 1.0;
    double result_N = 1.0;
    double m = (pow (-1, n) * pow (x, (2*n+1))) / (2*n+1) ;
    for (int i = 1; i <= n; i++) {
        result_N *= m; 
        sum += result_N;
    }
    return sum;
}

double function_E (double x, double epsilon) {
    double sum = 1.0;
    double result_E = 1.0;
    int n;
    double m = (pow (-1, n) * pow (x, (2*n+1))) / (2*n+1) ;
    int i = 1;
    while (result_E < epsilon) {
        result_E *= m;
        sum += result_E;
        ++i;
    }
    return sum;
}

int main() {

    double a = 0.1;
    double b = 1.0;
    int k = 10;
    int n = 40;
    double epsilon = 0.0001;
    double step = (b - a) / k;


    for ( int i = 0; i <= k; i++ ) {
        double x = a + i * step;
        double function = atan (x);
        double for_N = function_N (x, n);
        double for_E = function_E (x, epsilon);
        cout << "x = " << x << endl; 
        cout << "result = "  <<function << endl;
        cout << "result in n = "  << for_N << endl;
        cout << "result in epsilon = "  << for_E << endl;
    }
}
