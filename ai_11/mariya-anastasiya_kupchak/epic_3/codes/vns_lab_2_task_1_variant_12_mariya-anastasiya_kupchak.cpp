#include <iostream>
#include <cmath>

using namespace std;

double factorialn(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorialn(n - 1);
    }
}

int main()
{
    float e = 0.0001;
    double summ = 0;
    int n;
    double an;

    cout << "Введіть n: " << endl;
    cin >> n;

    an = (pow(2, n) * factorialn(n)) / pow(n, n);

    do
    {
        summ += an;
        an = an * ((2 * pow(n, n)) / pow((n + 1), n));
    } 
    while (an > e);

    cout << "Сума ряду з точністю " << e << "= " << summ << endl;

    return 0;
    
}