#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

double count_a(int n, double x)
{
    double a =cos(2*n*x)/(4*n*n-1);
    return a;
}

int main()
{
    int n=1;
    double a=0.1;
    double x=a;
    double b=0.8;
    int k=10;
    double step=(b-a)/k; 
    double sn=0;
    double se=0;
    double y;
    while (x<=b+0.00000001)
    {
        while (n<=50)
        {
            sn+=count_a(n,x);
            n++;
        }   
        n=1;
        while (fabs(count_a(n,x))>=0.0001)
        {
            se+=count_a(n,x);
            n++;
        }
        y=0.5-M_PI/4*fabs(sin(x));
        printf("x= %lf \t sn= %lf \t se= %lf \t y= %lf \n", x, sn, se, y);
        x+=step;
        sn=0;
        se=0;
        n=1;  
    }
    return 0;
}