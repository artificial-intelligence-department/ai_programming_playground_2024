#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main (){
    double accuracy = 0.0001;
    double sum = 0.0;
    int n = 2;
    double calc; 

    do {
        calc = n / pow((n-1), 2);
        sum += calc;
        n++;
    } while (calc >= accuracy);
    cout << sum;

    return 0;
}