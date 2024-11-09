#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main (){
double a = 1000.0;
double b = 0.0001;
double c = a - b;
double d = pow (c, 3);
double e = pow (a, 3);
double f = 3 * a * pow(b, 2);
double g = pow (b, 3);
double h = 3 * pow(a, 2) * b;
double result1 = (d - (e - f))/(g - h);
cout << "Результат виразу з double: " << setprecision(10) << result1 << endl;

float a2 = static_cast <float>(a);
float b2 = static_cast <float>(b);
float c2 = a2 - b2;
float d2 = pow(c2, 3);
float e2 = pow(a2, 3);
float f2 = 3 * a2 * pow(b2, 2);
float g2 = pow(b2, 3);
float h2 = 3 * pow(a2, 2) * b;
float result2 = (d2 - (e2 - f2))/(g2 - h2);
cout << "Результат виразу з float: " << setprecision(10) << result2 << endl;

double difference = result2 - result1;
cout << "Різниця між результатами: " << difference;

return 0;
}