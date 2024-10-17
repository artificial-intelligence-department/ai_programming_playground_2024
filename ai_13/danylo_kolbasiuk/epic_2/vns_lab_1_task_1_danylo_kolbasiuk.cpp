// Variant 10
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // because of different precision values using float and double, both don't output one
    float a1=100;
    float b1=0.001;
    float c11=a1-b1;
    float c1=pow(c11, 4);
    float d1=pow(a1,4);
    float e1=pow(a1,3);
    float g1=4*e1*b1;
    float h1=pow(a1,2);
    float i1=pow(b1,2);
    float j1=6*h1*i1;
    float k1=d1-g1+j1;
    float l1=c1-k1;
    float m1=pow(b1,4);
    float n1=pow(b1,3);
    float o1=4*a1*n1;
    float p1=m1-o1;
    float q1=l1/p1;
    cout << "Result with float: " << q1 << endl;
    double a2=100;
    double b2=0.001;
    double c21=a2-b2;
    double c2=pow(c21, 4);
    double d2=pow(a2,4);
    double e2=pow(a2,3);
    double g2=4*e2*b2;
    double h2=pow(a2,2);
    double i2=pow(b2,2);
    double j2=6*h2*i2;
    double k2=d2-g2+j2;
    double l2=c2-k2;
    double m2=pow(b2,4);
    double n2=pow(b2,3);
    double o2=4*a2*n2;
    double p2=m2-o2;
    double q2=l2/p2;
    cout << "Result with double: " << q2;
}
