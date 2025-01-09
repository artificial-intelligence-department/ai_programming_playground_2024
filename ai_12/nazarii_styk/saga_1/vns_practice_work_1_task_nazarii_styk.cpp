// Завдання 1. Варіант 17
#include <iostream>
#include <cmath>

#define e 2.7182

using namespace std;

int main()
{
    float a = 3.2;
    float b = 17.5;
    float x = -4.8;

    double Y = pow(b, 3) * pow(tan(x), 2) - a / (pow(sin(x/a), 2));
    double Z = a * pow(e, sqrt(3)) * cos((b*x)/a);

    cout << "Y = " << Y << endl;
    cout << "Z = " << Z << endl;

    return 0;
}
