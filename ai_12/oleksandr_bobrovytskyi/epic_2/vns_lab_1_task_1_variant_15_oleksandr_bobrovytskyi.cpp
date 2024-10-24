#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b = 0;
    double temp1,temp2 = 0;
    double result = 0;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    temp1 = pow(a+b, 3) - pow(a, 3);
    temp2 = 3*a*pow(b, 2) + pow(b, 3) + 3*b*pow(a, 2);

    result = temp1/temp2;

    cout << "Result = " << result;

    return 0;
}