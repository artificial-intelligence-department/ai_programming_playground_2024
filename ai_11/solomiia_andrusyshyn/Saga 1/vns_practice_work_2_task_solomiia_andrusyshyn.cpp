#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double h_x = 0.5; 
    double h_a = 0.2; 
    double x = 1.0;   
    double a = 0.6;   

    while (x <= 4.0) 
    {
    
        double T1 = sqrt(x - 1.5) + pow(x, a);
        double T2 = pow((x - 2), 1.0 / 3.0);
        double z = T1 / T2;

        cout << "x = " << x << "\t\ta = " << a << "\t\tz = " << z << endl;

        x += h_x;
        a += h_a;
    }

    return 0;
}
