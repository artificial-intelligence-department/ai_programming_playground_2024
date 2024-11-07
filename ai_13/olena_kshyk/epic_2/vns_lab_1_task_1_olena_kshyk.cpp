#include <iostream>
#include <math.h>
using namespace std;

int main(){
    //float takes 4 bytes and stores numbers with an accuracy of about 7 significant digits
    const float a1 = 1000;
    const float b1 = 0.0001;
    float c1 = pow(a1+b1, 3);
    float d1 = a1*a1*a1 + 3*a1*a1*b1;
    float e1 = 3*a1*b1*b1 + b1*b1*b1;
    float f1 = (c1 - d1)/e1;
    cout <<"Result with float: " << f1 << endl;

    // double can hold floating-point values of up to 15 digits taking up a space of 8 bytes in the memory.
    const double a2 = 1000;
    const double b2 = 0.0001;
    double c2 = pow(a2+b2, 3);
    double d2 = a2*a2*a2 + 3*a2*a2*b2;
    double e2 = 3*a2*b2*b2 + b2*b2*b2;
    double f2 = (c2 - d2)/e2;
    cout <<"Result with double: "<< f2 << endl; 
    return 0;
}