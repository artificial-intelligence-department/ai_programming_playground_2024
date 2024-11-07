#include <iostream>
#include <math.h>
using namespace std;
int main(){
    double result = 0.0;
    double precRes = 0.0;
    double sum = 0;
    double a = 0.1;
    double b = 1.0 ;
    double k = 10.0;
    const double eps = 0.0001;
    double funcResult;
    double step = (b - a) / k;
    for(double x = a; x <= b; x += step){
        cout << "\nx = " << x << "\n";
        funcResult += (exp(x) + exp(-x)) / 2;
        for(int n = 0; n < 10; n++){
            result += pow(x, 2 * n )/tgamma(2 * n + 1);}
        int start = 0;
        for(int n = start; !(precRes > funcResult ? precRes - funcResult < eps : funcResult - precRes < eps); n++){
            precRes += pow(x, 2*n)/tgamma(2 * n + 1);}
        cout<<"Actual result: " << funcResult << "\nAproximate result: " << result << "\nResult with precision of " << eps << " : " << precRes << endl;}
    return 0;}