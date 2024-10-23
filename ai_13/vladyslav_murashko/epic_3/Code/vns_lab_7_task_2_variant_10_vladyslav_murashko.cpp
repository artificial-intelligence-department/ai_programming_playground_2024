#include <iostream>
#include <cmath>

double fractionsSubstract(double fract1, double fract2)
{
    return fract1 - fract2;
}

double fractionsSubstract(int numerator1, int denominator1, int numerator2, int denominator2)
{
    double fract1 = (double)numerator1 / denominator1;
    double fract2 = (double)numerator2 / denominator2;
    return fractionsSubstract(fract1, fract2);
}

int main()
{
    std::cout << "Decimal substuction: " << fractionsSubstract(0.2, 0.1) << std::endl;
    std::cout << "Fractions substuction: " << fractionsSubstract(1, 2, 3, 4) << std::endl;

    return 0;
}
