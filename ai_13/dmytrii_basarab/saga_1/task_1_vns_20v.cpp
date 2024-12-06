#include <iostream>
#include <cmath>

using namespace std;

const double e = 2.71828; //в коді використана як мінімум одна дійсний з подвійною точністю змінна

int main() {
float A;
float B;
float a = 0.5;
float b = 2.9;
float x = 0.3;

A = (pow(a, x) + pow(b, -x)*sin(a-b))/sqrt(fabs(a-b));
cout << "A: " << A << endl;

B = a*pow(e, -sqrt(a))*cos(b*x/a);
cout << "B: " << B << endl;

return 0;
}