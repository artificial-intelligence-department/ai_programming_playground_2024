#include<iostream>
#include<cstdarg>

using namespace std;

double Multiplication(int Numerator1, int Denominator1, int Numerator2, int Denominator2)
{
    return static_cast<double>(Numerator1 * Numerator2) / (Denominator1 * Denominator2);
}

double Multiplication(double DecimalFraction1, double DecimalFraction2)
{
    return DecimalFraction1 * DecimalFraction2;
}

int main()
{
    int Numerator1 = 8;
    int Denominator1 = 33;
    int Numerator2 = 17;
    int Denominator2 = 25;

    double DecimalFraction1 = 3.14;
    double DecimalFraction2 = 11.096;

    cout << "Результат множення звичайних дробів : " << Multiplication(Numerator1, Denominator1, Numerator2, Denominator2) << endl;
    cout << "Результат множення десткових дробів : " << Multiplication(DecimalFraction1, DecimalFraction2) << endl;
    return 0;
}