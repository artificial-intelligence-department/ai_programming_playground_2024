#include <iostream>

using namespace std;

float Division(float num1, float num2)
{
    return num1 / num2;
}

double Division(double num1, double num2)
{
    return num1 / num2;
}

int main()
{
    float a = 1.2, b = 0.2;
    double x = (1.0 / 3.0), y = (9.0 / 17.0);

    float resultF = Division(a, b);
    double resultD = Division(x, y);

    cout << "Результатом ділення десяткових дробів " << a << " і " << b << " є: " << resultF << endl;
    cout << "Результатом ділення звичайних дробів 1/3 і 9/17 є: " << resultD << endl;

    return 0;
    
}