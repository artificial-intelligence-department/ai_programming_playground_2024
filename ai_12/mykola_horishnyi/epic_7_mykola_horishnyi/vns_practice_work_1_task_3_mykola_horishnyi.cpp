#include <iostream>
#include <cmath> 

using namespace std;

int main()
{
    double x = 1.2; 
    double y = -0.8; 

    double s = 1 + x + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 4; // pow = степінь

    double z = pow(sin(x), 3) + pow(cos(y), 2);

    cout << "s = " << s << endl;
    cout << "z = " << z << endl;

    return 0;


}








