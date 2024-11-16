#include <iostream>
#include <math.h>

using namespace std;

int main(){

    float a1 = 1000;
    float b1 = 0.0001;
    float c1 = a1 - b1;
    float d1 = pow ( c1, 3);
    float e1 = pow ( a1, 3);
    float f1 = pow ( a1, 2);
    float g1 = 3 * f1 * b1;
    float h1 = e1 - g1;
    float i1 = d1 - h1;
    float q1 = pow ( b1, 3);
    float k1 = pow ( b1, 2);
    float l1 = 3 * a1 * k1;
    float m1 = q1 - l1;
    float result1 = i1 / m1;

    cout << "Result with float is : " << result1 << endl;

    double a2 = 1000;
    double b2 = 0.0001;
    double c2 = a2 - b2;
    double d2 = pow ( c2, 3);
    double e2 = pow ( a2, 3);
    double f2 = pow ( a2, 2);
    double g2 = 3 * f2 * b2;
    double h2 = e2 - g2;
    double i2 = d2 - h2;
    double q2 = pow ( b2, 3);
    double k2 = pow ( b2, 2);
    double l2 = 3 * a2 * k2;
    double m2 = q2 - l2;
    double result2 = i2 / m2;

    cout << "Result with double is : " << result2 << endl;

    return 0;
}

//due to the fact that float and double store a different number of symbols,
//we get different results and this must be taken into account in the calculations.
