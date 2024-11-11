#include <iostream>
#include <cstdarg>
#include <math.h>

using namespace std;

int gcd(int a,int b)
{
    int res;
    if (a<b)
    {
        res=a;
    }
    else 
    {
        res=b;
    }
    while (res > 1) {
        if (a % res == 0 && b % res == 0)
            break;
        res--;
    }
    return res;
}


int lmc(int a, int b)
{
    return((a*b)/gcd(a,b));
}

int nok(int n,...)
{
    va_list a;
    va_start(a,n);
    
    int res= va_arg(a, int);
    for (int i=1; i<n;i++)
    {
        res=lmc(res, va_arg(a, int));        
    }
    va_end(a);
    return res;
} 

int main()
{
    cout << "lmc of numbers 5,8,9="<<nok(3,5,8,9)<<"\n";
    cout << "lmc of numbers 2,6,9,8,11="<<nok(5,2,6,9,8,11)<<"\n";
    cout << "lmc of numbers 9,17,98,55,88,13="<<nok(6,9,17,98,55,88,13)<<"\n";
    return 0;
}