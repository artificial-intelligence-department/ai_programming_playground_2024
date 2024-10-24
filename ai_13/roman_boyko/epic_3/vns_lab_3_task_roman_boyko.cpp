#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double functionForN(double x, int n);
double functionForEps(double x, double eps);
int main()
{
    double a = 0.1;
    double b = 1.0;
    int k = 10, n = 10;
    double eps = 0.0001;
    double step = (b - a) / k;

    for (int i = 0; i <= k; i++)
    {
        double x = a + i * step;
        double ex_value = pow(3, x);
        double forNums = functionForN(x, n);
        double forEps = functionForEps(x, eps);
        cout << "x = " << setprecision(4) << x << endl;
        cout << "res = " << setprecision(8) << ex_value << endl;
        cout << "res in n = " << setprecision(8) << forNums << endl;
        cout << "res in eps = " << setprecision(8) << forEps << endl;
        cout << endl;
    }
}
double functionForN(double x, int n)
{
    double sum = 1.0, res = 1.0;
    double ln3 = log(3);
    for (int i = 1; i <= n; i++)
    {
        res *= (ln3 * x) / i;
        sum += res;
    }
    return sum;
}
double functionForEps(double x, double eps)
{
    double sum = 1.0, res = 1.0;
    double ln3 = log(3);
    int i = 1;
    while (res > eps)
    {
        res *= (ln3 * x) / i;
        sum += res;
        ++i;
    }
    return sum;
}