#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double numerator, denominator, z, x = 1, a = 0.6, h_x = 0.5, h_a = 0.2;

    while(x<=4){
        numerator = pow((x-1.5), 1/2) + pow(x,a);
        denominator = pow((x-2), 1/3); 
        z = numerator / denominator;
        cout << "x = " << x << "\t\ta = " << a << "\t\tz = " << z << endl;
        x += h_x;
        a += h_a;
    }

    return 0;

}

