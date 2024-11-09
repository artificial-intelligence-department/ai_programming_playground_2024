#include <iostream>
#include <cmath> 

int main() {

    float a_f = 1000.0f;
    float b_f = 0.0001f;

    float num_f1 = pow(a_f + b_f, 3);                       // (a + b)^3
    float num_f2 = pow(a_f, 3) + 3 * a_f * a_f * b_f;       // a^3 + 3*a^2*b
    float denom_f = 3 * a_f * b_f * b_f + pow(b_f, 3);      // 3*a*b^2 + b^3

    float result_f = (num_f1 - num_f2) / denom_f;
    std::cout << "Result using float: " << result_f << std::endl;

    double a_d = 1000.0;
    double b_d = 0.0001;

    double num_d1 = pow(a_d + b_d, 3);                      // (a + b)^3
    double num_d2 = pow(a_d, 3) + 3 * a_d * a_d * b_d;      // a^3 + 3*a^2*b
    double denom_d = 3 * a_d * b_d * b_d + pow(b_d, 3);     // 3*a*b^2 + b^3

    double result_d = (num_d1 - num_d2) / denom_d;
    std::cout << "Result using double: " << result_d << std::endl;

    //Пояснення результатів:
    //Результат може відрізнятися між float і double через межі точності кожного типу.
    //'float'має більш низьку точність (близько 7 знаків після коми), в той час як'double'має більш високу точність (близько 15 знаків після коми).

    return 0;
}
