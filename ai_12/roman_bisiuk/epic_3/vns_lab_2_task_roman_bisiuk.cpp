#include <iostream>
#include <cmath>

using namespace std;


int main(){

    double sum = 0.0;
    unsigned long long factorial = 1;
    for(int n = 1; n <= 10; n++ ){
       factorial *=n;
       double denominator = pow(n, sqrt(n));
       double term = factorial / denominator;
       sum += term; 
    }
    cout << "Сума перших 10 членів ряду:   " << sum;

}


