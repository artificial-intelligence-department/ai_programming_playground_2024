#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

double calculateSum(double e){
    int n = 1;
    double sum_series = 0.0;
    double a_n;
    while (true){;
        double factorial = 1;
        a_n = (pow(10,-n)) * tgamma(n);
    if (a_n < e){
        break;}
        sum_series += a_n;
        n++;}
    return sum_series;}
int main(){
    double e = 0.0001;
    double sum = calculateSum(e);
    cout << "sum of set with accuracy e = " << e << ": " << sum << endl;
    return 0;}