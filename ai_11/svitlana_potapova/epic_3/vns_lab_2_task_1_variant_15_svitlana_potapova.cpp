#include <iostream>
#include <math.h>
using namespace std;

double factorial(int n) {
    if (n <= 1) 
        return 1;
    else
        return n * factorial(n - 1); 
}

int main(){
    double e = 0.0001;
    double sum = 0;
    int n = 1;
    double a_n = (factorial(n) * factorial(n)) / pow(2, n * n);

    do {
        sum += a_n;  
        
        a_n = a_n * ((n + 1) * (n + 1)) / pow(2, 2 * n + 1); // рекурентна формула
        ++n;          
    } while (a_n > e); 

    cout << "Сума ряду з точністю " << e << " дорівнює: " << sum << endl;

    return 0;
}

