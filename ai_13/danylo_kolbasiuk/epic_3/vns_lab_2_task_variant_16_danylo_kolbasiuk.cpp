#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n)
{
    if (n<1)
    {
        return 1;
    }
    else 
    {
        return factorial(n-1)*n;
    }
}
double suma (int n)
{
    double sum = 0.0;
    double factor = 1;
    for (int i=1; i<=n; i++)
    {   
        double factor = factorial(i);
        double log = log10(factor);
        double temp = -i*sqrt(i);
        double an = log*exp(temp);
        sum += an;
    }
    return sum;
}
int main()
{
    int n;
    cout << "Input the size of the row: ";
    cin >> n;
    double row_sum = suma(n);
    printf("The sum of the row: %0.4f", row_sum);
    return 0;
}