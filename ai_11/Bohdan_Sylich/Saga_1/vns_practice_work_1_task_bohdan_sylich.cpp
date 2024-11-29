#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 0.5, b = 2.9, x = 0.3;
    double numerator = pow(a, x) + pow(b, -x) * sin(a - b);
    double denominator = sqrt(fabs(a - b));
    double alpha = numerator / denominator;

    double beta = a * exp(-sqrt(a)) * cos(b * x / a);

    cout << "alpha (α) = " << alpha << endl;
    cout << "beta (β) = " << beta << endl;

    return 0;
}
