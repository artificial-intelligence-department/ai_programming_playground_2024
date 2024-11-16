#include<iostream>
#include <cmath>

using namespace std;

int Factorial(int n)
{
    int factorial = 1.0;

    for(int i = 1; i <= n; i++)
    {
        factorial *= i;
    } 

    return factorial;
}

int main()
{
    double precision = 0.0001;
    long double temp = 0.0;
    long double sum = 0.0;
    int n = 1;

    do
    {
        temp = Factorial(n)/ pow(n, n);
        if (temp < precision)
        {
            break;
        }
        sum += temp;
        n++;
    } while (temp >= precision);

    cout << sum;
    
    return 0;
}