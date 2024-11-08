#include <iostream>
#include <cmath>
using namespace std;

long long factorial(int n)
{
    long long result = 1;
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

double a(int n)
{
    return log(factorial(n) / pow(n, 2));
}

int main()
{
    const int num_terms = 13; 
    double sum = 0.0;
    for(int n = 1; n <= num_terms; ++n)
    {
        sum += a(n);
    }

    cout << "Сума перших " << num_terms << " членів ряду дорівнює: " << sum << endl;

    return 0;

}