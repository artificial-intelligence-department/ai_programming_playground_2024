#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double hx = 0.5, a = -0.5, ha = 0.2 , chisl , znam;

    for(double x = 1; x <= 4 ; x += hx , a += ha){
        chisl = pow((x - 1.5) , 0.5) + pow(x , a);
        znam = pow((x - 2) , 1.0/3);
        cout << "Z = " << chisl / znam << endl;
    }

    return 0;
}