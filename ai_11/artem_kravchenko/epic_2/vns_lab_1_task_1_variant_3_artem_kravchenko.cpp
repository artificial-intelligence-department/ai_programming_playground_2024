#include <iostream>
#include <cmath>
using namespace std;

int main (){
    float a_f = 1000;
    float b_f = 0.0001;

    float chiselnyk_f = pow((a_f + b_f),3) - (pow(a_f, 3) + 3*pow(a_f, 2)*b_f);
    float znamenik_f = 3*a_f*pow(b_f, 2) + pow(b_f, 3) ;

    float result_f = chiselnyk_f / znamenik_f;
    cout << "Результат float: " << result_f << endl;

    double a_d = 1000;
    double b_d = 0.0001;

    double chiselnyk_d = pow((a_d + b_d),3) - (pow(a_d, 3) + 3*pow(a_d, 2)*b_d);
    double znamenik_d = 3*a_d*pow(b_d, 2) + pow(b_d, 3) ;

    double result_d = chiselnyk_d / znamenik_d;
    cout << "Результат double: " << result_d << endl;

    return 0;
}