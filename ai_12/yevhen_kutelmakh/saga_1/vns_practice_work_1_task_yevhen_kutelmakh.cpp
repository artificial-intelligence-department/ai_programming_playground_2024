#include <iostream>
#include <cmath>
using namespace std;

/*
Варіант 15.
f = (mtgx + |csinx|)^1/2
e = mcos(bx + sinx) + c^3
m=2; с=1; х=1,2; b=0,7.
*/

double calculateF(int m, double x, int c) {
    double f = sqrt(m*tan(x) + abs(c*sin(x)));
    return f;
}

double calculateE(int m, double x, int c, double b) {
    double e = m*cos(b*x + sin(x)) + pow(c, 3);
    return e;
}

int main() {
    int m = 2, c = 1;
    double x = 1.2, b = 0.7;
    cout << "Result of first expression is: " << calculateF(m, x, c);
    cout << "\nResult of second expression is: " << calculateE(m, x, c, b);
    return 0;
}