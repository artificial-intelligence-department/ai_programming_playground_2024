#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;


int main()
{
    double y , z; 
    for(int b = 2;b <= 8;b += 2){
        for(double x = 1;x <= 2;x += 0.2){

        y = pow(M_E, x/2) * b*b * (cos(z) + sin(z));
        z = sqrt(4 * b + x*x) / 2;

        cout << "x = " << x << ", b = " << b << ", y = " << y << ", z = " << z << endl;
        }
    }

    return 0;

}