#include <iostream>
#include <cmath>

int main()
{
    // For float 
    // (a-b)^3 - (a^3) / b^3 - 3ab^2 - 3a^2b
    float a = 1000, b = 0.0001;
    float chyselnyk = pow((a - b), 3) - pow(a, 3);
    float znamennyk = pow(b, 3) - 3*a * pow(b, 2) - 3 * pow(a, 2) * b;
    float result = chyselnyk / znamennyk;

    // For double
    double aD = 1000, bD = 0.0001;
    double chyselnykD = pow((aD - bD), 3) - pow(aD, 3);
    double znamennykD = pow(bD, 3) - 3*aD * pow(bD, 2) - 3 * pow(aD, 2) * bD;
    double resultD = chyselnykD / znamennykD;

    std::cout << "Result for float: " << result << "\nResult for double: " << resultD << std::endl; 


    return 0;
}