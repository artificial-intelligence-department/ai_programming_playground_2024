#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    int a=100;
    double b=0.001;
    double s[4];

    s[0]=pow(a+b,4);
    s[1]=pow(a,4)+4*pow(a,3)*b+6*a*a*b*b;
    s[2]=4*a*pow(b,3)+pow(b,4);
    s[3]=(s[0]-s[1])/s[2];
    cout << "double: " << s[3]<<endl;
 
    int a1=100;
    float b1=0.001;
    float s1[4];

    s1[0]=pow(a1+b1,4);
    s1[1]=pow(a1,4)+4*pow(a1,3)*b1+6*a1*a1*b1*b1;
    s1[2]=4*a1*pow(b1,3)+pow(b1,4);
    s1[3]=(s1[0]-s1[1])/s1[2];
    
    cout << "float: " << s1[3]<<endl;
}