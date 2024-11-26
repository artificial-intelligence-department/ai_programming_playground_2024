#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 0.7, b = 0.05, x = 0.43;
    double R, S;
    R = pow(x, 2) * (x + 1) / b - pow(sin(x-a), 2);
    S = sqrt(x * b / a) + abs(pow(cos(x + b), 3));
    cout << "R = " << R << endl;
    cout << "S = " << S << endl;
    return 0;
}