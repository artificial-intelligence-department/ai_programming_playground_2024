#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float floatA = 1000.0f;
    float floatB = 0.0001f;

    double doubleA = 1000.0;
    double doubleB = 0.0001;

    float calculation_float_Up = pow(floatA - floatB, 3) - (pow(floatA, 3) - 3 * (pow(floatA, 2)) * floatB);
    float calculation_float_Down = pow(floatB, 2) - 3 * (floatA * pow(floatB, 2));
    float resultF = calculation_float_Up / calculation_float_Down;

   double calculation_double_Up = pow(doubleA - doubleB, 3) - (pow(doubleA, 3) - 3 * (pow(doubleA, 2)) * doubleB);
   double calculation_double_Down = pow(doubleB, 2) - 3 * (doubleA * pow(doubleB, 2));
   double resultD = calculation_double_Up / calculation_double_Down;

   cout << resultF << endl;
   cout << resultD;

   return 0;

}