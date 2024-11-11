#include <iostream>
#include <math.h>

using namespace std;

int main(){
    //((a+b)^3-(a^3-3a^2b))/(b^3-3ab^2)
    
    //float:
    float a = 1000, b = 0.0001;
    float x = pow((a-b), 3);
    float y = pow(a,3);
    float z = 3*b*pow(a,2);
    float k = pow(b,3);
    float l = 3*pow(b,2);
    float n = (x - y - z);
    float m = (k - l);
    float result = n/m;

    //double:
    double a2 = 1000, b2 = 0.0001;
    double x2 = pow((a2-b2), 3);
    double y2 = pow(a2,3);
    double z2 = 3*b2*pow(a2,2);
    double k2 = pow(b2,3);
    double l2 = 3*pow(b2,2);
    double n2 = (x2 - y2 - z2);
    double m2 = (k2 - l2);
    double result2 = n2/m2;

    cout << "Float = " << result << "\n";
    cout << "Double = " << result2 << "\n";

    return 0;
}