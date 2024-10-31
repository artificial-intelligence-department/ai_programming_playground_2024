#include <iostream>
#include <cmath>
//v 21

int main()
{
    //float
    float a_f = 100;
    float b_f = 0.001;
    float numerator_f, denominator_f;
    numerator_f = pow(a_f - b_f, 4) - (pow(a_f, 4) - 4*pow(a_f, 3)*b_f + 6*pow(a_f, 2)*pow(b_f, 2));
    denominator_f = (pow(b_f, 4) - 4*a_f*pow(b_f, 3));
    std::cout << "The result using float: " << (numerator_f / denominator_f) << std::endl;

    //double
    double a_d = 100;
    double b_d = 0.001;
    double numerator_d, denominator_d;
    numerator_d = pow(a_d - b_d, 4) - (pow(a_d, 4) - 4*pow(a_d, 3)*b_d + 6*pow(a_d, 2)*pow(b_d, 2));
    denominator_d = (pow(b_d, 4) - 4*a_d*pow(b_d, 3));
    std::cout << "The result using double: " << (numerator_d / denominator_d);
    return 0;
}