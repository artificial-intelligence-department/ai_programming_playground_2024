#include <iostream>
#include <cmath>                  // для pow()
using namespace std;

int main() {
    float a_f = 1000.0f;
    float b_f = 0.0001f;
    double a_d = 1000.0;
    double b_d = 0.0001;

    float up_f = pow(a_f + b_f, 3) - pow(a_f, 3);
    float down_f = 3 * a_f * pow(b_f, 2) + pow(b_f, 3) + 3 * pow(a_f, 2) * b_f;
    float result_f = up_f / down_f;

    double up_d = pow(a_d + b_d, 3) - pow(a_d, 3);
    double down_d = 3 * a_d * pow(b_d, 2) + pow(b_d, 3) + 3 * pow(a_d, 2) * b_d;
    double result_d = up_d / down_d;

    cout << "Результат для типу float: " << result_f << endl;
    cout << "Результат для типу double: " << result_d << endl;

    return 0;

}