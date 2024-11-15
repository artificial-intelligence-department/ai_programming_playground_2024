#include <stdio.h>
#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

int main()
{
    double a = 5.3, y = 1.1;
    int n = 0;
    double x[13];
    for (double i = -3; i <= 3; i += 0.5){
        x[n] = i;
        n++;
    }
    
    cout << fixed << setprecision(2); 

    for (int i = 0; i < n; i++){
        if ((pow(x[i],2) + pow(y,2)) <= pow(a,2)){
            cout << "First case:" << endl;
            y = (x[i]/(15*pow(x[i],2)));
            cout << "x = " << x[i] << "   " << '\t' << "y = " << y << endl;
        } else {
            cout << "Second case:" << endl;
            y = pow(x[i],2) + pow(M_E,x[i]);
            cout << "x = " << x[i] << "   " << '\t' << "y = "  << y << endl;
        }
    }    
    
}