#include <iostream>
#include <cmath>
using namespace std;

 double function (double x){
        return 0.25*(pow(x,2)-(pow(M_PI,2)/3));
    }
    
 double sumCondition (double x, int n){
       double sum = 0;
    for (int k = 1; k <= n; k++) {
        sum += pow(-1,k)*(cos(k*x)/pow (k,2)); 
    }
     return sum;
    }
 double sumE (double x, double e){
    double sum = 0.0;
    double s = 0.0;
    int k = 1;
    while (e<s){
        s = pow(-1,k)*(cos(k*x)/pow (k,2));
        sum += s;
        k++;
    }
    return sum;
 }
 int main (){
    double e= 0.0001;
    double a = M_PI/5;
    double b = M_PI;
    int k = 10;
    int n = 20;
    double condition = (b-a)/k;
   
for (double x = a; x <= b; x += condition) {
    double value = function (x);
    double first = sumCondition (x,n);
    double second = sumE (x,e);
    cout << value << "  " << first << "  " << second;
 }
return 0;
 }