#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a_f = 100.0;
    float b_f = 0.001;
    double a_d = 100.0;
    double b_d = 0.001;

    // Обчислення float
    float c_f = a_f - b_f;
    float d_f = pow(c_f, 4);

    float a2_f = pow(a_f, 2);
    float a3_f = pow(a_f, 3);
    float a4_f = pow(a_f, 4);

    float b2_f = pow(b_f, 2);
    float b3_f = pow(b_f, 3);
    float b4_f = pow(b_f, 4);

    float numerator_f = d_f - (a4_f - 4 * a3_f * b_f + 6 * a2_f * b2_f);
    float denominator_f = b4_f - 4 * a_f * b3_f;
    float result_f = numerator_f / denominator_f;

    // Обчислення double
    double c_d = a_d - b_d;
    double d_d = pow(c_d, 4);

    double a2_d = pow(a_d, 2);
    double a3_d = pow(a_d, 3);
    double a4_d = pow(a_d, 4);

    double b2_d = pow(b_d, 2);
    double b3_d = pow(b_d, 3);
    double b4_d = pow(b_d, 4);

    double numerator_d = d_d - (a4_d - 4 * a3_d * b_d + 6 * a2_d * b2_d);
    double denominator_d = b4_d - 4 * a_d * b3_d;
    double result_d = numerator_d / denominator_d;

    // Вивід результатів
    cout << "Result (float): " << result_f << endl;
    cout << "Result (double): " << result_d << endl;

    return 0;
}

