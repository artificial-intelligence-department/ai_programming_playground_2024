#include<iostream>
#include<math.h>

using namespace std;

int main(){
    double a = 1000.0;
    double b = 0.0001;

    double c = pow(a-b, 3);
    double d = pow(a, 3) - 3*a*pow(b, 2);
    double e = c - d;
    double f = pow(b, 3) - 3*b*pow(a, 2);
    double g = e / f;


    float a1 = 1000.0f;
    float b1 = 0.0001f;

    float c1 = pow(a1-b1, 3);
    float d1 = pow(a1, 3) - 3*a1*pow(b1, 2);
    float e1 = c1 - d1;
    float f1 = pow(b1, 3) - 3*b1*pow(a1, 2);
    float g1 = e1 / f1;

    cout.precision(10);
    cout << "Double: " << g << endl;
    cout << "Float: " << g1;

    return 0;
}