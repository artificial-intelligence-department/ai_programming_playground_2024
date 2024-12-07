// Варіант 21
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double GetH(double a, double b, double c)
{
    if (a <= 0) 
    { 
        return 0;
    }

    double p = (a + b + c) / 2; 
    return (2/a) * sqrt(p * (p - a) * (p - c));
}
int main()
{
    const int MAX = 5;
    double a[MAX], b[MAX], c[MAX];
    double h = 0;

    cout << "Введіть сторони п’яти трикутників (a, b, c):" << endl;
    for (int i = 0; i < MAX; i++) 
    {
        cout << "Трикутник " << i + 1 << ": ";
        cin >> a[i] >> b[i] >> c[i];

        double currentH = GetH(a[i], b[i], c[i]);
        if (currentH > h) 
        {
            h = currentH;
        }
    }

    cout << "Висота найбільшого трикутника = " << h << endl;

    return 0;
}