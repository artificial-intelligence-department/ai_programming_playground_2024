#include <cfloat>
#include <cmath>
#include <iostream>

float operationsFloat(float a, float b);
double operationsDouble(double a, double b);

const float f_a = 1000;
const float f_b = 0.0001;
const double d_a = 1000;
const double d_b = 0.0001;

int main()
{
    //((a - b)^2 - (a^2 - 2ab))/b^2
    float f_r = operationsFloat(f_a, f_b);
    double d_r = operationsDouble(d_a, d_b);

    std::cout << "Float result: " << f_r << '\n';
    std::cout << "Double result: " << d_r << '\n';
    // float result is wrong because floating point precison of float is only about 6 or 7 digits
    // double result is right because floating point precision of double is about 15 digits
    // in this example we need to hold at least 8 digits after the decimal point
}

float operationsFloat(float a, float b)
{
    float first_action = std::pow(a - b, 2);
    float second_action = pow(a, 2) - 2 * a * b;
    float third_action = first_action - second_action;
    float result = third_action / pow(b, 2);
    return result;
}

double operationsDouble(double a, double b)
{
    double first_action = std::pow(a - b, 2);
    double second_action = pow(a, 2) - 2 * a * b;
    double third_action = first_action - second_action;
    double result = third_action / pow(b, 2);
    return result;
}
