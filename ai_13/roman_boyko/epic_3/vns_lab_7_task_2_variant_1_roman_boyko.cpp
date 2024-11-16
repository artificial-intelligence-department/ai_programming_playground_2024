#include <iostream>
#include <complex>
using namespace std;
int sum(int a, int b)
{
    return a + b;
}
complex<double> sum(complex<double> a, complex<double> b)
{
    return a + b;
}
int main()
{

    int s = sum(1, 2);
    cout << s;
    cout << endl;
    complex<double> z = sum(complex<double>(1, 3), complex<double>(5, -7));
    double real = z.real();
    double im = z.imag();
    cout << real;
    if (im > 0)
    {
        cout << "+" << im << "i";
    }
    else
    {
        cout << "-" << -im << "i";
    }
}
