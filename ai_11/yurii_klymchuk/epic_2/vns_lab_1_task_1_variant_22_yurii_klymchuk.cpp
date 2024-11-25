#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // calculations for double type
    double a_d = 100, b_d = 0.001;
    
    double nominator_d = pow((a_d-b_d), 4) - (pow(a_d, 4) - 4*pow(a_d, 3)*b_d);
    double denominator_d = 6*pow(a_d*b_d, 2) - 4*a_d*pow(b_d, 3) + pow(b_d, 4);
    double result_d = nominator_d/denominator_d;

    cout << "Calculations using double type: " << result_d << endl;

    // calculation for float type
    float a_f = 100, b_f = 0.001;

    float nominator_f = pow((a_f-b_f), 4) - (pow(a_f, 4) - 4*pow(a_f, 3)*b_f);
    float denominator_f = 6*pow(a_f*b_f, 2) - 4*a_f*pow(b_f, 3) + pow(b_f, 4);
    float result_f = nominator_f/denominator_f;

    cout << "Calculations using float type: " << result_f << endl;
    return 0;
}