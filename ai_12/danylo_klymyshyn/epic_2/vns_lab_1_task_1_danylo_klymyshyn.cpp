#include <iostream>
#include <cmath>

int main(){


float a_f = 1000.0;
float b_f = 0.0001;

float chyselnyk_f = pow((a_f + b_f), 3) - pow(a_f, 3);
float znamennyk_f = 3*a_f*pow(b_f, 2) + pow(b_f, 3) + 3 * pow(a_f, 2) * b_f;   

std::cout << "Float result: " << chyselnyk_f/znamennyk_f << std::endl;

double a_d = 1000.0;
double b_d = 0.0001;

double chyselnyk_d = pow((a_d + b_d), 3) - pow(a_d, 3);
double znamennyk_d = 3*a_d*pow(b_d, 2) + pow(b_d, 3) + 3 * pow(a_d, 2) * b_d;   


std::cout << "Double result: " << chyselnyk_d/znamennyk_d << std::endl;
    return 0;
}