#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a_f = 1000;
    float b_f = 0.0001;

    float denominator_f = 3*a_f*pow(b_f, 3) + pow(b_f, 3);
    float numerator_f = pow(a_f + b_f, 3) - (pow(a_f, 3) + 3*pow(a_f, 2)* b_f);

    cout <<"Float result: " <<  numerator_f / denominator_f << endl;

    double a_d = 1000;
    double b_d = 0.0001;

    double denominator_d = 3*a_d*pow(b_d, 3) + pow(b_d, 3);
    double numerator_d = pow(a_d + b_d, 3) - (pow(a_d, 3) + 3*pow(a_d, 2)* b_d);
    
    cout << "Double result: "<< numerator_d / denominator_d << endl;
   
}