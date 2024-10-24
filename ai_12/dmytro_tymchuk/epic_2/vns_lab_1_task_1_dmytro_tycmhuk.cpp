#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    float a=1000;
    float b=0.0001;

    float op1f, op2f;
    op1f = pow((a + b), 3) - (pow(a,3) + 3*a*a*b);
    op2f = 3 * a * b * b + pow(b, 3);
    

    cout<<"Float: "<< op1f / op2f<<endl;

    double a1=1000;
    double b1=0.0001;

    double op1d, op2d;
    op1f = pow((a1 + b1), 3) - (pow(a1,3) + 3*a1*a1*b1);
    op2f = 3 * a1 * b1 * b1 + pow(b1, 3);
    

    cout<<"Double: "<< op1d / op2d <<endl;


    return 0;
}