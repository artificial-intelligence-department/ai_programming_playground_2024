#include<iostream>
#include <cmath>

using namespace std;

int Factorial(int n)
{
    int factorial = 1.0;

    for(int i = 1; i <= n; i++)
    {
        if (i == 0)
        {
            factorial = 0;
        }
        factorial *= i;
    } 

    return factorial;
}

double PresetPrecision(float x)
{
    double precision = 0.0001;
    long double temp = 0.0;
    double sum = 0.0;
    int n = 0;
    do
    {
        temp = ((2*n+1) / Factorial(n)) * pow(x, 2*n);
        if (temp < precision)
        {
            break;
        }
        sum += temp;
        n++;
    } while (temp >= precision);

    return sum;
}

double PresetNumber(float x)
{
    long double temp = 0.0;
    double sum = 0.0;

    for(int n = 0; n <= 10; n++)
    {
        temp = ((2*n+1) / Factorial(n)) * pow(x, 2*n);
        sum +=temp;
    }

    return sum;
}

long double ExactValue(float x)
{
    long double FunctionValue = (1 + 2*x*x) * exp(x*x);
    return FunctionValue;
}

int main()
{
    float a = 0.1;
    float b = 1.0;
    float k = 10.0;
    float step = (b-a)/k;

    for(float x = a; x <= b; x += step)
    {
        double UsingPresetPrecion = PresetPrecision(x);
        double UsingPresetNumber = PresetNumber(x);
        long double ExactFunctionValue = ExactValue(x);

        cout << "f(x), x = " << x << "\n - Exact value = " << ExactFunctionValue << "\n - With fixed precision = " << UsingPresetPrecion << "\n - With fixed 'n' = " << UsingPresetNumber << endl;
    }
    
    return 0;
}