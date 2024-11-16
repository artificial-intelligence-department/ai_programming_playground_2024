#include <iostream>
#include <math.h>

using namespace std;

unsigned long long factorial(int n){
    if(n <= 1) return 1;

    return n * factorial(n - 1);
}

int main(){
    double precision = 0.0001;
    double sum = 0;
    double a = 0;
    int n = 1;

    do{
        a = pow(n, 3) / (double)factorial(3 * n - 3);
        sum += a;
        n++;
    }while(a > precision);

    cout << sum << endl;
}