#include <iostream>
#include <complex>

long double Multiply(long double a, long double b)
{
    return a * b;
}

std::complex<double> Multiply(std::complex<double> a, std::complex<double> b)
{
    return a * b;
}


int main()
{
    std::complex<double> num1, num2;
    double re1, im1, re2, im2;
    std::cout << "Enter two complex numbers:" << std::endl;
    std::cin >> re1 >> im1 >> re2 >> im2;
    num1 = std::complex<double>(re1, im1);
    num2 = std::complex<double>(re2, im2);
    std::cout << "Multiple: " << Multiply(num1, num2) <<std::endl;

    long double a, b;
    std::cout << "Enter two real numbers:" << std::endl;
    std::cin >> a >> b;
    std::cout << "Multiple: " << Multiply(a, b) << std::endl;

    return 0;
}