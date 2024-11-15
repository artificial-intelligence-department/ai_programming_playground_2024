#include<iostream>
#include<math.h>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else 
    {
        return n * factorial(n - 1);
    }
}
double number_sum(int n)
{
    if (n == 1)
    {
        return 2;
    }
    else return ((pow(2, n) * factorial(n)) / pow(n, n)) + number_sum(n - 1);

}

int main()
{
    int n;
    cin>>n;

    printf("%.4lf", number_sum(n));

    return 0;
}