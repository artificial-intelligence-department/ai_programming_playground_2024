#include <iostream>
#include <cmath>
using namespace std;

int main() {

    float a_f = 1000.0f, b_f = 0.0001f;
    double a_d = 1000.0, b_d = 0.0001;

    //float
    float numerator_f = pow(a_f - b_f, 3) - (pow(a_f, 3) - 3 * pow(a_f, 2) * b_f);
    float denominator_f = pow(b_f, 3) - 3 * a_f * pow(b_f, 2);
    float result_f = numerator_f / denominator_f;

    //double
    double numerator_d = pow(a_d - b_d, 3) - (pow(a_d, 3) - 3 * pow(a_d, 2) * b_d);
    double denominator_d = pow(b_d, 3) - 3 * a_d * pow(b_d, 2);
    double result_d = numerator_d / denominator_d;


    cout << "Результат для float: " << result_f << endl;
    cout << "Результат для double: " << result_d << endl;

    return 0;
}
