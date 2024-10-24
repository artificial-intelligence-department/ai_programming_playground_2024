#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a = 1000;
    float b = 0.0001;

    float RESULT_ONE_F = pow((a + b), 3) - pow(a, 3);
    float RESULT_TWO_F = 3 * a * pow(b, 2) + pow(b, 3) + 3 * b * pow(a, 2);
    float RESULT_LAST_F = RESULT_ONE_F / RESULT_TWO_F;

    double c = 1000;
    double d = 0.0001;

    double RESULT_ONE_D = pow((c + d), 3) - pow(c, 3);
    double RESULT_TWO_D = 3 * c * pow(d, 2) + pow(d, 3) + 3 * d * pow(c, 2);
    double RESULT_LAST_D = RESULT_ONE_D / RESULT_TWO_D;

    cout << "Math problem:\n   [ (a + b )^3 - (a)^3 ]\n-----------------------------\n[ 3a(b)^2 + (b)^3 + 3b(a)^2 ]\n\n";
    cout << "The answers for this using float: " << RESULT_LAST_F << endl;
    cout << "The answers for this using double: " << RESULT_LAST_D << endl;

    return 0;
    //float - точність гірша, тільки 5 знаків після коми + гірше обробляє малі змінні при роботі з великими числами.
    //double - точність краща, оскільки 15-16 знаків після коми + краще обробляє малі змінні при роботі з великими числами.
}