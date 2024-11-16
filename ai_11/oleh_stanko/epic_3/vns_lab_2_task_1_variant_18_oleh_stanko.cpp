#include <iostream>
#include <math.h>

using namespace std;

double calculation(double b, int n)
{
    double a;
    a=b*pow(n+1,3)/(pow(n,3)*3*n*(3*n-1)*(3*n-2));
    return a;
}

int main()
{
    const double e=0.0001;
    double b=1;
    int n=1;
    long double s=b;
    while (b>e)
    {
    b=calculation(b,n);
    s+=b;
    n++;       
    }
    cout<<s<<"\n";
    return 0;
}