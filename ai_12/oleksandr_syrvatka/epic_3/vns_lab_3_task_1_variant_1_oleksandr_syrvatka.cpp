#include <iostream>
#include <math.h>

using namespace std;

double fact(int &n){
    double factorial= 1;
    for(int i = 1; i<=n; i++){
        factorial *= i;
    }
    return factorial;
}
double sumn(double &x, int &n){
    double sum = 0.0;
    double temp;
    for(int i = 0; i<n; i++){
        temp = (pow(log(3),i)/fact(i))*pow(x,i);
        sum += temp;
    }    
    return sum;
}
double sume(double &x, double &e){
    double temp = 1.0;
    double sum = 0.0;
    int i = 0;
    do {
        temp = (pow(log(3),i)/fact(i))*pow(x,i);
        sum += temp;
        i++;
    }  
    while (abs(temp) > e );
    
    return sum;
}
int main() {
    double a = 0.1, b = 1.0, e = 0.0001;
    int n = 10; 
    double krok = (b - a)/10;
    for (double x = a; x <= b; x+=krok){
         cout << "x = " << x <<"\n";
         cout << "f(x)  = " << pow(3,x) <<"\n";
         cout << "f(x) для n приблизно = " << sumn(x,n) <<"\n";
         cout << "f(x) для точності e приблизно = " << sume(x,e) << "\n";
         cout << "_______________________________________________________" << "\n"; 
    }
    return 0;  
}