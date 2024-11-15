#include <iostream>
#include <cmath>
using namespace std;
 int main (){
    int n = 1;
    double result; 
    double a=0;
    double e = 0.0001;
    long long factorial = 1;
    
    if (n <= 1)
        factorial=1;
    else {
        for(int i = 1; i <= n; ++i) {
            factorial *= i;
        }
    }
    
    while (a>e){
        a= factorial / (3*pow(n,n));
        n++;
        result +=a;
    }
    cout << result ;
 }