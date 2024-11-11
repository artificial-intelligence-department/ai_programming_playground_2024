#include <iostream>
#include <cmath>

using namespace std;

int main() {
float a_f = 100.0f, b_f = 0.001f;

float ab_s = pow(a_f + b_f, 4) - (pow(a_f, 4) + 4 * pow(a_f, 3) * b_f);
float ab_th = (6 * pow(a_f, 2) * pow(b_f, 2)) + (4 * a_f * pow(b_f, 3)) + pow(b_f, 4);
float resultf = ab_s / ab_th;
cout << resultf << endl;

double a_d = 100, b_d = 0.001;
double ab_sd = pow(a_d + b_d, 4) - (pow(a_d, 4) + 4 * pow(a_d, 3) * b_d);
double ab_thd = (6 * pow(a_d, 2) * pow(b_d, 2)) + (4 * a_d * pow(b_d, 3)) + pow(b_d, 4);
double resultd = ab_sd / ab_thd;

cout << resultd << endl;

}