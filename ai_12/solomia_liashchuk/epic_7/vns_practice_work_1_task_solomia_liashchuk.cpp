#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a = 0.5; 
    double b = 3.1; 
    double x = 1.4;

    double alpha_count1 = a * pow(x, 2) * sin(2 * x); 
    double alpha_count2 = exp(-2 * x) * (x + b);
    double alpha_result = sqrt(abs(alpha_count1 + alpha_count2));

    double cos_x = cos(x);
    double cos_squared_x = pow(cos_x, 2);
    double cube_root_count = cbrt(pow(a, 2) + pow(b, 2));
    double omega_result = (1 / cos_squared_x) * pow(x, 3) - x * cube_root_count;

    cout << "alpha: " << alpha_result << endl; 
    cout << "omega: " << omega_result << endl;

    return 0;

}
