#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double calculateArctan(double x, int terms)
{
    double sum = 0.0;
    for(int i = 0; i < terms; i++)
    {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
        sum += term;
    }
    return sum;
}

double calculateArctanWithEpsilon(double x, double epsilon) 
{
    double sum = 0.0; 
    int i = 0; 
    while (true) 
    {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
        sum += term;
        if (abs(term) < epsilon) {
            break;
        }
        i++; 
    }
    return sum;
}
int main() 
{
    double start = 0.1; 
    double end = 1.0;   
    int intervals = 10; 
    int terms = 40;  
    double epsilon = 0.0001;    

    double step = (end - start) / intervals; 

    cout << fixed << setprecision(8); 
    cout << "Calculation results:\n";
    for (int i = 0; i <= intervals; i++) 
    {
        
        double x = start + i * step; 
        
        double fixedN = calculateArctan(x, terms);
        
        double untilEpsilon = calculateArctanWithEpsilon(x, epsilon);
        
        double exact = atan(x);


        cout << "X=" << x 
             << " FixedN=" << fixedN 
             << " UntilEpsilon=" << untilEpsilon 
             << " Exact=" << exact << endl;
    }

    return 0; 
}