//Знайти суму ряду з точністю ε=0.0001, загальний член якого a(n) = 1/(2^n) + 1/(3^n)
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long double e = 0.00001;
    long double sum = 0;
    long double x = 1;
    for(int i = 1; x >= e;i++) {
        x = pow(2, -i) + pow(3, -i);
        sum += x;
    }
    cout << "The sum is: " << sum; 
    return 0;
}