#include <cmath>
#include <iostream>

using namespace std;

long long factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n-1);
}

int main()
{
    //float e = 0.0001;
    int num;
    cout << "Enter the number of terms to calculate the sum of the series: ";
    cin >> num;
    
    double sum = 0.0;

    for (int n = 1; n <= num; n++)
    {
        double term = pow(10, -n) * factorial(n - 1); 
        sum += term;
    }

    cout << "The sum of the series for " << num << " terms is: " << sum << endl;

    return 0;
}
