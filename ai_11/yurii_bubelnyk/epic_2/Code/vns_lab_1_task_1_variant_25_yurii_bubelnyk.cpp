#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a_float = 1000.0f;
    float b_float = 0.0001f;
    
    double a_double = 1000.0;
    double b_double = 0.0001;

    
    float num_float = pow(a_float - b_float, 3) - (pow(a_float, 3) - 3 * a_float * a_float * b_float);
    float den_float = pow(b_float, 3) - 3 * a_float * pow(b_float, 2);
    float result_float = num_float / den_float;

    cout << "float: " << result_float << endl;

    double num_double = pow(a_double - b_double, 3) - (pow(a_double, 3) - 3 * a_double * a_double * b_double);
    double den_double = pow(b_double, 3) - 3 * a_double * pow(b_double, 2);
    double result_double = num_double / den_double;

    cout << "double: " << result_double << endl;

    return 0;
}
