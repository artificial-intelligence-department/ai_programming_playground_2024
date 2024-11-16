#include <iostream>
#include <cmath> 
using namespace std;

int main() 
{
    const double epsilon = 0.0001; 
    double sum = 0.0; 
    double term; 
    int n = 1; 

    do 
    {
        term = (1.0 / pow(2, n)) + (1.0 / pow(3, n)); 
        sum += term; 
        n++;
    } 
    while (fabs(term) > epsilon); 

    cout << "Сума ряду з точністю до " << epsilon << " дорівнює: " << sum << endl; 
}
