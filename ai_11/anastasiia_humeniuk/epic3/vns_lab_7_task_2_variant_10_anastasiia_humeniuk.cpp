#include <iostream>
#include <cmath>
using namespace std;
double Substract(double num_1, double num_2)
{
    return num_1 - num_2;
}

double Substract(int numerator1, int denominator1, int numerator2, int denominator2)
{
    double num1 = (double)numerator1 / denominator1;
    double num2 = (double)numerator2 / denominator2;
    return Substract(num1, num2);
}

int main()
{
    cout << "Десяткові дроби: " << Substract(0.4, 0.2) << endl;
    cout << "Звичайні дроби: " << Substract(4, 1, 1, 2) << endl;

    return 0;
}