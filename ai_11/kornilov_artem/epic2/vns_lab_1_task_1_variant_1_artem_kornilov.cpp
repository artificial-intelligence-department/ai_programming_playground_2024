#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main (){

double a = 1000.0;
double b = 0.0001;

float a1 = 1000.0f;
float b1 = 0.0001f;

double sumd = pow((a + b), 2);
double sumd1 = pow(a, 2) + 2*a*b;
double sumd2 = sumd - sumd1;
double resultd = sumd2/pow(b, 2);

float sumf = pow((a1 + b1), 2);
float sumf1 = pow(a1, 2) + 2*a1*b1;
float sumf2 = sumf - sumf1;
float resultf = sumf/pow(b1, 2);

cout << "Double: " << resultd << endl;
cout << "Float: " << resultf;

return 0;
}