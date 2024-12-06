// var 8
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double x = 1.82;
    const double y = 18.5;    
    const double z = -3.4;
    double gamma = fabs(pow(x, y / x) - pow(y / x, 1.0 / 3.0));
    double fi = ((x - y) * y - (z / (y - x))) / (1 + pow(y - x, 2));
    cout << "gamma = " << gamma << "\t fi = " << fi;  
    return 0;
}