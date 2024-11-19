#include <iostream>
#include <math.h>

int main() {
    float a_f = 1000;
    float b_f = 0.0001;
   
    
    double a_d = 1000;
    double b_d = 0.0001;

    float c_f = pow(a_f - b_f, 3);
    float d_f = pow(a_f, 3) - 3 * pow(a_f, 2) * b_f;
    float e_f = pow(b_f, 3) - 3 * a_f * pow(b_f, 2);
    float result_f = (c_f - d_f) / e_f;

    double c_d = pow(a_d - b_d, 3);
    double d_d = pow(a_d, 3) - 3 * pow(a_d, 2) * b_d;
    double e_d = pow(b_d, 3) - 3 * a_d * pow(b_d, 2);
    double result_d = (c_d - d_d) / e_d;

    std::cout << "Результат для float: " << result_f << std::endl;
    std::cout << "Результат для double: " << result_d << std::endl;

    return 0;
}